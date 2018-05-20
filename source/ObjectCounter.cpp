#include "ObjectCounter.h"

int ObjectCounter::id_ = -1;
bool ObjectCounter::instance_flag_ = false;
ObjectCounter* ObjectCounter::counter_ = nullptr;

ObjectCounter* ObjectCounter::get_instance()
{
  if (!instance_flag_)
  {
      id_ = 0;
      instance_flag_ = true;
      counter_ = new ObjectCounter();
  }

  return counter_;
}

int ObjectCounter::assign_id() const
{
  return id_++;
}

void ObjectCounter::reset_counter() const
{
  id_ = 0;
}

ObjectCounter::~ObjectCounter()
{
  id_ = -1;
  counter_ = nullptr;
  instance_flag_ = false;
}
