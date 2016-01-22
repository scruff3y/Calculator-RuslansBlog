#ifndef PARSER_H
#define PARSER_H

#include <string>

#include "lexer.h"
#include "token.h"

/*
Rules:

expr : term((PLUS|MINUS)term)*
term : factor((MUL|DIV)factor)*
factor : NUMBER | LPAREN expr RPAREN

*/

/*
Parses the input, using the Lexer to tokenise the input.

*/
class Parser {
public:
	// Default.
	Parser();

	// Actual.
	Parser(Lexer& lexer);

	// [GrammarRule] Returns value of a factor.
	long double factor();

	// [GrammarRule] Returns value of a term.
	long double term();

	// [GrammarRule] Returns value of an expression.
	long double expr();

	// Eats a token of the specified type, and prints error if otherwise.
	void eat(int _TokenType);

	// Prints error message.
	void error(std::string errorMessage);

private:
	// Reference to a Lexer (tokeniser) for the Parser. 
	Lexer* parseLexer;

	// Current token being parsed.
	Token currentToken;
};

#endif
