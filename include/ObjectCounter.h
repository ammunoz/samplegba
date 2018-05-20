#pragma once

class ObjectCounter {
public:
  static ObjectCounter* get_instance(); // Returns a pointer to the current instance of ObjectCounter
  int assign_id() const; // Returns the next available object id
  void reset_counter() const; // Resets counter
  ~ObjectCounter();

private:
  static int id_;
  static bool instance_flag_;
  static ObjectCounter* counter_;
  ObjectCounter(){}
};
