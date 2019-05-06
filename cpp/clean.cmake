set(build_dir ${CMAKE_CURRENT_LIST_DIR}/build)

if(EXISTS ${build_dir})
    execute_process(
    COMMAND make clean
    WORKING_DIRECTORY ${build_dir}
    )
endif()
