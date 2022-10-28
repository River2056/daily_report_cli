configure_file(
    "config.h.in"
    "${CMAKE_BINARY_DIR}/input/include/config.h" ESCAPE_QUOTES
)

configure_file(
    "report.json"
    "${CMAKE_BINARY_DIR}/app/Debug/report.json" ESCAPE_QUOTES
)

configure_file(
    "report.yaml"
    "${CMAKE_BINARY_DIR}/app/Debug/report.yaml" ESCAPE_QUOTES
)

