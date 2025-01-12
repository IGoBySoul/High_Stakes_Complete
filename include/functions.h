#include "variables.h"


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
      LBSpinUp(13);
  } else if (liftMacroVar == 2) {
    liftMacroVar = 3;
    LBSpinUp(120);
  } else if (liftMacroVar == 3) {
    liftMacroVar = 1;
    LBSpinDown(3);
  }
}

void liftReset() {
  LBSpinDown(0);
  wait(500, msec);
  rotationSensor.resetPosition();
  rotationSensor.setPosition(5, degrees);
}

/*void liftHardstop() {
  if (rotationSensor.position(degrees) >= 133) {
    LBMech.spin(forward, 100, percent);
    waitUntil(rotationSensor.position(degrees) <= 130);
    LBMech.stop(); 
  }
}*/

/*void toggleSorting() {
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
    if (teamColor == 1) {
      if (opticalSensor.color() == blue && opticalSensor.isNearObject()){
        LBSpinUp(7);
        wait(1000, msec);
        LBSpinDown(1);
      }
    } else if (teamColor == 2 ) {
      if (opticalSensor.color() == red && opticalSensor.isNearObject()){
        LBSpinUp(7);
        wait(1000, msec);
        LBSpinDown(1);
      }
    }
  } else if (colorSortBool == false) {
    Controller.Screen.clearScreen();
    Controller.Screen.setCursor(1, 1);
    Controller.Screen.print("Sorting Disabled!");
  }
}*/

int curveJoystick(bool red, int input, double t){
  int val = 0;
  if(red){
    val = (std::exp(-t/10)+std::exp((std::abs(input)-100)/10)*(1-std::exp(-t/10))) * input;
  }else{
    val = std::exp(((std::abs(input)-100)*t)/1000) * input;
  }
  return val;
}

// Define some macros
void printTeamLogo() {
  if (teamColor == 0) {
    Brain.Screen.setPenColor(white);
    Brain.Screen.setFillColor(black);
  } else if (teamColor == 1) {
    Brain.Screen.setPenColor(red);
    Brain.Screen.setFillColor(black);
  } else if (teamColor == 2) {
    Brain.Screen.setPenColor(blue);
    Brain.Screen.setFillColor(black);
  } else if (teamColor == 3) {
    Brain.Screen.setPenColor(yellow);
    Brain.Screen.setFillColor(black);
  }

  Brain.Screen.clearScreen();
  Brain.Screen.setCursor(3, 1);
  Brain.Screen.print("   .d8888b.   d888   .d8888b.    888       888   "); Brain.Screen.newLine();
  Brain.Screen.print("  d88P  Y88b d8888  d88P  Y88b   888   o   888   "); Brain.Screen.newLine();
  Brain.Screen.print("       .d88P   888  888          888  d8b  888   "); Brain.Screen.newLine();
  Brain.Screen.print("      8888     888  d888888b.    888 d888b 888   "); Brain.Screen.newLine();
  Brain.Screen.print("        Y8b.   888  888P  Y88b   888d88888b888   "); Brain.Screen.newLine();
  Brain.Screen.print("  888    888   888  888    888   88888P Y88888   "); Brain.Screen.newLine();
  Brain.Screen.print("  Y88b  d88P   888  Y88b. d88P   8888P   Y8888   "); Brain.Screen.newLine();
  Brain.Screen.print("   'Y8888P'  8888888 'Y8888P'    888P     Y888   "); Brain.Screen.newLine();
}


void MogoCode() {
  if (MogoClamp.value() == false) {
    MogoClamp.set(true);
  } else {
    MogoClamp.set(false);
  }
}

void doinkCode() {
  if (Doinker.value() == false) {
    Doinker.set(true);
  } else {
    Doinker.set(false);
  }
}

void inputCurve() {
  double turnVal = curveJoystick(false, Controller.Axis1.position(percent), turningCurve); //Get curvature according to settings [-100,100]
  double forwardVal = curveJoystick(false, Controller.Axis3.position(percent), forwardCurve); //Get curvature according to settings [-100,100]

  double turnVolts = turnVal * 0.12; //Converts to voltage
  double forwardVolts = forwardVal * 0.12; //Converts to voltage

  LeftDrive.spin(forward, forwardVolts + turnVolts, voltageUnits::volt); //Apply Via Voltage
  RightDrive.spin(forward, forwardVolts - turnVolts, voltageUnits::volt);
}

void intakeConstant() {
  if (Controller.ButtonR1.pressing()) {
    IntakeMotor.spin(forward);
  } else if (Controller.ButtonR2.pressing()) {
    IntakeMotor.spin(reverse);
  } else {
    IntakeMotor.stop();
  }
}
