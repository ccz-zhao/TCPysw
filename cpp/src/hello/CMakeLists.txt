add_executable(test_error error.cpp)
add_executable(test_buffer test_buffer.cpp)

target_link_libraries(test_error PUBLIC util)
target_link_libraries(test_buffer PUBLIC socket)