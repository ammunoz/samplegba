#include "GameObject.h"

GameObject::GameObject()
: Object()
{
}

void GameObject::Render() const
{
  rendering_component_.Render();
}
