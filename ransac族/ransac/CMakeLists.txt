cmake_minimum_required(VERSION 3.14)
#project(プロジェクト名 CXX)
project(plt)
 
# # Default to C99
# if(NOT CMAKE_C_STANDARD)
#   set(CMAKE_C_STANDARD 99)
# endif()

# # Default to C++14
# if(NOT CMAKE_CXX_STANDARD)
#   set(CMAKE_CXX_STANDARD 14)
# endif()

set(CMAKE_CXX_STANDARD 11)
#  # Find the Python 3.10 package
# find_package(Python3 REQUIRED COMPONENTS Development)
# include_directories(${Python3_INCLUDE_DIRS})

# if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
#   add_compile_options(-Wall -Wextra -Wpedantic)
# endif()

# Include Python headers
add_executable(
  plt main.cpp
)
# target_link_libraries(plt ${Python3_LIBRARIES})
 
# matplotlibcppで使うPythonとNumpyを探す
find_package(Python3 COMPONENTS Development NumPy)
#target_include_directories(実行ファイル名 PRIVATE ${Python_INCLUDE_DIRS} ${Python_NumPy_INCLUDE_DIRS})
target_include_directories(plt PRIVATE ${Python3_INCLUDE_DIRS} ${Python3_NumPy_INCLUDE_DIRS})
#target_link_libraries(実行ファイル名 Python::Python Python::NumPy)
target_link_libraries(plt Python3::Python Python3::NumPy)