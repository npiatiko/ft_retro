cmake_minimum_required(VERSION 3.14)
project(ft_retro)
set(CMAKE_CXX_STANDARD 98)

set(CMAKE_CXX_COMPILER clang++)
set(CMAKE_CXX_FLAGS "-Wall -Wextra -Werror")
AUX_SOURCE_DIRECTORY(./ SRC_LIST)

add_executable(${PROJECT_NAME} ${SRC_LIST})
target_link_libraries(${PROJECT_NAME} ncurses)