
//Define Encoder pins
#define leftP1 1//left
#define leftP2 2

#define rightP1 3 //right
#define rightP2 4

#define sideP1 5 // back
#define sideP2 6

//the measured distance from the tracking wheel to the center
static double sl{0}; //fill in
static double sr{0}; //fill in
static double ss{0}; //fill in

static double wheelRadius{1.625}; //fill in
static double conversion{0.01745};

int delta_L_R, delta_R_R;
double delta_L, delta_R, delta_S, delta_L_P, delta_R_P, delta_S_P;
double reset_theta, theta_M, delta_theta, previous_theta, current_theta;
double currentLocation[2], translationGlobal[2], translationLocal[2], previousLocation[2];
/*          The units
Radians:
initial_theta, current_theta, previous_theta, delta_theta, theta_M


Inches:
currentLocation,translationLocal,translationGlobal
delta_L,delta_R,delta_S,delta_L_R,delta_R_R
*/
