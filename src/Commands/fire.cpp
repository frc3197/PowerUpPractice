#include "fire.h"

fire::fire()
{

	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
}

// Called just before this Command runs the first time
void fire::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void fire::Execute()
{

}

// Make this return true when this Command no longer needs to run execute()
bool fire::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void fire::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void fire::Interrupted()
{

}
