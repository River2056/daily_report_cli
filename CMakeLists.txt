cmake_minimum_required(VERSION 3.16)

project(DailyReportCli
    VERSION 1.0.0
    DESCRIPTION "Daily work report cli tool")

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
# set(CMAKE_CXX_EXTENSIONS OFF)

set(EXECUTABLE cli)
set(EXECUTABLE_YAML cli_y)
set(LIBRARY library)
set(CMAKE_INSTALL_PREFIX "C:/cli_tools")

set(CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/cmake/")
include(AddGitSubmodule)
add_git_submodule(external/json)
add_git_submodule(external/ClipboardXX)
add_git_submodule(external/yaml-cpp)

add_subdirectory(input)
add_subdirectory(src)
add_subdirectory(app)
