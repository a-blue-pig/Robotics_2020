#include "main.h"
double initialLocation[2];

void initialize() {
	pros::lcd::initialize();
	pros::lcd::set_text(1, "Testing odometry");

	pros::ADIEncoder leftEncoder (leftP1, leftP2, false);
	pros::ADIEncoder rightEncoder (rightP1, rightP2, false);
	pros::ADIEncoder sideEncoder (sideP1, sideP2, false);

	pros::Motor lf_mtr_init (lf_mtr_prt, pros::E_MOTOR_GEARSET_18, true, pros::E_MOTOR_ENCODER_ROTATIONS);
	pros::Motor lb_mtr_init (lb_mtr_prt, pros::E_MOTOR_GEARSET_18, true, pros::E_MOTOR_ENCODER_ROTATIONS);
	pros::Motor rf_mtr_init (rf_mtr_prt, pros::E_MOTOR_GEARSET_18, false, pros::E_MOTOR_ENCODER_ROTATIONS);
	pros::Motor rb_mtr_init (rb_mtr_prt, pros::E_MOTOR_GEARSET_18, false, pros::E_MOTOR_ENCODER_ROTATIONS);

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
	//take in the value or preset from display
	//set up the inital location here:
	//initialLocation[0] = ;
	//initialLocation[1] = ;
}
