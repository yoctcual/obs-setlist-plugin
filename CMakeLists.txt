cmake_minimum_required(VERSION 3.10)
project(obs_setlist_plugin)

set(CMAKE_CXX_STANDARD 17)

find_package(obs REQUIRED)

add_library(obs_setlist_plugin MODULE
    setlist-plugin.cpp
    setlist-source.cpp
)

target_link_libraries(obs_setlist_plugin
    PRIVATE
    libobs::obs
)

add_subdirectory(plugins/setlist-plugin)
