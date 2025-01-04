#include "robot-config.h"
#include "vex.h"
#include <algorithm>

const double PIConstant = 3.1415926535;
// Wheel diameter in inches
const double wheelDiameter = 3.25;
const double wheelCircumference = wheelDiameter * PIConstant;

// PID constants for driving
double kP_drive = 1.0;
double kI_drive = 0.0;
double kD_drive = 0.0;

// PID constants for turning
double kP_turn = 1.0;
double kI_turn = 0.0;
double kD_turn = 0.0;

// Tolerance for stopping the loop
const double tolerance = 0.2; // Adjust as needed

// Maximum integral term to prevent windup
const double maxIntegral = 100000.0; // Adjust as needed

// Function to drive straight
void DrivePID(double targetDistance, double maxSpeed) {
  double error = targetDistance;
  double prevError = 0;
  double integral = 0;
  double derivative = 0;
  double currentDistance = 0;

  // Reset sensors
  inertialSensor.resetRotation();
  leftMotorA.resetPosition();
  leftMotorB.resetPosition();
  leftMotorC.resetPosition();
  rightMotorA.resetPosition();
  rightMotorB.resetPosition();
  rightMotorC.resetPosition();

  while (fabs(error) > tolerance) {
    // Calculate the average distance in inches
    double leftDistance = ((leftMotorA.position(degrees) + leftMotorB.position(degrees) + leftMotorC.position(degrees)) / 3.0) / 360.0 * wheelCircumference;
    double rightDistance = ((rightMotorA.position(degrees) + rightMotorB.position(degrees) + rightMotorC.position(degrees)) / 3.0) / 360.0 * wheelCircumference;
    currentDistance = (leftDistance + rightDistance) / 2.0;

    // PID calculations
    error = targetDistance - currentDistance;
    integral += error;

    // Bound the integral to prevent windup
    if (integral > maxIntegral) integral = maxIntegral;
    if (integral < -maxIntegral) integral = -maxIntegral;

    derivative = error - prevError;
    prevError = error;

    // Print debug information
    Brain.Screen.printAt(10, 40, "Error: %f", error);
    Brain.Screen.printAt(10, 60, "Integral: %f", integral);
    Brain.Screen.printAt(10, 80, "Derivative: %f", derivative);
    Brain.Screen.printAt(10, 100, "Current Distance: %f", currentDistance);

    double motorSpeed = (kP_drive * error) + (kI_drive * integral) + (kD_drive * derivative);

    // Limit motor speed to the maxSpeed
    if (motorSpeed > maxSpeed) motorSpeed = maxSpeed;
    if (motorSpeed < -maxSpeed) motorSpeed = -maxSpeed;

    // Correction to avoid drifting
    double correction = (leftDistance - rightDistance) * 0.1; // Adjust the correction factor as needed

    // Set motor speeds with correction
    LeftDrive.spin(forward, motorSpeed - correction, percent);
    RightDrive.spin(forward, motorSpeed + correction, percent);

    // Small delay to prevent CPU overload
    task::sleep(20);
  }

  // Stop the motors
  LeftDrive.stop(brakeType::brake);
  RightDrive.stop(brakeType::brake);
}


// Function to turn to a specific angle
void TurnPID(double targetAngle, double maxSpeed) {
  double error = 0;
  double prevError = 0;
  double integral = 0;
  double derivative = 0;
  double currentAngle = 0;

  // Reset the inertial sensor
  inertialSensor.resetRotation();

  while (fabs(currentAngle - targetAngle) > 1) {
    // Get the current angle
    currentAngle = inertialSensor.rotation(degrees);

    // PID calculations
    error = targetAngle - currentAngle;
    integral += error;
    derivative = error - prevError;
    prevError = error;

    double motorSpeed = (kP_turn * error) + (kI_turn * integral) + (kD_turn * derivative);

    // Limit motor speed
    if (motorSpeed > maxSpeed) motorSpeed = maxSpeed;
    if (motorSpeed < -maxSpeed) motorSpeed = -maxSpeed;

    // Set motor speeds for turning
    LeftDrive.spin(forward, motorSpeed, percent);
    RightDrive.spin(reverse, motorSpeed, percent);

    // Small delay to prevent CPU overload
    task::sleep(20);
  }

  // Stop the motors
  LeftDrive.stop(brakeType::brake);
  RightDrive.stop(brakeType::brake);
}