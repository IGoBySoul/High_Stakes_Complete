using namespace vex;

extern brain Brain;

// VEXcode devices
extern controller Controller;
extern drivetrain Drivetrain;
extern motor leftMotorA;
extern motor leftMotorB;
extern motor leftMotorC;
extern motor rightMotorA;
extern motor rightMotorB;
extern motor rightMotorC;
extern motor_group LeftDriveSmart;
extern motor_group RightDriveSmart;
extern motor IntakeMotor;
extern motor LBMech;
extern optical Optical1;
extern digital_out Doinker;
extern digital_out MogoClamp;
extern digital_out IntakeLift;
extern digital_out Pneu4;
extern digital_out Pneu5;



/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void  vexcodeInit( void );