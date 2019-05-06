file(GLOB_RECURSE UNITTEST_SOURCES test_*.cpp)

add_executable(
    ${PROJECT_TEST_NAME}
    ${UNITTEST_SOURCES}
    )

target_link_libraries(
    ${PROJECT_TEST_NAME}
    gtest_main
    ${PROJECT_NAME}
    )

add_test(
  NAME
    unit
  COMMAND
    ${CMAKE_BINARY_DIR}/${CMAKE_INSTALL_BINDIR}/${PROJECT_TEST_NAME}
  )

# Setting CodeCoverage support
include(../cmake/CodeCoverage.cmake)
APPEND_COVERAGE_COMPILER_FLAGS()
set(COVERAGE_EXCLUDES '/usr/include/*' '*/include/gtest/*' '*/src/gtest*')
setup_target_for_coverage(NAME ${PROJECT_TEST_NAME}_coverage
                          EXECUTABLE ${PROJECT_TEST_NAME}
                          DEPENDENCIES ${PROJECT_TEST_NAME})

target_link_libraries(${PROJECT_TEST_NAME}
                      gcov
                     )
