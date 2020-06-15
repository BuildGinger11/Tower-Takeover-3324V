#pragma once
#include "api.h"

void armm(int power);
void armstuff();
void armreset();
void arm_pid(void*); 
extern pros::Task arm_pid_task;
