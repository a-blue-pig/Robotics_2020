/**
* \file harmonyAPI/Modules/Odometry/odometry.hpp
* ## The File
* A header file with the, forward declarations, global variables, and structs
* to be used for odometry.
*
* ## Related Files:
*/
#ifndef ODOMETRY_HPP_INCLUDED
#define ODOMETRY_HPP_INCLUDED
#include "../../../include/main.h"
/******************************************************************************
 *                                                                            *
 *                  FILL IN WITH THE CORRECT INFORMATION                      *
 *                                                                            *
 ******************************************************************************/
static const int leftP1{1}, leftP2{2},   // pins for the left tracking wheel
                 rightP1{5}, rightP2{6}, // pins for the right tracking wheel
                 sideP1{3}, sideP2{4};   // pins for the back tracking wheel

static const double sl{0},               // distance from left tracking wheel to tracking center
                    sr{0},               // distance from right tracking wheel to tracking center
                    ss{0},               // distance from back tracking wheel to tracking center
                    wheelRadius{1.625},  // radius of the tracking wheels
                    conversion{0.01745}; // unit of conversion from encoder ticks to Inches

//Sets up the tracking Encoders
pros::ADIEncoder leftEncoder(leftP1, leftP2);
pros::ADIEncoder rightEncoder(leftP1, leftP2);
pros::ADIEncoder sideEncoder(leftP1, leftP2);
/**
* @brief A struct.
* Holds the X, Y, and angle of the robot in addition to the previous values.
*
* The robot name decides the name of the object that was created. For Example:
*
*       static scorpio_odom;
*/
struct harmony_odom_t
{
  long double x,          /**< __Unit:__ _inches_. The current global x coordiante. __Only__ used in the tracking task. */
              y,          /**< __Unit:__ _inches_. The current global y coordiante. __Only__ used in the tracking task. */
              theta,      /**< __Unit:__ _radians_. The current global orientation. __Only__ used in the tracking task. */
              prev_x,     /**< __Unit:__ _inches_. The previous global x coordiante. __Only__ used in the tracking task. */
              prev_y,     /**< __Unit:__ _inches_. The previous global y coordiante. __Only__ used in the tracking task. */
              prev_theta; /**< __Unit:__ _radians_. The previous global orientation. __Only__ used in the tracking task. */
}static scorpio_odom;
//If the top doesnt work use the bottom:
//static struct harmony_odom_t scorpio_odom;

/**
* @brief A struct.
* Holds all the values used from the encoders, in addition to the variables.
*
* The position of the encoder determines the name if the object. For Example:
*
*       struct leftQuad, rightQuad, sideQuad;
*/
struct harmony_encoder_t{
  long raw_val,         /**< __Unit:__ _encoder ticks_. The current value of the encoder. __Only__ used in the tracking task.*/
       prev_raw_val;    /**< __Unit:__ _encoder ticks_. The encoder value of the check before the current. __Only__ used in the tracking task. */
  long double delta_in, /**< __Unit:__ _inches_. The change in inches. __Only__ used in the tracking task. */
              total_in; /**< __Unit:__ _inches_. The total distance traveled. __Only__ used in the tracking task. */
}leftQuad, rightQuad, sideQuad;

/**
* @brief Global Variables.
* The variables accessible by all files implementing odometry.hpp
* that provide the x, y, and angle.
*/
long double odom_x_in,  /**< __Unit:__ _inches_. X coordinate. */
            odom_y_in,  /**< __Unit:__ _inches_. Y coordinate. */
            odom_theta; /**< __Unit:__ _radians_. Absolute orientation. */
/**
* @brief A method
* Sets up the variables for the tracking algorithm in addition to setting up
* the encoders for the tracking.
* @param left reverses the encoder.
* @param right reverses the encoder.
* @param side reverses the encoder.
* @param start_x the starting x position (in).
* @param start_y the starting y position (in).
* @param start_theta the starting angle (degrees).
*/
void initOdom(const bool left, const bool right, const bool side, const double start_x, const double start_y, const double start_theta);

/**
* @brief Tracking task.
* The tracking algorithm that keeps track of position in cartesian coordinates
* and the orientation in radians. Since radians are more precise and used by the
* internal computations the output also is in radians.
*
* Utilizes the structs made and the global variables.
*/
void tracking(void*);

#endif
