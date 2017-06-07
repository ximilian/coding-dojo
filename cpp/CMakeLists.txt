cmake_minimum_required(VERSION 2.8.8)
set(PROJECT_NAME_STR coding-dojo)
set (CMAKE_CXX_STANDARD 11)
project(${PROJECT_NAME_STR} C CXX)

find_package(Threads REQUIRED)

if(CMAKE_COMPILER_IS_GNUCXX)
    add_definitions(-Wall -ansi -Wno-deprecated -pthread)
endif()

#-------------------
# Module sources
#-------------------
file(GLOB SRC_FILES ${PROJECT_SOURCE_DIR}/src/*.cpp)

#-------------------
# set common include folder for module
#-------------------
set(COMMON_INCLUDES ${PROJECT_SOURCE_DIR}/include)
set(EXT_PROJECTS_DIR ${PROJECT_SOURCE_DIR}/ext)

add_subdirectory(${EXT_PROJECTS_DIR}/gtest)

#-------------------
# Test
#-------------------
enable_testing()
set(PROJECT_TEST_NAME ${PROJECT_NAME_STR}_test)
include_directories(${GTEST_INCLUDE_DIRS} ${COMMON_INCLUDES})

# Uncomment this line to include all test automatically
# file(GLOB TEST_SRC_FILES ${PROJECT_SOURCE_DIR}/test/*.cpp)
# Otherwise add them below
set(TEST_SRC_FILES ${SRC_FILES}
### START KATA TO TEST ###
${PROJECT_SOURCE_DIR}/test/kata_fizzbuzz.cpp
${PROJECT_SOURCE_DIR}/test/kata_bank_account.cpp
### END KATA TO TEST ###
)

add_executable(${PROJECT_TEST_NAME} ${TEST_SRC_FILES})
add_dependencies(${PROJECT_TEST_NAME} googletest)


target_link_libraries(${PROJECT_TEST_NAME}
        ${GTEST_LIBS_DIR}/libgtest.a
        ${GTEST_LIBS_DIR}/libgtest_main.a
        )

target_link_libraries(${PROJECT_TEST_NAME} ${CMAKE_THREAD_LIBS_INIT})

add_test(test1 ${PROJECT_TEST_NAME})
