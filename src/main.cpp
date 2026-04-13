#include "main.h"
#include "helpers.hpp"
#include "globals.hpp"
#include "auton.hpp"
#include "ui.hpp"

// 1. MOVED TO GLOBAL SCOPE (Outside of any function)
// Now the whole program shares this one lock!
pros::Mutex screen_mutex; 

/**
 * A callback function for LLEMU's center button.
 */
void on_center_button() {
    static bool pressed = false;
    pressed = !pressed;
    if (pressed) {
        pros::lcd::set_text(2, "I was pressed!");
    } else {
        pros::lcd::clear_line(2);
    }
}

/**
 * Runs initialization code.
 */
void initialize() {
    
    chassis.calibrate(); // calibrate sensors
    lv_main_menu();

    // Create the background task for the screen
    pros::Task screen_task([&]() {
        pros::delay(500);
        while (true) {

            if (labelCoords != nullptr) {
                char buffer[100];
                lemlib::Pose pose = chassis.getPose();
                snprintf(buffer, sizeof(buffer), "POSITION:\nX: %.2f\nY: %.2f\nTheta: %.2f", 
                pose.x, pose.y, pose.theta);

                screen_mutex.take(); // LOCK the screen
                lv_label_set_text(labelCoords, buffer);
                screen_mutex.give(); // UNLOCK the screen
            }

            if (labelTemps != nullptr) {
                char tempBuf[300]; 
                
                double L1 = leftFrontMotor.get_temperature();
                double L2 = leftTopMotor.get_temperature();
                double L3 = leftBottomMotor.get_temperature();
                double R1 = rightFrontMotor.get_temperature();
                double R2 = rightTopMotor.get_temperature();
                double R3 = rightBottomMotor.get_temperature();
                double mTop = topMotor.get_temperature();
                double mBottom = bottomMotor.get_temperature();
                
                snprintf(tempBuf, sizeof(tempBuf), 
                        "FRONTL: %.0fC \n FRONTR: %.0fC\n"
                        "TOPL:   %.0fC \n TOPR:   %.0fC\n"
                        "BACKL:  %.0fC \n BACKR:  %.0fC\n"
                        "TOP: %.0fC \n SCORE: %.0fC",
                        L1, R1, L2, R2, L3, R3, mTop, mBottom);

                screen_mutex.take(); // LOCK the screen
                lv_label_set_text(labelTemps, tempBuf);

                // --- RED ALERT LOGIC ---
                if (L1 > 55 || L2 > 55 || L3 > 55 || R1 > 55 || R2 > 55 || R3 > 55 || mTop > 55 || mBottom > 55) {
                    lv_obj_set_style_text_color(labelTemps, lv_palette_main(LV_PALETTE_RED), 0);
                } else {
                    lv_obj_set_style_text_color(labelTemps, lv_palette_main(LV_PALETTE_GREEN), 0);
                }
                screen_mutex.give(); // UNLOCK the screen
            }

            if (countdownLabel != nullptr) {
                screen_mutex.take(); // LOCK the screen
                
                //AUTONOMOUS STATE LOGIC
                if (pros::competition::is_connected()){
                    lv_label_set_text(countdownLabel, "FIELD CONTROL ACTIVE");
                    lv_obj_set_style_text_color(countdownLabel, lv_palette_main(LV_PALETTE_BLUE), 0);
                    autonState = 0;
                }
                else if (autonState == 0) { // IDLE
                    lv_label_set_text(countdownLabel, "STATUS: Not Active");
                    lv_obj_set_style_text_color(countdownLabel, lv_palette_main(LV_PALETTE_GREY), 0);
                } 
                else if (autonState == 1) { // 3-2-1 COUNTDOWN
                    if (countdownValue > 0) {
                        lv_label_set_text_fmt(countdownLabel, "READY... %d", countdownValue);
                        lv_obj_set_style_text_color(countdownLabel, lv_palette_main(LV_PALETTE_ORANGE), 0);
                        countdownValue--;
                        screen_mutex.give(); // Unlock before delaying!
                        pros::delay(1000); 
                        continue; 
                    } else {
                        autonState = 2;
                    }
                } 
                else if (autonState == 2) { // MATCH TIMER
                    if (gameTimer > 0) {
                        lv_label_set_text_fmt(countdownLabel, "RUNNING: %d:%02d", gameTimer/60, gameTimer%60);
                        lv_obj_set_style_text_color(countdownLabel, lv_palette_main(LV_PALETTE_GREEN), 0);
                        gameTimer--;
                        screen_mutex.give(); // Unlock before delaying!
                        pros::delay(1000);
                        continue;
                    } else {
                        lv_label_set_text(countdownLabel, "TIME UP - STOPPED");
                        lv_obj_set_style_text_color(countdownLabel, lv_palette_main(LV_PALETTE_RED), 0);
                        autonState = 0;
                        screen_mutex.give(); // Unlock before delaying!
                        pros::delay(2000);
                        continue;
                    }
                }
                
                screen_mutex.give(); // UNLOCK if none of the above hit delays
            }
            
            pros::delay(100); // Master delay for the task
        }
    }); // 2. FIXED BRACKETS HERE! This properly closes the lambda and the Task constructor.
}

void disabled() {}

/**
 * Runs after initialize(), and before autonomous when connected to the Field
 * Management System or the VEX Competition Switch. This is intended for
 * competition-specific initialization routines, such as an autonomous selector
 * on the LCD.
 *
 * This task will exit when the robot is enabled and autonomous or opcontrol
 * starts.
 */
void competition_initialize() {}

/**
 * Runs the user autonomous code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the autonomous
 * mode. Alternatively, this function may be called in initialize or opcontrol
 * for non-competition testing purposes.
 *
 * If the robot is disabled or communications is lost, the autonomous task
 * will be stopped. Re-enabling the robot will restart the task, not re-start it
 * from where it left off.
 */
void autonomous() {


	//left7block();
	//skillsAuton();
	//parkSkillsAuton();

	/*
	chassis.moveToPoint(0,24,9999);	
	chassis.moveToPoint(0,0,9999, {.forwards=false});
	*/
	
	
	//chassis.turnToHeading(180,9999);
	
	//creation for a autonselector code should go hear, with switch statements relating the autonomousPreSet int variable;
	

    chassis.setBrakeMode(pros::E_MOTOR_BRAKE_HOLD);

	switch (autonomousPreSet){
		case 1:
		left4plus3();
		break;
		case 2:
		left7rush();
		break;

		case 3:
		right4plus3();
		break;

        case 4:
        right7();
        break;

		case 8:
		soloAWP();
		break;

		case 9:
		skillsAuton();
		break;

        case 99:
        chassis.setPose(0,0,0);
        chassis.turnToHeading(180,10000);
        //chassis.moveToPose(0,24,0,1000,{},false);

		default:
		break;

	}
		
	

}



/**
 * Runs the operator control code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the operator
 * control mode.
 *
 * If no competition control is connected, this function will run immediately
 * following initialize().
 *
 * If the robot is disabled or communications is lost, the
 * operator control task will be stopped. Re-enabling the robot will restart the
 * task, not resume it from where it left off.
 */
void opcontrol() {
	pros::Controller master(pros::E_CONTROLLER_MASTER);
	pros::MotorGroup left_mg({-4, -5, -6});    // Creates a motor group with forwards ports 1 & 3 and reversed port 2
	pros::MotorGroup right_mg({1, 2, 3});  // Creates a motor group with forwards port 5 and reversed ports 4 & 6

	chassis.setBrakeMode(pros::E_MOTOR_BRAKE_COAST);


	while (true) {

		if (pros::competition::is_autonomous()) {
            pros::delay(20);
            continue;
        }

		

		
		pros::lcd::print(0, "%d %d %d", (pros::lcd::read_buttons() & LCD_BTN_LEFT) >> 2,
						(pros::lcd::read_buttons() & LCD_BTN_CENTER) >> 1,
						(pros::lcd::read_buttons() & LCD_BTN_RIGHT) >> 0);  // Prints status of the emulated screen LCDs

		// Arcade control scheme
		int dir = master.get_analog(ANALOG_LEFT_Y);    // Gets amount forward/backward from left joystick
		int turn = master.get_analog(ANALOG_RIGHT_X);  // Gets the turn left/right from right joystick
		left_mg.move(dir + turn);                      // Sets left motor voltage
		right_mg.move(dir - turn);                     // Sets right motor voltage
		pros::delay(20);                               // Run for 20 ms then update

		//intake code

		
		int intakePower = 0;
		int scoringPower = 0;

		// --- 1. INDEPENDENT SCORING LOGIC (L1 or L2) ---
		if (master.get_digital(DIGITAL_L1)) { //middle goal score
			topMotor.move(127);
            bottomMotor.move(127);
			scoringPiston.retract();
		} 
		else if (master.get_digital(DIGITAL_L2)) { //long goal
			topMotor.move(127);
            bottomMotor.move(127);
            scoringPiston.extend();
            wingPiston.retract();
		} 
			
		else if (master.get_digital(DIGITAL_R1)) { //outtake
            topMotor.move(-127);
            bottomMotor.move(-127);
        } 
        else if (master.get_digital(DIGITAL_R2)) { //storing
            topMotor.move(127);
            bottomMotor.move(127);
            scoringPiston.extend();
            wingPiston.extend();
        } 
        else {
			topMotor.move(0);
            bottomMotor.move(0);
            scoringPiston.extend();
		}
			
		if (master.get_digital_new_press(DIGITAL_RIGHT)){
			wingPiston.toggle();
		}	
		
		if (master.get_digital_new_press(DIGITAL_Y)){ //on click of the button, not holding.
		    loaderPiston.toggle(); 
		}
        if (master.get_digital_new_press(DIGITAL_X)){ //on click of the button, not holding.
		    middlePiston.toggle();
		}
		

	}
}