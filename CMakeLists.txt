cmake_minimum_required(VERSION 2.8)
project( FACT-GAME )

# 預設 SDL 及 Boost 相關的 headers, libs 都放在 d:/contrib 下
# 請自行修改至正確目錄
include_directories( d:/contrib/include )
link_directories ( d:/contrib/lib )

add_executable ( 
  main main.cpp 
  core.cpp 
  surface.cpp 
  event.cpp 
  animate.cpp
  entity.cpp
  )

target_link_libraries ( main SDL SDLmain SDL_image)
