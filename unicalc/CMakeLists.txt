cmake_minimum_required(VERSION 3.12)
project(Unicalc VERSION 0.1)

set(CMAKE_CXX_STANDARD 17)

add_executable(calculator
    src/main.cpp 
    src/core/tokenizer.cpp 
    src/core/rpn_converter.cpp 
    src/core/rpn_calculator.cpp 
    src/core/calculator.cpp 
)

target_include_directories(calculator PRIVATE include)