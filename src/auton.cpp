#include "auton.hpp"
#include "helpers.hpp"
#include "globals.hpp"

void left4plus3(){
    
    chassis.setPose(57.5,22,-90);
    loaderPiston.toggle();
    chassis.moveToPose(28,22,-90,800,{.maxSpeed=127},false);
    
    chassis.turnToHeading(180,500,{.maxSpeed=127},false);
    
    setIntake(127);
    chassis.moveToPose(26,0,180,1250,{.maxSpeed=127},false);
    chassis.moveToPose(26,50,180,1000,{.forwards=false,.maxSpeed=127},false);
    loaderPiston.toggle();
    setScoring(127,'L');
    pros::delay(600);
    setIntake(127);
    //chassis.moveToPose(26,30,180,1000,{.maxSpeed=127},false);
    chassis.swingToHeading(90, DriveSide::LEFT, 500, {.maxSpeed=127},false);
    chassis.moveToPose(47,44,-312,1000,{.maxSpeed=127},false);
    
    

    

    chassis.turnToHeading(-134,500);
    
    chassis.moveToPose(68,60,-134,1000,{.forwards=false,.maxSpeed=127},false);
    
    setScoring(127,'M');
    pros::delay(600);
    setScoring(0,'M');
    chassis.moveToPose(40,26,-141,1000,{},false);
    
    chassis.moveToPose(40,55,180,2000,{.forwards=false},false);
    chassis.setBrakeMode(pros::E_MOTOR_BRAKE_HOLD);
    chassis.cancelAllMotions();
    
    
    
    

    
}
void left4rush(){
    chassis.setPose(57.5,22,-90);
    loaderPiston.toggle();
    chassis.moveToPose(28,22,-90,1000,{.maxSpeed=127},false);
    
    chassis.turnToHeading(180,500,{.maxSpeed=127},false);
    loaderPiston.toggle();
    setIntake(127);
    chassis.moveToPose(26,0,180,1250,{.maxSpeed=127},false);
    chassis.moveToPose(26,50,180,1000,{.forwards=false,.maxSpeed=127},false);
    setScoring(127,'L');
    pros::delay(2000);
    setScoring(0,'L');
    chassis.moveToPose(26,20,180,1000,{.maxSpeed=127},false);
    chassis.moveToPose(32,32,-148,1000,{.forwards=false,.maxSpeed=127},false);
    chassis.moveToPose(35.5,50,180,2000,{.forwards=false},false);
}
void left7rush(){ //devin code try testing later
    chassis.setPose(57.5,22,90);
    //chassis.moveToPose()
}
void right7(){ //still requires retuning
    
    chassis.setPose(92,28,0);
    setIntake(127);
    chassis.moveToPose(100,50,42,1250,{},false);
    
    loaderPiston.toggle();
    pros::delay(200);
    
    chassis.turnToHeading(133,500);
    chassis.moveToPose(129, 30, 133, 1500, {}, false);
    chassis.turnToHeading(180,500);
    
    chassis.moveToPose(130, 17, 180, 1000, {}, false);
    chassis.moveToPose(129, 52, 180, 1500, {.forwards=false}, false);
    setScoring(127, 'L');
    loaderPiston.toggle();
    pros::delay(1500);

    chassis.moveToPose(129, 20, 180, 500, {}, false);
    chassis.moveToPose(136, 36, 211, 500, {.forwards=false}, false); //change these to true
    chassis.moveToPose(136, 69, 180, 4000, {.forwards=false}, false); ////change these to true
    chassis.setBrakeMode(pros::E_MOTOR_BRAKE_HOLD);
    chassis.cancelAllMotions();
    
    
    
    
    
}
void right4plus3(){

    chassis.setPose(92,22,90);
    loaderPiston.toggle();
    chassis.moveToPose(124,22,90,1000,{},false); //towards loader
    chassis.turnToHeading(180,500,{},false); //swing towards loader?
    
    
    setIntake(127);
    chassis.moveToPose(126,0,180,1000,{}, false); //loader mech
    chassis.moveToPose(125,43,180,1000,{.forwards=false,.maxSpeed=80},false); //long goal
    setScoring(127, 'L');
    loaderPiston.toggle();
    pros::delay(900);
    setIntake(127);
    chassis.moveToPose(125,35,180,500,{.maxSpeed=80},false); //straight align back long goal

    chassis.swingToHeading(310, DriveSide::RIGHT, 500, {.maxSpeed=127},false);


    chassis.moveToPose(102,40,310,1000, {}, false); //3 block
    
    chassis.moveToPose(84,53,310,1000,{}, true); //align bottom
    /*
    pros::delay(500);
    setIntake(-127);
    pros::delay(1000);
    setIntake(127);
    
    chassis.moveToPose(110,38,310,1000,{.forwards=false}, false); //align long goal
    wingPiston.retract();
    chassis.moveToPose(110,63,0,1000, {}, false); //push
    chassis.turnToHeading(320,1000,{},false);
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
    setIntake(127);
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
    setIntake(127);
    setScoring(127,'L');
    pros::delay(3500);
    setScoring(0,'L');
    setIntake(127);

    

    // Intake blocks from top right loader
    chassis.moveToPose(120, 160, 0, 5000, {.maxSpeed = 30},false); 

    // Return to goal to score
    chassis.moveToPose(123, 102, 0, 1500, {.forwards = false},false);
    setScoring(127,'L');
    setIntake(127);
    pros::delay(3000);
    loaderPiston.toggle();
    setScoring(0,'L');
    setIntake(127);

    

    chassis.moveToPose(124, 115, 0, 1000, {},true);
    chassis.turnToHeading(-90,500);



    

    chassis.moveToPose(20, 115, -90, 3000); 
    chassis.turnToHeading(0,500);

    // Intake from top left loader
    setIntake(127);
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
    setScoring(127,'L');
    pros::delay(5000);
    setScoring(0,'L');
    loaderPiston.toggle();

    // Final loader grab and score
    chassis.moveToPose(23, 0, -180, 5000, {.maxSpeed = 30});
    chassis.moveToPose(20, 50, -180, 1500, {.forwards = false},false);
    setScoring(127,'L');
    pros::delay(5000);
    setScoring(0,'L');
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
    setScoring(0,'L');
    
    
    chassis.moveToPose(108, 28.5, -90, 1250, {.forwards = false ,.maxSpeed = 127, .earlyExitRange = 0},false);
    chassis.turnToHeading(180, 750,{.maxSpeed = 127},false);
    loaderPiston.toggle();
    setIntake(127);
    
    //chassis.moveToPoint(105, 0, 1250, { .maxSpeed = 50 },false);
    chassis.moveToPose(108, 0, 180, 750,{ .maxSpeed = 127},false); 
    pros::delay(500);
    loaderPiston.toggle();
    
    chassis.moveToPose(108, 50, 180, 1500,{ .forwards = false },false); 
    setScoring(127,'L');
    pros::delay(1500);
    setScoring(0,'L');
    chassis.moveToPose(108, 25 ,180, 500,{.maxSpeed = 127},true); 

    
    chassis.turnToHeading(-55,500,{},false);
    chassis.moveToPose(92, 48 ,-55, 1000,{.maxSpeed = 127},false); 
    loaderPiston.toggle();
    chassis.moveToPose(85, 48 ,-90, 500,{.earlyExitRange = 0},false); 
    loaderPiston.toggle();
    chassis.moveToPose(44.5, 49 ,-90, 1250,{.earlyExitRange = 0},false); 
    loaderPiston.toggle();
    chassis.moveToPose(52, 60 ,-133, 1000,{.forwards=false},false); 

    
    

    setScoring(127,'M');
    pros::delay(1000);
    setScoring(0,'M');
    
    chassis.moveToPose(13,20,-148,1500,{.maxSpeed = 127,.earlyExitRange = 4},true);

    chassis.turnToHeading(180,500,{},false);
    //chassis.moveToPose(12,0,180,500,{},false);
    chassis.moveToPose(13,50,180,1000,{.forwards=false},false);
    
    setScoring(127,'L');
    
    
    
    
    

}