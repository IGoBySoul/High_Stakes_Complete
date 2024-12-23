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

// PID Controller Variables
double kP_drive = 0.5;  // Proportional gain for forward movement
double kI_drive = 0.0;  // Integral gain for forward movement
double kD_drive = 0.1;  // Derivative gain for forward movement

double kP_turn = 0.3;   // Proportional gain for turning
double kI_turn = 0.0;   // Integral gain for turning
double kD_turn = 0.05;  // Derivative gain for turning

double targetDistance = 1000;  // Target distance in encoder counts (change as needed)
double targetAngle = 90;       // Target angle in degrees (change as needed)
double error, prevError = 0, integral = 0, derivative;

// Forward Movement PID
double pidDriveControl(double setpoint, double current) {
  error = setpoint - current;
  integral += error;
  derivative = error - prevError;
  
  double output = (kP_drive * error) + (kI_drive * integral) + (kD_drive * derivative);
  prevError = error;
  return output;
}

// Turning PID
double pidTurnControl(double setpoint, double current) {
  error = setpoint - current;
  integral += error;
  derivative = error - prevError;
  
  double output = (kP_turn * error) + (kI_turn * integral) + (kD_turn * derivative);
  prevError = error;
  return output;
}

// Drive Forward to a distance
void PIDDrive(double distance) {
  while (true) {
    double currentPosition = inertialSensor.rotation();  // Get current rotation
    double output = pidDriveControl(distance, currentPosition);  // Calculate PID output
    
    LeftDrive.spin(vex::directionType::fwd, output, vex::voltageUnits::mV);
    RightDrive.spin(vex::directionType::fwd, output, vex::voltageUnits::mV);
    
    // Check if the robot is close enough to the target distance
    if (fabs(targetDistance - currentPosition) < 10) {
      LeftDrive.stop();
      RightDrive.stop();
      break;  // Exit loop when close to target
    }
    
    vex::task::sleep(20);  // Sleep for a short delay
  }
}

// Turn to a specific angle
void PIDTurn(double angle) {
  while (true) {
    double currentAngle = inertialSensor.rotation();  // Get current rotation
    double output = pidTurnControl(angle, currentAngle);  // Calculate PID output
    
    LeftDrive.spin(vex::directionType::fwd, -output, vex::voltageUnits::mV);  // Reverse motor on one side to turn
    RightDrive.spin(vex::directionType::fwd, output, vex::voltageUnits::mV);
    
    // Check if the robot is close enough to the target angle
    if (fabs(targetAngle - currentAngle) < 5) {
      LeftDrive.stop();
      RightDrive.stop();
      break;  // Exit loop when close to target
    }
    
    vex::task::sleep(20);  // Sleep for a short delay
  }
}


///////AUTON PATHS///////

void skillsAuton() {
  PIDDrive(10);
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