/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include <Commands/Command.h>
#include <Commands/Scheduler.h>
#include <LiveWindow/LiveWindow.h>
#include <SmartDashboard/SendableChooser.h>
#include <SmartDashboard/SmartDashboard.h>
#include <IterativeRobot.h>
//Random Comment
#include "Commands/ExampleCommand.h"
#include "Commands/AutoCommands/MyAutoCommand.h"
#include "Commands/AutoCommands/DriveStraight.h"

class Robot: public frc::IterativeRobot {
private:
	std::unique_ptr<frc::Command> autoCommand;
	frc::SendableChooser<frc::Command*> chooser;
	MyAutoCommand defaultAuto;
	DriveStraight straightAuto;

public:
	void RobotInit() override {
		chooser.AddDefault("Default Auto", &defaultAuto);
		chooser.AddObject("Drive Straight", &straightAuto);
		frc::SmartDashboard::PutData("Auto Modes", &chooser);
	}

	void AutonomousInit() override {
		autoCommand.reset(chooser.GetSelected());
		if(autoCommand.get() != nullptr)
			autoCommand->Start();
	}

	void AutonomousPeriodic() override {
		frc::Scheduler::GetInstance()->Run();
	}

	void DisabledInit() override {
	}

	void DisabledPeriodic() override {
		frc::Scheduler::GetInstance()->Run();
	}

	void TeleopInit() override {
		if (autoCommand != nullptr) {
			autoCommand ->Cancel();
			autoCommand = nullptr;
		}
	}

	void TeleopPeriodic() override {
		frc::Scheduler::GetInstance()->Run();
	}

	void TestPeriodic() override {
	}

};

START_ROBOT_CLASS(Robot)
