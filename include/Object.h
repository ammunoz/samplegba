#pragma once

#include "RenderingComponent.h"

class Object
{
protected:
  int id_;

public:
  Object();
  int id() const;
  virtual void Update() = 0;
};
