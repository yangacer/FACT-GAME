#include "entity.hpp"

namespace AsWind {

std::vector<CEntity*> CEntity::EntityList; 
  
CEntity::CEntity() 
: Surf_Entity(NULL), 
  X(0.0f), Y(0.0f),
  Width(0), Height(0),
  AnimState(0)
{}

  
CEntity::~CEntity() 
{} 
  
bool CEntity::OnLoad(char* File, 
  int Width, int Height, int MaxFrames) 
{ 
    if((Surf_Entity = CSurface::OnLoad(File)) == NULL) { 
        return false; 
    } 
  
    Uint32 color = 
      CSurface::map_rgb(Surf_Entity, 255, 0, 255);

    CSurface::Transparent(Surf_Entity, color); 
  
    this->Width = Width; 
    this->Height = Height; 
  
    Anim_Control.MaxFrames = MaxFrames; 
  
    return true; 
} 
  
void CEntity::OnLoop() 
{ 
    Anim_Control.OnAnimate(); 
} 
  
void CEntity::OnRender(SDL_Surface* Surf_Display) 
{ 

    if(Surf_Entity == NULL || Surf_Display == NULL) 
      return; 
  
    CSurface::OnDraw(
      Surf_Display, Surf_Entity, 
      (int)X, (int)Y, 
      AnimState * Width, 
      Anim_Control.GetCurrentFrame() * Height, 
      Width, Height); 
} 
  
void CEntity::OnCleanup() 
{ 
    if(Surf_Entity) { 
        SDL_FreeSurface(Surf_Entity); 
    } 
  
    Surf_Entity = NULL; 
} 


} // namespace AsWind
