#include "clipboardxx.hpp"
#include "config.h"
#include "yaml-cpp/yaml.h"
#include <fstream>
#include <iostream>
#include <sstream>

static constexpr const char *const DATESTR = "date";
static constexpr const char *const WORK = "work";
static constexpr const char *const TITLE = "title";
static constexpr const char *const PROGRESS = "progress";
static constexpr const char *const TIME = "time";
static constexpr const char *const DETAILS = "details";

int main() {
  clipboardxx::clipboard clipboard;
  std::ifstream f(yaml_input_path);
  std::stringstream s;

  // main logic here
  YAML::Node data = YAML::LoadFile(yaml_input_path);
  s << data[DATESTR] << " Daily Report" << '\n';
  for (int i = 0; i < data[WORK].size(); i++) {
    YAML::Node work = data[WORK];
    s << "# " << work[i][TITLE] << '\n';

    if (work[i][PROGRESS].as<int>() >= 0) {
      s << "Progress: " << work[i][PROGRESS] << "%" << '\n';
    }

    s << "Time Tracking: " << work[i][TIME] << "H" << '\n';
    if (work[i][DETAILS].size() > 0) {
      s << "Details: " << '\n';
      for (int j = 0; j < work[i][DETAILS].size(); j++) {
        YAML::Node details = work[i][DETAILS][j];
        s << "  * " << details << '\n';
      }
    }

    s << '\n';
  }


  std::cout << s.str() << '\n';
  clipboard << s.str();

  return 0;
}
