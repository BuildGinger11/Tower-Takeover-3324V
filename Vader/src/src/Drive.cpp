#include "main.h"
<<<<<<< Updated upstream

//pros::Imu Inersial(17);
// R2 = shift
//R1 = intake
//R1+shift = outake
//Y = slow intake
//shift+Y = slow outake
//L1 = arm up
//L2 = arm down
//L1+shift = descore
//L2+shift = descore
//Right arrow = arm down, tray back
//B = tray in
//down arrow = tray out
pros::Distance BallOut(15);

void on_center_button() {
	static bool pressed = false;
	pressed = !pressed;
	if (pressed) {
		pros::lcd::set_text(2, "I was pressed!");
	} else {
		pros::lcd::clear_line(2);
	}
}
void initialize()
{
  //pros::delay(500);
//  tray_pid_task.suspend();

	Drive_pid_task.suspend();
	Turn_pid_task.suspend();
	//BallsinRobotTask.suspend();
	pros::delay(500);
//  armreset();
  pros::lcd::initialize();
  pros::lcd::set_text(1, "Hello PROS User!");
  pros::lcd::register_btn1_cb(on_center_button);
	ResetInersial();

}

void disabled() {}
void competition_initialize() {


}
void SkillsAutonV3()
{
	Drive_pid_task.resume();
	Set_Drive(LSwing, 20, 80, 0.2);
	Deploy();
	wait_drive();
	intake(-127);
	ALift(-80, 80);
	Set_Drive(Drive, 33, 80, 0.2);
	pros::delay(300);
	ALift(0, 100);
	wait_drive();
	Set_Drive(Drive, -10, 80, 0.2);
	wait_drive();
	Set_Drive(Turn, -45, 80, 0.2);
	wait_drive();
	//Score first corner goal
	Set_Drive(Drive, 17, 80, 0.2);
	pros::delay(1300);
	Lift(127);
	intake(-127);
	pros::delay(750);
	ALift(0,80);
	intake(0);

	Set_Drive(Drive, -34, 80, 0.2);
	pros::delay(200);
	intake(127);
	Lift(-127);
	wait_drive();
	Set_Drive(Turn, -180, 80, 0.2);
	wait_drive();
	//Grab first ball for first side goal
	intake(-127);
	ALift(0, 127);
	Set_Drive(Drive, 17, 80, 0.2);
	wait_drive();
	Set_Drive(Turn, -90, 80, 0.2);
	wait_drive();
	//Drive to first side goal
	Set_Drive(Drive, 25, 80, 0.2);
	//Score first side goal
	pros::delay(1200);
	Lift(127);
	intake(-127);
	pros::delay(400);
	intake(0);
	pros::delay(200);
	Lift(0);
	Set_Drive(Drive, -6, 80, 0.2);
	wait_drive();
	Set_Drive(Turn, -177, 80, 0.2);
	wait_drive();
	intake(-127);
	ALift(0, 80);
	Set_Drive(Drive, 35, 80, 0.2);
	wait_drive();
	Set_Drive(Turn, -205, 80, 0.2);
	wait_drive();
	Set_Drive(Drive, 11, 80, 0.2);
	wait_drive();
	Set_Drive(Drive, -9, 80, 0.2);
	wait_drive();
	Set_Drive(Turn, -132, 80, 0.2);
	wait_drive();
	//Score Second corner goal
	Set_Drive(Drive, 15, 80, 0.2);
	pros::delay(1000);
	Lift(127);
	intake(-127);
	pros::delay(750);
	intake(0);
	Lift(0);
	Set_Drive(Drive, -39, 80, 0.2);
	pros::delay(200);
	intake(127);
	Lift(-127);
	wait_drive();
	//grab first ball for second Middle goal
	intake(-127);
	ALift(0,80);
	Set_Drive(Turn, -265, 75, 0.1);
	wait_drive();
	Set_Drive(Drive, 17, 50, 0.1);
	wait_drive();
	Set_Drive(Turn, -178, 75, 0.1);
	wait_drive();
	//score second middle goal
	Set_Drive(Drive, 30, 75, 0.1);
	intake(-127);
	pros::delay(1400);
	Lift(127);
	pros::delay(300);
	ALift(127, 0);
	pros::delay(500);
	intake(127);
	ALift(0, 127);
	Set_Drive(Drive, -16, 75, 0.2);
	wait_drive();
	Set_Drive(Turn, -135, 75, 0.1);
	wait_drive();
	//grab first ball for third corner goal
	intake(127);
	Lift(-127);
	pros::delay(600);
	Set_Drive(Turn, -265, 60, 0.1);
	wait_drive();
	intake(-127);
	ALift(0, 127);
	Set_Drive(Drive, 37, 75, 0.1);
	wait_drive();
	intake(0);
	Lift(0);
	Set_Drive(RSwing, -215, 75, 0.1);
	wait_drive();
	//drive to third corner goal
	Set_Drive(Drive, 28, 75, 0.2);
	//score third corner goal
	pros::delay(1200);
	Lift(127);
	pros::delay(700);
	ALift(0, 127);
	intake(-127);
	pros::delay(600);
	Lift(0);
	Set_Drive(Drive, -38, 60, 0.2);
	pros::delay(100);
	ALift(0, -127);
	intake(127);
	pros::delay(900);
	ALift(0, 127);
	intake(-127);
	wait_drive();
	//grab ball for third middle goal
	Set_Drive(Turn, -360, 75, 0.1);
	wait_drive();
	intake(-127);
	ALift(0, 127);
	Set_Drive(Drive, 14, 50, 0.1);
	wait_drive();
	Set_Drive(Turn, -267, 80, 0.2);
	wait_drive();
	Set_Drive(Drive, 26, 80, 0.2);
	//score third middle goal
	pros::delay(900);
	intake(-127);
	Lift(127);
	pros::delay(700);
	intake(127);
	Lift(0);
	Set_Drive(Drive, -6, 80, 0.2);
	wait_drive();
	//outake blue ball
	Set_Drive(Turn, -225, 80, 0.2);
	pros::delay(300);
	intake(127);
	Lift(-127);
	wait_drive();
	pros::delay(500);
	intake(127);
	Lift(0);
	//grab first ball for 4th corner goal
	Set_Drive(Turn, -355, 80, 0.1);
	wait_drive();
	intake(-127);
	ALift(0, 127);
	Set_Drive(Drive, 39, 70, 0.1);
	wait_drive();
	intake(0);
	Lift(0);
	//turn to 4th corner goal
	Set_Drive(Turn, -305, 80, 0.1);
	wait_drive();
	pros::delay(100);
	intake(0);
	Lift(0);
	Set_Drive(Drive, 18, 80, 0.2);
	//score 4th corner goal
	pros::delay(700);
	Lift(127);
	pros::delay(600);
	intake(-127);
	ALift(0, 100);
	pros::delay(450);
	intake(0);
	Lift(0);
	Set_Drive(Drive, -14, 80, 0.2);
	pros::delay(300);
	intake(127);
	Lift(-127);
	wait_drive();
	pros::delay(200);
	Set_Drive(Turn, -443, 80, 0.2);
	wait_drive();
	intake(-127);
	ALift(0, 127);
	Set_Drive(Drive, 36, 60, 0.1);
	wait_drive();
	intake(0);
	Lift(0);
	Set_Drive(Turn, -354, 75, 0.1);
	wait_drive();
	pros::delay(100);
	intake(0);
	Lift(0);
	Set_Drive(Drive, 10, 80, 0.2);
	pros::delay(700);
	Lift(127);
	intake(-127);
	pros::delay(700);
	intake(0);
	Lift(0);
	pros::delay(200);
	Set_Drive(Drive, -10, 80, 0.2);
	intake(127);
	Lift(-127);
	wait_drive();
	pros::delay(200);
	Set_Drive(Turn, -178, 70, 0.1);
	wait_drive();
	intake(-127);
	ALift(0, 80);
	Set_Drive(Drive, 35, 60, 0.2);
	pros::delay(2700);
	intake(127);
	pros::delay(700);
	Lift(127);
	pros::delay(500);
	Lift(0);
	intake(0);
	Set_Drive(Drive, -10, 127, 0.2);
	wait_drive();

}
void SkillsAutonV2()
{
	Drive_pid_task.resume();
	ALift(127, 0);
	pros::delay(1500);
	ALift(0, 127);
	intake(-127);
	Set_Drive(Drive, 17, 60, 0.1);
	wait_drive();
	pros::delay(100);
	intake(-127);
	ALift(0, 100);
	Set_Drive(Turn, 24, 75, 0.1);
	wait_drive();
	pros::delay(100);
	Set_Drive(Drive, 34, 60, 0.1);
	wait_drive();
	Set_Drive(Turn, -25, 75, 0.1);
	wait_drive();
	Set_Drive(Drive, 20, 75, 0.1);
	wait_drive();
	Set_Drive(Drive, -14, 75, 0.2);
	wait_drive();
	intake(0);
	Lift(0);
	Set_Drive(Turn, 40, 75, 0.1);
	wait_drive();
	Set_Drive(Drive, 16, 75, 0.2);
	pros::delay(1300);
	Lift(127);
	intake(-127);
	pros::delay(400);
	intake(0);
	pros::delay(400);
	Lift(0);
	Set_Drive(Drive, -36, 45, 0.1);
	pros::delay(100);
	Lift(-127);
	intake(127);
	wait_drive();
	pros::delay(100);
	Set_Drive(Turn, -90, 75, 0.1);
	wait_drive();
	pros::delay(100);
	intake(-127);
	ALift(0, 80);
	Set_Drive(Drive, 24, 50, 0.1);
	wait_drive();
	pros::delay(100);
	Set_Drive(Turn, -5, 75, 0.1);
	wait_drive();
	pros::delay(100);
	Set_Drive(Drive, 30, 75, 0.1);
	intake(-127);
	pros::delay(1400);
	Lift(127);
	pros::delay(100);
	ALift(127, 0);
	pros::delay(500);
	intake(127);
	ALift(0, 127);
	Set_Drive(Drive, -15, 75, 0.2);
	wait_drive();
	Set_Drive(Turn, 45, 75, 0.1);
	wait_drive();
	intake(127);
	ALift(0, -127);
	pros::delay(600);
	Set_Drive(Turn, -87, 60, 0.1);
	wait_drive();
	intake(-127);
	ALift(0, 127);
	Set_Drive(Drive, 47, 75, 0.1);
	wait_drive();
	Set_Drive(Drive, -10, 75, 0.2);
	wait_drive();
	intake(0);
	Lift(0);
	Set_Drive(RSwing, -35, 75, 0.1);
	wait_drive();
	Set_Drive(Drive, 26, 75, 0.2);
	pros::delay(1000);
	ALift(127, 0);
	pros::delay(300);
	ALift(0, 127);
	intake(-127);
	pros::delay(600);
	Lift(0);
	Set_Drive(Drive, -35, 60, 0.2);
	pros::delay(100);
	ALift(0, -127);
	intake(127);
	pros::delay(500);
	ALift(0, 127);
	intake(-127);
	wait_drive();
	Set_Drive(Turn, -189, 75, 0.1);
	wait_drive();
	intake(-127);
	ALift(0, 127);
	Set_Drive(Drive, 19, 50, 0.1);
	wait_drive();
	Set_Drive(Turn, -266, 40, 0.1);
	wait_drive();
	pros::delay(300);
	intake(-127);
	Set_Drive(Drive, 20, 127, 0.2);
	pros::delay(700);
	intake(127);
	pros::delay(1200);
	ALift(127, 0);
	intake(0);
	pros::delay(400);
	intake(100);
	Set_Drive(Drive, -19, 75, 0.2);
	wait_drive();
	Set_Drive(Turn, -437, 75, 0.1);
	ALift(0, 127);
	wait_drive();
	intake(0);
	Lift(0);
	Set_Drive(Drive, 20, 75, 0.2);
	pros::delay(700);
	intake(-127);
	Lift(127);
	pros::delay(700);
	intake(127);
	Lift(0);
	//stoped here
	Set_Drive(Drive, -7, 75, 0.2);
	wait_drive();
	Set_Drive(Turn, -400, 75, 0.2);
	pros::delay(300);
	intake(127);
	Lift(-127);
	wait_drive();
	pros::delay(500);
	intake(127);
	Lift(0);
	Set_Drive(Turn, -527, 75, 0.1);
	wait_drive();
	intake(-127);
	ALift(0, 127);
	Set_Drive(Drive, 37, 60, 0.1);
	wait_drive();
	intake(0);
	Lift(0);
	Set_Drive(Turn, -500, 75, 0.1);
	wait_drive();
	pros::delay(100);
	intake(0);
	Lift(0);
	Set_Drive(Drive, 20, 75, 0.2);
	pros::delay(700);
	Lift(127);
	intake(-127);
	pros::delay(700);
	intake(0);
	Lift(0);
	Set_Drive(Drive, -15, 45, 0.2);
	pros::delay(100);
	Lift(-127);
	intake(127);
	wait_drive();
	pros::delay(100);
	Set_Drive(Turn, -620, 75, 0.1);
	wait_drive();
	pros::delay(100);
	intake(-127);
	ALift(0, 80);
	Set_Drive(Drive, 38, 50, 0.1);
	wait_drive();
	pros::delay(100);
	Set_Drive(Turn, -540, 75, 0.1);
	wait_drive();
	pros::delay(100);
	Set_Drive(Drive, 9, 75, 0.2);
	pros::delay(700);
	intake(-127);
	pros::delay(100);
	Lift(127);
	pros::delay(500);
	Lift(0);
	Set_Drive(Drive, -15, 75, 0.2);
	wait_drive();
	Set_Drive(Turn, -500, 75, 0.2);
	pros::delay(300);
	intake(127);
	Lift(-127);
	wait_drive();
	pros::delay(400);
	intake(0);
	Lift(0);
	Set_Drive(Turn, -625, 75, 0.1);
	wait_drive();
	intake(-127);
	ALift(0, 127);
	Set_Drive(Drive, 57, 50, 0.1);
	wait_drive();
	Set_Drive(Drive, -13, 75, 0.2);
	wait_drive();
	Set_Drive(RSwing, -570, 75, 0.1);
	wait_drive();
	intake(-127);
	Set_Drive(Drive, 26, 75, 0.2);
	pros::delay(700);
	Lift(127);
	pros::delay(900);
	Lift(0);
	Set_Drive(Drive, -35, 75, 0.2);
	wait_drive();






}
void SkillsAuton()
{
	Drive_pid_task.resume();
	Lift(127);
	pros::delay(1000);
	Lift(0);
	ALift(-127, 80);
	pros::delay(500);
	Lift(0);
	//printf("working \n");
	Set_Drive(Drive, 24, 60, 0.2);
	ALift(0, 127);
	intake(-127);
	wait_drive();
	ALift(0,0);
	intake(0);
	Set_Drive(Turn, 130, 60, 0.2);
	wait_drive();
	Set_Drive(Drive, 30, 60, 0.2);
	wait_drive();
	printf("COMpLETE");
	intake(-127);
	ALift(127, 127);
	pros::delay(825);
	ALift(0,0);
	intake(0);
	intake(127);
	Set_Drive(Drive, -30, 50, 0.2);
	wait_drive();
	pros::delay(200);
	Set_Drive(Turn, 180, 60, 0.2);
	wait_drive();
	intake(127);
	Lift(-127);
	pros::delay(1000);
	intake(0);
	Lift(0);
	Set_Drive(Turn, 90, 60, 0.2);
	wait_drive();
	intake(-127);
	ALift(0, 80);
	Set_Drive(Drive, 22, 60, 0.2);
	wait_drive();
	pros::delay(1000);
	intake(0);
	Lift(0);
	Set_Drive(Drive, -12, 60, 0.2);
	wait_drive();
	pros::delay(200);
	Set_Drive(Turn, 0, 60, 0.2);
	wait_drive();
	intake(-127);
	ALift(-127, 80);
	Set_Drive(Drive, 36, 40, 0.2);
	wait_drive();
	intake(0);
	Lift(0);
	Set_Drive(Turn, 90, 60, 0.2);
	wait_drive();
	Set_Drive(Drive, 8, 60, 0.2);
	wait_drive();
	intake(-127);
	ALift(127, 127);
	pros::delay(875);
	ALift(0,0);
	intake(0);
	intake(127);
	Lift(-127);
	Set_Drive(Drive, -22, 60, 0.2);
	wait_drive();
	intake(0);
	Lift(0);
	Set_Drive(Turn, 0, 60, 0.2);
	wait_drive();
	intake(-127);
	ALift(-127, 80);
	Set_Drive(Drive, 52, 40, 0.2);
	wait_drive();
	pros::delay(500);
	intake(0);
	Lift(0);
	Set_Drive(Drive, -8, 60, 0.2);
	wait_drive();
	Set_Drive(Turn, 55, 60, 0.2);
	wait_drive();
	Set_Drive(Drive, 26, 60, 0.2);
	wait_drive();
	intake(-127);
	ALift(127, 127);
	pros::delay(850);
	//works
	Lift(-127);
	intake(127);
	Set_Drive(Drive, -18, 60, 0.2);
	wait_drive();
	Lift(0);
	intake(0);
	Set_Drive(Turn, -90, 60, 0.2);
	wait_drive();
	ALift(-127, 80);
	intake(-127);
	Set_Drive(Drive, 86, 40, 0.2);
	wait_drive();
	Lift(0);
	intake(0);
	Set_Drive(Turn, -45, 60, 0.2);
	wait_drive();
	Set_Drive(Drive, 16, 60, 0.2);
	wait_drive();
	intake(-127);
	ALift(127, 127);
	pros::delay(875);
	Lift(-127);
	intake(127);
	Set_Drive(Drive, -20, 60, 0.2);
}
void RedCenterGoalAuton()
{
	Drive_pid_task.resume();
//	Deploy();
//grab 1st ball
	intake(-127);
	ALift(0, 80);
	Set_Drive(Drive, 4, 40, 0.2);
	wait_drive();
	//swing turn to goal
	Set_Drive(LSwing, 40, 80, 0.2);
	wait_drive();
	intake(-127);
	ALift(127, 80);
	pros::delay(750);
	ALift(0, -80);
	intake(127);
	//back up
	Set_Drive(Drive, -20, 127, 0.2);
	wait_drive();
	Lift(0);
	intake(0);
	Set_Drive(Turn, 0, 127, 0.2);
	wait_drive();
	Set_Drive(Drive, -44, 127, 0.2);
	wait_drive();
	Set_Drive(Turn, 90, 127, 0.2);
	wait_drive();
	Set_Drive(Drive, 14, 127, 0.2);
	wait_drive();
	intake(-105);
	ALift(127, 80);
	pros::delay(750);
	Lift(0);
	intake(0);
	Set_Drive(Drive, -20, 127, 0.2);
	wait_drive();
	ALift(0, 80);
	intake(127);
	pros::delay(250);
	Set_Drive(Turn, -86, 127, 0.2);
	wait_drive();
	intake(-127);
	Set_Drive(Drive, 38, 100, 0.2);
	wait_drive();
	intake(0);
	Lift(127);
	pros::delay(500);
	Lift(0);
	Set_Drive(Drive, -20, 127, 0.2);
	wait_drive();

}
void SingleGoalRight()
{
	Drive_pid_task.resume();
	Deploy();
//grab 1st ball
	intake(-127);
	ALift(0, 80);
	Set_Drive(Drive, 4, 40, 0.2);
	wait_drive();
	//swing turn to goal
	Set_Drive(LSwing, 43, 80, 0.2);
	wait_drive();
	//score first goal
	intake(-127);
	ALift(127, 80);
	pros::delay(500);
	intake(0);
	pros::delay(800);
	ALift(0, -100);
	intake(127);
	//back up
	Set_Drive(Drive, -20, 127, 0.2);
	pros::delay(600);
	ALift(0, 80);
	intake(-127);
	wait_drive();
}
void TwoGoalRight()
{
	Drive_pid_task.resume();
	Deploy();
//grab 1st ball
	intake(-127);
	ALift(0, 80);
	Set_Drive(Drive, 4, 40, 0.2);
	wait_drive();
	//swing turn to goal
	Set_Drive(LSwing, 43, 80, 0.2);
	wait_drive();
	//score first goal
	intake(-127);
	ALift(127, 80);
	pros::delay(800);
	ALift(0, -100);
	intake(127);
	//back up
	Set_Drive(Drive, -20, 127, 0.2);
	pros::delay(600);
	ALift(0, 80);
	intake(-127);
	wait_drive();
	//turn to second goal
	Set_Drive(Turn, 0, 127, 0.2);
	wait_drive();
	ALift(-127, 127);
	Set_Drive(Drive, -40, 127, 0.2);
	wait_drive();
	Set_Drive(Turn, 90, 127, 0.2);
	wait_drive();
	Set_Drive(Drive, 10, 60, 0.2);
	wait_drive();
	// score second goal
	intake(-105);
	Lift(127);
	pros::delay(700);
	intake(127);
	ALift(127,0);
	pros::delay(500);
	Lift(0);
	//back up
	Set_Drive(Drive, -18, 127, 0.2);
	pros::delay(500);
	ALift(0, -80);
	intake(127);
	pros::delay(100);
	Lift(0);
	wait_drive();
	Lift(0);
	intake(0);
}
void SingleGoalLeft()
{
	Drive_pid_task.resume();
	Deploy();
//grab 1st ball
	intake(-127);
	ALift(0, 80);
	Set_Drive(Drive, 4, 40, 0.2);
	wait_drive();
	//swing turn to goal
	Set_Drive(RSwing, -43, 80, 0.2);
	wait_drive();
	//score first goal
	intake(-127);
	ALift(127, 80);
	pros::delay(500);
	intake(0);
	pros::delay(800);
	ALift(0, -100);
	intake(127);
	//back up
	Set_Drive(Drive, -20, 127, 0.2);
	pros::delay(600);
	ALift(0, 80);
	intake(-127);
	wait_drive();
}
void TwoGoalLeft()
{
	Drive_pid_task.resume();
	Deploy();
//grab 1st ball
	intake(-127);
	ALift(0, 80);
	Set_Drive(Drive, 4, 40, 0.2);
	wait_drive();
	//swing turn to goal
	Set_Drive(RSwing, 30, 110, 0.2);
	wait_drive();
	//score first goal
	intake(127);
	ALift(127, 80);
	pros::delay(300);
	ALift(0, -100);
	intake(0);
	//back up
	Set_Drive(Drive, -20, 110, 0.2);
	ALift(-127, 80);
	wait_drive();
	//turn to second goal
	Set_Drive(Turn, 0, 110, 0.2);
	wait_drive();
	ALift(-127, 127);
	Set_Drive(Drive, -32, 110, 0.2);
	wait_drive();
	Set_Drive(Turn, -90, 110, 0.2);
	wait_drive();
	Set_Drive(Drive, 12, 110, 0.2);
	wait_drive();
	// score second goal
	intake(-105);
	Lift(127);
	pros::delay(800);
	intake(127);
	ALift(127,0);
	pros::delay(400);
	Lift(0);
	//back up
	Set_Drive(Drive, -18, 127, 0.2);
	wait_drive();
	pros::delay(100);
	Lift(0);
	wait_drive();
	Lift(0);
	intake(0);
}
int ballsOutint = 0;
void HomeRow()
{
	Drive_pid_task.resume();
	//BallsinRobotTask.resume();
	Deploy();
//grab 1st ball
	intake(-127);
	ALift(-127, 80);
	Set_Drive(Drive, 4, 40, 0.2);
	pros::delay(300);
	ALift(0, 80);
	wait_drive();
	//swing turn to goal
	Set_Drive(LSwing, 43, 80, 0.2);
	wait_drive();
	//score first goal
	//intake(-127);
	ALift(127, 0);//127
	pros::delay(550);
	//intake(127);
	//pros::delay(300);
	ALift(-100, 80);
	intake(100);
	//back up
	Set_Drive(Drive, -20, 127, 0.2);
	wait_drive();
	//turn to second goal
	Set_Drive(Turn, 0, 127, 0.2);
	wait_drive();
	ALift(-127, 127);
	Set_Drive(Drive, -27, 127, 0.2);
	wait_drive();
	Set_Drive(Turn, 90, 127, 0.2);
	wait_drive();
	Set_Drive(Drive, 13, 127, 0.2);
	pros::delay(500);
	// score second goal
	Lift(127);
	pros::delay(1200);
	Lift(0);
	//back up
	Set_Drive(Drive, -33, 127, 0.2);//33
	pros::delay(500);
	ALift(0, -80);
	intake(127);
	pros::delay(100);
	Lift(0);
	wait_drive();
	Lift(0);
	intake(0);
		Set_Drive(LSwing, 145, 127, 0.2);//145
		wait_drive();
		ALift(-127, 127);
		intake(-127);
		//drive forward to third goal
		Set_Drive(Drive, 51, 127, 0.2);
		pros::delay(2000);
		intake(0);
		Lift(127);
		pros::delay(500);
		intake(100);
		pros::delay(750);
		ALift(0, 80);
		pros::delay(200);
		Set_Drive(Drive, -30, 127, 0.2);
		wait_drive();
		Set_Drive(Turn, 40, 110, 0.2);
		wait_drive();
}
void CenterRow()
{
	Drive_pid_task.resume();
	//BallsinRobotTask.resume();
	Deploy();
//grab 1st ball
	intake(-127);
	ALift(-127, 80);
	Set_Drive(Drive, 4, 40, 0.2);
	pros::delay(300);
	ALift(0, 80);
	wait_drive();
	Set_Drive(Drive, -4, 127, 0.2);
	wait_drive();
	//swing turn to goal
	Set_Drive(Turn, -72, 80, 0.2);
	wait_drive();
	intake(0);
	Set_Drive(Drive, 37, 127, 0.2);
	pros::delay(800);
	Lift(-127);
	intake(127);
	pros::delay(500);
	Lift(-127);
	intake(127);
	pros::delay(400);
	Set_Drive(Drive, -15, 80, 0.2);
	wait_drive();
	Set_Drive(Turn, 0, 127, 0.2);
	wait_drive();
	Set_Drive(Drive, -43, 127, 0.2);
	wait_drive();
	Set_Drive(Turn, 90, 127, 0.2);
	wait_drive();
	Set_Drive(Drive, -13, 127, 0.2);
	wait_drive();
	Set_Drive(LSwing, 140, 127, 0.2);
	wait_drive();
	ALift(-127, 127);
	intake(-127);
	//drive forward to third goal
	Set_Drive(Drive, 50, 127, 0.2);
	pros::delay(1600);
	intake(0);
	Lift(127);
	pros::delay(500);
	intake(100);
	pros::delay(750);
	ALift(0, 80);
	pros::delay(200);
	Set_Drive(Drive, -20, 127, 0.2);
	wait_drive();

}
/* home field
void CenterGoal()
{
	Drive_pid_task.resume();
	Deploy();
//grab 1st ball
	intake(-127);
	ALift(0, 80);
	Set_Drive(Drive, 4, 40);
	wait_drive();
	//swing turn to goal
	Set_Drive(LSwing, 43, 80);
	wait_drive();
	//score first goal
	intake(-127);
	ALift(127, 80);
	pros::delay(750);
	ALift(0, -100);
	intake(127);
	//back up
	Set_Drive(Drive, -20, 127);
	pros::delay(600);
	ALift(0, 80);
	intake(-127);
	wait_drive();
	//turn to second goal
	Set_Drive(Turn, 222, 127);
	wait_drive();
	//drive to second goal
	Set_Drive(Drive, 53, 80);
		ALift(-127, 127);
		pros::delay(500);
		Lift(0);
	wait_drive();
	//score second goal
	drive(127, 127);
	intake(-127);
	Lift(127);
	pros::delay(1200);
	//back up from second goal
	Set_Drive(Drive, -12, 127);
	wait_drive();
	//Turn to third goal
	Set_Drive(Turn, 103, 127);
	wait_drive();
	//drive to third goal
	Set_Drive(Drive, 48, 127);
	wait_drive();
	//score third goal
	intake(-127);
	ALift(127, 80);
	pros::delay(1200);
	ALift(127, 0);
	pros::delay(750);
	Lift(0);
	intake(127);
	Set_Drive(Drive, -20, 127);
	wait_drive();

}
*///hotel field
void CenterGoal()
{
	Drive_pid_task.resume();
	Deploy();
//grab 1st ball
	intake(-127);
	ALift(0, 80);
	Set_Drive(Drive, 4, 40, 0.2);
	wait_drive();
	//swing turn to goal
	Set_Drive(LSwing, 43, 80, 0.2);
	wait_drive();
	//score first goal
	intake(-127);
	ALift(127, 80);
	pros::delay(750);
	ALift(0, -100);
	intake(127);
	//back up
	Set_Drive(Drive, -20, 127, 0.2);
	pros::delay(600);
	ALift(0, 80);
	intake(-127);
	wait_drive();
	//turn to second goal
	Set_Drive(Turn, 225, 127, 0.2);
	wait_drive();
	//drive to second goal
	Set_Drive(Drive, 55, 80, 0.2);
		ALift(-127, 127);
		pros::delay(500);
		Lift(0);
	wait_drive();
	//score second goal
	drive(127, 127);
	intake(-127);
	Lift(127);
	pros::delay(1200);
	//back up from second goal
	Set_Drive(Drive, -12, 127, 0.2);
	wait_drive();
	//Turn to third goal
	Set_Drive(Turn, 103, 127, 0.2);
	wait_drive();
	//drive to third goal
	Set_Drive(Drive, 48, 127, 0.2);
	wait_drive();
	//score third goal
	intake(-127);
	ALift(127, 80);
	pros::delay(1200);
	ALift(127, 0);
	pros::delay(750);
	Lift(0);
	intake(127);
	Set_Drive(Drive, -20, 127, 0.2);
	wait_drive();
=======
pros::Controller master(CONTROLLER_MASTER);

pros::Motor left_back(14, true);
pros::Motor left_front(13, true);
pros::Motor right_back(9);
pros::Motor right_front(16);
pros::Imu Inersial(15);
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
>>>>>>> Stashed changes

}


<<<<<<< Updated upstream
void Center_Row()
{
	Drive_pid_task.resume();
	//Deploy();
	intake(-127);
	ALift(0,80);
	Set_Drive(Drive, 4, 110, 0.2);
	wait_drive();
	Set_Drive(Drive, -9, 110, 0.2);
	wait_drive();
	Set_Drive(Turn, 90, 110, 0.2);
	wait_drive();
	Set_Drive(Drive, 38, 110, 0.12);
	wait_drive();
	Set_Drive(Drive, -15, 110, 0.2);
	wait_drive();
	Set_Drive(Turn, 180, 110, 0.2);
	wait_drive();
	Set_Drive(Drive, 25, 110, 0.2);
	wait_drive();
	Set_Drive(Turn, 91, 110, 0.2);
	wait_drive();
	Set_Drive(Drive, 20, 110, 0.2);
	wait_drive();

}

void autonomous()
{
	//Center_Row();
	SkillsAutonV3();
	//HomeRow();
	//Drive_pid_task.resume();
	//Set_Drive(Drive, 40, 50, 0.2);
	//intake(-127);
	//wait_drive();
}


void opcontrol()
{

Drive_pid_task.suspend();
  while (true)
  {

    drive(master.get_analog(ANALOG_RIGHT_Y), master.get_analog(ANALOG_LEFT_Y));
  	liftstuff();

  	intakestuff();
    pros::delay(10);
		if(master.get_digital(DIGITAL_A))
		{
			Deploy();
		}
		else if(master.get_digital(DIGITAL_X))
		{
			SkillsAutonV3();
		}
  }
=======
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
