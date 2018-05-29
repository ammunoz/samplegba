#include "GameObject.h"

GameObject::GameObject()
: Object()
, px_(0)
, py_(0)
, rendering_component_(id_)
, size_(0)
{
}

GameObject::GameObject(int px, int py, int size)
: Object()
, px_(px)
, py_(py)
, rendering_component_(id_)
, size_(size)
{
}

void GameObject::Render(vu16* buffer) const
{
  rendering_component_.Render(px_, py_, size_, buffer);
}

void GameObject::SetPosition(int px, int py)
{
  px_ = px;
  py_ = py;
}

void GameObject::SetSize(int size)
{
  size_ = size;
}

RenderingComponent& GameObject::GetRenderingComponent()
{
  return rendering_component_;
}
