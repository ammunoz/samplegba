#include "Object.h"
#include "ObjectCounter.h"

Object::Object()
: id_(ObjectCounter::get_instance()->assign_id())
{
}

int Object::id() const
{
  return id_;
}
