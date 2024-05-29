#instead of referencing directories in CMake file it is good practice to have a seperate CMakeLists.txt for every seperate directory

set(LIBRARY_SOURCES "my_mathlib.cpp" )
set(LIBRARY_HEADERS "my_mathlib.h")
set(LIBRARY_INCLUDES
    "./"
    "${CMAKE_BINARY_DIR}/configured_files/include")

add_library(${LIBRARY_NAME} STATIC
    ${LIBRARY_SOURCES}
    ${LIBRARY_HEADERS})

target_include_directories(${LIBRARY_NAME} PUBLIC
    ${LIBRARY_INCLUDES}
)

target_link_libraries(${LIBRARY_NAME} PUBLIC
    nlohmann_json::nlohmann_json
    fmt::fmt
    spdlog::spdlog
    cxxopts::cxxopts)

if(${ENABLE_WARNINGS})
    target_set_warnings(${LIBRARY_NAME} ${ENABLE_WARNINGS} ${ENABLE_WARNINGS_AS_ERRORS})


endif()

if(${ENABLE_LTO})
    target_enable_lto(${LIBRARY_NAME} ${ENABLE_LTO})
endif()
