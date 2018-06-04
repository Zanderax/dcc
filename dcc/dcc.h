#pragma once

#include <string>

#include "Logger.h"

class dcc
{
public:
	dcc(std::string filename);
	~dcc();

private:
	Logger logger_;
};

