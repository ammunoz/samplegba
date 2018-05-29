#include "RenderingSystem.h"

RenderingSystem::RenderingSystem()
{
  SetMode(LCDC_BITS::MODE_3 | LCDC_BITS::BG2_ENABLE);
}

void RenderingSystem::Render(std::vector<GameObject*> game_objects) const
{
  // rendering_component_.ClearScreen();
  for(auto game_object : game_objects)
  {
    game_object->Render();
  }
}

