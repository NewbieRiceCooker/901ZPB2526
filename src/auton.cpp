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

void left7lateblock(){ //pretty consistent, however; proably will be off meta, since this goes for top goal too quick
    
    chassis.setPose(57.5,22,-90);
    chassis.moveToPose(28,22,-90,1000,{.maxSpeed=127},false);
    
    chassis.turnToHeading(180,500,{.maxSpeed=127},false);
    loaderPiston.toggle();
    setIntake(127);
    chassis.moveToPose(26,0,180,1250,{.maxSpeed=127},false);
    chassis.moveToPose(26,50,180,1000,{.forwards=false,.maxSpeed=127},false);
    loaderPiston.toggle();
    setScoring(127);
    pros::delay(2000);
    setScoring(0);
    chassis.moveToPose(26,30,180,1000,{.maxSpeed=127},false);
    chassis.swingToHeading(90, DriveSide::LEFT, 500, {.maxSpeed=127},false);
    chassis.moveToPose(50,36,-308,1000,{.maxSpeed=127},false);
    
    loaderPiston.toggle();

    chassis.turnToHeading(-134,500);
    chassis.moveToPose(64,51,-134,1000,{.forwards=false,.maxSpeed=127},false);
    loaderPiston.toggle();
    middlePiston.toggle();
    setScoring(127);
    pros::delay(2000);
    middlePiston.toggle();
    setScoring(0);
    chassis.moveToPose(34,26,-141,1000,{},false);
    
    chassis.moveToPose(37,50,180,2000,{.forwards=false},false);
    chassis.setBrakeMode(pros::E_MOTOR_BRAKE_HOLD);
    chassis.cancelAllMotions();
    
    
    

    
}

void left4rush(){
    chassis.setPose(57.5,22,-90);
    chassis.moveToPose(28,22,-90,1000,{.maxSpeed=127},false);
    
    chassis.turnToHeading(180,500,{.maxSpeed=127},false);
    loaderPiston.toggle();
    setIntake(127);
    chassis.moveToPose(26,0,180,1250,{.maxSpeed=127},false);
    chassis.moveToPose(26,50,180,1000,{.forwards=false,.maxSpeed=127},false);
    loaderPiston.toggle();
    setScoring(127);
    pros::delay(2000);
    setScoring(0);
    chassis.moveToPose(26,20,180,1000,{.maxSpeed=127},false);
    chassis.moveToPose(32,32,-148,1000,{.forwards=false,.maxSpeed=127},false);
    chassis.moveToPose(35.5,50,180,2000,{.forwards=false},false);
}

void right7alleylongblock(){ //still requires retuning
    
    chassis.setPose(92,28,0);
    setIntake(127);
    chassis.moveToPose(98,47,50,1250,{},false);
    loaderPiston.toggle();
    chassis.turnToHeading(133,500);
    chassis.moveToPose(123, 23, 133, 1500, {.minSpeed = 0, .earlyExitRange = 0.5}, false);
    chassis.turnToHeading(180,500);
    chassis.moveToPose(122, 0, 180, 1500, {.maxSpeed=60, .earlyExitRange = 0.5}, false);
    chassis.moveToPose(122, 60, 180, 1500, {.forwards=false ,.minSpeed = 0, .earlyExitRange = 0.5, }, false);
    setScoring(127);
    pulse();
    pros::delay(3000);
    chassis.moveToPose(122, 23, 180, 500, {.minSpeed = 0, .earlyExitRange = 0.5, }, false);
    chassis.moveToPose(130, 36, 211, 500, {.forwards=false ,.minSpeed = 60, .earlyExitRange = 0.5, }, false); //change these to true
    chassis.moveToPose(130, 50.5, 180, 4000, {.forwards=false ,.minSpeed = 0, .earlyExitRange = 0.5, }, false); ////change these to true
    chassis.setBrakeMode(pros::E_MOTOR_BRAKE_HOLD);
    chassis.cancelAllMotions();
    
    
    //chassis.moveToPose(127,17,180,1000,{},false);
    /*
    chassis.moveToPoint(126,30,2000,{.forwards=false,.maxSpeed=90}); //still possibly overshooting?
    chassis.turnToHeading(180,1000);
    
    chassis.moveToPoint(124,10,1500,{.maxSpeed=70},false);
    chassis.moveToPoint(123,55,1500,{.forwards=false,.maxSpeed=70},false);
    setScoring(127);
    pros::delay(1500);
    chassis.moveToPoint(124,30,1000,{},false);
    chassis.moveToPoint(136,30,500,{.forwards=false},false);
    chassis.moveToPoint(136,60,4000,{.forwards=false},false);
     */
    
}
void skillsAuton(){
    // Initialize Pose
    chassis.setPose(92, 28, 90);
    loaderPiston.toggle();
    wingPiston.toggle();

    // Move to first point while rotating to 90 (maintaining current heading)
    chassis.moveToPose(120, 28, 90, 1000);

    // Rotate and move to bottom-right loader
    smartIntake(127);
    chassis.moveToPose(120, 0, 180, 5000, {.maxSpeed = 30}); 
    chassis.moveToPose(120, 28, 180, 2000, {.forwards = false}); 
    

    // Move back toward the goal area (reversing)
    chassis.moveToPose(132, 40, 180, 1000, {.forwards = false},true);
    chassis.moveToPose(130, 120, 180, 2500, {.forwards = false},true);
    chassis.turnToHeading(-90,500);
    chassis.moveToPose(122, 120, -90, 1500, {},true); 
    chassis.turnToHeading(0,1000);


    // Align with right long goal (turning to 0 while moving)
    chassis.moveToPose(123, 102, 0, 1500, {.forwards = false},false);
    smartIntake(127);
    setScoring(127);
    pros::delay(3500);
    setScoring(0);
    smartIntake(127);

    

    // Intake blocks from top right loader
    chassis.moveToPose(120, 160, 0, 5000, {.maxSpeed = 30},false); 

    // Return to goal to score
    chassis.moveToPose(123, 102, 0, 1500, {.forwards = false},false);
    setScoring(127);
    smartIntake(127);
    pros::delay(3000);
    loaderPiston.toggle();
    setScoring(0);
    smartIntake(127);

    

    chassis.moveToPose(124, 115, 0, 1000, {},true);
    chassis.turnToHeading(-90,500);



    

    chassis.moveToPose(20, 115, -90, 3000); 
    chassis.turnToHeading(0,500);

    // Intake from top left loader
    smartIntake(127);
    loaderPiston.toggle();
    chassis.moveToPose(23, 144, 0, 5000, {.maxSpeed = 30});

    // Align with alley and move through (reversed)
    chassis.moveToPose(15, 100, 0, 1000, {.forwards = false},true);
    loaderPiston.toggle();
    chassis.moveToPose(15, 30, 0, 2500, {.forwards = false}),true;

    // Position with right long goal and score
    chassis.turnToHeading(90,1000);
    chassis.moveToPose(20, 30, 90, 1500, {.forwards = false});
    chassis.turnToHeading(-180,1000);
    chassis.moveToPose(20, 50, -180, 1500, {.forwards = false},false);
    setScoring(127);
    pros::delay(5000);
    setScoring(0);
    loaderPiston.toggle();

    // Final loader grab and score
    chassis.moveToPose(23, 0, -180, 5000, {.maxSpeed = 30});
    chassis.moveToPose(20, 50, -180, 1500, {.forwards = false},false);
    setScoring(127);
    pros::delay(5000);
    setScoring(0);
    loaderPiston.toggle();

    // Heading to red park zone
    chassis.moveToPose(40, 10, 90, 1000);
    chassis.moveToPose(72, 10, 90, 1000);








    
    //118 136
}
void parkSkillsAuton(){
    chassis.setPose(0,0,0);
    chassis.moveToPoint(0,15,5000);
    setIntake(127);
}

void soloAWP(){
    
  
    
    
    
   
    chassis.setPose(72, 28.5, -90);
    wingPiston.toggle();
    //chassis.moveToPoint(60, 28.5,300,{},false); 
    chassis.moveToPose(60, 28.5, -90, 500, {.maxSpeed = 30, .earlyExitRange = 0},false);
    setIntake(127);
    setScoring(0);
    
    
    chassis.moveToPose(108, 28.5, -90, 1250, {.forwards = false ,.maxSpeed = 127, .earlyExitRange = 0},false);
    chassis.turnToHeading(180, 750,{.maxSpeed = 127},false);
    loaderPiston.toggle();
    setIntake(127);
    
    //chassis.moveToPoint(105, 0, 1250, { .maxSpeed = 50 },false);
    chassis.moveToPose(108, 0, 180, 750,{ .maxSpeed = 127},false); 
    pros::delay(500);
    loaderPiston.toggle();
    
    chassis.moveToPose(108, 50, 180, 1500,{ .forwards = false },false); 
    setScoring(127);
    pros::delay(1500);
    setScoring(0);
    chassis.moveToPose(108, 25 ,180, 500,{.maxSpeed = 127},true); 

    
    chassis.turnToHeading(-55,500,{},false);
    chassis.moveToPose(92, 48 ,-55, 1000,{.maxSpeed = 127},false); 
    loaderPiston.toggle();
    chassis.moveToPose(85, 48 ,-90, 500,{.earlyExitRange = 0},false); 
    loaderPiston.toggle();
    chassis.moveToPose(44.5, 49 ,-90, 1250,{.earlyExitRange = 0},false); 
    loaderPiston.toggle();
    chassis.moveToPose(52, 60 ,-133, 1000,{.forwards=false},false); 

    
    
    middlePiston.toggle();
    setScoring(127);
    pros::delay(1000);
    middlePiston.toggle();
    setScoring(0);
    
    chassis.moveToPose(13,20,-148,1500,{.maxSpeed = 127,.earlyExitRange = 4},true);

    chassis.turnToHeading(180,500,{},false);
    //chassis.moveToPose(12,0,180,500,{},false);
    chassis.moveToPose(13,50,180,1000,{.forwards=false},false);
    
    setScoring(127);
    
    
    
    
    

}