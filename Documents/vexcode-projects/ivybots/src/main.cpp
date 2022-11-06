/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       VEX                                                       */
/*    Created:      Thu Sep 26 2019                                           */
/*    Description:  Competition Template                                      */
/*                                                                            */
/*----------------------------------------------------------------------------*/

// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// Controller1          controller                    
// FlyWheelMotor        motor         10              
// MotorLeft            motor_group   1, 2            
// MotorRight           motor_group   3, 4            
// IntakeMotor          motor         5               
// Roller               motor         6               
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"
#include "main.h"

using namespace vex;

// A global instance of competition
competition Competition;

// define your global instances of motors and other devices here

/*---------------------------------------------------------------------------*/
/*                          Pre-Autonomous Functions                         */
/*                                                                           */
/*  You may want to perform some actions before the competition starts.      */
/*  Do them in the following function.  You must return from this function   */
/*  or the autonomous and usercontrol tasks will not be started.  This       */
/*  function is only called once after the V5 has been powered on and        */
/*  not every time that the robot is disabled.                               */
/*---------------------------------------------------------------------------*/

void pre_auton(void) {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();

  // All activities that occur before the competition starts
  // Example: clearing encoders, setting servo positions, ...
}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              Autonomous Task                              */
/*                                                                           */
/*  This task is used to control your robot during the autonomous phase of   */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*-------------------;;;;;;;;;;--------------------------------------------------------*/

void autonomous(void) {
  
  MotorLeft.spin(forward,50,percent);
  MotorRight.spin(reverse,50,percent);
  wait(500, msec);
  MotorLeft.stop();
  MotorRight.stop();

  Roller.spin(forward,100,percent);
  wait(1000, msec);
  Roller.stop();


}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              User Control Task                            */
/*                                                                           */
/*  This task is used to control your robot during the user control phase of */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/







void usercontrol(void) {

  Controller1.ButtonB.pressed(intakepress);
  Controller1.ButtonY.pressed(rollerpress);
  Controller1.ButtonX.pressed(intakerevpress);
  // User control code here, inside the loop
  while (1) {
    // This is the main execution loop for the user control program.
    // Each time through the loop your program should update motor + servo
    // values based on feedback from the joysticks.

    // ........................................................................
    // Insert user code here. This is where you use the joystick values to
    // update your motors, etc.
    // ........................................................................

    double motorforwardaxis = Controller1.Axis1.position(percent);
    double motorturnaxis = Controller1.Axis3.position(percent);


    double motorleftval = motorforwardaxis + motorturnaxis;
    double motorrightval = motorforwardaxis - motorturnaxis;


    MotorLeft.spin(fwd, motorleftval, percent);
    MotorRight.spin(fwd, motorrightval, percent);

    //void vex.IntakeMotor.spin;
  


    

    if (intakeon == true) {
      IntakeMotor.spin(reverse);
    }

    else {
      IntakeMotor.stop();
    }

    if(intakeon) {
      if (intakereverse) {
        IntakeMotor.spin(reverse);
      } else {
        IntakeMotor.spin(forward);
      }

    } else {
      IntakeMotor.stop();
    }

     if (rolleron == true) {
      Roller.spin(forward, 100, percent);
    }

    else {
      Roller.stop();
    }

    //if (intakereverse == true) {
     // IntakeMotor.spin(reverse);
   // } 

    // if (intakereverse == false) {
     // IntakeMotor.stop();
   // }
   
   
    
    Brain.Screen.clearScreen();
    Brain.Screen.setCursor(1,1);
    Brain.Screen.print("MotorLeft: %f", motorleftval);
    Brain.Screen.newLine();
    Brain.Screen.print("MotorRight: %f", motorrightval);
    Brain.Screen.newLine();
    Brain.Screen.print(intakeon);
    



    wait(20, msec); // Sleep the task for a short amount of time to
                    // prevent wasted resources.
  }
}

//
// Main will set up the competition functions and callbacks.
//
int main() {
  // Set up callbacks for autonomous and driver control periods.
  Competition.autonomous(autonomous);
  Competition.drivercontrol(usercontrol);

  // Run the pre-autonomous function.
  pre_auton();

  // Prevent main from exiting with an infinite loop.
  while (true) {
    wait(100, msec);
  }
}
