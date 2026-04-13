#include "globals.hpp"
#include "lemlib/api.hpp"
#include "liblvgl/lvgl.h"

pros::MotorGroup left_motors({-4, -5, -6}, pros::MotorGearset::blue); 
pros::MotorGroup right_motors({1, 2, 3}, pros::MotorGearset::blue); 

lemlib::Drivetrain drivetrain(&left_motors,
    &right_motors,
    11, //track width
    lemlib::Omniwheel::NEW_325,
    450, //RPM
    8); //horizontal drift

pros::Imu imu(12); 
pros::Rotation vertical_sensor(-11); //TO DO: check the signs of the vertical sensor and the horizontal sensor, if moving in the positive diretion, and printing out negative values, make sure to reverse them
pros::Rotation horizontal_sensor(4);

lemlib::TrackingWheel horizontal_tracking_wheel(&horizontal_sensor, lemlib::Omniwheel::NEW_2, -5.75);
    // vertical tracking wheel
lemlib::TrackingWheel vertical_tracking_wheel(&vertical_sensor, lemlib::Omniwheel::NEW_2, 0); //last value is based on the tracking center from the middle

lemlib::OdomSensors sensors(&vertical_tracking_wheel, // vertical tracking wheel 1, set to null
                            nullptr, // vertical tracking wheel 2, set to nullptr as we are using IMEs
                            nullptr, // horizontal tracking wheel 1horizontal_tracking_wheel
                            nullptr, // horizontal tracking wheel 2, set to nullptr as we don't have a second one
                            &imu // inertial sensor
                            );

lemlib::ControllerSettings lateral_controller(10, // proportional gain (kP)
                                              0.05, // integral gain (kI)
                                              55, // derivative gain (kD)
                                              3, // anti windup
                                              0.5, // small error range, in inches
                                              350, // small error range timeout, in milliseconds
                                              2, // large error range, in inches
                                              500, // large error range timeout, in milliseconds
                                              0 // maximum acceleration (slew)
);

// angular PID controller
lemlib::ControllerSettings angular_controller(3.0, // proportional gain (kP)
                                              0.001, // integral gain (kI)
                                              45, // derivative gain (kD)
                                              0, // anti windup
                                              0.5, // small error range, in degrees
                                              0, // small error range timeout, in milliseconds
                                              3, // large error range, in degrees
                                              500, // large error range timeout, in milliseconds
                                              0 // maximum acceleration (slew)
);

//these are the default values for the PID, check LEMLIB documentation for tuning when driving.

// create the chassis
lemlib::Chassis chassis(drivetrain, // drivetrain settings
                        lateral_controller, // lateral PID settings
                        angular_controller, // angular PID settings
                        sensors // odometry sensors
);

pros::Motor topMotor(13,pros::v5::MotorGears::blue); 
pros::Motor bottomMotor(-14,pros::v5::MotorGears::blue); 

pros::Motor leftFrontMotor(-4, pros::v5::MotorGears::blue);
pros::Motor leftBottomMotor(-5, pros::v5::MotorGears::blue);
pros::Motor leftTopMotor(-6, pros::v5::MotorGears::blue);
pros::Motor rightFrontMotor(1, pros::v5::MotorGears::blue);
pros::Motor rightBottomMotor(2, pros::v5::MotorGears::blue);
pros::Motor rightTopMotor(3, pros::v5::MotorGears::blue);

pros::adi::Pneumatics scoringPiston('C',true); 
pros::adi::Pneumatics loaderPiston('B',false);
pros::adi::Pneumatics wingPiston('G',false);
pros::adi::Pneumatics middlePiston('A',false);


int autonomousPreSet = 4;


lv_obj_t * labelCoords = NULL;
lv_obj_t * autonomousSubtitle = NULL;
lv_obj_t * labelTemps = NULL;




int countdownValue = 3; //3 second countdown
lv_obj_t * countdownLabel = NULL;

int autonState = 0;       // 0: Idle, 1: Countdown, 2: Running
int gameTimer = 0;        // The match/skills clock



