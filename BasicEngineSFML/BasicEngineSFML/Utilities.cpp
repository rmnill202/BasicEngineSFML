#include "Utilities.h"

GameException::GameException (char * text, ExceptionType type) {
	exception_text = text;
	exception_type = type; 
}

const char * GameException::what() const throw()
{
	return this->exception_text;
}

GameException::ExceptionType GameException::type()
{
	return exception_type;
}