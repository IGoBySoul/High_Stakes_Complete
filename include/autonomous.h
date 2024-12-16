#include "robot-config.h"

//create variables and stuff
int liftMacroVar = 1;

double driveError = 162.5; //set to 90% for 10% overshoot and 110% for 10% undershoot
double turnError = 162.5; //same as this ^^^

double moveActual;
double turnActual;

//error control
void driveForward (double moveDistance) {
  moveActual=(((moveDistance) / 100) * driveError);
  Drivetrain.driveFor(forward, (moveActual), inches);
}
void driveReverse (double moveDistance) {
  moveActual=(((moveDistance) / 100) * driveError);
  Drivetrain.driveFor(reverse, (moveActual), inches);
}
void turnRight (double turnDistance) {
  turnActual=(((turnDistance) / 100) * turnError);
  Drivetrain.turnFor(right, (turnActual), degrees);
}
void turnLeft (double turnDistance) {
  turnActual=(((turnDistance) / 100) * turnError);
  Drivetrain.turnFor(left, (turnActual), degrees);
}


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