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

void skillsAuton() { //w skills?
  
  //START RED PATH//

  IntakeMotor.spinFor(forward, 1, seconds); //score on alliance stake
  wait(2, msec);
  IntakeMotor.spinFor(reverse, 0.25, seconds);
  wait(2, msec);
  driveForward(9);
  wait(2, msec);

  turnLeft(95); //grabs mogo
  wait(2, msec);
  driveReverse(24);
  wait(2, msec);
  MogoClamp.set(true);
  wait(2, msec);

  turnRight(93); //intakes first ring
  wait(2, msec);
  IntakeMotor.spin(forward);
  wait(2, msec);
  driveForward(24);
  wait(2, msec);

  turnRight(93); //second ring
  wait(2, msec);
  driveForward(24);
  wait(2, msec);

  turnRight(93); //scores 5th ring
  wait(2, msec);
  IntakeMotor.spin(forward);
  wait(2, msec);
  driveForward(24);
  wait(500, msec);

  driveForward(8); //intakes and scores 6th ring
  wait(2, msec);
  driveReverse(16);
  wait(2, msec);
  
  turnLeft(46); //intakes and scores 7th ring
  wait(2, msec);
  driveForward(12);
  wait(1000, msec);

  turnLeft(180); //puts mogo in corner
  wait(2, msec);
  IntakeMotor.stop();
  wait(2, msec);
  Drivetrain.drive(reverse);
  wait(1500, msec);
  Drivetrain.stop();
  wait(2, msec);
  MogoClamp.set(false);
  wait(2, msec);
  driveForward(16);
  wait(2, msec);

  turnLeft(45); //allign with wall
  wait(2, msec);
  Drivetrain.drive(reverse);
  wait(1500, msec);
  Drivetrain.stop();
  wait(2, msec);
  driveForward(19);
  wait(2, msec);

  //START GREEN PATH//

  
  turnRight(195); //grabs green mogo
  wait(2, msec);
  driveReverse(72);
  wait(2, msec);
  MogoClamp.set(true);
  wait(2, msec);

  turnRight(195);
  wait(2, msec);
  IntakeMotor.spin(forward);
  wait(2, msec);
  driveForward(24);
  wait(2, msec);

  driveForward(12);
  wait(2, msec);
  turnRight(90);
  wait(2, msec);
  Drivetrain.drive(reverse);
  wait(1000, msec);
  Drivetrain.stop();
  wait(2, msec);
  MogoClamp.set(false);

}

void redNegativeAuton() { //probably works?
  driveReverse(24); //grabs mogo
  wait(2, msec);
  MogoClamp.set(true);
  wait(2, msec);
  
  IntakeMotor.spin(forward); //scores preload and first ring
  wait(2, msec);
  turnRight(145);
  wait(2, msec);
  driveForward(24.25);
  wait(500, msec);
  driveReverse(12.25);
  wait(2, msec);
  driveForward(3);
  wait(2, msec);
  driveReverse(10);
  wait(2, msec);

  turnLeft(50); //scores second ring
  wait(2, msec);
  driveForward(24);
  wait(500, msec);
  driveReverse(1);
  wait(2, msec);

  turnRight(80); //scores third ring
  wait(2, msec);
  driveForward(11.5);
  wait(500, msec);
  driveReverse(6);
  wait(2, msec);
  driveForward(3);
  wait(2, msec);
  driveReverse(8.5);
  wait(2, msec);

  turnRight(110); //drives to touch ladder
  wait(2, msec);
  driveForward(44);
  wait(2, msec);
  IntakeMotor.stop();
}

void blueNegativeAuton() { //works AMAZINGLY <3
  driveReverse(24); //grabs mogo
  wait(2, msec);
  MogoClamp.set(true);
  wait(2, msec);
  
  IntakeMotor.spin(forward); //scores preload and first ring
  wait(2, msec);
  turnLeft(145);
  wait(2, msec);
  driveForward(24.25);
  wait(500, msec);
  driveReverse(12.25);
  wait(2, msec);
  driveForward(3);
  wait(2, msec);
  driveReverse(6);
  wait(2, msec);

  turnRight(50); //scores second ring
  wait(2, msec);
  driveForward(19);
  wait(500, msec);
  driveReverse(1);
  wait(2, msec);

  turnLeft(80); //scores third ring
  wait(2, msec);
  driveForward(13.5);
  wait(500, msec);
  driveReverse(10);
  wait(2, msec);
  driveForward(3);
  wait(2, msec);
  driveReverse(6.5);
  wait(2, msec);

  turnLeft(120); //drives to touch ladder
  wait(2, msec);
  driveForward(44);
  wait(2, msec);
  IntakeMotor.stop();
}

void redPositiveAuton() { //2 ring mid ahh auton
  driveReverse(30);
  wait(2, msec);
  MogoClamp.set(true);
  wait(2, msec);

  turnLeft(90);
  wait(2, msec);
  IntakeMotor.spin(forward);
  driveForward(26);
  wait(500, msec);
  driveReverse(26);
  IntakeMotor.stop();
  wait(2, msec);

  turnLeft(180);
  wait(2, msec);
  driveForward(24);
  wait(2, msec);
}

void bluePositiveAuton() { //another 2 ring mid ahh auton
  driveReverse(30);
  wait(2, msec);
  MogoClamp.set(true);
  wait(2, msec);

  turnRight(90);
  wait(2, msec);
  IntakeMotor.spin(forward);
  driveForward(26);
  wait(500, msec);
  driveReverse(26);
  IntakeMotor.stop();
  wait(2, msec);

  turnRight(180);
  wait(2, msec);
  driveForward(24);
  wait(2, msec);
}

void redNegativeElimsAuto() { //probably works? mostly
  driveReverse(24); //grabs mogo
  wait(2, msec);
  MogoClamp.set(true);
  wait(2, msec);
  
  IntakeMotor.spin(forward); //scores preload and first ring
  wait(2, msec);
  turnRight(145);
  wait(2, msec);
  driveForward(24.25);
  wait(500, msec);
  driveReverse(12.25);
  wait(2, msec);
  driveForward(3);
  wait(2, msec);
  driveReverse(6);
  wait(2, msec);

  turnLeft(50); //scores second ring
  wait(2, msec);
  driveForward(19);
  wait(500, msec);
  driveReverse(1);
  wait(2, msec);

  turnRight(80); //scores third ring
  wait(2, msec);
  driveForward(13.5);
  wait(500, msec);
  driveReverse(10);
  wait(2, msec);
  driveForward(3);
  wait(2, msec);
  driveReverse(6.5);
  wait(2, msec);
}

void blueNegativeElimsAuto() { //works mostly
  driveReverse(24); //grabs mogo
  wait(2, msec);
  MogoClamp.set(true);
  wait(2, msec);
  
  IntakeMotor.spin(forward); //scores preload and first ring
  wait(2, msec);
  turnLeft(145);
  wait(2, msec);
  driveForward(24.25);
  wait(500, msec);
  driveReverse(12.25);
  wait(2, msec);
  driveForward(3);
  wait(2, msec);
  driveReverse(6);
  wait(2, msec);

  turnRight(50); //scores second ring
  wait(2, msec);
  driveForward(19);
  wait(500, msec);
  driveReverse(1);
  wait(2, msec);

  turnLeft(80); //scores third ring
  wait(2, msec);
  driveForward(13.5);
  wait(500, msec);
  driveReverse(10);
  wait(2, msec);
  driveForward(3);
  wait(2, msec);
  driveReverse(6.5);
  wait(2, msec);
}

void redPositiveElimsAuto() { //works decent
  driveReverse(30);
  wait(2, msec);
  MogoClamp.set(true);
  wait(2, msec);

  turnLeft(90);
  wait(2, msec);
  IntakeMotor.spin(forward);
  driveForward(26);
  wait(500, msec);
  driveReverse(26);
  IntakeMotor.stop();
  wait(2, msec);

  turnLeft(90);
  wait(2, msec);
  driveForward(24);
  wait(2, msec);
}

void bluePositiveElimsAuto() { //works decent
  driveReverse(30);
  wait(2, msec);
  MogoClamp.set(true);
  wait(2, msec);

  turnRight(90);
  wait(2, msec);
  IntakeMotor.spin(forward);
  driveForward(26);
  wait(500, msec);
  driveReverse(26);
  IntakeMotor.stop();
  wait(2, msec);

  turnRight(90);
  wait(2, msec);
  driveForward(24);
}