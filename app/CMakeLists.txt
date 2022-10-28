set(EXECUTABLE_SOURCES
    "main.cpp")

set(EXECUTABLE_SOURCES_YAML
    "main_y.cpp")

add_executable(${EXECUTABLE} ${EXECUTABLE_SOURCES})
add_executable(${EXECUTABLE_YAML} ${EXECUTABLE_SOURCES_YAML})

target_include_directories(${EXECUTABLE} PUBLIC 
    "${CMAKE_SOURCE_DIR}/src/include"
    "${CMAKE_BINARY_DIR}/input/include")

target_include_directories(${EXECUTABLE_YAML} PUBLIC 
    "${CMAKE_SOURCE_DIR}/src/include"
    "${CMAKE_BINARY_DIR}/input/include")

target_link_libraries(${EXECUTABLE} PUBLIC 
    ${LIBRARY}
    nlohmann_json
    ClipboardXX)

target_link_libraries(${EXECUTABLE_YAML} PUBLIC 
    ${LIBRARY}
    yaml-cpp
    ClipboardXX)

install(
    TARGETS ${EXECUTABLE_YAML}
    RUNTIME DESTINATION ${CMAKE_INSTALL_PREFIX})

install(FILES "${CMAKE_SOURCE_DIR}/input/report.yaml" 
    DESTINATION ${CMAKE_INSTALL_PREFIX})
