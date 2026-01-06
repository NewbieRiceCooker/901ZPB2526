#include "main.h"
#include "helpers.hpp"
#include "globals.hpp"
#include "auton.hpp"
#include "ui.hpp"



/**
 * A callback function for LLEMU's center button.
 *
 * When this callback is fired, it will toggle line 2 of the LCD text between
 * "I was pressed!" and nothing.
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
 * Runs initialization code. This occurs as soon as the program is started.
 *
 * All other competition modes are blocked by initialize; it is recommended
 * to keep execution time for this mode under a few seconds.
 */
void initialize() {
	

	//LBVL
	/**/


    chassis.calibrate(); // calibrate sensors


	lv_main_menu();
	//LCD PROS
	/*

	pros::lcd::initialize(); // initialize brain screen
    chassis.calibrate(); // calibrate sensors
	*/


    pros::Task screen_task([&]() {
		pros::delay(500);
        while (true) {


			//PROS LCD

			/*
			// print robot location to the brain screen
            pros::lcd::print(0, "X: %f", chassis.getPose().x); // x
            pros::lcd::print(1, "Y: %f", chassis.getPose().y); // y
            pros::lcd::print(2, "Theta: %f", chassis.getPose().theta); // heading
            // delay to save resources
            pros::delay(20);
			*/
			
		


			//LBVL
			

			
			if (labelCoords != nullptr) {

				char buffer[100];
				lemlib::Pose pose = chassis.getPose();
				snprintf(buffer, sizeof(buffer), "POSITION:\nX: %.2f\nY: %.2f\nTheta: %.2f", 
				pose.x, pose.y, pose.theta);

				
				lv_label_set_text(labelCoords, buffer);
			}

			if (labelTemps != nullptr) {
				char tempBuf[300]; 

				// Assuming you have defined these motor names in globals.hpp
				// Drive Left (3 motors)
				double L1 = leftFrontMotor.get_temperature();
				double L2 = leftTopMotor.get_temperature();
				double L3 = leftBottomMotor.get_temperature();

				// Drive Right (3 motors)
				double R1 = rightFrontMotor.get_temperature();
				double R2 = rightTopMotor.get_temperature();
				double R3 = rightBottomMotor.get_temperature();

				// Subsystems (2 motors)
				double mIntake = intakeMotor.get_temperature();
				double mScoring = scoringMotor.get_temperature();

				// Format as a grid for readability
				snprintf(tempBuf, sizeof(tempBuf), 
						"FRONTL: %.0fC | FRONTR: %.0fC\n"
						"TOPL:   %.0fC | TOPR:   %.0fC\n"
						"BACKL:  %.0fC | BACKR:  %.0fC\n"
						"INTAKE: %.0fC | SCORE: %.0fC",
						L1, R1, L2, R2, L3, R3, mIntake, mScoring);

				lv_label_set_text(labelTemps, tempBuf);

				// --- RED ALERT LOGIC ---
				// Checks if ANY of the 8 motors are overheating
				if (L1 > 55 || L2 > 55 || L3 > 55 || R1 > 55 || R2 > 55 || R3 > 55 || mIntake > 55 || mScoring > 55) {
					lv_obj_set_style_text_color(labelTemps, lv_palette_main(LV_PALETTE_RED), 0);
				} else {
					lv_obj_set_style_text_color(labelTemps, lv_palette_main(LV_PALETTE_NONE), 0);
				}
			}

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
					pros::delay(1000); 
					continue; 
				} else {
					autonState = 2;
					// Start the robot movement in the background
					pros::Task run_auton([](){ autonomous(); });
				}
			} 
			else if (autonState == 2) { // MATCH TIMER
				if (gameTimer > 0) {
					lv_label_set_text_fmt(countdownLabel, "RUNNING: %d:%02d", gameTimer/60, gameTimer%60);
					lv_obj_set_style_text_color(countdownLabel, lv_palette_main(LV_PALETTE_GREEN), 0);
					gameTimer--;
					pros::delay(1000);
					continue;
				} else {
					// --- STOP ALL MOVEMENT AT 0 SECONDS ---
					leftFrontMotor.brake(); leftTopMotor.brake(); leftBottomMotor.brake();
					rightFrontMotor.brake(); rightTopMotor.brake(); rightBottomMotor.brake();
					intakeMotor.brake(); scoringMotor.brake();
					
					lv_label_set_text(countdownLabel, "TIME UP - STOPPED");
					lv_obj_set_style_text_color(countdownLabel, lv_palette_main(LV_PALETTE_RED), 0);
					pros::delay(2000);
					autonState = 0;
				}
			}
			pros::delay(100);
				
			
        }
    });
	
}

/**
 * Runs while the robot is in the disabled state of Field Management System or
 * the VEX Competition Switch, following either autonomous or opcontrol. When
 * the robot is enabled, this task will exit.
 */
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


	left7block();
	//skillsAuton();
	//parkSkillsAuton();

	/*
	chassis.moveToPoint(0,24,9999);	
	chassis.moveToPoint(0,0,9999, {.forwards=false});
	*/
	
	
	//chassis.turnToHeading(180,9999);
	/*
	creation for a autonselector code should go hear, with switch statements relating the autonomousPreSet int variable;
	


	switch (autonomousPreSet){
		case 1:
		left7block();
		break;

		case 9:
		skillsAuton();
		break;

		default:
		break;

	}
		
	*/

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
	pros::MotorGroup left_mg({-1, -2, -3});    // Creates a motor group with forwards ports 1 & 3 and reversed port 2
	pros::MotorGroup right_mg({8, 9, 10});  // Creates a motor group with forwards port 5 and reversed ports 4 & 6


	while (true) {
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

		if(master.get_digital(DIGITAL_R1)){
			setIntake(-127); //outtake
		} 
		else if(master.get_digital(DIGITAL_R2)){
			setIntake(127); //spin motor to intake
		}
		else if (master.get_digital(DIGITAL_RIGHT)){
			wingPiston.toggle();
		}		
		else{
			setIntake(0);
			middlePiston.extend();
		}

		//score mech code
		
		if (master.get_digital(DIGITAL_L1)){
			setIntake(127);
			middlePiston.retract();
		}
		else if(master.get_digital(DIGITAL_L2)){
			setScoring(127);
		}
		else{
			setScoring(0);
		}


		 
		if (master.get_digital_new_press(DIGITAL_Y)){ //on click of the button, not holding.
			loaderPiston.toggle(); 
		}

	}
}