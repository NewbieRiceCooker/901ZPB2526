#include "auton.hpp"
#include "helpers.hpp"
#include "globals.hpp"

void left7block(){
    chassis.setPose(57.5,22,0);
    setIntake(127);
    chassis.moveToPoint(49.5,44,1000,{.maxSpeed=60}); //overshooting, because getting two blocks. potentially need to move back.
    chassis.turnToHeading(-135,1000);
    setIntake(0);
    middlePiston.toggle();
    chassis.moveToPoint(65,62,1000,{.forwards=false});
    setIntake(127);
    pros::delay(3000);
    chassis.moveToPoint(17,20,1000); //still possibly overshooting?
    setIntake(0);
    middlePiston.toggle();
    chassis.turnToHeading(180,1000);
    loaderPiston.toggle();
    setIntake(127);
    chassis.moveToPoint(17,-10,1000);
    chassis.moveToPoint(18,47,1000,{.forwards=false});
    setScoring(127);
}