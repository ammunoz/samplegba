#pragma once

#include <gba_video.h>

#include "CommonInclude.h"

class RenderingComponent
{
  friend class GameObject;
private:
  void Render() const;
  void Update();
};
