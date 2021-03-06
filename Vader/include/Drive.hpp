#pragma once
#include "api.h"
extern pros::Controller master ;
const int Drive = 1;
const int Turn = 2;
const int RSwing = 3;
const int LSwing = 4;
const int Line = 5;
void drive(int r, int l);
void RightTurn(int degrees, int Power);
void LeftTurn(int degrees, int Power);
void LeftTurn(int degrees, int power);
bool checkshift();
void set_angle(int Angle);
float InersialReadings ();
void ResetInersial ();
int RightEncoderval ();
int LeftEncoderval ();
void drive(int r, int l);
void Set_Drive(int typeinput, int Target, int max, float kp);
void wait_drive();
extern pros::Task Drive_pid_task;
extern pros::Task Turn_pid_task;
