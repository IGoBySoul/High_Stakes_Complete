#include "robot-config.h"
#include "vex.h"
#include <algorithm>

//create variables and stuff
int liftMacroVar = 1;
bool colorSortBool = true;
int teamColor = 1; //1 == red, 2 == blue

void LBSpinUp(double targetAngle) {
  LBMech.spin(reverse, 100, percent);
  waitUntil(rotationSensor.position(degrees) >= targetAngle);
  LBMech.stop();
}

void LBSpinDown(double targetAngle) {
  LBMech.spin(forward, 100, percent);
  waitUntil(rotationSensor.position(degrees) <= targetAngle);
  LBMech.stop(); 
}

void liftMacro() {
  if (liftMacroVar == 1) {
      liftMacroVar = 2;
      LBSpinUp(18);
  } else if (liftMacroVar == 2) {
    liftMacroVar = 3;
    LBSpinUp(135);
  } else if (liftMacroVar == 3) {
    liftMacroVar = 1;
    LBSpinDown(5);
  }
}

void toggleSorting() {
  if (colorSortBool == true) {
    colorSortBool = false;
  } else if (colorSortBool == false) {
    colorSortBool = true;
  }
}

void colorSort(){
  if (colorSortBool == true) {
    Controller.Screen.clearScreen();
    Controller.Screen.setCursor(1, 1);
    Controller.Screen.print("Sorting Enabled!");
    if (teamColor == 1 /*red*/) {
      if (opticalSensor.color() == blue && opticalSensor.isNearObject()){
        LBSpinUp(15);
        wait(200, msec);
        LBSpinDown(15);
      }
    } else if (teamColor == 2 /*blue*/) {
      if (opticalSensor.color() == red && opticalSensor.isNearObject()){
        LBSpinUp(15);
        wait(200, msec);
        LBSpinDown(15);
      }
    }
  } else if (colorSortBool == false) {
    Controller.Screen.clearScreen();
    Controller.Screen.setCursor(1, 1);
    Controller.Screen.print("Sorting Disabled!");
  }
}

///PID///

// Define constants for PID control
const double kP = 0.5; // Proportional gain
const double kI = 0.01; // Integral gain
const double kD = 0.1; // Derivative gain
const double PI = 3.141592653589793; // Pi constant
const double SPEED_FACTOR = 0.50;

void PIDDrive(double targetDistance, double timeout) {
    // Timer for timeout
    timer timer;
    timer.reset();

    double currentDistance = 0;
    double previousError = 0;
    double integral = 0;
    double startAngle = inertialSensor.rotation(); // Initial angle

    while (true) {
        // Calculate error
        double error = targetDistance - currentDistance;

        // Integral and derivative
        integral += error;
        double derivative = error - previousError;

        // PID calculation
        double voltage = (kP * error) + (kI * integral) + (kD * derivative);
        voltage = std::max(-12.0, std::min(voltage, 12.0)); // Clamp voltage to -12V to 12V
        voltage *= SPEED_FACTOR; // Scale voltage by speed factor

        // Apply voltage to motors
        LeftDrive.spin(forward, voltage, voltageUnits::volt);
        RightDrive.spin(forward, voltage, voltageUnits::volt);

        // Update current distance based on inertial sensor
        double currentAngle = inertialSensor.rotation();
        double deltaAngle = currentAngle - startAngle;
        currentDistance = deltaAngle / 360.0 * targetDistance; // Calculate distance using inertial sensor rotation

        // Exit conditions
        if (fabs(error) < 0.5 || timer.time() > timeout * 1000) {
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
        double voltage = (kP * error) + (kI * integral) + (kD * derivative);
        voltage = std::max(-6.0, std::min(voltage, 6.0)); // Clamp voltage to -6V to 6V
        voltage *= SPEED_FACTOR; // Scale voltage by speed factor

        // Apply voltage to motors
        LeftDrive.spin(forward, -voltage, voltageUnits::volt);
        RightDrive.spin(forward, voltage, voltageUnits::volt);

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
  PIDDrive(10, 2);
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