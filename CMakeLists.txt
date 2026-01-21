cmake_minimum_required(VERSION 3.23)

project(json_yaml_converter)

add_executable(json_yaml_converter)

target_sources(json_yaml_converter
    PRIVATE
        src/main.cpp
)