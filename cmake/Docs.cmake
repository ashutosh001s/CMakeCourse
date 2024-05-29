find_package(Doxygen)

#CMAKE_SOURCE_DIR Absolute path to main  cmake directory
#CMAKE_BINARY_DIR Absolute path to cmake build directory
if(DOXYGEN_FOUND)
    add_custom_target(docs
       ${DOXYGEN_EXECUTABLE}
       WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}/docs
    )
endif()
