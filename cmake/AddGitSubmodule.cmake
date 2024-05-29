#defines function called add_git_submodule that takes a argument called dir
function(add_git_submodule dir)
#Ensure git is installed in system
    find_package(Git REQUIRED)

    #Condition the check if CMakeLists.txt exist within dir. if not it execute command (git submodule update --init --recursive --${dir})
    #it will fetch or update the submodule if not exist
    #WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}) set working directory to project source directory which mean call that git commant from project source level
    if(NOT EXISTS ${dir}/CMakeLists.txt)
        execute_process(COMMAND ${GIT_EXECUTABLE}
        submodule update --init --recursive --${dir}
        WORKING_DIRECTORY ${PROJECT_SOURCE_DIR})
    endif()

    #add that fetched git submodule (basically a git repo) as sub module, if CMakeLists.txt exists in that directory
    if(EXISTS ${dir}/CMakeLists.txt)
        add_subdirectory(${dir})
    endif()
endfunction(add_git_submodule)
