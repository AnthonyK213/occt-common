cmake_minimum_required(VERSION 3.20)

project(
  OcctCommon
  VERSION 0.0.1
  DESCRIPTION "A Rhinocommon-like library based on OpenCASCADE"
  LANGUAGES CXX
  )

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_EXPORT_COMPILE_COMMANDS True)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/cmake" ${CMAKE_MODULE_PATH})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib")
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib")

### Require out-of-source builds
file(TO_CMAKE_PATH "${PROJECT_BINARY_DIR}/CMakeLists.txt" LOC_PATH)
if(EXISTS "${LOC_PATH}")
  message(FATAL_ERROR "You cannot build in a source directory 
  (or any directory with a CMakeLists.txt file). Please make a 
  build subdirectory. Feel free to remove CMakeCache.txt and CMakeFiles.")
endif()

option(ENABLE_UNIT_TESTS "Enable unit tests" ON)
message(STATUS "Enable testing: ${ENABLE_UNIT_TESTS}")

find_package(OpenCASCADE COMPONENTS FoundationClasses REQUIRED)
find_package(OpenCASCADE COMPONENTS ModelingAlgorithms REQUIRED)
find_package(OpenCASCADE COMPONENTS ModelingData REQUIRED)
find_package(OpenCASCADE COMPONENTS DataExchange REQUIRED)
find_package(OpenCASCADE COMPONENTS Visualization REQUIRED)

MESSAGE("OCC-Include-Dir: ${OpenCASCADE_INCLUDE_DIR}")
MESSAGE("OCC-Lib-Dir: ${OpenCASCADE_LIBRARY_DIR}")
MESSAGE("OCC-Libs: ${OpenCASCADE_LIBRARIES}")

include_directories(
  ${PROJECT_BINARY_DIR}
  ${PROJECT_SOURCE_DIR}/include/
  ${OpenCASCADE_INCLUDE_DIR}
  )

link_directories(${OpenCASCADE_LIBRARY_DIR})

add_subdirectory(src)

if(ENABLE_UNIT_TESTS)
  enable_testing()
  add_subdirectory(tests)
endif()
