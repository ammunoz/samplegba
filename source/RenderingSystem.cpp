#include "RenderingSystem.h"

RenderingSystem::RenderingSystem()
{
  SetMode(LCDC_BITS::MODE_3 | LCDC_BITS::BG2_ENABLE);
  ClearScreen(Colour::BLACK);
}

void RenderingSystem::DrawCircle(int cx, int cy, int radius, int colour, vu16* screen) const
{
	// https://en.wikipedia.org/wiki/Midpoint_circle_algorithm
	int x = radius-1;
	int y = 0;
	int dx = 1;
	int dy = 1;
	int err = dx - (radius << 1);

	while (x >= y)
	{
		ColourPixel(cx + x, cy + y, colour, screen);
		ColourPixel(cx + x, cy + y, colour, screen);
		ColourPixel(cx + y, cy + x, colour, screen);
		ColourPixel(cx - y, cy + x, colour, screen);
		ColourPixel(cx - x, cy + y, colour, screen);
		ColourPixel(cx - x, cy - y, colour, screen);
		ColourPixel(cx - y, cy - x, colour, screen);
		ColourPixel(cx + y, cy - x, colour, screen);
		ColourPixel(cx + x, cy - y, colour, screen);

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
				err += dx - (radius << 1);
		}
	}
}
