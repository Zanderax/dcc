#pragma once

#include <string>
#include <vector>

struct Token
{
public:
	enum TokenType {
		none,
		keyword_int,
		keyword_return,
		open_brace,
		close_brace,
		open_parenthesis,
		close_parenthesis,
		semicolon,
		literal_integer,
		identifier,
		whitespace,
	};

	Token(TokenType type, std::string text);
	Token(TokenType type, std::vector<char> text);
	Token(TokenType type, char * text);
	Token(char * text);
	~Token();

	static bool isSymbol( char * c );
	static bool isWhitespace(char * c);

	/*const std::vector<std::pair<std::string, TokenType>> regexToType{
		{"int", keyword_int},
		{"return", keyword_return},
		{"{", open_brace},
		{"}", close_brace },
		{"(" , open_parenthesis },
		{")" , close_parenthesis },
		{";" , semicolon},
		{"[0-9]+", literal_integer},
		{"[a-zA-Z]\w*", identifier},
	};*/

private:

	TokenType type_;
	std::string text_;
};

