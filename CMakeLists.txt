cmake_minimum_required(VERSION 3.4)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

option(BUILD_TESTS "Build tests" OFF)

project(banking)

include_directories(include)

add_library(Account STATIC ${CMAKE_CURRENT_SOURCE_DIR}/sources/Account.cpp)

add_library(Transaction STATIC ${CMAKE_CURRENT_SOURCE_DIR}/sources/Transaction.cpp)


if(BUILD_TESTS)
  enable_testing()
  add_subdirectory(third-party/gtest)
  add_executable(check tests/test1.cpp tests/test2.cpp tests/test3.cpp)
  target_compile_options(check PRIVATE --coverage)
  target_link_libraries(check Account Transaction gtest_main gmock --coverage)
  add_test(NAME check COMMAND check)
endif()
