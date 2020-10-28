cmake_minimum_required(VERSION 3.16)
cmake_policy(VERSION 3.16)
project(DesignPatternsCpp)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS OFF)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

# <fruit>
set(BUILD_SHARED_LIBS OFF)
set(FRUIT_USES_BOOST FALSE)
if (APPLE)
    set(CMAKE_MACOSX_RPATH ON)
endif ()
# </fruit>

enable_testing()

add_subdirectory(contrib)
add_subdirectory(src)
