#include "robot-config.h"
#include "vex.h"
#include <algorithm>

//create variables and stuff
int liftMacroVar = 1;

void liftMacro() {
  if (liftMacroVar == 1) {
      liftMacroVar = 2;
      LBMech.spinTo(-45, degrees);
  } else if (liftMacroVar == 2) {
    liftMacroVar = 3;
    LBMech.spinTo(-275, degrees);
  } else if (liftMacroVar == 3) {
    liftMacroVar = 1;
    LBMech.spinTo(0, degrees);
  }
}

///PID///

// Define constants for PID control
const double kP = 0.5; // Proportional gain
const double kI = 0.01; // Integral gain
const double kD = 0.1; // Derivative gain
const double PI = 3.141592653589793; // Pi constant

double degreesToRadians(double degrees) {
    return degrees * PI / 180.0;
}

void PIDDrive(double targetDistance, double timeout) {
    // Timer for timeout
    timer timer;
    timer.reset();

    double currentDistance = 0;
    double previousError = 0;
    double integral = 0;

    while (true) {
        // Calculate error
        double error = targetDistance - currentDistance;

        // Integral and derivative
        integral += error;
        double derivative = error - previousError;

        // PID calculation
        double power = (kP * error) + (kI * integral) + (kD * derivative);
        power = std::max(-100.0, std::min(power, 100.0));

        // Apply power to motors
        LeftDrive.spin(forward, power, percent);
        RightDrive.spin(forward, power, percent);

        // Simulate updating the distance (replace with actual sensor feedback in practice)
        currentDistance += (LeftDrive.velocity(percent) + RightDrive.velocity(percent)) / 2.0 * 0.02 * 10; // Average velocity * time

        // Exit conditions
        if (fabs(error) < 10 || timer.time() > timeout * 1000) {
            break;
        }

        previousError = error;

        wait(20, msec);
    }

    // Stop motors
    LeftDrive.stop();
    RightDrive.stop();
}

void PIDTurn(double targetAngle, double timeout) {
    // Timer for timeout
    timer timer;
    timer.reset();

    double currentAngle = inertialSensor.heading();
    double previousError = 0;
    double integral = 0;

    while (true) {
        // Calculate error
        double error = targetAngle - currentAngle;

        // Normalize error to -180 to 180 degrees
        if (error > 180) {
            error -= 360;
        } else if (error < -180) {
            error += 360;
        }

        // Integral and derivative
        integral += error;
        double derivative = error - previousError;

        // PID calculation
        double power = (kP * error) + (kI * integral) + (kD * derivative);
        power = std::max(-50.0, std::min(power, 50.0));

        // Apply power to motors
        LeftDrive.spin(forward, -power, percent);
        RightDrive.spin(forward, power, percent);

        // Update current angle
        currentAngle = inertialSensor.heading();

        // Exit conditions
        if (fabs(error) < 1 || timer.time() > timeout * 1000) {
            break;
        }

        previousError = error;

        wait(20, msec);
    }

    // Stop motors
    LeftDrive.stop();
    RightDrive.stop();
}

///////AUTON PATHS///////

void skillsAuton() {

}

void redNegativeAuton() {
  
}

void blueNegativeAuton() {

}

void redPositiveAuton() {

}

void bluePositiveAuton() {

}

void redNegativeElimsAuto() {

}

void blueNegativeElimsAuto() {

}

void redPositiveElimsAuto() {

}

void bluePositiveElimsAuto() {

}