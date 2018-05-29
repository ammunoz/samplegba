#pragma once

#include "CommonInclude.h"

class RenderingSystem;

class RenderingComponent
{
  friend class GameObject;

public:
  RenderingComponent();
  void ClearScreen(int colour = Colour::BLACK, vu16* screen = Screen) const;
  void SetColour( Colour colour );

private:
  void Render(int cx, int cy, int size, vu16* screen = Screen) const;
  void Update();

  inline void ColourPixel(int px, int py, int colour, vu16* screen = Screen) const;

  Colour colour_;
};
