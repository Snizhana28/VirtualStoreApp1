#include "../../../Internal/library.h"
#ifndef ACTIONHANDLER_H
#define ACTIONHANDLER_H

class ActionHandler
{
public:
	virtual void Create() = 0;
	virtual bool SignIn() = 0;
};
#endif