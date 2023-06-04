add_executable(
  OcctCommonTest
  ""
  )

target_sources(
  OcctCommonTest
  PRIVATE
  test.cpp
  )

target_link_libraries(
  OcctCommonTest
  PRIVATE
  OcctCommon
  gtest_main
  )

enable_testing()

add_test(
  NAME google_test
  COMMAND $<TARGET_FILE:OcctCommonTest>
  )
