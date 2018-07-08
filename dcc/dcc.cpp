#include "dcc.h"

#include <iomanip>
#include <sstream>
#include <iostream>
#include <fstream>

const std::string LOG_DIR = "../../../logs/";

Logger DateTimeLogger(std::string LOG_DIR)
{
	std::time_t currDateTime = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
	std::stringstream logFileName{};
	logFileName << std::put_time(std::localtime(&currDateTime), "%m-%d_%H-%M-%S") ;
	return Logger{ Logger::Output::FILE, LOG_DIR + logFileName.str() };
}

dcc::dcc( std::string filename ) :
	logger_(DateTimeLogger(LOG_DIR)),
	sourceFile_(filename)
{
	logger_.log(filename.c_str());
}


dcc::~dcc()
{
	sourceFile_.close();
}


void dcc::Compile() 
{
	if (!sourceFile_.is_open())
	{
		return;
	}
	std::vector<char> currentStringToken;
	char curr[2] = {0};
	while (!sourceFile_.eof())
	{
		curr[0] = (char)sourceFile_.get();
		if (Token::isSymbol(curr) || Token::isWhitespace(curr))
		{
			if (currentStringToken.size() != 0)
			{
				tokens_.push_back( new Token{ Token::TokenType::identifier, currentStringToken } );
				currentStringToken.clear();
			}
			if (Token::isSymbol(curr))
			{
				tokens_.push_back(new Token{ curr });
			}
			continue;
		}
		currentStringToken.push_back(curr[0]);
	}
	tokens_.size();
}