#include "PID.h"


int liftMacroVar = 1;
bool colorSortBool = true;
int teamColor = 0; //1 == red, 2 == blue
bool autonActive = false;
int aselection = -1;

// Joystick curve
int turningCurve = 20; // Turning curve intensity
bool turningRed = true; // Flag for turning curve type (red or blue)

int forwardCurve = 20; // Forward curve intensity
bool forwardRed = true; // Flag for forward curve type (red or blue)