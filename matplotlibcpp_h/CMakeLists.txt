cmake_minimum_required(VERSION 3.14)

project(plt)

set(CMAKE_CXX_STANDARD 11)
add_executable(
  plt matplotlibcpp_h.cpp
)
# target_link_libraries(plt ${Python3_LIBRARIES})
 
# matplotlibcppで使うPythonとNumpyを探す
find_package(Python3 COMPONENTS Development NumPy)
#target_include_directories(実行ファイル名 PRIVATE ${Python_INCLUDE_DIRS} ${Python_NumPy_INCLUDE_DIRS})
target_include_directories(plt PRIVATE ${Python3_INCLUDE_DIRS} ${Python3_NumPy_INCLUDE_DIRS})
#target_link_libraries(実行ファイル名 Python::Python Python::NumPy)
target_link_libraries(plt Python3::Python Python3::NumPy)