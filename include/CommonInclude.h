#pragma once

#include <gba_video.h>

#define Screen (vu16*)0x6000000

enum Colour
{
  BLACK = RGB5( 0,  0,  0),
  BLUE  = RGB5( 0,  0, 31),
  GREEN = RGB5( 0, 31,  0),
  RED   = RGB5(31,  0,  0),
  WHITE = RGB5(31, 31, 31)
};
