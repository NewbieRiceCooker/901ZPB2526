#include "auton.hpp"
#include "helpers.hpp"
#include "globals.hpp"

void left7block(){
    
    chassis.setPose(57.5,22,0);
    setIntake(127);
    chassis.moveToPoint(49.5,49,3000,{.maxSpeed=35}); //overshooting, because getting two blocks. potentially need to move back.
    chassis.turnToHeading(-134,1000);
    chassis.moveToPose(57,56,-134,2000,{.forwards=false,.horizontalDrift=0.8, .maxSpeed=90},false);
    middlePiston.toggle(); //middle piston extend
    setScoring(68);
    pros::delay(1500);
    middlePiston.toggle(); //middle piston retract
    setScoring(0);
    chassis.moveToPoint(17,20,2000,{.maxSpeed=60}); //still possibly overshooting?
    setIntake(0);
    chassis.turnToHeading(180,1000);
    loaderPiston.toggle();
    setIntake(127);
    chassis.moveToPoint(18,-6,1000,{.maxSpeed=50});
    chassis.moveToPoint(18,6,500,{.maxSpeed=50});
    chassis.moveToPoint(18,-6,500,{.maxSpeed=50});
    chassis.moveToPoint(19,35,1000,{.forwards=false, .maxSpeed=100},false);
    
    
    
    setScoring(127);
    pros::delay(200);
    setIntake(-10);
    pros::delay(100);
    setIntake(127);
    
    
    
    
    
    
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
    chassis.moveToPoint(118,160,7000,{.maxSpeed=100},false);
    chassis.moveToPoint(117,102,2000,{.forwards=false, .maxSpeed=80},false);
    setScoring(127);
    
    //118 136
}
void parkSkillsAuton(){
    chassis.setPose(0,0,0);
    chassis.moveToPoint(0,15,5000);
    setIntake(127);
}