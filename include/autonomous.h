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

// Global variables for PID
double error = 0;
double previousError = 0;
double integral = 0;
double derivative = 0;

// Target position (x, y) in mm
double targetX = 0;
double targetY = 0;

// Position tracking
double currentX = 0;
double currentY = 0;
double currentHeading = 0;

double lastHeading = 0;

double degreesToRadians(double degrees) {
    return degrees * PI / 180.0;
}

void updatePosition() {
    // Get the current heading and calculate change in heading
    currentHeading = inertialSensor.heading();
    double deltaHeading = currentHeading - lastHeading;

    // Normalize deltaHeading to the range -180 to 180 degrees
    if (deltaHeading > 180) {
        deltaHeading -= 360;
    } else if (deltaHeading < -180) {
        deltaHeading += 360;
    }

    // Calculate distance moved based on left and right motor velocities
    double distanceMoved = (LeftDrive.velocity(percent) + RightDrive.velocity(percent)) / 2.0 * 0.02 * 10; // Average velocity * time

    // Update X and Y positions
    currentX += distanceMoved * cos(degreesToRadians(currentHeading));
    currentY += distanceMoved * sin(degreesToRadians(currentHeading));

    // Update lastHeading
    lastHeading = currentHeading;
}

void PIDMoveTo(double targetXPos, double targetYPos, double timeout) {
    // Set the target position
    targetX = targetXPos;
    targetY = targetYPos;

    // Timer for timeout
    timer timer;
    timer.reset();

    while (true) {
        // Update the robot's position
        updatePosition();

        // Calculate the distance and angle to the target
        double deltaX = targetX - currentX;
        double deltaY = targetY - currentY;
        double distanceToTarget = sqrt(deltaX * deltaX + deltaY * deltaY);
        double angleToTarget = atan2(deltaY, deltaX) * 180.0 / PI;

        // Calculate heading error
        double headingError = angleToTarget - currentHeading;

        // Normalize heading error to -180 to 180 degrees
        if (headingError > 180) {
            headingError -= 360;
        } else if (headingError < -180) {
            headingError += 360;
        }

        // PID for heading
        double turnPower = (kP * headingError) + (kI * integral) + (kD * derivative);
        turnPower = std::max(-50.0, std::min(turnPower, 50.0));

        // PID for forward movement
        double forwardPower = (kP * distanceToTarget);
        forwardPower = std::max(-100.0, std::min(forwardPower, 100.0));

        // Apply motor power
        LeftDrive.spin(forward, forwardPower - turnPower, percent);
        RightDrive.spin(forward, forwardPower + turnPower, percent);

        // Exit condition: if within tolerance or timeout exceeded
        if (distanceToTarget < 10 || timer.time() > timeout * 1000) {
            break;
        }

        // Small delay for control loop
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