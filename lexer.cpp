#include "lexer.h"

Lexer::Lexer() {
}

Lexer::Lexer(std::string inputString) {
	this->_text = inputString;
	//std::cout << "Input text:\n" << inputString << std::endl;
}
Token Lexer::getNextToken() {
	//std::cout << "Getting next token" << std::endl;
	int textLength = this->_text.length();
	while (this->_pos < textLength) {
		if (this->_text.at(this->_pos) == 0x20) {
			this->skipWhitespace();
		}

		if (this->_text.at(this->_pos) == '+') {
			this->advance();
			//std::cout << "Found + token" << std::endl;
			return Token::Token(Token::PLUS, '+');
		}
		else if (this->_text.at(this->_pos) == '-') {
			this->advance();
			//std::cout << "Found - token" << std::endl;
			return Token::Token(Token::MINUS, '-');
		}
		else if (this->_text.at(this->_pos) == '*') {
			this->advance();
			//std::cout << "Found * token" << std::endl;
			return Token::Token(Token::MULTI, '*');
		}
		else if (this->_text.at(this->_pos) == '/') {
			this->advance();
			//std::cout << "Found / token" << std::endl;
			return Token::Token(Token::DIVI, '/');
		}
		else if (this->_text.at(this->_pos) == '(') {
			this->advance();
			//std::cout << "Found ( token" << std::endl;
			return Token::Token(Token::LPAREN, '(');
		}
		else if (this->_text.at(this->_pos) == ')') {
			this->advance();
			//std::cout << "Found ) token" << std::endl;
			return Token::Token(Token::RPAREN, ')');
		}
		else if ((this->_text.at(this->_pos) >= 0x30) && (this->_text.at(this->_pos) <= 0x39)) {
			//std::cout << "Found NUMBER token" << std::endl;
			return Token::Token(Token::NUMBER, this->number());
		}
		std::string errorText = "Failed to switch char at: ";
		errorText += std::to_string(this->_pos);
		errorText += "\n";
		//this->error(errorText);
	}
	return Token(Token::END, -1);
}

void Lexer::advance() {
	//std::cout << "Advancing..." << std::endl;
	this->_pos++;
}

void Lexer::skipWhitespace() {
	//std::cout << "Skipping space character" << std::endl;
	while (this->_text.at(this->_pos) == 0x20) {
		this->advance();
	}
}

long double Lexer::number() {
	//std::cout << "Number" << std::endl;
	std::string numberReturn = "0";

	int textLength = this->_text.length();
	while ((this->_pos < textLength) && ((this->_text.at(this->_pos) >= '0') && (this->_text.at(this->_pos) <= '9') || (this->_text.at(this->_pos) == '.')) ) {
		numberReturn += this->_text.at(this->_pos);
		this->advance();
	}
	//std::cout << "value: " << numberReturn << std::endl;
	return std::stold(numberReturn);
}

void Lexer::error(std::string errorMessage) {
	std::cout << "#[Lexer]-> " << errorMessage << std::endl;
}
