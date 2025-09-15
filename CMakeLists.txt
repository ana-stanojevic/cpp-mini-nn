cmake_minimum_required(VERSION 3.31)
project(cpp_ffn LANGUAGES CXX)

set(CMAKE_C++_STANDARD 20)
set(CMAKE_C++_STANDARD_REQUIRED ON)
set(CMAKE_CXX_CLANG_TIDY "clang-tidy;-checks=*")
find_package(Eigen3 3.4 REQUIRED NO_MODULE)

add_library(ffn src/nn.cpp)
target_include_directories(ffn PUBLIC include)
target_link_libraries(ffn PUBLIC Eigen3::Eigen)

add_executable(xor_demo examples/xor_demo.cpp)
target_link_libraries(xor_demo PRIVATE ffn)

enable_testing()
add_executable(test_nn tests/test_nn.cpp)
target_link_libraries(test_nn PRIVATE ffn)
target_include_directories(test_nn PRIVATE /opt/homebrew/include/doctest)
add_test(NAME nn_tests COMMAND test_nn)


