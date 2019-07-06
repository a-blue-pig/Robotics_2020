/**
* @file harmonyAPI/harmonyAPI.h
* @brief Top level header file.
* ## Summary:
* A header file that decides whhich files to include or which ones to
* omit based on the c file.
*
* The file scans for definitions and then includes the correct Files
* in order to ensure that the functions can be called properly.
* For Example:
*
* opcontrol.cpp:
*
*     #define USING_TEST
*     #include "main.h"
*
* harmonyAPI.h:
*
*     #ifdef USING_TEST
*       #include "Modules/TestFolder/Test.cpp"
*     #endif
*/
#ifndef HARMONYAPI_INCLUDED //ensure it does not define twice
#define HARMONYAPI_INCLUDED

///Enable position tracking
#ifdef USING_ODOMETRY
  #include "Modules/Odometry/odometry.cpp"
#endif

///Enable port setup (motors)
#ifdef  USING_SETUP
  #include "Modules/Setup/setup.hpp"
#endif

#endif
