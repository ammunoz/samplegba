#pragma once

#include "Object.h"
#include "RenderingComponent.h"

class GameObject : public Object
{
public:
  GameObject();
  GameObject(int px, int py, int size = 0);
  virtual void Render() const;
  virtual void Update() override {}

  void SetPosition(int px, int py);
  void SetSize(int size);

  // TODO: Template
  RenderingComponent& GetRenderingComponent();

protected:
  int px_;
  int py_;
  int size_;
  RenderingComponent rendering_component_;
};
