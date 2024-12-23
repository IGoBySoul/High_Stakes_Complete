#include "robot-config.h"
#include "vex.h"
#include <algorithm>


// Wheel diameter in inches
const double wheelDiameter = 3.25;
const double wheelCircumference = wheelDiameter * M_PI;

// PID constants for driving
double kP_drive = 5;
double kI_drive = 0.1;
double kD_drive = 0.2;

// PID constants for turning
double kP_turn = 0.5;
double kI_turn = 0.0;
double kD_turn = 0.1;

// Function to drive straight
void PIDDrive(double targetDistance, double maxSpeed) {
  double error = 0;
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

  while (currentDistance < targetDistance) {
    // Calculate the average distance in inches
    double leftDistance = ((leftMotorA.position(degrees) + leftMotorB.position(degrees) + leftMotorC.position(degrees)) / 3.0) / 360.0 * wheelCircumference;
    double rightDistance = ((rightMotorA.position(degrees) + rightMotorB.position(degrees) + rightMotorC.position(degrees)) / 3.0) / 360.0 * wheelCircumference;
    currentDistance = (leftDistance + rightDistance) / 2.0;

    // PID calculations
    error = targetDistance - currentDistance;
    integral += error;
    derivative = error - prevError;
    prevError = error;

    double motorSpeed = (kP_drive * error) + (kI_drive * integral) + (kD_drive * derivative);

    // Limit motor speed
    if (motorSpeed > maxSpeed) motorSpeed = maxSpeed;
    if (motorSpeed < -maxSpeed) motorSpeed = -maxSpeed;

    // Set motor speeds
    LeftDrive.spin(forward, motorSpeed, percent);
    RightDrive.spin(forward, motorSpeed, percent);

    // Small delay to prevent CPU overload
    task::sleep(20);
  }

  // Stop the motors
  LeftDrive.stop();
  RightDrive.stop();
}

// Function to turn to a specific angle
void PIDTurn(double targetAngle, double maxSpeed) {
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
  LeftDrive.stop();
  RightDrive.stop();
}