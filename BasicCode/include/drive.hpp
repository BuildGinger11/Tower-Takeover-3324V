#pragma once
#include "api.h"
extern pros::Controller master;

bool checkshift();
int RightEncoderval ();
int LeftEncoderval ();
void drive(int r, int l);
void Set_Drive(int Target);
void wait_drive();
extern pros::Task Drive_pid_task;
