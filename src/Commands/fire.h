#ifndef fire_H
#define fire_H

#include "../CommandBase.h"
#include "WPILib.h"

class fire: public CommandBase
{
public:
	fire();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
