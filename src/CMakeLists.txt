set(LIBRARY_SOURCES 
    "WorkRecord.cpp")

add_library(${LIBRARY} STATIC ${LIBRARY_SOURCES})

target_include_directories(${LIBRARY} PUBLIC
    include)
