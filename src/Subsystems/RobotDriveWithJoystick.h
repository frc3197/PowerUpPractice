#ifndef ROBOT_DRIVE_JOYSTICK_H
#define ROBOT_DRIVE_JOYSTICK_H

#include <Commands/Subsystem.h>
#include "WPILib.h"
#include <C:\Users\Hexhounds\wpilib\user\cpp\include\CANTalon.h>

class RobotDriveWithJoystick: public Subsystem {
public:
	RobotDriveWithJoystick();
	void InitDefaultCommand() override;
	void driveBot(float left, float right);
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
	RobotDrive rDrive;
	CANTalon can1;
	CANTalon can2;
	CANTalon can3;
	CANTalon can4;
};

#endif //ROBOT_DRIVE_JOYSTICK_H
