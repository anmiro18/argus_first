cmake_minimum_required(VERSION 3.14)

project(test_task_argus LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(OpenCV 4.2 REQUIRED)

add_executable(test_task_argus
  main.cpp
  core.h
  core.cpp
)

target_link_libraries(test_task_argus PRIVATE ${OpenCV_LIBS})
