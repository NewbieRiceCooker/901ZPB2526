#include "helpers.hpp"
#include "globals.hpp"

void setIntake(int intakePower){
    intakeMotor.move(intakePower);
}
void setScoring(int scoringPower){
    scoringMotor.move(scoringPower);

}

void smartIntake(int intakePower) {
    // get_efficiency() returns 0-100. Lower means the motor is struggling/stalled.
    // get_current_draw() returns mA. Higher means it's working harder.
    
    if (intakeMotor.get_current_draw() > 2000) {
        // We are likely jammed or pushing a heavy load
        intakeMotor.move(-127); // Quick reverse to re-seat the Triball
        pros::delay(100);
        intakeMotor.move(intakePower);  // Power through
    } else {
        // Motor is spinning freely, no need to pulse
        intakeMotor.move(intakePower);
    }
}
void pulse(){
    
    intakeMotor.move(127);
    pros::delay(250);
    intakeMotor.move(-127);
    pros::delay(100);
    intakeMotor.move(127);
    pros::delay(250);
    intakeMotor.move(-127);
    pros::delay(100);
    intakeMotor.move(127);



}