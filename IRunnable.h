#ifndef IRunnable_h_
#define IRunnable_h_
#include "Server.h"
class IRunnable
{
public:
	virtual void run(Server) = 0;
};

#endif
