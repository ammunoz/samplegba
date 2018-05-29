#include "RenderingSystem.h"

RenderingSystem::RenderingSystem()
  : current_buffer_((vu16*)MODE5_FB)
  , screen_clearer_()
{
  SetMode(LCDC_BITS::MODE_4 | LCDC_BITS::BG2_ENABLE);
}

void RenderingSystem::Render(std::vector<GameObject*> game_objects)
{
  // Clear appropriate buffer
  screen_clearer_.GetRenderingComponent().ClearScreen(current_buffer_);

  // Draw to buffer
  for(auto game_object : game_objects)
  {
    game_object->Render(current_buffer_);
  }

  // Display
  FlipBuffers();
}

void RenderingSystem::FlipBuffers()
{
  // Swap buffers
  if(current_buffer_ == (vu16*)MODE5_FB)
  {
    REG_DISPCNT &= ~LCDC_BITS::BACKBUFFER;
    current_buffer_ = (vu16*)MODE5_BB;
  }
  else
  {
    REG_DISPCNT |= LCDC_BITS::BACKBUFFER;
    current_buffer_ = (vu16*)MODE5_FB;
  }
}

