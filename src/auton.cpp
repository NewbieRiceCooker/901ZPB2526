#include "auton.hpp"
#include "helpers.hpp"
#include "globals.hpp"

void left7block(){ //pretty consistent, however; proably will be off meta, since this goes for top goal too quick
    
    chassis.setPose(57.5,22,0);
    intakeMotor.move(127);
    chassis.moveToPoint(49.5,49,600,{},false); //overshooting, because getting two blocks. potentially need to move back.
    loaderPiston.toggle();
    chassis.turnToHeading(-134,1000);
    chassis.moveToPoint(56,54,750,{.forwards=false,.maxSpeed=90},false); //55,54 was undershooting but still scoring
    middlePiston.toggle(); //middle piston extend   
    scoringMotor.move(68);
    pros::delay(1500);
    middlePiston.toggle(); //middle piston retract
    scoringMotor.move(68);
    chassis.moveToPoint(15,20,1500,{}); //still possibly overshooting?
    intakeMotor.move(0);
    chassis.turnToHeading(180,500);
    intakeMotor.move(127);
    chassis.moveToPoint(15,-8,1250,{.maxSpeed=50});
    chassis.moveToPoint(18,35,1500,{.forwards=false},false);
    intakeMotor.move(127);
    pros::delay(1500);
    chassis.moveToPoint(20,10,500,{},false);
    chassis.moveToPoint(32,20,250,{.forwards=false},false);
    chassis.moveToPoint(32,47,4000,{.forwards=false},false);
}
void right7alleylongblock(){ //still requires retuning
    
    chassis.setPose(92,28,0);
    setIntake(127);
    chassis.moveToPoint(96,46,800,{},false); //overshooting, because getting two blocks. potentially need to move back.
    loaderPiston.toggle();
    chassis.moveToPoint(121,30,1500,{.forwards=false,.maxSpeed=90}); //still possibly overshooting?
    chassis.turnToHeading(180,1000);
    chassis.moveToPoint(121,50,1500,{.forwards=false},false);
    setScoring(127);
    setIntake(127);
    pros::delay(2000);
    setScoring(0);
    chassis.moveToPoint(121,0,1750,{.maxSpeed=60});
    chassis.moveToPoint(121,55,1500,{.forwards=false,.maxSpeed=70},false);
    setScoring(127);
    pros::delay(1500);
    chassis.moveToPoint(121,20,1000,{},false);
    chassis.moveToPoint(126,30,500,{.forwards=false},false);
    chassis.moveToPoint(126,60,4000,{.forwards=false},false);
}
void skillsAuton(){
    chassis.setPose(92,28,90);
    loaderPiston.toggle();
    chassis.moveToPoint(122,28,1000, {});
    chassis.turnToHeading(180,1000,{},false);
    setIntake(127);
    chassis.moveToPoint(122,0,5000,{.maxSpeed=50}); //intake at bottom-right loader
    chassis.moveToPoint(132,40,5000, {.forwards=false});
    chassis.turnToHeading(180,1000,{},false);
    chassis.moveToPoint(132,100,5000, {.forwards=false});
    chassis.moveToPoint(122,115,3000, {.forwards=false}); 
    chassis.turnToHeading(0,1000);
    chassis.moveToPoint(122,102,2000,{.forwards=false},false); //align with right long goal
    setIntake(127);
    setScoring(127);
    pros::delay(2000);
    setScoring(0);
    chassis.moveToPoint(122,160,7000,{},false); //intake blocks from top right loader
    chassis.moveToPoint(122,102,2000,{.forwards=false},false); //align with right long goal
    setScoring(127);
    pros::delay(5000);
    loaderPiston.toggle();
    setIntake(0);
    setScoring(0);
    chassis.moveToPoint(100,132,2000,{},false); //align with parking zone
    chassis.turnToHeading(-90,1000);
    chassis.moveToPoint(40,132,2000,{},false); //enter parking zone, clear all blocks
    chassis.turnToHeading(180,1000);
    chassis.moveToPoint(40,120,2000,{},false); 
    chassis.turnToHeading(-90,1000);
    chassis.moveToPoint(22,120,2000,{},false); //implement distance sensor logic here, due to potential autonomous drift
    //chassis.setPose(22,120,-90); //correct position after distance sensor logic
    chassis.turnToHeading(0,1000);
    setIntake(127);
    loaderPiston.toggle();
    chassis.moveToPoint(22,144,5000,{.maxSpeed=50},false); //intake from top left loader
    chassis.moveToPoint(10,155,2000,{.forwards=false},false); //align with alley
    chassis.turnToHeading(0,1000);
    chassis.moveToPoint(10,30,7000,{.forwards=false},false); //move through alley
    chassis.moveToPoint(21.5,30,2000,{.forwards=false},false); //position with right long goal
    chassis.turnToHeading(-180,1000);
    chassis.moveToPoint(21.5,47,2000,{.forwards=false},false); //position with right long goal, score
    setScoring(127);
    pros::delay(5000);
    setScoring(0);
    chassis.moveToPoint(21.5,0,5000,{.maxSpeed=50},false); //grab blocks from bottom right loader
    chassis.moveToPoint(21.5,47,2000,{.forwards=false},false); //position with right long goal, score x2
    setScoring(127);
    pros::delay(5000);
    setScoring(0);
    chassis.moveToPoint(40,10,3000); //start heading to red park zone
    chassis.turnToHeading(90,1000);
    chassis.moveToPoint(72,10,3000); //enter parkzone









    
    //118 136
}
void parkSkillsAuton(){
    chassis.setPose(0,0,0);
    chassis.moveToPoint(0,15,5000);
    setIntake(127);
}

void soloAWP(){
    /*
    chassis.setPose(0,0,0);
    chassis.moveToPoint(0,24,10000);
    //chassis.turnToHeading(180,10000);
    */
    chassis.setPose(72, 28.5, -90);
    chassis.moveToPoint(60, 28.5,300,{},false);
    setIntake(127);
    setScoring(0);
    chassis.moveToPoint(107, 28.5, 1500,{ .forwards = false },false);
    chassis.turnToHeading(180, 500,{},false);
    loaderPiston.toggle();
    setIntake(127);
    chassis.moveToPoint(107, 0, 1250, { .maxSpeed = 50 },false);
    pros::delay(500);
    loaderPiston.toggle();
    chassis.moveToPoint(107, 47, 1500, { .forwards = false },false);
    setScoring(127);
    pros::delay(1000);
    setScoring(0);
    setIntake(0);
    /*
    chassis.moveToPoint(107.5, 37, 1000, { .forwards = false });
    chassis.turnToHeading(270, 500);
    setIntake(127);
    chassis.moveToPoint(85, 36, 2500, { .maxSpeed = 80 },false);
    loaderPiston.toggle();
    pros::delay(500);
    loaderPiston.toggle();
    chassis.moveToPoint(50, 40, 2500, { .maxSpeed = 80 },false);
    loaderPiston.toggle();
    chassis.turnToHeading(135, 600);
    chassis.moveToPoint(56, 57, 1000, { .forwards = false });
    setScoring(127);
    pros::delay(1200);
    setIntake(0);
    setScoring(0);
    chassis.moveToPoint(20, 20, 2000);
    chassis.turnToHeading(180, 500);
    setIntake(127);
    chassis.moveToPoint(21, 0, 1200);
    chassis.waitUntilDone();
    pros::delay(500);
    chassis.moveToPoint(20, 47, 1500, { .forwards = false });
    chassis.waitUntilDone();
    setScoring(127);
    pros::delay(1000);
    setScoring(0);
    */
    

}