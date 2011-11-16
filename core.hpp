#ifndef _CORE_HPP
#define _CORE_HPP

#include "boost/noncopyable.hpp"
#include "SDL/SDL.h"
#include "event.hpp"

namespace AsWind {

class CApp 
: boost::noncopyable , CEvent
{ 
public: 
  CApp(); 
  ~CApp();

  int OnExecute();   

  bool OnInit(); 

  // void OnEvent(SDL_Event* Event); 

  void OnLoop(); 

  void OnRender(); 

private: 
  bool Running; 
  SDL_Surface *Surf_Display; 
  SDL_Surface *Surf_Test; 
}; 

} // namespace AsWind

#endif
