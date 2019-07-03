
#ifndef _PROS_MAIN_H_
#define _PROS_MAIN_H_

#define PROS_USE_SIMPLE_NAMES

#define PROS_USE_LITERALS

#include "api.h"

#define lf_mtr_prt 1 //fill in
#define lb_mtr_prt 2 //fill in
#define rf_mtr_prt 10 //fill in
#define rb_mtr_prt 9 //fill in


//#include "okapi/api.hpp"
//#include "pros/api_legacy.h"

/**
 * If you find doing pros::Motor() to be tedious and you'd prefer just to do
 * Motor, you can use the namespace with the following commented out line.
 *
 * IMPORTANT: Only the okapi or pros namespace may be used, not both
 * concurrently! The okapi namespace will export all symbols inside the pros
 * namespace.
 */
// using namespace pros;
// using namespace pros::literals;
// using namespace okapi;


#ifdef __cplusplus
extern "C" {
#endif
void autonomous(void);
void initialize(void);
void disabled(void);
void competition_initialize(void);
void opcontrol(void);


#ifdef __cplusplus
}
#endif

#ifdef __cplusplus

#include "harmonyAPI/odometryAPI.hpp"
//#include <iostream>
#endif

#endif  // _PROS_MAIN_H_
