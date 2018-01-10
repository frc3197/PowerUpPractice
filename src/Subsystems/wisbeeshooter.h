#ifndef wisbeeshooter_H
#define wisbeeshooter_H

#include "Commands/Subsystem.h"
#include "WPILib.h"

class wisbeeshooter: public Subsystem
{
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
public:
	wisbeeshooter();
	void InitDefaultCommand();
};

#endif
