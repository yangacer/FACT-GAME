#include "animate.hpp"

namespace AsWind {

CAnimation::CAnimation() 
: CurrentFrame(0), MaxFrames(0),
  FrameInc(1), FrameRate(100), // mili-sec
  OldTime(0), Oscillate(false)
{} 
  
void CAnimation::OnAnimate() { 
    if(OldTime + FrameRate > SDL_GetTicks()) { 
        return; 
    } 
  
    OldTime = SDL_GetTicks(); 
  
    CurrentFrame += FrameInc; 
  
    if(Oscillate) { 
        if(FrameInc > 0) { 
            if(CurrentFrame >= MaxFrames - 1) { 
                FrameInc = -FrameInc; 
            } 
        }else{ 
            if(CurrentFrame <= 0) { 
                FrameInc = -FrameInc; 
            } 
        } 
    }else{ 
        if(CurrentFrame >= MaxFrames - 1) { 
            CurrentFrame = 0; 
        } 
    } 
} 
  
void CAnimation::SetFrameRate(int Rate) { 
    FrameRate = Rate; 
} 
  
void CAnimation::SetCurrentFrame(unsigned int Frame) { 
    if(Frame < 0 || Frame >= MaxFrames) return; 
  
    CurrentFrame = Frame; 
} 
  
unsigned int 
CAnimation::GetCurrentFrame() { 
    return CurrentFrame; 
} 


} // namespace AsWind
