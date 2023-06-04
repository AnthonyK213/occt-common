include(FetchGTest)

enable_testing()

add_executable(
  OcctCommonTest
  test.cpp
  )

target_link_libraries(
  OcctCommonTest
  gtest_main
  )

include(GoogleTest)
gtest_discover_tests(OcctCommonTest)
