#ifndef _SURFACE_HPP
#define _SURFACE_HPP

#include "SDL/SDL.h"

namespace AsWind {

/** @brief Wrapper of SDL's surface drawing methods
 *  @detail SDL 可以將一個 surface 上的圖形繪製到另
 *  一個 surface，並且可以在來源 surface 上指定一個
 *  矩形 (使用 left, top, width, height) ，只將該矩
 *  形涵蓋的範圍繪製到目的 surface 上。
 */
class CSurface 
{ 
public: 
  
  /** @brief Load bitmap as a surface
   *  @detail Load bitmap as a surface and 
   *  transform the surface into current 
   *  display formation.
   */
  static SDL_Surface* 
  OnLoad(char* File); 
 
  static bool
  Transparent(SDL_Surface* Dest, Uint32 Color);
  
  static Uint32 
  map_rgb(SDL_Surface* Surf,
    Uint8 Red, Uint8 Green, Uint8 Blue);

  /** @brief Wrapper of SDL's drawing method
   *  @param Surf_Dest Destination.
   *  @param Surf_Src Source.
   *  @param X 要畫到 Surf_Dest 的位置 (x 軸)
   *  @param Y 要畫到 Surf_Dest 的位置 (y 軸)
   *  @return Success/Failure
   */
  static bool 
  OnDraw(
    SDL_Surface* Surf_Dest, SDL_Surface* Surf_Src, 
    int X, int Y); 
  
  /** @brief Extended drawing method.
   *  @param Surf_Dest
   *  @param Surf_Src
   *  @param X 要畫到 Surf_Dest 的位置 (x 軸)
   *  @param Y 要畫到 Surf_Dest 的位置 (y 軸)
   *  @param X2 要從 Surf_Src 擷取的位置 (x 軸)
   *  @param Y2 要從 Surf_Src 擷取的位置 (x 軸)
   *  @param X2 要從 Surf_Src 擷取的寬度
   *  @param Y2 要從 Surf_Src 擷取的高度
   *  @return Sunccess/Failure
   */
  static bool 
  OnDraw(
    SDL_Surface* Surf_Dest, 
    SDL_Surface* Surf_Src, 
    int X, int Y, int X2, int Y2, 
    int W, int H ); 

}; 

} // namespace AsWind

#endif
