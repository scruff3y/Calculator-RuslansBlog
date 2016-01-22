#include "token.h"

// Definition of string representation map.
const std::map<const int, const std::string> Token::TypeStr = {
	{ Token::NUMBER,	"NUMBER" },
	{ Token::LPAREN,	"(" },
	{ Token::RPAREN,	")" },
	{ Token::PLUS,		"+" },
	{ Token::MINUS,		"-" },
	{ Token::MULTI,		"*" },
	{ Token::DIVI,		"/" },
	{ Token::MOD,		"%" },
	{ Token::NONE,		"NONE" },
	{ Token::END,		"END" } };

// Default
Token::Token() {}

// Actual
Token::Token(int TYPE, long double VALUE) {
	this->_Ttype = TYPE;
	this->_TValue = VALUE;
	//std::cout << this->tokenPrint() << std::endl;
}

// Copy
Token::Token(Token& token) {
	this->_Ttype = token.getType();
	this->_TValue = token.getValue();
}

std::string Token::tokenPrint(){
	return "#[Token] Type: " + Token::TypeStr.at(this->_Ttype) + ", Value: " + std::to_string(this->_TValue) + "\n";
}

int Token::getType() const {
	return this->_Ttype;
}

long double Token::getValue() const {
	return this->_TValue;
}

/* Operator overloads;
plus, minus, multiply, divide, negate, modulo, assignment, equality
*/

Token Token::operator+(Token token) {
	// Check that both token operands are indeed numbers.
	if (!((this->_Ttype != NUMBER) || (token._Ttype != NUMBER))) {
		return Token::Token(Token::NUMBER, this->_TValue + token._TValue);
	}
	else {
		//std::cout << "#[+] Error; operands are not numbers." << std::endl;
		this->tokenPrint();
		token.tokenPrint();
	}
}
					   
Token Token::operator-(Token token) {
	// Check that both token operands are indeed numbers.
	if (!((this->_Ttype != NUMBER) || (token._Ttype != NUMBER))) {
		return Token::Token(Token::NUMBER, this->_TValue - token._TValue);
	}
	else {
		//std::cout << "#[-] Error; operands are not numbers." << std::endl;
	}
}

Token Token::operator*(Token token) {
	// Check that both token operands are indeed numbers.
	if (!((this->_Ttype != NUMBER) || (token._Ttype != NUMBER))) {
		return Token::Token(Token::NUMBER, this->_TValue * token._TValue);
	}
	else {
		//std::cout << "#[*] Error; operands are not numbers." << std::endl;
	}
}

Token Token::operator/(Token token) {
	// Check that both token operands are indeed numbers.
	if (!((this->_Ttype != NUMBER) || (token._Ttype != NUMBER))) {
		return Token::Token(Token::NUMBER, this->_TValue / token._TValue);
	}
	else {
		//std::cout << "#[/] Error; operands are not numbers." << std::endl;
	}
}

Token Token::operator-() {
	// Check that both token operands are indeed numbers.
	if (this->_Ttype == NUMBER) {
		return Token::Token(Token::NUMBER, - this->_TValue);
	}
	else {
		//std::cout << "#[negation] Error; operands are not numbers." << std::endl;
	}
}

Token Token::operator%(Token token) {
	// Check that both token operands are indeed numbers.
	if (!((this->_Ttype != NUMBER) || (token._Ttype != NUMBER))) {
		return Token::Token(Token::NUMBER, (int)this->_TValue % (int)token._TValue);
	}
	else {
		//std::cout << "#[%] Error; operands are not numbers." << std::endl;
	}
}

void Token::operator=(Token token) {
	this->_Ttype = token.getType();
	this->_TValue = token.getValue();
}

bool Token::operator==(Token token) {
		return this->_TValue == token._TValue;
}

void Token::operator+=(Token token) {
	this->_TValue += token.getValue();
}
