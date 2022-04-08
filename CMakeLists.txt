# CMakeList.txt : Top-level CMake project file, do global configuration
# and include sub-projects here.
#
cmake_minimum_required (VERSION 3.9.4)

project ("InstructionMachine")

set(CMAKE_CXX_STANDARD 14)
#set_target_properties(TARGET InstructionMachine)

#set_property(TARGET InstructionMachine PROPERTY CXX_STANDARD 11)

add_executable (InstructionMachine "main.cpp" "Machine.cpp" "Machine.h")
target_compile_features(InstructionMachine PRIVATE cxx_std_17)
