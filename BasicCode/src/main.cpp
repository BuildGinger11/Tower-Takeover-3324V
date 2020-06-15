#include "main.h"

// R2 = shift
//R1 = intake
//R1+shift = outake
//Y = slow intake
//shift+Y = slow outake
//L1 = arm up
//L2 = arm down
//L1+shift = descore
//L2+shift = descore
//Right arrow = arm down, tray back
//B = tray in
//down arrow = tray out
void initialize()
{
  pros::delay(500);
  tray_pid_task.suspend();
  arm_pid_task.suspend();
  armreset();
  pros::lcd::initialize();
  pros::lcd::set_text(1, "Hello PROS User!");

}

void disabled() {}
void competition_initialize() {}

void autonomous() {}




void opcontrol()
{

  while (true)
  {
    drive(master.get_analog(ANALOG_RIGHT_Y), master.get_analog(ANALOG_LEFT_Y));
    traystuff();
    intakestuff();
    armstuff();
    pros::delay(10);
  }
}
