#include "helpers.hpp"
#include "globals.hpp"

void setIntake(int intakePower){
    intakeMotor.move(intakePower);
}
void setScoring(int scoringPower){
    scoringMotor.move(scoringPower);
}