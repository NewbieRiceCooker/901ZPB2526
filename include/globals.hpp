#include "main.h"
#include "lemlib/api.hpp"

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

extern pros::adi::Pneumatics loaderPiston;
extern pros::adi::Pneumatics middlePiston;