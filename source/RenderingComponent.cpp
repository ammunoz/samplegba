#include "RenderingComponent.h"

RenderingComponent::RenderingComponent()
: colour_(Colour::BLACK)
{
}

void RenderingComponent::ClearScreen(int colour, vu16* screen) const
{
  for (int x = 0; x < SCREEN_WIDTH; ++x)
  {
    for (int y = 0; y < SCREEN_HEIGHT; ++y)
    {
        ColourPixel(x, y, colour, screen);
    }
  }
}

void RenderingComponent::SetColour(Colour colour)
{
  colour_ = colour;
}

void RenderingComponent::Render(int px, int py, int size, vu16* screen) const
{
  int x = size-1;
  int y = 0;
  int dx = 1;
  int dy = 1;
  int err = dx - (size << 1);

  while (x >= y)
  {
    ColourPixel(px + x, py + y, colour_, screen);
    ColourPixel(px + x, py + y, colour_, screen);
    ColourPixel(px + y, py + x, colour_, screen);
    ColourPixel(px - y, py + x, colour_, screen);
    ColourPixel(px - x, py + y, colour_, screen);
    ColourPixel(px - x, py - y, colour_, screen);
    ColourPixel(px - y, py - x, colour_, screen);
    ColourPixel(px + y, py - x, colour_, screen);
    ColourPixel(px + x, py - y, colour_, screen);

    if (err <= 0)
    {
        ++y;
        err += dy;
        dy += 2;
    }
    
    if (err > 0)
    {
      x--;
      dx += 2;
      err += dx - (size << 1);
    }
  }
}

void RenderingComponent::Update()
{
}

void RenderingComponent::ColourPixel(int px, int py, int colour, vu16* screen) const
{
  screen[px + (py * SCREEN_WIDTH)] = colour;
}
