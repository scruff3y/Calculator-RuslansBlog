#ifndef TOKEN_H
#define TOKEN_H

#include <iostream>
#include <string>
#include <map>

/*
This is the basic unit of the interpreter. Tokens have a value
and a type. The Lexer is responsible for identifying tokens within
the input string and then passing them to the Parser, which then
performs the operations defined in the input.

*/

class Token {
public:
	// Default.
	Token();

	// Actual.
	Token(int TYPE, long double VALUE);

	// Copy.
	Token(Token& token);

	// Getters for type and value.
	int getType() const;
	long double getValue() const;

	// Prints token information (type and value).
	std::string tokenPrint();

	Token operator+(Token token);	// Addition
	Token operator-(Token token);	// Subtraction
	Token operator*(Token token);	// Multiply
	Token operator/(Token token);	// Divide

	Token operator-();						// Negation
	Token operator%(Token token);	// Modulo. Note that this will cast the values to int.

	void operator=(Token token);		// Assignment
	bool operator==(Token token);	// Equality

	void operator+=(Token token);	// PLusEquals

	// enum for token types.
	const enum{
		NUMBER	, 
		LPAREN	,
		RPAREN	,
		PLUS	,
		MINUS	,
		MULTI	,
		DIVI	,
		MOD		,
		NONE	,
		END		};

private:
	// map to hold string representations of token.
	static const std::map<const int, const std::string> TypeStr;

	// Type of this token.
	int _Ttype = NONE;

	// Value of this token.
	long double _TValue = 0;
};

#endif
