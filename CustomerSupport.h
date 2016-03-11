#ifndef CustomerSupport_h_
#define CustomerSupport_h_

#include <iostream>
#include "IRunnable.h"


class CustomerSupport:public IRunnable
{
public:
	void run(Server);
};

#endif

