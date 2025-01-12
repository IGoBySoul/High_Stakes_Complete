#include "functions.h"

void skillsAuton() {

}

void redNegativeAuton() {
  
}

void blueNegativeAuton() {
}

void redPositiveAuton() {
}

void bluePositiveAuton() {
  Drivetrain.driveFor(forward, 60, inches, 400, rpm, false);
  wait(300, msec);
  IntakeMotor.spin(forward);
  Doinker.set(true);
  wait(600, msec);
  Doinker.set(false);
  IntakeMotor.stop();
  Drivetrain.driveFor(reverse, 24, inches, 400, rpm);
}

void redNegativeElimsAuto() {
}

void blueNegativeElimsAuto() {
}

void redPositiveElimsAuto() {
}

void bluePositiveElimsAuto() {
}