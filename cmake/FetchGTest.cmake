include(FetchContent)

Fetchcontent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest
  GIT_TAG v1.13.0
  SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/extern/googletest
  )

Fetchcontent_Makeavailable(googletest)
