#include "main.h"
pros::Controller master(CONTROLLER_MASTER);

pros::Motor left_back(14, true);
pros::Motor left_front(13, true);
pros::Motor right_back(15);
pros::Motor right_front(16);
pros::Imu Inertial(19);
pros::ADILineSensor RightLineSensor(3);
pros::ADILineSensor LeftLineSensor(1);

float wheel_size = 5.45; //2.75
float tick_per_rev = 900; //* (5/3); //360
float circumference = wheel_size*M_PI;
float tick_per_inch = (tick_per_rev/circumference);

void RightTurn(int degrees, int power)
{
  if(RightEncoderval() >= degrees)
  {
    drive(power, -power);
  }
}
//void LeftTurn(int degrees, int power)
//{
//  if(RightEncoderval() >= degrees)
  //{
  //  drive(power, power);
  //}
//}
int clipit(float max, float min, float input) {
  if (input > max)
    return max;
  else if (input < min)
    return min;
  return input;
}

bool checkshift()
{
  return master.get_digital(DIGITAL_R2);
}
float InertialReadings ()
{
  return Inertial.get_rotation();
}
void ResetInertial ()
{
  Inertial.reset();
  pros::delay(2000);
}
int RightEncoderval ()
{
  /*
  int RightAvrage = (right_front.get_position() + right_back.get_position()) / 2;
  return RightAvrage;
  */
  return right_back.get_position();

}
int LeftEncoderval ()
{
  /*
  int RightAvrage = (left_front.get_position() + left_back.get_position()) / 2;
  return RightAvrage;
  */
  return left_back.get_position();


}
void Inertialtest()
{
  while(true)
  {
    printf("Get Rotation: %f \n", Inertial.get_rotation());
    printf("Get Heading: %f \n", Inertial.get_heading());
  }
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
int currentdrivetype;
 int angle = 0;
 int maxval = 80;
 int minval = -80;
 //THE BELOW IS NOT TURN KP
 float Kp = 0.02; //0.035  //THIS IS DRIVE KP
 //THE ABOVE IS NOT TURN KP




 float Ki = 0.0;//0.001 0.2
 float Kd = 20.0;//40.0 20.0
  float start_i = 10;
//_____________________________________________________________________________________________________________
void
Drive_pid(void*)
 {
   float Re;
   float Le;
   float Angle_error;
   int Rightmotorval;
   int Leftmotorval;
   int GOutput;
   float HeadingKp = 9;
   float Gyro_Kp = 4.4;//1.05
   float integral;
   float derivitive;
   float Rderivitive;
   float Lderivitive;
   float prev_error;
   float Rprev_error;
   float Lprev_error;
   float incherror;
   int Rprev_line;
   int Rline_error;
   int Lprev_line;
   int Lline_error;
   int ROutput;
   int LOutput;

  while (true)
   {
     Angle_error = angle - InertialReadings();
     printf("Inertial readings: %f", InertialReadings());
     Le = Left_Target_Value - LeftEncoderval();
     Re = Right_Target_Value - RightEncoderval();
      // printf("Angle_error: %d \n", Angle_error);
      printf("error = %f \n", Re);
      printf("Encoder Value = %d \n", RightEncoderval());
      printf("Target Value = %d \n", Right_Target_Value);
     if(fabs(Angle_error) < start_i)
        integral = integral + Angle_error;
     else
       integral = 0;
       if(currentdrivetype == Drive)
       {
         Rderivitive = Re - Rprev_error;
         Rprev_error = Re;
         Lderivitive = Le - Lprev_error;
         Lprev_error = Le;
       }
       else if(currentdrivetype == Turn)
       {
         derivitive = Angle_error - prev_error;
         prev_error = Angle_error;
       }
     Rightmotorval = Kp * Re;
     Leftmotorval = Kp * Le;
     if(currentdrivetype == Drive)
       GOutput = Angle_error * HeadingKp;
     else if(currentdrivetype == Turn || currentdrivetype == RSwing || currentdrivetype == LSwing)
       GOutput = Angle_error * Gyro_Kp;
      // printf("Angle_error: %d \n", Angle_error);
      printf("Rightmotorval = %d \n", Rightmotorval);
      Rightmotorval = clipit(maxval, minval, Rightmotorval);
      Leftmotorval = clipit(maxval, minval, Leftmotorval);
     //printf("Rightmotorval = %d \n", Rightmotorval);
    // printf("Angle_P = %d and InertialReadings = %d \n", Angle_P, InertialReadings());
      if (pros::millis()>=2000)
      {
      //  printf("working \n");
        if(currentdrivetype == Turn)
        {
         GOutput = clipit(maxval, minval, GOutput);
          printf("Angle error: %f \n", Angle_error);
          drive(-((Angle_error*Gyro_Kp) + (Ki *integral) + (Kd * derivitive)), ((Angle_error*Gyro_Kp) + (Ki *integral) + (Kd * derivitive)));
        }
        else if(currentdrivetype == Drive)
        {
          drive(Rightmotorval - GOutput, Leftmotorval + GOutput);
          //drive(Rightmotorval, Leftmotorval);
          printf("Angle error: %f \n", Angle_error);
          printf("GOutput: %d \n", GOutput);
        }
        else if(currentdrivetype == Line)
        {
          drive(Rightmotorval + ROutput + (Kd * Rderivitive), Leftmotorval + LOutput + (Kd * Lderivitive));
        }
        else if(currentdrivetype == RSwing)
        {
          GOutput = clipit(maxval, minval, GOutput);
          drive(-GOutput, 0);
        }
        else if(currentdrivetype == LSwing)
        {
          GOutput = clipit(maxval, minval, GOutput);
          drive(0, GOutput);
        }
      }
      else
      {
        drive(0, 0);
      }
    pros::delay(10);
  }
}
pros::Task Drive_pid_task(Drive_pid, nullptr, "drive_pid");

void Set_Drive(int typeinput, int Target, int max, float kp)
{
  Kp = kp;
  maxval = max;
  currentdrivetype = typeinput;
  if(currentdrivetype == Drive || currentdrivetype == Line)
  {
    Left_Target_Value = LeftEncoderval()  + (Target*tick_per_inch);
    Right_Target_Value = RightEncoderval() + (Target*tick_per_inch);
  }
  else if (currentdrivetype == Turn || currentdrivetype == RSwing || currentdrivetype == LSwing){
    angle = Target;
  }
}

//___________________________________________________________________________________________________________________________
void set_angle(int Angle)
{
  angle = Angle;
}
void
Turn_pid(void*)
 {

  while (true)
   /*

     Gyro_P = angle - InertialReadings();
     GOutput = Gyro_P * Gyro_Kp;
     //Output = clipit(maxval, minval, Output);
     printf("Output = %d \n", GOutput);
     if (pros::millis()>=2000)
     {
     //  printf("working \n");
       drive(-GOutput, GOutput);
     }
     else
     {
       //printf("millis = %d \n", pros::millis());
       //printf("Almost working \n");
       drive(0, 0);
     }
    //pid goes here
    */
    pros::delay(10);
}
pros::Task Turn_pid_task(Turn_pid, nullptr, "Turn_pid");
void
wait_drive() {
  int i = 0;
  while (true) {
    if (currentdrivetype == Drive) {
      pros::delay(20);
      if (abs(Left_Target_Value-LeftEncoderval())<40 && abs(Right_Target_Value-RightEncoderval())<40) {
        pros::delay(50);
        return;
      }
      if (abs(Left_Target_Value-LeftEncoderval())<150 && abs(Right_Target_Value-RightEncoderval())<150) {
        i++;
        if (i>400/20)
        {
          pros::delay(50);
          return;
        }
      }
      else
      {
        i = 0;
      }
    }

    else if (currentdrivetype == Turn || currentdrivetype == RSwing || currentdrivetype == LSwing) {
      pros::delay(10);
      if (fabs(angle-InertialReadings())<2) {
        pros::delay(50);
        return;
      }
      if (fabs(angle-InertialReadings())<10) {
        i++;
        if (i>400/20)
        {
          pros::delay(50);
          return;
        }
      }
      else
      {
        i = 0;
      }
    }
  }

}
/*     else if(currentdrivetype == Line)
     {
       if(RightLineSensor.get_value() >= 1200)
       {
         LOutput = 20;
         ROutput = 0;
       }
       else if(LeftLineSensor.get_value() >= 500)
       {
         ROutput = 20;
         LOutput = 0;
       }
       else
       {
         ROutput = 0;
         LOutput = 0;
       }
     }
     Rline_error = RightLineSensor.get_value() - Rprev_line;
     Lline_error = RightLineSensor.get_value() - Lprev_line;
     Rprev_line = RightLineSensor.get_value();
     Lprev_line = LeftLineSensor.get_value();
     */
