#include "parser.h"

Parser::Parser() {

}

Parser::Parser(Lexer& lexer) {
	this->parseLexer = &lexer;
	this->currentToken = Token(parseLexer->getNextToken());
}

long double Parser::factor() {
	//std::cout << "Factor" << std::endl;
	/* factor = NUMBER* (LPAR expr RPAR)* */
	// note: in theory, this rule says a factor is;
	// "zero or more NUMBERs followed by zero or more exprs"
	// but in practise there will only ever be zero or one NUMBERs.

	if ((this->currentToken.getType() == Token::NUMBER) ||
		(this->currentToken.getType() == Token::LPAREN) ||
		(this->currentToken.getType() == Token::RPAREN)) {

		long double result = 0;

		if (this->currentToken.getType() == Token::NUMBER) {
			result = this->currentToken.getValue();
			this->eat(Token::NUMBER);
		}
		else if (this->currentToken.getType() == Token::LPAREN) {
			this->eat(Token::LPAREN);
			result = this->expr();
			this->eat(Token::RPAREN);
		}
		else if (this->currentToken.getType() == Token::RPAREN) {
			this->eat(Token::RPAREN);
		}

		if (this->currentToken.getType() == Token::LPAREN) {
			while (this->currentToken.getType() == Token::LPAREN) {
				this->eat(Token::LPAREN);
				result *= this->expr();
				this->eat(Token::RPAREN);
			}
		}

		return result;
	}
	else {
		for (int i = 0; i < this->parseLexer->getPos() + 1; i++) {
			/* ------------------------------------------^
				This is to account for the prompt.
			*/
			std::cout << "-";
		}
		std::cout << "^" << std::endl;
		std::cout << "Unrecognised.\n" << std::endl;
		return -1;
	}
}

long double Parser::term() {
	//std::cout << "Term" << std::endl;
	/* term : factor((MUL|DIV)factor)* */

	long double result = this->factor();

	while (
		(this->currentToken.getType() == Token::MULTI) ||
		(this->currentToken.getType() == Token::DIVI)) {
		Token termToken(this->currentToken);
		if (termToken.getType() == Token::MULTI) {
			this->eat(Token::MULTI);
			result *= this->factor();
		}
		else if (termToken.getType() == Token::DIVI) {
			this->eat(Token::DIVI);
			long double dontDivByZero = this->factor();
			if (!dontDivByZero) {
				std::cout << "You're trying to divide by zero ya cheeky cunt...\n" << std::endl;
				return -1;
			}
			else {
				result /= dontDivByZero;
			}
		}
	}
	return result;

}

long double Parser::expr() {
	//std::cout << "Expression" << std::endl;
	/* expr : term((PLUS|MINUS)term)* */

	long double result = this->term();

	while (
		(this->currentToken.getType() == Token::PLUS) ||
		(this->currentToken.getType() == Token::MINUS)) {
		Token termToken(this->currentToken);
		if (termToken.getType() == Token::PLUS) {
			this->eat(Token::PLUS);
			result += this->term();
		}
		else if (termToken.getType() == Token::MINUS) {
			this->eat(Token::MINUS);
			result -= this->term();
		}
	}
	return result;
}

void Parser::eat(int _TokenType) {
	//std::cout << "Eating " << std::to_string(_TokenType) << std::endl;
	if (this->currentToken.getType() == _TokenType) {
		this->currentToken = this->parseLexer->getNextToken();
	}
	else {
		//this->error("Failed to eat token.\n");
	}
}

void Parser::error(std::string errorMessage) {
	std::cout << "#[Parser] " << errorMessage << currentToken.tokenPrint() << std::endl;
}
