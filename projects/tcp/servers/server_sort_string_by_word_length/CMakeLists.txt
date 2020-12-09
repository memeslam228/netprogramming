project(server_sort_string_by_word_length)

include_directories(include)
file(GLOB SRC src/*.cpp src/*.cxx)
add_executable(${PROJECT_NAME} ${SRC})

target_link_libraries(${PROJECT_NAME} ${COMMON_DEPENDENCIES} ${SHARED_TCP_DEPENDENCIES})
