#include "robot-config.h"

//create variables and stuff
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



///////BEGIN AUTON PATHS///////

void skillsAuton() {
    driveReverse(6);
    wait(2, msec);
    MogoClamp.set(true);
    wait(2, msec);
    turnLeft(190);
    wait(2, msec);
    IntakeMotor.spin(forward);
    wait(2, msec);
    driveForward(35.5);
    wait(2, msec);
    turnRight(93);
    wait(2, msec);
    driveForward(24);
    wait(2, msec);
    turnRight(93);
    wait(2, msec);
    driveForward(24);
    wait(1, seconds);
    driveForward(10);
    wait(2, msec);
    driveReverse(10);
    wait(2, msec);
    turnRight(136);
    wait(2, seconds);
    IntakeMotor.stop();
    wait(2, msec);
    MogoClamp.set(false);
    driveReverse(16);
    wait(2, msec);
    driveForward(16);
    wait(2, msec);
    turnRight(145.75);
    wait(2, msec);
    driveReverse(68.5);
    wait(2, msec);
    MogoClamp.set(true);
    wait(2, msec);
    turnLeft(92);
    wait(2, msec);
    IntakeMotor.spin(forward);
    wait(2, msec);
    driveForward(24);
    wait(2, msec);
    turnLeft(92);
    wait(2, msec);
    driveForward(24);
    wait(2, msec);
    turnLeft(92);
    wait(2, msec);
    driveForward(24);
    wait(1, seconds);
    driveForward(12);
    wait(2, msec);
    driveReverse(12);
    wait(2, msec);
    turnLeft(145);
    wait(2, msec);
    MogoClamp.set(false);
    wait(2, msec);
    driveReverse(14);
    wait(2, msec);
    driveForward(14);
    wait(2, msec);

    //second half of skills auton
    turnLeft(45);
    wait(2, msec);
    driveForward(72);
    wait(2, msec);
    IntakeMotor.spinFor(forward, 2, turns);
    wait(2, msec);
    driveForward(24);
    wait(2, msec);
    IntakeMotor.spinFor(forward, 2, turns);
    wait(2, msec);
    turnLeft(92);
    wait(2, msec);
    driveReverse(48);
    wait(2, msec);
    MogoClamp.set(true);
    wait(2, msec);
    IntakeMotor.spin(forward);
    wait(2, msec);
    driveForward(48);
    wait(2, seconds);
    IntakeMotor.stop();
    wait(2, msec);
    turnLeft(135);
    wait(2, msec);
    MogoClamp.set(false);
    wait(2, msec);
    driveReverse(16);
    wait(2, msec);
    driveForward(16);
    wait(2, msec);
    turnRight(135);
    wait(2, msec);
    driveReverse(48);
    wait(2, msec);
    turnLeft(92);
    wait(2, msec);
    Drivetrain.driveFor(reverse, 24, inches, 25, rpm, false);
    wait(2, seconds);
    driveForward(10);
    wait(2, msec);
    turnRight(92);
    wait(2, msec);
    driveForward(24);
    wait(2, msec);
    MogoClamp.set(true);
    wait(2, msec);
    turnLeft(180);
    wait(2, msec);
    IntakeMotor.spin(forward);
    wait(2, msec);
    driveForward(36);
    wait(2, msec);
    turnRight(135);
    wait(2, msec);
    driveReverse(16);
}

void redNegativeAuton() {

}

void blueNegativeAuton() {

}

void redPositiveAuton() {

}

void bluePositiveAuton() {
  
}