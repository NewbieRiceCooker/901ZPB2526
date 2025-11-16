#include "auton.hpp"
#include "helpers.hpp"
#include "globals.hpp"

void left7block(){
    chassis.setPose(57.5,22,0);
    setIntake(127);
    chassis.moveToPoint(49.5,49,3000,{.maxSpeed=30}); //overshooting, because getting two blocks. potentially need to move back.
    //chassis.moveToPoint(50,44,2000,{.forwards=false});
    chassis.turnToHeading(-135,1000);
    chassis.moveToPoint(58.5,54.5,2000,{.forwards=false, .maxSpeed=60},false);
    middlePiston.toggle(); //middle piston extend
    setScoring(64);
    pros::delay(750);
    middlePiston.toggle(); //middle piston retract
    setScoring(0);
    chassis.moveToPoint(18,20,2000,{.maxSpeed=60}); //still possibly overshooting?
    setIntake(0);
    chassis.turnToHeading(180,1000);
    loaderPiston.toggle();
    setIntake(127);
    chassis.moveToPoint(18,-20,1500,{.maxSpeed=70});
    chassis.moveToPoint(21,33,2000,{.forwards=false, .maxSpeed=60},false);
    setScoring(127);
    
}
void skillsAuton(){
    chassis.setPose(92,28,90);
    loaderPiston.toggle();
    chassis.moveToPoint(118,28,1000, {.maxSpeed=80});
    chassis.turnToHeading(180,1000,{},false);
    setIntake(127);
    chassis.moveToPoint(116,0,5000);
    chassis.moveToPoint(126,40,5000, {.forwards=false, .maxSpeed=80,});
    chassis.moveToPoint(126,100,5000, {.forwards=false, .maxSpeed=80,});
    chassis.moveToPoint(116,115,3000, {.forwards=false, .maxSpeed=80,}); //120 is slightly too much to the right
    chassis.turnToHeading(0,1000);
    chassis.moveToPoint(117,102,2000,{.forwards=false, .maxSpeed=80},false);
    setIntake(127);
    setScoring(127);
    pros::delay(2000);
    setScoring(0);
    chassis.moveToPoint(118,160,7000,{.maxSpeed=80},false);
    chassis.moveToPoint(117,102,2000,{.forwards=false, .maxSpeed=80},false);
    setScoring(127);
    
    //118 136
}