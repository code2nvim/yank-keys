cmake_minimum_required(VERSION 4.1)
# the value of CMAKE_EXPERIMENTAL_CXX_IMPORT_STD is only for CMake 4.1
# set(CMAKE_EXPERIMENTAL_CXX_IMPORT_STD d0edc3af-4c50-42ea-a356-e2862fe7a444)
# set(CMAKE_CXX_MODULE_STD ON)
project(yank-keys LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 26)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(COMPILE_WARNING_AS_ERROR ON)
add_compile_options(-Wall -Wextra -Wpedantic)
add_compile_options(-Wno-reserved-module-identifier)

add_compile_options(-pthread)

find_package(Libinput REQUIRED)
find_package(PkgConfig REQUIRED)
pkg_check_modules(gtkmm REQUIRED IMPORTED_TARGET gtkmm-4.0)
pkg_check_modules(libevdev REQUIRED IMPORTED_TARGET libevdev)
pkg_check_modules(libudev REQUIRED IMPORTED_TARGET libudev)

add_library(std)
target_sources(std
  PUBLIC
    FILE_SET CXX_MODULES FILES
      std.cc # in .gitignore
)

add_library(data)
target_link_libraries(data PRIVATE std)
target_sources(data
  PUBLIC
    FILE_SET CXX_MODULES FILES
      src/data.cpp
      src/data/helper.cpp
      src/data/modifier.cpp
)

add_library(input)
target_link_libraries(input PRIVATE Libinput::Libinput PkgConfig::libevdev PkgConfig::libudev)
target_link_libraries(input PRIVATE std)
target_sources(input
  PUBLIC
    FILE_SET CXX_MODULES FILES
      src/input.cpp
      src/input/event.cpp
      src/input/external.cpp
      src/input/memory.cpp
)

add_executable(yank-keys src/main.cpp)
target_sources(yank-keys
  PRIVATE
    FILE_SET CXX_MODULES FILES
      src/window.cpp
      src/window/cfg.cpp
      src/window/menu.cpp
      src/window/toggle.cpp
)

target_link_libraries(yank-keys
  PRIVATE
    PkgConfig::gtkmm
    data
    input
    std
)
