include(FetchContent)

Fetchcontent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest
  GIT_TAG v1.13.0
  SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/extern/googletest
  )

Fetchcontent_Makeavailable(googletest)

if(NOT googletest_POPULATED)
  FetchContent_Populate(googletest)

  # Prevent GoogleTest from overriding our compiler/linker options
  # when building with Visual Studio
  set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
  # Prevent GoogleTest from using PThreads
  set(gtest_disable_pthreads ON CACHE BOOL "" FORCE)

  # adds the targers: gtest, gtest_main, gmock, gmock_main
  add_subdirectory(
    ${googletest_SOURCE_DIR}
    ${googletest_BINARY_DIR}
    )

  # Silence std::tr1 warning on MSVC
  if(MSVC)
    foreach(_tgt gtest gtest_main gmock gmock_main)
      target_compile_definitions(${_tgt}
        PRIVATE
        "_SILENCE_TR1_NAMESPACE_DEPRECATION_WARNING"
        )
    endforeach()
  endif()
endif()

add_executable(
  OcctCommonTest
  test.cpp
  )

target_link_libraries(
  OcctCommonTest
  PRIVATE
  gtest
  ${OpenCASCADE_LIBRARIES}
  ${PROJECT_NAME}
  )

include(GoogleTest)

gtest_discover_tests(OcctCommonTest)
