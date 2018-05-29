#pragma once

#include "CommonInclude.h"

class RenderingSystem;

class RenderingComponent
{
  friend class GameObject;

public:
  RenderingComponent(int id_);
  void ClearScreen(vu16* buffer) const;
  void SetColour( Colour colour );

private:
  void Render(int cx, int cy, int size, vu16* buffer) const;
  void Update();

  inline void ColourPixel(int px, int py, int colour, vu16* buffer) const;

  Colour colour_;
  char colour_id_;
  int id_;
};
