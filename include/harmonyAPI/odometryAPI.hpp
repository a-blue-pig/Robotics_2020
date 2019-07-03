#ifndef odometry
#define odometry
//Define Encoder pins
#define leftP1 1//left
#define leftP2 2

#define rightP1 3 //right
#define rightP2 4

#define sideP1 5 // back
#define sideP2 6

//the measured distance from the tracking wheel to the center
extern double sl; //fill in
extern double sr; //fill in
extern double ss; //fill in

extern double wheelRadius; //fill in
extern double conversion;

extern double delta_L, delta_R, delta_S, delta_L_P, delta_R_P, delta_S_P, delta_L_R, delta_R_R;
extern double reset_theta, theta_M, delta_theta, previous_theta, current_theta;
extern double currentLocation[2], translationGlobal[2], translationLocal[2], previousLocation[2];

/*          The units
Radians:
initial_theta, current_theta, previous_theta, delta_theta, theta_M


Inches:
currentLocation,translationLocal,translationGlobal
delta_L,delta_R,delta_S,delta_L_R,delta_R_R
*/
#endif
