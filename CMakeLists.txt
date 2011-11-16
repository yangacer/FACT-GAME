cmake_minimum_required(VERSION 2.8)
project( AsWind )

include_directories( d:/contrib/include )
link_directories ( d:/contrib/lib )

add_executable ( main main.cpp core.cpp surface.cpp event.cpp animate.cpp)
target_link_libraries ( main SDL SDLmain)
