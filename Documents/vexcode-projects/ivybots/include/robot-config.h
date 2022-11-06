using namespace vex;

extern brain Brain;

// VEXcode devices
extern controller Controller1;
extern motor FlyWheelMotor;
extern motor_group MotorLeft;
extern motor_group MotorRight;
extern motor IntakeMotor;
extern motor Roller;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void  vexcodeInit( void );