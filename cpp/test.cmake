include(cmakemodules/Common.cmake)

execute_process(
  COMMAND ${build_dir}/${PROJECT_TEST_NAME} --force-colour
  RESULT_VARIABLE test_result
)