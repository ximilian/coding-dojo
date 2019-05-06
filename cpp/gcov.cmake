include(build.cmake)

execute_process(
  COMMAND make ut_coding_dojo_playground_coverage
  COMMAND sed "s@\\(Open \\).\\(.*coverage report.\\)@${BoldGreen}\\1file://${CMAKE_CURRENT_SOURCE_DIR}/build/\\2${Reset}@"
  WORKING_DIRECTORY ${build_dir}
  RESULT_VARIABLE test_result
)

if(${test_result})
  message(FATAL_ERROR "test failed")
endif()
