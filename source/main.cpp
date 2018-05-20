#include "CommonInclude.h"
#include "GameObject.h"
#include "RenderingSystem.h"

int main()
{
  RenderingSystem rendering_system;

  int cx = (SCREEN_WIDTH / 2) - 1;
  int cy = (SCREEN_HEIGHT / 2) - 1;
  rendering_system.DrawCircle(cx, cy, 30, Colour::RED);
  rendering_system.DrawCircle(cx, cy, 20, Colour::GREEN);
  rendering_system.DrawCircle(cx, cy, 10, Colour::BLUE);

  GameObject g;

  // Main Loop
  while(true){}
}
