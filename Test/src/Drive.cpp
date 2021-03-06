#include "main.h"
<<<<<<< Updated upstream
pros::Motor left_back(14, true);
pros::Motor left_front(13, true);
pros::Motor right_back(12);
pros::Motor right_front(11);
/**
 * A callback function for LLEMU's center button.
 *
 * When this callback is fired, it will toggle line 2 of the LCD text between
 * "I was pressed!" and nothing.
 */
void on_center_button() {
	static bool pressed = false;
	pressed = !pressed;
	if (pressed) {
		pros::lcd::set_text(2, "I was pressed!");
	} else {
		pros::lcd::clear_line(2);
	}
}

/**
 * Runs initialization code. This occurs as soon as the program is started.
 *
 * All other competition modes are blocked by initialize; it is recommended
 * to keep execution time for this mode under a few seconds.
 */
void initialize() {
	pros::lcd::initialize();
	pros::lcd::set_text(1, "Hello PROS User!");

	pros::lcd::register_btn1_cb(on_center_button);
}

/**
 * Runs while the robot is in the disabled state of Field Management System or
 * the VEX Competition Switch, following either autonomous or opcontrol. When
 * the robot is enabled, this task will exit.
 */
void disabled() {}

/**
 * Runs after initialize(), and before autonomous when connected to the Field
 * Management System or the VEX Competition Switch. This is intended for
 * competition-specific initialization routines, such as an autonomous selector
 * on the LCD.
 *
 * This task will exit when the robot is enabled and autonomous or opcontrol
 * starts.
 */
void competition_initialize() {}

/**
 * Runs the user autonomous code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the autonomous
 * mode. Alternatively, this function may be called in initialize or opcontrol
 * for non-competition testing purposes.
 *
 * If the robot is disabled or communications is lost, the autonomous task
 * will be stopped. Re-enabling the robot will restart the task, not re-start it
 * from where it left off.
 */
 void drive(int r, int l)
 {
   right_front.move(r);
   right_back.move(r);
   left_back.move(l);
   left_front.move(l);

 }
void autonomous()
{
	drive(127, 127);
	pros::delay(20);

}

/**
 * Runs the operator control code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the operator
 * control mode.
 *
 * If no competition control is connected, this function will run immediately
 * following initialize().
 *
 * If the robot is disabled or communications is lost, the
 * operator control task will be stopped. Re-enabling the robot will restart the
 * task, not resume it from where it left off.
 */
void opcontrol() {
	pros::Controller master(pros::E_CONTROLLER_MASTER);
	pros::Motor left_mtr(1);
	pros::Motor right_mtr(2);

	while (true) {
		pros::lcd::print(0, "%d %d %d", (pros::lcd::read_buttons() & LCD_BTN_LEFT) >> 2,
		                 (pros::lcd::read_buttons() & LCD_BTN_CENTER) >> 1,
		                 (pros::lcd::read_buttons() & LCD_BTN_RIGHT) >> 0);
		int left = master.get_analog(ANALOG_LEFT_Y);
		int right = master.get_analog(ANALOG_RIGHT_Y);

		left_mtr = left;
		right_mtr = right;
		pros::delay(20);
	}
=======
pros::Controller master(CONTROLLER_MASTER);

pros::Motor left_back(7, true);
pros::Motor left_front(8, true);
pros::Motor right_back(9);
pros::Motor right_front(10);
pros::Imu Inersial(12);
pros::ADILineSensor RightLineSensor(3);
pros::ADILineSensor LeftLineSensor(1);

float wheel_size = 3.25; //2.75
float tick_per_rev = 360 * (7/3); //360
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
float InersialReadings ()
{
  return Inersial.get_rotation();
}
void ResetInersial ()
{
  Inersial.reset();
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
 float Kp = 0.2; //0.035  //THIS IS DRIVE KP
 //THE ABOVE IS NOT TURN KP




 float Ki = 0.2;//0.001 0.2
 float Kd = 30.0;//40.0 20.0
  float start_i = 10;
//_____________________________________________________________________________________________________________________________________________________
void
Drive_pid(void*)
 {
   float Re;
   float Le;
   float Angle_error;
   int Rightmotorval;
   int Leftmotorval;
   int GOutput;
   float HeadingKp = 12;
   float Gyro_Kp = 4.4;//1.05
   float integral;
   float derivitive;
   float prev_error;
   int Rprev_line;
   int Rline_error;
   int Lprev_line;
   int Lline_error;
   int ROutput;
   int LOutput;

  while (true)
   {
     Angle_error = angle - InersialReadings();
     Le = Left_Target_Value - LeftEncoderval();
     Re = Right_Target_Value - RightEncoderval();
      // printf("Angle_error: %d \n", Angle_error);
     if(fabs(Angle_error) < start_i)
        integral = integral + Angle_error;
     else
       integral = 0;
     derivitive = Angle_error - prev_error;
     prev_error = Angle_error;
     Rline_error = RightLineSensor.get_value() - Rprev_line;
     Lline_error = RightLineSensor.get_value() - Lprev_line;
     Rprev_line = RightLineSensor.get_value();
     Lprev_line = LeftLineSensor.get_value();
     Rightmotorval = Kp * Re;
     Leftmotorval = Kp * Le;
     if(currentdrivetype == Drive)
       GOutput = Angle_error * HeadingKp;
     else if(currentdrivetype == Line)
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
     else if(currentdrivetype == Turn || currentdrivetype == RSwing || currentdrivetype == LSwing)
       GOutput = Angle_error * Gyro_Kp;
      // printf("Angle_error: %d \n", Angle_error);
      Rightmotorval = clipit(maxval, minval, Rightmotorval);
      Leftmotorval = clipit(maxval, minval, Leftmotorval);
     //printf("Rightmotorval = %d \n", Rightmotorval);
    // printf("Angle_P = %d and InersialReadings = %d \n", Angle_P, InersialReadings());
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
          /*printf("DRIVE: %d \n",Rightmotorval);
          printf("Error = %d \n", Re);
          printf("Encoder Readings: %d \n", RightEncoderval());
          printf("Ticks Per Inch = %f \n", tick_per_inch);*/

          drive(Rightmotorval - GOutput, Leftmotorval + GOutput);
        }
        else if(currentdrivetype == Line)
        {
          drive(Rightmotorval + ROutput, Leftmotorval + LOutput);
        }
        else if(currentdrivetype == RSwing)
        {
          GOutput = clipit(maxval, minval, GOutput);
          drive(-GOutput, 0);
          //printf("power: %d \n", GOutput);
          //printf("Inersial: %d \n", InersialReadings());
        }
        else if(currentdrivetype == LSwing)
        {
          GOutput = clipit(maxval, minval, GOutput);
          drive(0, GOutput);
        }
      }
      else
      {
        //printf("millis = %d \n", pros::millis());
        //printf("Almost working \n");
        drive(0, 0);
      }

    //pid goes here
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

//_____________________________________________________________________________________________________________________________________________________
void set_angle(int Angle)
{
  angle = Angle;
}
void
Turn_pid(void*)
 {

  while (true)
   /*

     Gyro_P = angle - InersialReadings();
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
      if (fabs(angle-InersialReadings())<2) {
        pros::delay(50);
        return;
      }
      if (fabs(angle-InersialReadings())<10) {
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

>>>>>>> Stashed changes
}
