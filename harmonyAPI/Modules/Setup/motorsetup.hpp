/**
* @file harmonyAPI/Modules/Setup/motorsetup.hpp
* @brief Motor setup file
* ## Motor Setup:
* Has the all motor port variables in order to ease the change of ports. E.g.
*
*     const int motorname_prt{port#};
*
* Sets up the motors with the gearset, diretion, and the unit for the internal
* encoders. The internal encoders are not really every used.
*
* Setup the motors like so:
*
*     pros::Motor motorname (motor_port, thegearset, isreversed, unit);
*
* Both the unit and the gearset use pros namespace.
*/
#ifndef SETUP_HPP_INCLUDED
#define SETUP_HPP_INCLUDED
#include "../../../include/main.h"

//port configuration
static const int lf_mtr_prt{0}, //Left front drive
                 lb_mtr_prt{0}, //Left back drive
                 rf_mtr_prt{0}, //Right front drive
                 rb_mtr_prt{0}; //Right back drive

pros::Motor left_front  (lf_mtr_prt, pros::E_MOTOR_GEARSET_18, false, pros::E_MOTOR_ENCODER_ROTATIONS);
pros::Motor left_back   (lb_mtr_prt, pros::E_MOTOR_GEARSET_18, false, pros::E_MOTOR_ENCODER_ROTATIONS);
pros::Motor right_front (rf_mtr_prt, pros::E_MOTOR_GEARSET_18, true, pros::E_MOTOR_ENCODER_ROTATIONS);
pros::Motor right_back  (rb_mtr_prt, pros::E_MOTOR_GEARSET_18, true, pros::E_MOTOR_ENCODER_ROTATIONS);

#endif
