# 0. Create Source and CMakeLists.txt file
# 1. mkdir build
# 2. cd build
# 3. cmake .. Generating the build files / Configure the project
# 4. cmake --build
# 5. ./Executable

cmake_minimum_required(VERSION 3.22)

project(
    CppProjectTemplate
    VERSION 1.0.0
    LANGUAGES C CXX)

#CMake variables can be string , int or bools (bools are special case), CMake is smart enough to differenciate between types so we dont need to use "" to define a Variable name that is string

#some important variable setting (highly recommended to always set these variable )
set(CMAKE_CXX_STANDARD 17)
# require the compiler has fully implemented the standard version mentioned above
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_BUILD_TYPE "Debug")

#some compilers have features like gcc or g++ that are not part of c++ standard
set(CMAKE_CXX_EXTENSIONS OFF)

set(LIBRARY_NAME MyMathLib)
#variable name can be both with or with quatation marks
#set(LIBRARY_NAME "MyMathLib") this is also fine

set(EXECUTABLE_NAME EXECUTABLE)

#setting variable CMAKE_MODULE_PATH , it should be absolut path
#CMAKE_MODULE_PATH: This is a special CMake variable that holds a list of directories. When you use the include() command to incorporate a module into your CMakeLists.txt file, CMake searches for the module in the directories specified by CMAKE_MODULE_PATH.
#"${PROJECT_SOURCE_DIR}/cmake/":

#PROJECT_SOURCE_DIR: This is a built-in CMake variable that refers to the root directory of your project's source code.

#/cmake/: This part creates a subdirectory path within your project's source directory. This is where you would typically store your custom CMake modules.
set(CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/cmake/")

# these are like setting variables but only set bool , can be used to turn on/off certain features/functions
# can be override from command like for below example run cd build , cmake .. -DCOMPILE_EXECUTABLE=ON (no space after -D) this will override value of variable COMPILE_EXECUTABLE
option(COMPILE_EXECUTABLE "[Project] Compiling Executable" ON)

option(ENABLE_TESTING "Enable Testing" ON)

OPTION(ENABLE_WARNINGS "Enable Warnings" ON)
OPTION(ENABLE_WARNINGS_AS_ERRORS "Enable Warnings as errors" ON)

option(ENABLE_SANITIZER_ADDRESS "Enable address sanitizer" OFF)
option(ENABLE_SANITIZER_UNDEFINED "Enable undefined sanitizer" OFF)

option(ENABLE_LTO "Enable Link time optimization" ON)

option(USE_CPM "Whether to use CPM" OFF)
option(USE_CONAN "Whether to use Conon" OFF)
option(USE_VCPKG "Whether to use VCPKG" ON)

#Git Submodule lecture
#include(AddGitSubmodule)

include(FetchContent)
include(Docs)

if(ENABLE_WARNINGS)
    include(Warnings)

endif()

if(ENABLE_SANITIZER_ADDRESS OR ENABLE_SANITIZER_UNDEFINED)
    message(STATUS "Sanitizer Enabled")
    include(Sanitizers)
    add_sanitizer_flags()

else()
    message(STATUS "Sanitizer Disabled")
endif()

if(ENABLE_LTO)
    include(LTO)
endif()

if(USE_CPM)
    include(CPM)
    message(STATUS "Using CPM")

    cpmaddpackage("gh:nlohmann/json#v3.11.3")
    cpmaddpackage("gh:fmtlib/fmt#10.2.1")
    cpmaddpackage("gh:gabime/spdlog#v1.14.1")
    cpmaddpackage("gh:jarro2783/cxxopts#v3.2.0")

    if(ENABLE_TESTING)
        cpmaddpackage("gh:catchorg/Catch2#v3.5.3")
        FetchContent_MakeAvailable(Catch2)
        message(STATUS "Included Catch.cmake from: ${catch2_SOURCE_DIR}")
        list(APPEND CMAKE_MODULE_PATH ${catch2_SOURCE_DIR}/extras)
    endif()

elseif(USE_CONAN OR USE_VCPKG)
    if(USE_CONAN)
        message(STATUS "Using Conan")
        include(${CMAKE_BINARY_DIR}/conan_toolchain.cmake)
    elseif(USE_VCPKG)
        message(STATUS "Using VCPKG")
        include(${CMAKE_SOURCE_DIR}/external/vcpkg/scripts/buildsystems/vcpkg.cmake)
    endif()
    find_package(nlohmann_json REQUIRED)
    find_package(fmt REQUIRED)
    find_package(spdlog REQUIRED)
    find_package(cxxopts REQUIRED)
    if(ENABLE_TESTING)
        find_package(Catch2 REQUIRED)
        list(APPEND CMAKE_MODULE_PATH ${Catch2_SOURCE_DIR}/extras)
    endif()
else()
    message(STATUS "Using FetchContent")
        #ONLY WORK WITH CMAKE PROJECTS IF NOT USE GIT SUBMODULE METHOD TO DEFINE YOUR CUSTOM LIBRARY TARGET
    #IT WILL COPY GIVEN GIT REPO IN BUILD FOLDER
    FetchContent_Declare(
        nlohmann_json #PROJECT_NAME OF THE GITHUT/GITLAB CMAKE ONLY
        GIT_REPOSITORY https://github.com/nlohmann/json #URL
        GIT_TAG v3.11.3 #VERSION/Tag
        GIT_SHALLOW TRUE #SHALLOW COPY DONT COPY RECURSIVELY
    )

    #LOAD LIBRARY IN OUR CMAKE PROJECT
    FetchContent_MakeAvailable(nlohmann_json)

    FetchContent_Declare(
        fmt #PROJECT_NAME OF THE GITHUT/GITLAB CMAKE ONLY
        GIT_REPOSITORY https://github.com/fmtlib/fmt #URL
        GIT_TAG 10.2.1 #VERSION/Tag
        GIT_SHALLOW TRUE #SHALLOW COPY DONT COPY RECURSIVELY
    )

    #LOAD LIBRARY IN OUR CMAKE PROJECT
    FetchContent_MakeAvailable(fmt)

    FetchContent_Declare(
        spdlog #PROJECT_NAME OF THE GITHUT/GITLAB CMAKE ONLY
        GIT_REPOSITORY https://github.com/gabime/spdlog #URL
        GIT_TAG v1.14.1 #VERSION/Tag
        GIT_SHALLOW TRUE #SHALLOW COPY DONT COPY RECURSIVELY
    )

    #LOAD LIBRARY IN OUR CMAKE PROJECT
    FetchContent_MakeAvailable(spdlog)

    FetchContent_Declare(
        cxxopts #PROJECT_NAME OF THE GITHUT/GITLAB CMAKE ONLY
        GIT_REPOSITORY https://github.com/jarro2783/cxxopts #URL
        GIT_TAG v3.2.0 #VERSION/Tag
        GIT_SHALLOW TRUE #SHALLOW COPY DONT COPY RECURSIVELY
    )

    #LOAD LIBRARY IN OUR CMAKE PROJECT
    FetchContent_MakeAvailable(cxxopts)

    if(ENABLE_TESTING)
        FetchContent_Declare(
            Catch2 #PROJECT_NAME OF THE GITHUT/GITLAB CMAKE ONLY
            GIT_REPOSITORY https://github.com/catchorg/Catch2 #URL
            GIT_TAG v3.5.3 #VERSION/Tag
            GIT_SHALLOW TRUE #SHALLOW COPY DONT COPY RECURSIVELY
        )

        #LOAD LIBRARY IN OUR CMAKE PROJECT
        FetchContent_MakeAvailable(Catch2)

        list(APPEND CMAKE_MODULE_PATH ${catch2_SOURCE_DIR}/extras)
    endif()

endif()



#Git Submodule lecture
#add_git_submodule(external/json)

add_subdirectory(configured)

#Git Submodule lecture
#add_subdirectory(external)

#order in which subdirectory are added matter , dependencies shoud be added first
add_subdirectory(Source)

if(COMPILE_EXECUTABLE)
    add_subdirectory(App)
else()
    message("[Project] Compiling Executable [SKIP].")
endif()

if(ENABLE_TESTING)
#CTest ship with regular cmake , we need to enable it
    include(CTest)
    enable_testing()
    add_subdirectory(tests)
endif()
