#pragma once

#include <gba_video.h>

#include "CommonInclude.h"

enum Colour
{
  BLACK = RGB5( 0,  0,  0),
  BLUE  = RGB5( 0,  0, 31),
  GREEN = RGB5( 0, 31,  0),
  RED   = RGB5(31,  0,  0),
  WHITE = RGB5(31, 31, 31)
};

class RenderingSystem
{
public:
  RenderingSystem();
  void DrawCircle(int cx, int cy, int radius, int colour, vu16* screen = Screen) const;

private:
  inline void ColourPixel(int px, int py, int colour, vu16* screen = Screen) const
  {
    screen[px + (py * SCREEN_WIDTH)] = colour;
  }

  inline void ClearScreen(int colour = Colour::BLACK, vu16* screen = Screen) const
  {
    for(int x = 0; x < SCREEN_WIDTH; ++x)
    {
      for(int y = 0; y < SCREEN_HEIGHT; ++y)
      {
        ColourPixel(x, y, colour, screen);
      }
    }
  }
};
