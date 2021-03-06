#include "main.h"
//R1+shift = outake
//Y = slow intake
//shift+Y = slow outake

pros::Motor right_intake(18, true);
pros::Motor left_intake(11);

void intake(int power)
{
  left_intake.move(power);
  right_intake.move(power);
}


void intakestuff()
{
  if (master.get_digital(DIGITAL_L2))
  {
    intake(127);
  }
  else if (master.get_digital(DIGITAL_L1))
  {
    intake(-127);
  }
  else
  {
    intake(0);
  }

}