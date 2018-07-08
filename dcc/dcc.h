#pragma once

#include "Logger.h"
#include "token.h"

#include <fstream>
#include <string>
#include <vector>

class dcc
{
public:
	dcc(std::string filename);
	~dcc();
	void Compile();
private:
	Logger logger_;
	std::ifstream sourceFile_;
	std::vector<Token*> tokens_;
};

