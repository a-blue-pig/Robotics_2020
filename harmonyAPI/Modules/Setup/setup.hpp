#ifndef SETUP_HPP_INCLUDED
#define SETUP_HPP_INCLUDED
#include "../../../include/main.h"

const int lf_mtr_prt{0};
const int lb_mtr_prt{0};
const int rf_mtr_prt{0};
const int rb_mtr_prt{0};

pros::Controller master(pros::E_CONTROLLER_MASTER);
pros::Motor left_front  (lf_mtr_prt, pros::E_MOTOR_GEARSET_18, false, pros::E_MOTOR_ENCODER_ROTATIONS);
pros::Motor left_back   (lb_mtr_prt, pros::E_MOTOR_GEARSET_18, false, pros::E_MOTOR_ENCODER_ROTATIONS);
pros::Motor right_front (rf_mtr_prt, pros::E_MOTOR_GEARSET_18, true, pros::E_MOTOR_ENCODER_ROTATIONS);
pros::Motor right_back  (rb_mtr_prt, pros::E_MOTOR_GEARSET_18, true, pros::E_MOTOR_ENCODER_ROTATIONS);

#endif
