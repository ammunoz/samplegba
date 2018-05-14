#include "CommonInclude.h"
#include "RenderingSystem.h"

enum Colour;

int main()
{
  RenderingSystem rendering_system;

  int cx = (240 / 2) - 1;
  int cy = (160 / 2) - 1;
  rendering_system.DrawCircle(cx, cy, 30, Colour::RED);
  rendering_system.DrawCircle(cx, cy, 20, Colour::GREEN);
  rendering_system.DrawCircle(cx, cy, 10, Colour::BLUE);

  // Main Loop
  while(true){}
}
