#include <cstdio>
#include <iostream>
#include <fstream>


#include "dcc.h"

const std::string SAMPLE_DIR = "../../../";

int main()
{
	dcc compiler{ SAMPLE_DIR + "sample_1.c"};
	compiler.Compile();
	return 0;
}