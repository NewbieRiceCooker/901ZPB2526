#include "main.h"
#include "lemlib/api.hpp"
#include "liblvgl/lvgl.h"

extern pros::MotorGroup left_motors;
extern pros::MotorGroup right_motors; 



//lemlib features

extern lemlib::Drivetrain drivetrain;

extern pros::Imu imu;
extern pros::Rotation vertical_sensor;
extern pros::Rotation horizontal_sensor;

extern lemlib::TrackingWheel vertical_tracking_wheel;
extern lemlib::TrackingWheel horizontal_tracking_wheel;

extern lemlib::OdomSensors sensors;

extern lemlib::ControllerSettings lateral_controller;
extern lemlib::ControllerSettings angular_controller;

extern lemlib::Chassis chassis;

extern pros::Motor intakeMotor;
extern pros::Motor scoringMotor;

extern pros::Motor leftFrontMotor;
extern pros::Motor leftBottomMotor;
extern pros::Motor leftTopMotor;
extern pros::Motor rightFrontMotor;
extern pros::Motor rightBottomMotor;
extern pros::Motor rightTopMotor;

extern pros::adi::Pneumatics loaderPiston;
extern pros::adi::Pneumatics middlePiston;
extern pros::adi::Pneumatics wingPiston;

extern int autonomousPreSet;

extern lv_obj_t * autonomousSubtitle;
extern lv_obj_t * labelCoords;
extern lv_obj_t * labelTemps;


extern int countdownValue; //3 second countdown
extern lv_obj_t * countdownLabel;

extern int autonState;       // 0: Idle, 1: Countdown, 2: Running
extern int countdownValue;   // The 3-2-1 before start
extern int gameTimer;        // The match/skills clock


