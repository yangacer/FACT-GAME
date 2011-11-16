#ifndef _CANIMATION_H_ 
#define _CANIMATION_H_ 
#include "SDL/SDL.h"

namespace AsWind {

class CAnimation { 
  
    public: 
        unsigned int    MaxFrames; 
        bool    Oscillate; 
  
    public: 
        
        CAnimation(); 
        void OnAnimate(); 
  
    public: 

        void SetFrameRate(int Rate); 
        void SetCurrentFrame(unsigned int Frame); 
        unsigned int GetCurrentFrame(); 
    
    private: 
        unsigned int    CurrentFrame; 
        int     FrameInc; 
        unsigned int     FrameRate; //Milliseconds 
        unsigned long    OldTime; 
}; 

} // namespace AsWind

#endif 

