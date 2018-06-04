#include "dcc.h"

#include <iomanip>
#include <sstream>

const std::string LOG_DIR = "../../../logs/";

Logger DateTimeLogger(std::string LOG_DIR)
{
	std::time_t currDateTime = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
	std::stringstream logFileName{};
	logFileName << std::put_time(std::localtime(&currDateTime), "%m-%d_%H-%M-%S") ;
	return Logger{ Logger::Output::FILE, LOG_DIR + logFileName.str() };
}

dcc::dcc( std::string filename ) :
	logger_(DateTimeLogger(LOG_DIR))
{
	logger_.log(filename.c_str());
}


dcc::~dcc()
{
}
