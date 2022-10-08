cmake_minimum_required(VERSION 3.16)

project(dcan_CompilerGenerator
                      DESCRIPTION "Compiler/Ecosystem generator for language(s): dcan. This CompilerGenerator project uses Deamer CC for the generation, and DLDL to generate the definitions."
                      LANGUAGES CXX)

find_package(Deamer REQUIRED)

file(GLOB_RECURSE SOURCE_LIST "${dcan_CompilerGenerator_SOURCE_DIR}/lib/*.cpp")

add_library(dcan_CompilerGenerator_implementation_detail STATIC)
target_sources(dcan_CompilerGenerator_implementation_detail PRIVATE ${SOURCE_LIST})

target_include_directories(dcan_CompilerGenerator_implementation_detail PUBLIC "${dcan_CompilerGenerator_SOURCE_DIR}/include")
target_link_libraries(dcan_CompilerGenerator_implementation_detail PUBLIC Deamer::Deamer)
target_compile_features(dcan_CompilerGenerator_implementation_detail PUBLIC cxx_std_17)
set_target_properties(dcan_CompilerGenerator_implementation_detail PROPERTIES LINKER_LANGUAGE CXX)

add_executable(dcan_CompilerGenerator_Main)
target_sources(dcan_CompilerGenerator_Main PRIVATE "${dcan_CompilerGenerator_SOURCE_DIR}/main.cpp")
target_link_libraries(dcan_CompilerGenerator_Main PRIVATE dcan_CompilerGenerator_implementation_detail)
