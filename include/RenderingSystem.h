#pragma once

#include <vector>

#include "CommonInclude.h"
#include "GameObject.h"
#include "RenderingComponent.h"

class RenderingSystem
{
public:
  RenderingSystem();
  void Render(std::vector<GameObject*> game_objects) const;

private:
  RenderingComponent rendering_component_;
};
