#ifndef ODOMETRY_CPP_INCLUDED
#define ODOMETRY_CPP_INCLUDED
#include "odometry.hpp"

long double reset_theta, theta_M, delta_theta, polar_r, polar_theta, translationGlobal[2],
translationLocal[2];

void initOdom(const bool left, const bool right, const bool side, const double start_x, const double start_y, const double start_theta){
  pros::ADIEncoder leftEncoder(leftP1, leftP2, left); //reverse the encoders
  pros::ADIEncoder rightEncoder(leftP1, leftP2, right);
  pros::ADIEncoder sideEncoder(leftP1, leftP2, side);
  scorpio_odom.prev_theta = reset_theta = start_theta;
  scorpio_odom.prev_x = scorpio_odom.x = start_x;
  scorpio_odom.prev_y = scorpio_odom.y = start_y;
}



void tracking(void*){
  while(true){
    //Step 1: take the current values:
    leftQuad.raw_val = leftEncoder.get_value();
    rightQuad.raw_val = rightEncoder.get_value();
    sideQuad.raw_val = sideEncoder.get_value();
    //Step 2: find the change from last check and convert to inches
    leftQuad.delta_in = (leftQuad.raw_val-leftQuad.prev_raw_val)*wheelRadius*conversion;
    rightQuad.delta_in = (rightQuad.raw_val-rightQuad.prev_raw_val)*wheelRadius*conversion;
    sideQuad.delta_in = (sideQuad.raw_val-sideQuad.prev_raw_val)*wheelRadius*conversion;
    leftQuad.prev_raw_val = leftQuad.raw_val;
    rightQuad.prev_raw_val = rightQuad.raw_val;
    sideQuad.prev_raw_val = sideQuad.raw_val;
    //Step 3: find total change from last reset in inches and store
    leftQuad.total_in = leftQuad.raw_val*wheelRadius*conversion;
    rightQuad.total_in = rightQuad.raw_val*wheelRadius*conversion;
    //Step 4: Find the absolute orientation
    scorpio_odom.theta = reset_theta + ((leftQuad.total_in-rightQuad.total_in)/(sl+sr));
    //current_theta = std::fmod(current_theta, 6.28319); //everthing in radians
    //Step 5: find the change in angle
    delta_theta = scorpio_odom.theta - scorpio_odom.prev_theta;
    //Step 6: calculate the translation depending on delta_theta
    if(delta_theta == 0){
      translationLocal[0]=sideQuad.delta_in;
      translationLocal[1]=rightQuad.delta_in;
    }else{
      long double outside{2*std::sin((delta_theta/2))};
      translationLocal[0]= outside*((sideQuad.delta_in/delta_theta)+ss);
      translationLocal[1]= outside*((rightQuad.delta_in/delta_theta)+sr);
    }
    //Step 7: Calculate average orientation
    theta_M = scorpio_odom.prev_theta + (delta_theta/2);
    //Step 8: Calculate global offset --> convert from cartesian to polar and back
    if(translationLocal[0] == translationLocal[1] && translationLocal[0] == 0){
      polar_r = 0.0;
      polar_theta = 0.0;
    }else{
      polar_r = std::hypot(translationLocal[0], translationLocal[1]);
      polar_theta = std::atan(translationLocal[1]/translationLocal[0]);
    }
    polar_theta = polar_theta-theta_M;
    translationGlobal[0] = polar_r*std::cos(polar_theta);
    translationGlobal[1] = polar_r*std::sin(polar_theta);
    //Step 9: Calculate the new absolute position
    scorpio_odom.x = scorpio_odom.x+translationGlobal[0];
    scorpio_odom.y = scorpio_odom.y+translationGlobal[1];
    //Step 10: update the value to be used for the next check(update previous value)
    scorpio_odom.prev_theta = scorpio_odom.theta;
    scorpio_odom.prev_x = scorpio_odom.x;
    scorpio_odom.prev_y = scorpio_odom.y;
    printf("X: %Lf", scorpio_odom.x);
    printf(" Y: %Lf", scorpio_odom.y);
    printf(" Angle: %Lf\r", scorpio_odom.theta);
    pros::delay(2);
  }
}
#endif
