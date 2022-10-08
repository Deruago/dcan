cmake_minimum_required(VERSION 3.16)

project(dcan_LanguageProject
                      DESCRIPTION "Project for the language(s): dcan"
                      LANGUAGES CXX)

option(dcan_ENABLE_COMPILER_GENERATOR "Enable Compiler Generation" OFF)
if (dcan_ENABLE_COMPILER_GENERATOR)
	find_package(Deamer REQUIRED)
	add_subdirectory(CompilerGenerator)
endif()

option(dcan_ENABLE_LANGUAGE_BUILD "Enable Language CMake Build." ON)
if (dcan_ENABLE_LANGUAGE_BUILD)
	add_subdirectory(dcan)

endif()
