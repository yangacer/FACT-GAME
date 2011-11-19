#include "surface.hpp"
#include "SDL/SDL_image.h"

namespace AsWind { 

SDL_Surface* CSurface::OnLoad(char* File) 
{ 
    SDL_Surface* Surf_Temp(NULL); 
    SDL_Surface* Surf_Return(NULL); 
  
    if(NULL == (Surf_Temp = IMG_Load(File))){//SDL_LoadBMP(File))) { 
        return NULL; 
    } 
    
    // transform display formation of the loaded
    // surface into current format
    Surf_Return = SDL_DisplayFormatAlpha(Surf_Temp); 

    SDL_FreeSurface(Surf_Temp); 
  
    return Surf_Return; 
} 

Uint32
CSurface::map_rgb(SDL_Surface* Surf,
    Uint8 Red, Uint8 Green, Uint8 Blue)
{
  return SDL_MapRGB(Surf->format, Red, Green, Blue);
}

bool
CSurface::Transparent(SDL_Surface* Dest, Uint32 Color)
{
  return  0 == SDL_SetColorKey(Dest, 1, Color);
}



bool CSurface::OnDraw(
  SDL_Surface* Surf_Dest, SDL_Surface* Surf_Src, 
  int X, int Y) 
{ 
    if(Surf_Dest == NULL || Surf_Src == NULL) { 
        return false; 
    } 
  
    SDL_Rect DestR; 
  
    DestR.x = X; 
    DestR.y = Y; 
  
    SDL_BlitSurface(Surf_Src, NULL, Surf_Dest, &DestR); 
  
    return true; 
}

bool 
CSurface::OnDraw(
  SDL_Surface* Surf_Dest, SDL_Surface* Surf_Src, 
  int X, int Y, int X2, int Y2, int W, int H) 
{ 
    if(Surf_Dest == NULL || Surf_Src == NULL) { 
        return false; 
    } 
  
    SDL_Rect DestR; 
  
    DestR.x = X; 
    DestR.y = Y; 
  
    SDL_Rect SrcR; 
  
    SrcR.x = X2; 
    SrcR.y = Y2; 
    SrcR.w = W; 
    SrcR.h = H; 
  
    SDL_BlitSurface(Surf_Src, &SrcR, Surf_Dest, &DestR); 
  
    return true; 
}

} // namespace AsWind
