// Copyright 2021 Hiram Silvey

#ifndef PC_CONTROLLER_H_
#define PC_CONTROLLER_H_

#include <memory>
#include <unordered_map>
#include <vector>

#include "controller.h"
#include "hall_joystick.h"
#include "mcu.h"

class PCController: public Controller {
public:
  PCController(std::unique_ptr<MCU> mcu);
  static bool Active();
  void Loop() override;

private:
  struct PCButtonPinMapping : Controller::ButtonPinMapping {
    std::vector<Controller::AnalogButton> z_y;
    std::vector<Controller::AnalogButton> z_x;
    std::vector<Controller::AnalogButton> slider_left;
    std::vector<Controller::AnalogButton> slider_right;
    std::vector<int> hat_up;
    std::vector<int> hat_down;
    std::vector<int> hat_left;
    std::vector<int> hat_right;
  };

  PCButtonPinMapping GetButtonPinMapping(const hs_profile_Profile_Layer& layer);
  void LoadProfile() override;
  int GetDPadAngle(const PCButtonPinMapping& mapping);
  void UpdateButtons(const PCButtonPinMapping& mapping);

  std::unique_ptr<MCU> mcu_;
  std::unique_ptr<HallJoystick> joystick_;
  PCButtonPinMapping base_mapping_;
  PCButtonPinMapping mod_mapping_;
};

#endif  // PC_CONTROLLER_H_
