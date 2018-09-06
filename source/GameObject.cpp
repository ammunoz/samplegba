#include "GameObject.h"

template <typename T> T CLAMP(const T& value, const T& low, const T& high) 
{
  return value < low ? low : (value > high ? high : value); 
}

GameObject::GameObject()
: Object()
, px_(0)
, py_(0)
, rendering_component_(id_)
, size_(0)
, max_size_(0)
, min_size_(0)
, growth_direction_(0)
{
}

GameObject::GameObject(int px, int py, int size)
: Object()
, px_(px)
, py_(py)
, rendering_component_(id_)
, size_(size)
, max_size_(size * 2)
, min_size_(size / 2)
, growth_direction_(-1)
{
}

void GameObject::Render(vu16* buffer) const
{
  rendering_component_.Render(px_, py_, size_, buffer);
}

void GameObject::Update()
{
  size_ = CLAMP(size_ + growth_direction_, min_size_, max_size_);
  if (size_ >= max_size_ || size_ <= min_size_)
  {
    growth_direction_ *= -1;
  }
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
