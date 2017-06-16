cmake_minimum_required(VERSION 3.0)
project(simple_webcam_sdl2)


find_package(PkgConfig REQUIRED)
pkg_search_module(SDL2 REQUIRED sdl2 libsdl2)

set(src main.c v4l2_driver.c)
set(LD_FLAGS ${SDL2_LIBRARIES} pthread)

add_executable(simple_cam ${src})

target_include_directories(simple_cam PUBLIC ${SDL2_INCLUDE_DIRS})
target_link_libraries(simple_cam ${LD_FLAGS})
# target_compile_options(simple_cam PUBLIC -w) #omit warnings
