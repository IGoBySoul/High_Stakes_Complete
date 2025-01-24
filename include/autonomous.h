#include "functions.h"

void skillsAuton() {

  //BLACK  PATH//

  IntakeMotor.spinFor(forward, 1, seconds);
  DrivePID(12.25, 50);

  TurnPID(-88.75, 35);
  DrivePID(-24, 25);
  MogoClamp.set(true);
  wait(300, msec);

  Drivetrain.turnFor(111, deg);
  IntakeMotor.spin(forward);
  DrivePID(24, 50);
  Drivetrain.turnFor(95, degrees);
  wait(750, msec);

  DrivePID(42.5, 50);
  liftMacro();
  wait(2000, msec);
  IntakeMotor.stop();
  TurnPID(40, 30);
  Drivetrain.drive(forward, 200, rpm);
  wait(1000, msec);
  Drivetrain.stop();
  liftMacro();
  wait(750, msec);
  DrivePID(-16, 50);
  liftMacro();

  TurnPID(88, 35);
  IntakeMotor.spin(forward);
  DrivePID(48, 50);
  wait(1500, msec);

  DrivePID(12, 35);
  wait(500, msec);
  TurnPID(-45, 35);
  DrivePID(-10, 50);
  TurnPID(-45, 35);
  DrivePID(24, 50);
  DrivePID(-12, 50);

  TurnPID(-135, 35);
  wait(500, msec);
  IntakeMotor.stop();
  DrivePID(-16, 50);
  MogoClamp.set(false);
  wait(200, msec);
  DrivePID(16, 50);

  TurnPID(-45, 35);
  Drivetrain.drive(reverse, 200, rpm);
  wait(1250, msec);
  Drivetrain.stop();
  DrivePID(16, 50);
  TurnPID(45, 35);

  //RED PATH//

  DrivePID(34, 50);
  IntakeMotor.spin(forward);
  DrivePID(34, 50);
  wait(750, msec);
  IntakeMotor.stop();

  TurnPID(70, 35);
  DrivePID(53, 50);
  MogoClamp.set(true);
  wait(250, msec);

  TurnPID(-20, 35);
  IntakeMotor.spin(forward);
  DrivePID(24, 50);
  wait(1000, msec);

  TurnPID(-56, 35);
  liftMacro();
  DrivePID(-43, 50);
  wait(1250, msec);
  TurnPID(-34, 35);
  IntakeMotor.stop();
  Drivetrain.drive(forward);
  wait(1000, msec);
  Drivetrain.stop();
  liftMacro();
  wait(1500, msec);
  DrivePID(-16, 50);
  liftMacro();

  TurnPID(-90, 35);
  IntakeMotor.spin(forward);
  DrivePID(48, 50);
  wait(1500, msec);

  DrivePID(8, 35);
  TurnPID(45, 35);
  DrivePID(-12, 35);
  TurnPID(45, 35);
  DrivePID(20, 50);
  DrivePID(-10, 50);
  wait(1000, msec);

  TurnPID(135, 35);
  IntakeMotor.stop();
  DrivePID(-16, 50);
  MogoClamp.set(false);
  wait(250, msec);
  DrivePID(16, 50);
  
  TurnPID(-45, 35);
  Drivetrain.drive(reverse);
  wait(750, msec);
  Drivetrain.stop();
  DrivePID(16, 50);

  //GREEN PATH//

}

void redNegativeAuton() {
  
}

void blueNegativeAuton() {
  DrivePID(-24, 50);
  MogoClamp.set(true);
  wait(200, msec);
  IntakeMotor.spin(forward);
  TurnPID(-135, 27.5);
  DrivePID(21, 35);
  TurnPID(27.5, 25);
  wait(400, msec);
  DrivePID(7.5, 35);
  wait(250, msec);
  DrivePID(-10, 35);
  TurnPID(-20, 25);
  DrivePID(-7, 35);
  TurnPID(55, 25);
  DrivePID(18, 35);
  TurnPID(155, 35);
  wait(1000, msec);
  Drivetrain.drive(forward, 300, rpm);
  wait(1250, msec);
  Drivetrain.stop();
  IntakeMotor.stop();
}

void redPositiveAuton() {
}

void bluePositiveAuton() {
  Drivetrain.driveFor(forward, 53.25, inches, 400, rpm, false);
  IntakeMotor.spin(forward);
  wait(100, msec);
  Doinker.set(true);
  wait(550, msec);
  Doinker.set(false);
  wait(200, msec);
  DrivePID(-26, 50);
  IntakeMotor.stop();
  wait(200, msec);
  Doinker.set(true);
  wait(200, msec);
  DrivePID(-3, 50);
  wait(250, msec);
  Doinker.set(false);
  wait(150, msec);
  TurnPID(189, 35);
  Drivetrain.driveFor(reverse, 35, inches, 300, rpm);
  MogoClamp.set(true);
  wait(200, msec);
  IntakeMotor.spin(forward);
  DrivePID(45, 60);
  wait(350, msec);
  DrivePID(-14, 55);
  IntakeMotor.stop();
  TurnPID(-180, 40);
  MogoClamp.set(false);
  DrivePID(5, 50);
  TurnPID(-120, 35);
  DrivePID(-26, 65);
  MogoClamp.set(true);
  wait(250, msec);
  DrivePID(10, 50);
  IntakeMotor.spin(forward);
  wait(1500, msec);
  IntakeMotor.stop();
  TurnPID(-145, 40);
  Drivetrain.drive(forward, 300, rpm);
  wait(1000, msec);
  Drivetrain.stop();
}

void redNegativeElimsAuto() {
}

void blueNegativeElimsAuto() {
}

void redPositiveElimsAuto() {
}

void bluePositiveElimsAuto() {
}