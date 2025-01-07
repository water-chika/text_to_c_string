cmake_minimum_required(VERSION 3.20)

project(text_to_c_string)

add_executable(text_to_c_string
    main.cpp)

target_compile_features(text_to_c_string PUBLIC cxx_std_23)