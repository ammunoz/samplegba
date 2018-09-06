#pragma once

#include "Object.h"
#include "RenderingComponent.h"

class GameObject : public Object
{
public:
  GameObject();
  GameObject(int px, int py, int size = 0);
  virtual void Render(vu16* buffer) const;
  virtual void Update() override;

  void SetPosition(int px, int py);
  void SetSize(int size);

  // TODO: Template
  RenderingComponent& GetRenderingComponent();

protected:
  int px_;
  int py_;
  int size_;
  int max_size_;
  int min_size_;
  int growth_direction_;
  RenderingComponent rendering_component_;
};
