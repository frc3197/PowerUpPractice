#include "RobotDriveWithJoystick.h"

#include "../Commands/TankControl.h"

#include "../RobotMap.h"

RobotDriveWithJoystick::RobotDriveWithJoystick() :
		Subsystem("RobotDriveWithJoystick"),
			can1(1), can2(2), can3(3), can4(4),
			rDrive(can1, can2, can3, can4)
{
	rDrive.SetSafetyEnabled(false);

}

void RobotDriveWithJoystick::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	// SetDefaultCommand(new MySpecialCommand());
	SetDefaultCommand(new TankControl());
}

void RobotDriveWithJoystick::driveBot(float left, float right){
	rDrive.TankDrive(left, right, false);
}

// Put methods for controlling this subsystem
// here. Call these from Commands.

