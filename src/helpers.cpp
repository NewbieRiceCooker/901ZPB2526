#include "helpers.hpp"
#include "globals.hpp"

void setIntake(int intakePower){
    scoringPiston.extend();
    wingPiston.extend();
    bottomMotor.move(intakePower);
    topMotor.move(intakePower);
    
    //string is going to be attached to prevent blocks from feeding out.
    //however, another piston (hood) may be required to perform this task
}
void setScoring(int scoringPower,  char goalSelection){
    if (goalSelection == 'L'){
        scoringPiston.extend();
        wingPiston.retract();
        bottomMotor.move(scoringPower);
        topMotor.move(scoringPower);
    }
    else if (goalSelection == 'M'){
        scoringPiston.retract();
        bottomMotor.move(scoringPower);
        topMotor.move(scoringPower);
    }
    
    //see comment above, if hood is included above, make sure to add logic here

}

void pulse(int scoringPower, char goalSelection){ //possibly redundant function, due to the transition to S-Bot
    if (goalSelection == 'L'){
        topMotor.move(-127);
        bottomMotor.move(-127);
        pros::delay(250);
        scoringPiston.extend();
        wingPiston.retract();
        topMotor.move(scoringPower);
        bottomMotor.move(scoringPower);
    }
    



}