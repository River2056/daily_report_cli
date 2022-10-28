#include "clipboardxx.hpp"
#include "config.h"
#include "nlohmann/json.hpp"
#include <codecvt>
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
  std::ifstream f(json_input_path);
  nlohmann::json data = nlohmann::json::parse(f);
  std::stringstream s;

  std::string date = std::string(data[DATESTR]);

  s << date << " "
    << "daily report" << '\n';
  for (int i = 0; i < data[WORK].size(); i++) {
    nlohmann::json work = data[WORK];
    s << "# " << std::string(work[i][TITLE]) << '\n';

    if (work[i][PROGRESS] >= 0) {
      s << "Progress: " << work[i][PROGRESS] << "%" << '\n';
    }

    s << "Time Tracking: " << work[i][TIME] << "H" << '\n';
    if (work[i][DETAILS].size() > 0) {
      s << "Details: " << '\n';
      for (int j = 0; j < work[i][DETAILS].size(); j++) {
        nlohmann::json details = work[i][DETAILS][j];
        s << "  * " << std::string(details) << '\n';
      }
    }

    s << '\n';
  }

  std::cout << s.str() << '\n';
  clipboard << s.str();

  return 0;
}
