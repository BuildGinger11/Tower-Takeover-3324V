#include "main.h"
pros::Controller master(CONTROLLER_MASTER);

pros::Motor left_back(19, true);
pros::Motor left_front(18, true);
pros::Motor right_back(20);
pros::Motor right_front(17);

bool checkshift()
{
  return master.get_digital(DIGITAL_R2);
}

void drive(int r, int l)
{
  left_back.move(l);
  left_front.move(l);
  right_front.move(r);
  right_back.move(r); 
}
