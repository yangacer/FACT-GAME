#ifndef _SURFACE_HPP
#define _SURFACE_HPP

#include "SDL/SDL.h"

namespace AsWind {

/** @brief Wrapper of SDL's surface drawing methods
 *  @detail SDL �i�H�N�@�� surface �W���ϧ�ø�s��t
 *  �@�� surface�A�åB�i�H�b�ӷ� surface �W���w�@��
 *  �x�� (�ϥ� left, top, width, height) �A�u�N�ӯx
 *  �β[�\���d��ø�s��ت� surface �W�C
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
   *  @param X �n�e�� Surf_Dest ����m (x �b)
   *  @param Y �n�e�� Surf_Dest ����m (y �b)
   *  @return Success/Failure
   */
  static bool 
  OnDraw(
    SDL_Surface* Surf_Dest, SDL_Surface* Surf_Src, 
    int X, int Y); 
  
  /** @brief Extended drawing method.
   *  @param Surf_Dest
   *  @param Surf_Src
   *  @param X �n�e�� Surf_Dest ����m (x �b)
   *  @param Y �n�e�� Surf_Dest ����m (y �b)
   *  @param X2 �n�q Surf_Src �^������m (x �b)
   *  @param Y2 �n�q Surf_Src �^������m (x �b)
   *  @param X2 �n�q Surf_Src �^�����e��
   *  @param Y2 �n�q Surf_Src �^��������
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
