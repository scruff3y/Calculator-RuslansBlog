/*
Interpreter
By: Scruff3y, December 2015- ongoing

This is a mathematical expression inpterpreter, following instructions found in
here:

	http://ruslanspivak.com/lsbasi-part1/ (links to part 1)

Notes:

-

	---------------------------------------------------------------------------

Grammar (modified EBNF notation, as per blog post no. 4):

	expr = term((PLUS | MINUS) term)* 
	term = factor((MULT | DIVI) factor)*
	factor = NUMBER* (LPAR expr RPAR)*		(note; really, only zero or one
	                                      number, not "zero or more")

Where:

	PLUS, MINUS, MULT, DIVI		:		+, -, *, /,  operators respectively.
	NUMBER						:		Any kind of scalar numerical value.
	LPAR, RPAR		         	:		left and right parentheses, respective.

	---------------------------------------------------------------------------

TODO:
	- Implement modulo and exponents.
	- Implement more helpful error messages.
	- Check that all behaves as expected;
  	(2+) should give an error
  	---^ here.
	- Implement better debug solution;
  	Maybe debug class?
  	Add debug command for runtime
  	Logging capability? (command-enabled?)
	- Implement command-line arguments
	- Implement reading from text file
  	Add command to read file in same directory with name;
  	e.g syntax;
		
    	read file.txt

*/

#include <iostream>
#include <string>

#include "token.h"
#include "lexer.h"
#include "parser.h"

int main()
{
	std::string input;

	while (true) {
		std::cout << ":>";
		std::getline(std::cin, input);
		Lexer lexer(input);
		Parser parser(lexer);
		std::cout << std::to_string(parser.expr()) << "\n" << std::endl;
	}

	return 0;
}
