cmake_minimum_required(VERSION 2.8)
project( FACT-GAME )

list (APPEND CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake_mod)
include (GetGitRevisionDescription)
include (use_c++11)
include (disable_useless_vc_warning)

find_package( SDL REQUIRED )
find_package( SDL_image REQUIRED )
find_package( Boost REQUIRED COMPONENTS system )

include_directories(${Boost_INCLUDE_DIRS})

include_directories ( ${SDL_INCLUDE_DIR} ${SDLIMAGE_ICLUDE_DIR} )
set( LIBS ${SDL_LIBRARY} ${SDLIMAGE_LIBRARY} ${Boost_LIBRARIES} )

add_executable ( main main.cpp )
target_link_libraries ( main ${LIBS} )
