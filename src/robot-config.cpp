#include "vex.h"

using namespace vex;
using signature = vision::signature;
using code = vision::code;

// A global instance of brain used for printing to the V5 Brain screen
brain  Brain;

// VEXcode device constructors
//drivetrain
controller Controller = controller(primary);
motor leftMotorA = motor(PORT7, ratio6_1, true);
motor leftMotorB = motor(PORT8, ratio6_1, true);
motor leftMotorC = motor(PORT10, ratio6_1, true);
motor_group LeftDrive = motor_group(leftMotorA, leftMotorB, leftMotorC);
motor rightMotorA = motor(PORT14, ratio6_1, false);
motor rightMotorB = motor(PORT4, ratio6_1, false);
motor rightMotorC = motor(PORT5, ratio6_1, false);
motor_group RightDrive = motor_group(rightMotorA, rightMotorB, rightMotorC);
drivetrain Drivetrain = drivetrain(LeftDrive, RightDrive, 319.19, 295, 40, mm, 1);

//other devices
motor LBMech = motor(PORT12, ratio36_1, false);
motor IntakeMotor = motor(PORT18, ratio6_1, true);
inertial inertialSensor(PORT9);
optical opticalSensor(PORT10);
rotation rotationSensor(PORT13);

//pneumatics
digital_out MogoClamp = digital_out(Brain.ThreeWirePort.A);
digital_out Doinker = digital_out(Brain.ThreeWirePort.B);
digital_out Doinker2 = digital_out(Brain.ThreeWirePort.C);

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