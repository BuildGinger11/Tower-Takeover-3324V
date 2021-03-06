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
void on_center_button() {
	static bool pressed = false;
	pressed = !pressed;
	if (pressed) {
		pros::lcd::set_text(2, "I was pressed!");
	} else {
		pros::lcd::clear_line(2);
	}
}
void initialize()
{
  //pros::delay(500);
//  tray_pid_task.suspend();

	Drive_pid_task.suspend();
//  armreset();
  pros::lcd::initialize();
  pros::lcd::set_text(1, "Hello PROS User!");
  pros::lcd::register_btn1_cb(on_center_button);
}

void disabled() {}
void competition_initialize() {}
void autonomous()
{
  while(true)
  {
    drive(127, 127);
    pros::delay(20);
  }

//  Drive_pid_task.resume();
//  Set_Drive(1000);
//  pros::delay(1000);
}



void opcontrol()
{

  while (true)
  {
    drive(master.get_analog(ANALOG_RIGHT_Y), master.get_analog(ANALOG_LEFT_Y));
    liftstuff();
   intakestuff();

    pros::delay(10);
  }
}
