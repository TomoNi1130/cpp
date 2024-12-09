cmake_minimum_required(VERSION 3.10)
#project(プロジェクト名 CXX)
project("plt")

set(CMAKE_CXX_STANDARD 11)

include_directories(../include)

add_executable(plt
  main.cpp 
)

find_package(Python3 COMPONENTS Development NumPy)
target_include_directories(plt PRIVATE ${Python3_INCLUDE_DIRS} ${Python3_NumPy_INCLUDE_DIRS})
target_include_directories(plt PRIVATE ${CMAKE_SOURCE_DIR}/sbb.cpp)
target_link_libraries(plt Python3::Python Python3::NumPy)