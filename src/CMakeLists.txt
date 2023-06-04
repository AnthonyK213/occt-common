find_package(OpenCASCADE COMPONENTS FoundationClasses REQUIRED)
find_package(OpenCASCADE COMPONENTS ModelingAlgorithms REQUIRED)
find_package(OpenCASCADE COMPONENTS ModelingData REQUIRED)
find_package(OpenCASCADE COMPONENTS DataExchange REQUIRED)
find_package(OpenCASCADE COMPONENTS Visualization REQUIRED)

MESSAGE("OCC-Include-Dir: ${OpenCASCADE_INCLUDE_DIR}")
MESSAGE("OCC-Lib-Dir: ${OpenCASCADE_LIBRARY_DIR}")
MESSAGE("OCC-Libs: ${OpenCASCADE_LIBRARIES}")

include_directories(
  ${PROJECT_NAME}
  ${PROJECT_BINARY_DIR}
  ${PROJECT_SOURCE_DIR}/include/
  ${OpenCASCADE_INCLUDE_DIR}
  ${OpenCASCADE_LIBRARY_DIR}
  )

add_library(
  ${PROJECT_NAME}
  SHARED
  occt_common.cpp
  )

target_link_libraries(
  ${PROJECT_NAME}
  PRIVATE
  ${OpenCASCADE_LIBRARIES}
  )

target_include_directories(
  ${PROJECT_NAME}
  PUBLIC
  ${PROJECT_SOURCE_DIR}/include/
  )
