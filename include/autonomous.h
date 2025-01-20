#include "functions.h"

void skillsAuton() {

  //BLACK  PATH//

  IntakeMotor.spinFor(forward, 1, seconds);
  DrivePID(16, 50);

  TurnPID(-90, 35);
  DrivePID(24, 50);
  MogoClamp.set(true);
  wait(300, msec);

  TurnPID(90, 35);
  IntakeMotor.spin(forward);
  DrivePID(24, 50);
  TurnPID(56, 35);
  wait(750, msec);

  liftMacro();
  DrivePID(43, 50);
  wait(1000, msec);
  TurnPID(34, 30);
  IntakeMotor.stop();
  Drivetrain.drive(forward);
  wait(750, msec);
  Drivetrain.stop();
  liftMacro();
  wait(750, msec);
  DrivePID(16, 50);
  liftMacro();

  TurnPID(90, 35);
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
  Drivetrain.drive(reverse);
  wait(1000, msec);
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
  TurnPID(-135, 35);
  DrivePID(24, 50);
  TurnPID(30, 35);
  wait(750, msec);
  DrivePID(8, 35);
  TurnPID(-10, 25);
  DrivePID(-10, 35);
  TurnPID(70, 25);
  DrivePID(14, 35);
  TurnPID(135, 35);
  wait(1500, msec);
  DrivePID(48, 50);
}

void redPositiveAuton() {
}

void bluePositiveAuton() {
  Drivetrain.driveFor(forward, 51.75, inches, 400, rpm, false);
  IntakeMotor.spin(forward);
  wait(100, msec);
  Doinker.set(true);
  wait(550, msec);
  Doinker.set(false);
  wait(200, msec);
  DrivePID(-24, 60);
  wait(200, msec);
  Doinker.set(true);
  DrivePID(-3, 50);
  IntakeMotor.stop();
  wait(250, msec);
  Doinker.set(false);
  wait(150, msec);
  TurnPID(195, 35);
  DrivePID(-27, 60);
  MogoClamp.set(true);
  wait(200, msec);
  IntakeMotor.spin(forward);
  DrivePID(45, 60);
  wait(750, msec);
  IntakeMotor.stop();
  DrivePID(-14, 55);
  TurnPID(-215, 35);
  DrivePID(-16, 55);
  MogoClamp.set(false);
  DrivePID(8, 50);
  TurnPID(-125, 35);
  DrivePID(-27, 60);
  MogoClamp.set(true);
  wait(200, msec);
  DrivePID(8, 50);
  IntakeMotor.spin(forward);
  wait(1500, msec);
  IntakeMotor.stop();
  TurnPID(-105, 35);
  Drivetrain.drive(forward, 400, rpm);
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