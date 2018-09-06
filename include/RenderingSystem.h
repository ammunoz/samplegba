#pragma once

#include <vector>

#include "CommonInclude.h"
#include "GameObject.h"

class RenderingSystem
{
public:
  RenderingSystem();
  void Render(std::vector<GameObject*>& game_objects);

private:
  void FlipBuffers();
  vu16* current_buffer_;
  GameObject screen_clearer_;
};
