#include "main.h"

pros::Motor arm(1);
void armreset()
{
  arm.set_zero_position(0);
}
void armm(int power)
{

  arm.move(power);
}
int enval ()
{
  return arm.get_position();

}
int ATarget_Value;
void
arm_pid(void*)
 {
   int e;
   int motorval;
   float Kp = 0.35;
  while (true)
   {
     e = ATarget_Value - enval();
     motorval = Kp * e;
     armm(motorval);
    //pid goes here
    pros::delay(10);
  }
}
pros::Task arm_pid_task(arm_pid, nullptr, "arm_pid");


void armstuff()
{


/*
  if (master.get_digital(DIGITAL_DOWN))
  {
    armm(127);
  }
  else if (master.get_digital(DIGITAL_B))
  {
    armm(-127);
  }
  else
  {
    armm(0);
  }
  */
  if(master.get_digital(DIGITAL_RIGHT))
  {

    arm_pid_task.resume();
    ATarget_Value = 0;

  }
  else if (master.get_digital(DIGITAL_L1))
  {
    arm_pid_task.resume();
    ATarget_Value = (checkshift() ? 350 : 400);

  }
  else if (master.get_digital(DIGITAL_L2))
  {
    arm_pid_task.resume();
    ATarget_Value = (checkshift() ? 750 : 800);
  }
  else
  {
    if (enval() <= 200)
    {
        arm_pid_task.suspend();
        armreset();
      if(master.get_digital(DIGITAL_Y) || master.get_digital(DIGITAL_R1))
      {

        armm(-45);
      }
      else
      {

        armm(-10);
      }
    }
  }
}
