#ifndef LEXER_H
#define LEXER_H

#include <string>

#include "token.h"

/* 
This is the class responsible for splitting the input string
of the interpreter into tokens. A reference to a Lexer is passed
to the Parser on the Parser's initialisation.

*/

class Lexer {
public:
	// Default.
	Lexer();

	// Actual.
	Lexer(std::string inputString);

	// Finds next token from input string.
	Token getNextToken();
	
	// Increments _pos
	void advance();

	// Skips whitespace characters in input string.
	/* ? I'm implementing this as a separate function, instead of deleting all
	whitespace in the constructor, just in case it is actually neccessary for
	some input... */
	void skipWhitespace();

	// Consumes a number from the input.
	long double number();

	// Prints error message.
	void error(std::string errorMessage);

	// Returns the position in the input.
	/* ? This is called by the Parser when it finds something unexpected. */
	int getPos() { return this->_pos; }

private:
	// Current string being scanned/tokenised.
	std::string _text;

	// Current position of Lexer in parsng input string.
	int _pos = 0;
};

#endif
