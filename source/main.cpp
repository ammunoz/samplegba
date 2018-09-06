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

  GameObject r(cx, cy, 45);
  r.GetRenderingComponent().SetColour(Colour::RED);

  GameObject g(cx, cy, 30);
  g.GetRenderingComponent().SetColour(Colour::GREEN);

  GameObject b(cx, cy, 15);
  b.GetRenderingComponent().SetColour(Colour::BLUE);
  
  std::vector<GameObject*> game_objects = {&r, &g, &b};

  // Main Loop
  while(true)
  {
    for(auto object : game_objects)
    {
      object->Update();
    }
    rendering_system.Render(game_objects);
  }
}
