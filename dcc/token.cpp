#include "token.h"



Token::Token(TokenType type, std::string text)
	: type_(type), text_(text)
{
}

Token::Token(TokenType type, std::vector<char> text)
	: type_(type), text_(text.begin(), text.end())
{
}

Token::Token(TokenType type, char * text)
	: type_(type), text_(text)
{
}

Token::Token(char * text)
	: text_(text)
{
	switch (*text)
	{
		case '{':
			type_ = TokenType::open_brace;
			break;
		case '}':
			type_ = TokenType::close_brace;
			break;
		case '(':
			type_ = TokenType::open_parenthesis;
			break;
		case ')':
			type_ = TokenType::close_parenthesis;
			break;
		case ';':
			type_ = TokenType::semicolon;
			break;
		default:
			type_ = TokenType::none;
	}
}


Token::~Token()
{
}

bool Token::isSymbol(char * c)
{
	return (*c == '{' || *c == '}' || *c == '(' || *c == ')' || *c == ';');
}

bool Token::isWhitespace(char * c)
{
	return *c == ' ' || *c == '\r' || *c == '\n' || *c == '\t';
}