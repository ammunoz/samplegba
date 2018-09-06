#include "RenderingComponent.h"

RenderingComponent::RenderingComponent(int id)
  : id_(id)
{
  SetColour(Colour::BLACK);
}

void RenderingComponent::ClearScreen(vu16* buffer) const
{
  for (int x = 0; x < SCREEN_WIDTH; ++x)
  {
    for (int y = 0; y < SCREEN_HEIGHT; ++y)
    {
        ColourPixel(x, y, colour_id_, buffer);
    }
  }
}

void RenderingComponent::SetColour(Colour colour)
{
  colour_ = colour;
  colour_id_ = id_;
  BG_PALETTE[id_] = colour_;
}

void RenderingComponent::Render(int px, int py, int size, vu16* buffer) const
{
  int x = size-1;
  int y = 0;
  int dx = 1;
  int dy = 1;
  int err = dx - (size << 1);

  while (x >= y)
  {
    ColourPixel(px + x, py + y, colour_id_, buffer);
    ColourPixel(px + x, py + y, colour_id_, buffer);
    ColourPixel(px + y, py + x, colour_id_, buffer);
    ColourPixel(px - y, py + x, colour_id_, buffer);
    ColourPixel(px - x, py + y, colour_id_, buffer);
    ColourPixel(px - x, py - y, colour_id_, buffer);
    ColourPixel(px - y, py - x, colour_id_, buffer);
    ColourPixel(px + y, py - x, colour_id_, buffer);
    ColourPixel(px + x, py - y, colour_id_, buffer);

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

void RenderingComponent::ColourPixel(int px, int py, int colour, vu16* buffer) const
{
  int offset = (px + (py * SCREEN_WIDTH)) >> 1;
  int pixel = buffer[offset];

  buffer[offset] = (py & 1) ?
    (colour_id_ << 8) | (pixel & 0x00ff) :
    (pixel & 0xff00) | colour_id_;
}
