#include "vex.h"

using namespace vex;
using signature = vision::signature;
using code = vision::code;

// A global instance of brain used for printing to the V5 Brain screen
brain  Brain;

// VEXcode device constructors
controller Controller1 = controller(primary);
motor FlyWheelMotor = motor(PORT10, ratio6_1, true);
motor MotorLeftMotorA = motor(PORT1, ratio18_1, true);
motor MotorLeftMotorB = motor(PORT2, ratio18_1, true);
motor_group MotorLeft = motor_group(MotorLeftMotorA, MotorLeftMotorB);
motor MotorRightMotorA = motor(PORT3, ratio18_1, true);
motor MotorRightMotorB = motor(PORT4, ratio18_1, true);
motor_group MotorRight = motor_group(MotorRightMotorA, MotorRightMotorB);
motor IntakeMotor = motor(PORT5, ratio18_1, false);
motor Roller = motor(PORT6, ratio18_1, false);

// VEXcode generated functions
// define variable for remote controller enable/disable
bool RemoteControlCodeEnabled = true;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void vexcodeInit( void ) {
  // nothing to initialize
}