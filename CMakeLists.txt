cmake_minimum_required(VERSION 3.5)
project(dbc-demo)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

if (MSVC)
    add_compile_options(/W4 /WX)
else(MSVC)
    add_compile_options(-Wall -Wextra -pedantic -Werror)
endif(MSVC)

option(BUILD_TESTING "" OFF)
include(CTest)

include(CMakeLocal.txt OPTIONAL)

if(BUILD_TESTING)
    find_package(Qt5Test REQUIRED)
endif(BUILD_TESTING)
find_package(Boost REQUIRED)

include_directories(${CMAKE_SOURCE_DIR}/assertexcept)
include_directories(${CMAKE_SOURCE_DIR}/ssn)
include_directories(${CMAKE_SOURCE_DIR}/payroll)
include_directories(${Boost_INCLUDE_DIRS})

set(CMAKE_INCLUDE_CURRENT_DIR ON)

add_subdirectory(assertexcept)
add_subdirectory(ssn)
add_subdirectory(payroll)
if(BUILD_TESTING)
    add_subdirectory(test)
endif(BUILD_TESTING)

