#include "PID.h"

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




///////AUTON PATHS///////

void skillsAuton() {
  PIDDrive(10, 50);
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