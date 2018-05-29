#include "GameObject.h"

GameObject::GameObject()
: Object()
, px_(0)
, py_(0)
, size_(0)
{
}

GameObject::GameObject(int px, int py, int size)
: Object()
, px_(px)
, py_(py)
, size_(size)
{
}

void GameObject::Render() const
{
  rendering_component_.Render(px_, py_, size_);
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
