cmake_minimum_required(VERSION 4.1)
project(cpp_mini_nn LANGUAGES C++)
set(CMAKE_C++_STANDARD 20)
set(CMAKE_C++_STANDARD_REQUIRED ON)

add_library(mininn src/nn.cpp)
target_include_directories(mininn PUBLIC include)

add_executable(xor_demo examples/xor_demo.cpp)
target_link_libraries(xor_demo PRIVATE mininn)

enable_testing()
add_executable(test_nn tests/test_nn.cpp)
target_link_libraries(test_nn PRIVATE mininn)
add_test(NAME nn_tests COMMAND test_nn)


