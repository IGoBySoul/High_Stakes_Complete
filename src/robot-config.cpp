#include "vex.h"

using namespace vex;
using signature = vision::signature;
using code = vision::code;

// A global instance of brain used for printing to the V5 Brain screen
brain  Brain;

// VEXcode device constructors
//drivetrain
controller Controller = controller(primary);
motor leftMotorA = motor(PORT12, ratio6_1, true);
motor leftMotorB = motor(PORT13, ratio6_1, true);
motor leftMotorC = motor(PORT14, ratio6_1, true);
motor_group LeftDriveSmart = motor_group(leftMotorA, leftMotorB, leftMotorC);
motor rightMotorA = motor(PORT4, ratio6_1, false);
motor rightMotorB = motor(PORT5, ratio6_1, false);
motor rightMotorC = motor(PORT8, ratio6_1, false);
motor_group RightDriveSmart = motor_group(rightMotorA, rightMotorB, rightMotorC);
drivetrain Drivetrain = drivetrain(LeftDriveSmart, RightDriveSmart, 319.19, 295, 40, mm, 1);

//other devices
motor LBMech = motor(PORT19, ratio18_1, false);
motor IntakeMotor = motor(PORT18, ratio18_1, false);
optical Optical1 = optical(PORT17);

//pneumatics
digital_out Doinker = digital_out(Brain.ThreeWirePort.A);
digital_out MogoClamp = digital_out(Brain.ThreeWirePort.B);
digital_out IntakeLift = digital_out(Brain.ThreeWirePort.C);
digital_out Pneu4 = digital_out(Brain.ThreeWirePort.D);
digital_out Pneu5 = digital_out(Brain.ThreeWirePort.E);

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