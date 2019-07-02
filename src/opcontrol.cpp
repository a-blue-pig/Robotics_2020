#include "main.h"

 void tracking(void*){
	 pros::ADIEncoder leftEncoder (leftP1, leftP2);
	 pros::ADIEncoder rightEncoder (rightP1, rightP2);
	 pros::ADIEncoder sideEncoder (sideP1, sideP2);

	 while(true){
		 //Step 1: take the current values:
		 int left_value{leftEncoder.get_value()};
		 int right_value{rightEncoder.get_value()};
		 int side_value{sideEncoder.get_value()};
		 //Step 2: find the change from last check and convert to inches
		 delta_L = (double)(left_value-delta_L_P)*wheelRadius*conversion;
		 delta_R = (double)(right_value-delta_R_P)*wheelRadius*conversion;
		 delta_S = (double)(side_value-delta_S_P)*wheelRadius*conversion;
		 //Step 3: find total change from last reset in inches and store
		 delta_L_R = left_value*wheelRadius*conversion;
		 delta_R_R = right_value*wheelRadius*conversion;
		 //Step 4: Find the absolute orientation
		 current_theta  = reset_theta + ((delta_L_R-delta_R_R)/(sl+sr));
		 //Step 5: find the change in angle
		 delta_theta = current_theta - previous_theta;
		 //Step 6: calculate the translation depending on delta_theta
		 if(delta_theta == 0){
			 translationLocal[0]=delta_S;
			 translationLocal[1]=delta_R;
		 }else{
			 double outside{2*std::sin((delta_theta/2))};
			 translationLocal[0]= outside*((delta_S/delta_theta)+ss);
			 translationLocal[1]= outside*((delta_R/delta_theta)+sr);
		 }
		 //Step 7: Calculate average orientation
		 theta_M = previous_theta + (delta_theta/2);
		 //Step 8: Calculate global offset --> convert from cartesian to polar and back
		 double polar_r{std::hypot(translationLocal[0], translationLocal[1])};
		 double polar_theta{std::atan(translationLocal[1]/translationLocal[0])};
		 polar_theta -= theta_M;
		 translationGlobal[0] = polar_r*std::cos(polar_theta);
		 translationGlobal[1] = polar_r*std::sin(polar_theta);
		 //Step 9: Calculate the new absolute position
		 currentLocation[0] = previousLocation[0]+translationGlobal[0];
		 currentLocation[1] = previousLocation[1]+translationGlobal[1];
		 //Step 10: update the value to be used for the next check(update previous value)
		 delta_L_P = left_value;
		 delta_R_P = right_value;
		 delta_S_P = side_value;
		 previous_theta = current_theta;
		 previousLocation[0] = currentLocation[0];
		 previousLocation[1] = currentLocation[1];
	 }
 }


void opcontrol() {
	pros::Controller master(pros::E_CONTROLLER_MASTER);
	pros::Motor lf_mtr(lf_mtr_prt);
	pros::Motor lb_mtr(lb_mtr_prt);
	pros::Motor rf_mtr(rf_mtr_prt, true);
	pros::Motor rb_mtr(rb_mtr_prt, true);

	pros::Task trackTask(tracking);

	while (true) {
    int left = master.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y);
    int right = master.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_Y);
    lf_mtr.move_velocity(left); lb_mtr.move_velocity(left);
    rf_mtr.move_velocity(right); rb_mtr.move_velocity(right);
    int x = (int)currentLocation[0];
    int y = (int)currentLocation[1];
    int a = (int) current_theta;
    std::printf("X: %f",wheelRadius);
    std::printf(" Y: %f",conversion);
    std::printf(" A: %d\r",a);
    pros::delay(2);
	}
}
