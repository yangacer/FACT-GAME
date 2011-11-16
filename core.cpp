#include "core.hpp"
#include "animate.hpp"
#include "surface.hpp"

namespace AsWind {

CApp::CApp() 
: Running(true), 
  Surf_Display(NULL), Surf_Test(NULL)
{} 

CApp::~CApp()
{

  SDL_FreeSurface(Surf_Test);
  SDL_FreeSurface(Surf_Display);
  SDL_Quit();
}

int 
CApp::OnExecute() 
{ 
    if(OnInit() == false) { 
        return -1; 
    } 
  
    SDL_Event Event; 
  
    while(Running) { 
        while(SDL_PollEvent(&Event)) { 
            OnEvent(&Event); 
        } 
  
        OnLoop(); 
        OnRender(); 
    } 
  
    return 0; 
} 
  
CAnimation yoshi;

bool 
CApp::OnInit() 
{
  
    if(SDL_Init(SDL_INIT_EVERYTHING) < 0) { 
        return false; 
    }
    if(NULL ==( Surf_Display = 
          SDL_SetVideoMode(
            640, 480, 32, 
            SDL_HWSURFACE | SDL_DOUBLEBUF)) ) 
    { 
      return false; 
    } 
    
    if( NULL == ( Surf_Test = CSurface::OnLoad("yoshi.bmp"))) {
      return false;
    }

    yoshi.MaxFrames = 8;
    yoshi.Oscillate = true;   
    return true; 
}

/*
void 
CApp::OnEvent(SDL_Event* Event) 
{ 
  if(Event->type == SDL_QUIT) { 
        Running = false; 
  } 
}
*/


void
CApp::OnRender()
{
  CSurface::OnDraw(Surf_Display, Surf_Test, 
    290, 220, 0, yoshi.GetCurrentFrame() * 64, 64, 64); 

  SDL_Flip(Surf_Display);
}



void
CApp::OnLoop()
{
  yoshi.OnAnimate();  
}

} // namespace AsWind
