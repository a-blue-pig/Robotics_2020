#include "main.h"

double sl{6.29}; //fill in
double sr{6.29}; //fill in
double ss{4.81}; //fill in

double wheelRadius{1.625}; //fill in
double conversion{0.01745};

double delta_L{0.0}, delta_R{0.0}, delta_S{0.0}, delta_L_P{0.0}, delta_R_P{0.0}, delta_S_P{0.0}, delta_L_R{0.0}, delta_R_R{0.0};
double reset_theta{0.0}, theta_M{0.0}, delta_theta{0.0}, previous_theta{0.0}, current_theta{0.0};
double currentLocation[2]{0.0,0.0}, translationGlobal[2]{0.0,0.0}, translationLocal[2]{0.0,0.0}, previousLocation[2]{0.0,0.0};

void initialize() {
	//global stuffs
	pros::ADIEncoder leftEncoder (leftP1, leftP2, false);
	pros::ADIEncoder rightEncoder (rightP1, rightP2, false);
	pros::ADIEncoder sideEncoder (sideP1, sideP2, false);

	delta_L_P = 0;
	delta_R_P = 0;
	delta_S_P = 0;
	reset_theta = previous_theta = 0; //fill in
	previousLocation[0] = 0; //fill in
	previousLocation[1] = 0; //fill in
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
void competition_initialize() {
	delta_L_P = 0;
	delta_R_P = 0;
	delta_S_P = 0;
	//take in the value or preset from display
	//set up the inital location here:
	switch (/*button thing on lcd*/0) { //fill in
		case /*the button*/0: //fill in
			reset_theta = 0; //fill in
			previous_theta = 0; //fill in
			previousLocation[0] = 0; //fill in
			previousLocation[1] = 0; //fill in
			break;
		default:
			reset_theta = 0; //fill in
			previous_theta = 0; //fill in
			previousLocation[0] = 0; //fill in
			previousLocation[1] = 0; //fill in
			break;
	}
}
