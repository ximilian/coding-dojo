add_library(${PROJECT_NAME} "")

file(GLOB_RECURSE PRIVATE_SOURCES *.cpp)
file(GLOB_RECURSE PUBLIC_SOURCES *.h)

target_sources(
    ${PROJECT_NAME}
    PRIVATE
        ${PRIVATE_SOURCES}
    PUBLIC
        ${PUBLIC_SOURCES}
    )

target_include_directories(
    ${PROJECT_NAME}
    PUBLIC
        ${CMAKE_CURRENT_LIST_DIR}
    )
