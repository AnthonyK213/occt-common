file(
  GLOB
  OcctCommon_SRC
  *.cpp
  )

add_library(
  ${PROJECT_NAME}
  SHARED
  ${OcctCommon_SRC}
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
