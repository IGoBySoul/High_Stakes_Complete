/*
PORTS:
  Drivetrain left: 12, 13, 14
  Drivetrain right: 4, 5, 8 
  Lady brown: 20
  Intake/conveyor: 18
  Inertial sensor: 9
  Optical sensor: 10
  Rotational sensor: 17
THREE WIRE CONNECTIONS:
  Mobile goal mechanism: ThreeWireA
  Doinker: ThreeWireB
*/

#include "vex.h"
#include <cmath>
#include "robot-config.h"
#include "autonomous.h"
#include "autonSelect.h"

using namespace vex;

//AUTON CODE//
void autonCode(void) {
  autonActive = true;
  colorSortBool = true;
  printTeamLogo();
  LBMech.setStopping(hold);
  IntakeMotor.setVelocity(100, percent);
  LBMech.setVelocity(100, percent);
  Drivetrain.setStopping(brake);
  Drivetrain.setDriveVelocity(40, percent);
  Drivetrain.setTurnVelocity(27.5, percent);
  MogoClamp.set(false);


  if (aselection == 0) {
    //do nothing
  } else if (aselection == 1) { //red negative auton
    redNegativeAuton();
  } else if (aselection == 2) { //blue negative auton
    blueNegativeAuton();
  } else if (aselection == 3) { //red positive auton
    redPositiveAuton();
  } else if (aselection == 4) { //blue positive auton
    bluePositiveAuton();
  } else if (aselection == 5) { //skills auton
    skillsAuton();
  } else if (aselection == 6) { //red neg elims auton
    redNegativeElimsAuto();
  } else if (aselection == 7) { //blue neg elims auton
    blueNegativeElimsAuto();
  } else if (aselection == 8) { //red pos elims auton
    redPositiveElimsAuto();
  } else if (aselection == 9) { //blue pos elims auton
    bluePositiveElimsAuto();
  }

  autonActive = false;

  while(autonActive == true) {
    colorSort();
  }
}


///DRIVER CONTROL///
void driverControl(void) {
  //simple stuff really
  autonActive = false;
  printTeamLogo();
  Controller.ButtonL2.pressed(liftMacro);
  Controller.ButtonY.pressed(doinkCode);
  Controller.ButtonRight.pressed(doinkCode2);
  Controller.ButtonL1.pressed(MogoCode);
  //Controller.ButtonB.pressed(toggleSorting);
  colorSortBool = true;
  Drivetrain.setStopping(brake);
  LBMech.setStopping(hold);
  IntakeMotor.setVelocity(100, percent);
  LBMech.setVelocity(25, percent);
  
  
  while(true){
    inputCurve();
    intakeConstant();
    //colorSort();
    //liftHardstop();

    this_thread::sleep_for(20);
  }
}

int main() {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();


  bool unconfirmed = true;

  Brain.Screen.clearScreen("black");
  confirm.setPenColor("#0f990b");
  drawTonomous();

  //use coordinate presser for exact spacing
  while(unconfirmed){
    if(Brain.Screen.pressing()){
      if(redButton.pressing()){
        ColorChosen = 1;
        redNeg.moveTo(xplace,redNeg.yPos);
        redPos.moveTo(xplace,redPos.yPos);
        blueNeg.moveTo(1000,blueNeg.yPos);
        bluePos.moveTo(1000,bluePos.yPos);
        redNegElims.moveTo(xplace2, redNegElims.yPos);
        redPosElims.moveTo(xplace2, redPosElims.yPos);
        blueNegElims.moveTo(1300,blueNegElims.yPos);
        bluePosElims.moveTo(1300,bluePosElims.yPos);
        drawTonomous();
      }
      else if (blueButton.pressing()){
        ColorChosen = 2;
        redNeg.moveTo(1000,redNeg.yPos);
        redPos.moveTo(1000,redPos.yPos);
        blueNeg.moveTo(xplace,blueNeg.yPos);
        bluePos.moveTo(xplace,bluePos.yPos);
        redNegElims.moveTo(1300,redNegElims.yPos);
        redPosElims.moveTo(1300,redPosElims.yPos);
        blueNegElims.moveTo(xplace2, redNegElims.yPos);
        bluePosElims.moveTo(xplace2, redPosElims.yPos);
        drawTonomous();
      }
      else if (ColorChosen == 1){
        if(redNeg.pressing()){
          aselection = 1;
          teamColor = 1;
          drawTonomous();
        }
        else if (redPos.pressing()){
          teamColor = 1;
          aselection = 3;
          drawTonomous();
        }
        else if (redNegElims.pressing()) {
          teamColor = 1;
          aselection = 6;
          drawTonomous();
        }
        else if (redPosElims.pressing()) {
          teamColor = 1;
          aselection = 8;
          drawTonomous();
        }
      }
      else if (ColorChosen == 2){
        if(blueNeg.pressing()){
          aselection = 2;
          teamColor = 2;
          drawTonomous();
        }
        else if (bluePos.pressing()){
          aselection = 4;
          teamColor = 2;
          drawTonomous();
        }
        else if (blueNegElims.pressing()) {
          aselection = 7;
          teamColor = 2;
          drawTonomous();
        }
        else if (bluePosElims.pressing()) {
          aselection = 9;
          teamColor = 2;
          drawTonomous();
        }

      }
      if (skills.pressing()){
        aselection = 5;
        drawTonomous();
      }
      if (none.pressing()){
        aselection = 0;
        drawTonomous();
      }
    }


    if(aselection >-1){  
      switch(aselection){
        case 0: Brain.Screen.printAt(200, 200, "none");
          break;
        case 1: Brain.Screen.printAt(200, 200, "Red Neg");
          break;
        case 2: Brain.Screen.printAt(200, 200, "Blue Neg");
         break;
        case 3: Brain.Screen.printAt(200, 200, "Red Pos");
         break;
        case 4: Brain.Screen.printAt(200, 200, "Blue Pos");
          break;
        case 5: Brain.Screen.printAt(200, 200, "skills auton");
          break;
        case 6: Brain.Screen.printAt(200, 200, "Red Neg Elims");
          break;
        case 7: Brain.Screen.printAt(200, 200, "Blue Neg Elims");
          break;
        case 8: Brain.Screen.printAt(200, 200, "Red Pos Elims");
          break;
        case 9: Brain.Screen.printAt(200, 200, "Blue Pos Elims");
          break;
      }
      if(confirm.pressing()){
        unconfirmed = false;
      }
    }
    else{
      if(confirm.pressing()){
        Brain.Screen.printAt(150, 220, "Please select an option");
      }
    }
    this_thread::sleep_for(50);
  }
  Brain.Screen.clearScreen();
  
  

  // All activities that occur before the competition starts
  // Example: clearing encoders, setting servo positions, ...
  rotationSensor.resetPosition();
  rotationSensor.setPosition(1, degrees);
  /*inertialSensor.resetRotation();
  inertialSensor.calibrate();
  while (inertialSensor.isCalibrating()) {
    wait(50, msec);
  }
  inertialSensor.resetRotation();*/
  //opticalSensor.setLight(ledState::on);
  opticalSensor.setLight(ledState::on);

  //competition setup
  competition Competition;
  Competition.autonomous(autonCode);
  autonActive = false;
  Competition.drivercontrol(driverControl);
}