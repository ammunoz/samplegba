#pragma once

#include "Object.h"
#include "RenderingComponent.h"

class GameObject : public Object
{
public:
  GameObject();
  virtual void Render() const;
  virtual void Update() override{}

protected:
  RenderingComponent rendering_component_;
};
