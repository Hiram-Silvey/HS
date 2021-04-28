// Copyright 2021 Hiram Silvey

#include "hall_joystick.h"

#include <Tlv493d.h>

void HallJoystick::Init() {
  sensor_.begin();
}

int HallJoystick::GetX() {
  // TODO(hiram): implement
  return output_bounds_.neutral;
}

int HallJoystick::GetY() {
  // TODO(hiram): implement
  return output_bounds_.neutral;
}
