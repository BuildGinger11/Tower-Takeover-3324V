#include "main.h"
#include "adi.h"
//B = tray in
//down arrow = tray out
//down = 1165
//middle = 2375
//up = 3842
pros::Motor Index(1);
pros::Motor lift(2);
pros::ADILineSensor AutoIndexer(1);
//pros::IntakeCheak(2);
void Lift(int power)
{
  lift.move(power);
  Index.move(power);

}
bool Auto = false;
void liftstuff()
{/*
  if(IntakeCheak.get_value() == 1 && AutoIndexer.get_value() > 2000)
    {
      Auto = true;
    }
  else if(AutoIndexer.get_value() < 2000 && IntakeCheak.get_value() == 0)
    {
      Auto = false;
    }
  else if(IntakeCheak.get_value() == 1 && AutoIndexer.get_value() < 2000)
    {
      Auto = true;
    }
  else if(IntakeCheak.get_value() == 0 && AutoIndexer.get_value() > 2000)
    {
      Auto = false;
    }
  if(Auto == true)
    {
      Lift(127);
    }
  else if (master.get_digital(DIGITAL_R1))
   {
     //Lift(127);
   }
  else if (master.get_digital(DIGITAL_R2))
   {
     //Lift(-127);
   }
   else
   {
     Lift(0);
   }*/
   if(IntakeCheak.get_value() == 1)
   {
     pros::lcd::set_text(1, "Limit swich hit");
   }
   else if(AutoIndexer.get_value() == 2000)
   {
    pros::lcd::set_text(1, "Line sensor hit");
   }
}




























//B = tray in
//down arrow = tray out
//down = 1165
//middle = 2375
//up = 3842
/*pros::Motor tray(10, true);
pros::ADIAnalogIn traypot(8);
void traym(int power)
{

  tray.move(power);
}
int potval ()
{
  return traypot.get_value();

}

int Target_Value = 1162;
void
tray_pid(void*)
 {
   int e;
   int motorval;
   float Kp = 0.35;
  while (true)
   {
     e = Target_Value - potval();
     motorval = Kp * e;
     traym(motorval);
    //pid goes here
    pros::delay(10);
  }
}
pros::Task tray_pid_task(tray_pid, nullptr, "tray_pid");
void traystuff()
{
  if (master.get_digital(DIGITAL_DOWN))
  {
    tray_pid_task.suspend();
    Target_Value = potval();
    if(potval() <= 2375)
    {
      traym(127);
    }

    else if(potval() <= 3442)
    {
      traym(60);
    }
    else if(potval() >= 3442)
    {
      traym(30);
    }
  }
  else if (master.get_digital(DIGITAL_L2))
  {
    tray_pid_task.suspend();
    Target_Value = potval();
    traym(-127);
  }
  else
  {
    tray_pid_task.resume();
  }
} */
