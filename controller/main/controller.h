// Copyright 2021 Hiram Silvey

#ifndef CONTROLLER_H_
#define CONTROLLER_H_

#include "profile.pb.h"

class Controller {
public:
  // Initializations to be run once before the main loop. Returns true on
  // success, false otherwise.
  virtual bool Init() = 0;

  // Main loop to be run each tick.
  virtual void Loop() = 0;

protected:
  // Fetch the specified profile given the platform.
  static hs_profile_Profile_Layout FetchProfile(hs_profile_Profile_Platform Platform);

private:
  // Load the controller profile settings based on the button held.
  virtual void LoadProfile() = 0;
};

#endif  // CONTROLLER_H_
