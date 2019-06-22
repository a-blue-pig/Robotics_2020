#include "main.h"


 void tracking(void*){
	 pros::ADIEncoder leftEncoder (leftP1, leftP2);
	 pros::ADIEncoder rightEncoder (rightP1, rightP2);
	 pros::ADIEncoder sideEncoder (sideP1, sideP2);

	 double conversion{0.01745};
	 int l, r, s, delta_L_R, delta_R_R;
	 double delta_L, delta_R, delta_S, delta_L_P, delta_R_P, delta_S_P, initial_theta, theta_M, delta_Theta;
	 double currentLocation[2], translationGlobal[2], translationLocal[2];

	 while(true){
		 int left_value{leftEncoder.get_value()};
		 int right_value{rightEncoder.get_value()};
		 int side_value{sideEncoder.get_value()};
		 delta_L = (double)(left_value-delta_L_P)*wheelRadius*conversion;
		 delta_R = (double)(right_value-delta_R_P)*wheelRadius*conversion;
		 delta_S = (double)(side_value-delta_S_P)*wheelRadius*conversion;

	 }
 }
void opcontrol() {
	pros::Controller master(pros::E_CONTROLLER_MASTER);
	pros::Motor lf_mtr (lf_mtr_prt);
	pros::Motor lb_mtr (lb_mtr_prt);
	pros::Motor rf_mtr (rf_mtr_prt);
	pros::Motor rb_mtr (rb_mtr_prt);

	pros::Task task(tracking);

	while (true) {

		int left = master.get_analog(ANALOG_LEFT_Y);
		int right = master.get_analog(ANALOG_RIGHT_Y);

		lf_mtr = lb_mtr = left;
		rf_mtr = rb_mtr = right;
		pros::delay(20);
	}
}
