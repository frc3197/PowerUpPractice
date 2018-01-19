#include <Commands/AutoCommands/DriveStraight.h>
#define MAX_TIME 1
#define SPEED 1

DriveStraight::DriveStraight() {
	Requires(robotDrive);

	state = 0;
	finished = false;
}

void DriveStraight::Drive(float s) {
	robotDrive->driveBot(s, s);
}

void DriveStraight::Initialize() {
	timer.Reset();

	timer.Start();
	state = 0;
	finished = false;
}

void DriveStraight::Execute() {
	switch (state)  {
	case 0:
		if (!timer.HasPeriodPassed(MAX_TIME))
			Drive(SPEED);
		else
			state++;
		break;

	case 1:

		finished = true;
		timer.Stop();
		Drive(0);

		break;

	default:
		finished = true;
		break;
	}
}

// Make this return true when this Command no longer needs to run execute()
bool DriveStraight::IsFinished() {
	return finished;
}

// Called once after isFinished returns true
void DriveStraight::End() {
	Drive(0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void DriveStraight::Interrupted() {

}
