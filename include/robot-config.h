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
extern motor_group LeftDrive;
extern motor_group RightDrive;
extern motor IntakeMotor;
extern motor LBMech;
extern optical opticalSensor;
extern digital_out Doinker;
extern digital_out MogoClamp;
extern digital_out Doinker2;
extern inertial inertialSensor;
extern rotation rotationSensor;


/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void  vexcodeInit( void );