#include "main.h"
pros::Controller master(CONTROLLER_MASTER);

pros::Motor left_back(14, true);
pros::Motor left_front(13, true);
pros::Motor right_back(12);
pros::Motor right_front(11);

float wheel_size = 2.75; //2.75
float tick_per_rev = 360 * (7/3); //360
float circumference = wheel_size*M_PI;
float tick_per_inch = (tick_per_rev/circumference);

bool checkshift()
{
  return master.get_digital(DIGITAL_R2);
}
int RightEncoderval ()
{
  int RightAvrage = (right_front.get_position() + right_back.get_position()) / 2;
  return RightAvrage;

}
int LeftEncoderval ()
{
  int RightAvrage = (left_front.get_position() + left_back.get_position()) / 2;
  return RightAvrage;

}
void drive(int r, int l)
{
  right_front.move(r);
  right_back.move(r);
  left_back.move(l);
  left_front.move(l);

}


int Right_Target_Value;
int Left_Target_Value;

void
Drive_pid(void*)
 {
   int Re;
   int Le;
   int Rightmotorval;
   int Leftmotorval;
   float Kp = 0.35;
  while (true)
   {
     Le = Right_Target_Value - LeftEncoderval();
     Re = Left_Target_Value - RightEncoderval();
     Rightmotorval = Kp * Re;
     Leftmotorval = Kp * Le;
     drive(Rightmotorval, Leftmotorval);
    //pid goes here
    pros::delay(10);
  }
}
pros::Task LeftDrive_pid_task(Drive_pid, nullptr, "drive_pid");

void
wait_drive() {
  pros::delay(20);
  int i = 0;
  while (true) {
    pros::delay(20);
    if (abs(Left_Target_Value-LeftEncoderval())<40 && abs(Right_Target_Value-RightEncoderval())<40) {
      return;
    }
    if (abs(Left_Target_Value-LeftEncoderval())<150 && abs(Right_Target_Value-RightEncoderval())<150) {
      i++;
      if (i>1000/20)
      {
        return;
      }
    }
    else
    {
      i = 0;
    }
  }

}
void Set_Drive(int Target)
{
  Left_Target_Value = LeftEncoderval()  + (Target*tick_per_inch);
  Right_Target_Value = RightEncoderval() + (Target*tick_per_inch);
}
