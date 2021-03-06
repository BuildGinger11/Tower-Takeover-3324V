#include "main.h"
#include "api.h"
//B = tray in
//down arrow = tray out
//down = 1165
//middle = 2375
//up = 3842
pros::Motor Index(3, true);
pros::Motor lift(17);
pros::Distance BallIn(11);
//pros::Distance BallOut(15);
//pros::ADIDigitalIn Stopper(2);
//pros::ADIDigitalIn Hoodstopper(1);
//pros::IntakeCheak(2);
/*
int BallsInRobot = 1;
void
ballsinRobotvoid (void*)
{
  while(true)
  {
    if(BallIn.get() <= 70)
    {
      BallsInRobot++;
      while(BallIn.get() < 100)
      {
        pros::delay(10);
      }
    }
    if(BallOut.get() <= 70 && BallOut.get() != 0)
    {
      BallsInRobot--;
      while(BallOut.get() < 100)
      {
        pros::delay(10);
      }
    }
    printf("%d \n", BallsInRobot);
  }
}
pros::Task BallsinRobotTask(ballsinRobotvoid, nullptr, "BIR");
int BallsInRobotint()
{
  return BallsInRobot;
}*/
void EnReset()
{
  Index.set_zero_position(0);
  lift.set_zero_position(0);
}
void Lift(int power)
{
  lift.move(power);
  Index.move(power);
}
void ALift (int toppower, int bottompower)
{
  lift.move(bottompower);
  Index.move(toppower);
}
//void EnLift(int power, int encoder)
//{
//  EnReset();
//  if(lift.get_position() < encoder)
//  {
//    lift.move(power);
//    Index.move(power);

//  }
//}
/*
int i = 0;
bool LPressed = false;
void bringdown ()
{
  while(!Stopper.get_value())
    {
      if(master.get_digital(DIGITAL_R2))
      {
        break;
      }
      Lift(-127);
      if(i*10 >= 300)
      {
        i = 0;
        break;
      }
      i++;
      pros::delay(20);
    }
}*/
void Deploy()
{
  intake(127);
  Lift(127);
  pros::delay(300);
  ALift(127, 0);
  pros::delay(500);
  Lift(0);
  intake(0);
}

void liftstuff()
{
  //printf("Limit Switch: %d \n", AutoIndexer.get_value());
  if(master.get_digital(DIGITAL_L1) && master.get_digital(DIGITAL_L2))
  {
    Lift(-127);
  }
  else if(master.get_digital(DIGITAL_R1))
  {
    Lift(127);
  }
  else if(master.get_digital(DIGITAL_R1))
  {
    ALift(-127, 127);
  }

  else
  {
    Lift(0);
  }
}
