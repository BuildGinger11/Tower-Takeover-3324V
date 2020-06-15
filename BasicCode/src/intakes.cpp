#include "main.h"

// R2 = shift
//R1 = intake
//R1+shift = outake
//Y = slow intake
//shift+Y = slow outake

pros::Motor right_intake(9, true);
pros::Motor left_intake(2);

void intake(int power)
{
  left_intake.move(power);
  right_intake.move(power);

}
int shiftkey()
{
  if(master.get_digital(DIGITAL_R2))
    return -1;
  return 1;
}

 
void intakestuff()
{
  if (master.get_digital(DIGITAL_R1))
  {
    intake(shiftkey()*127);
  }
  else if (master.get_digital(DIGITAL_Y))
  {
    intake(shiftkey()*50);
  }
  else
  {
    intake(0);
  }

}
