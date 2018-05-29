#include "CommonInclude.h"
#include "GameObject.h"
#include "RenderingSystem.h"

#include <vector>

int main()
{
  // Construct systems
  RenderingSystem rendering_system;

  // Init game objects
  int cx = (SCREEN_WIDTH / 2) - 1;
  int cy = (SCREEN_HEIGHT / 2) - 1;

  GameObject r(cx, cy, 50);
  r.GetRenderingComponent().SetColour(Colour::RED);

  GameObject g(cx, cy, 30);
  g.GetRenderingComponent().SetColour(Colour::GREEN);

  GameObject b(cx, cy, 10);
  b.GetRenderingComponent().SetColour(Colour::BLUE);
  
  std::vector<GameObject*> game_objects = {&r, &g, &b};

  // Main Loop
  int counter = 0;
  int bsize = 10;
  while(true)
  {
    rendering_system.Render(game_objects);
    if(counter == 119)
    {
      ++bsize;
      counter = 0;
      b.SetSize(bsize);
    }
    ++counter;
  }
}
