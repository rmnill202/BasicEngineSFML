/*
* Created: 07/11/2016
*
* Contains a number of general utilities for the application, such as specific math functions
*   or exceptions.
*
*/
#pragma once
#include <exception>
#include <SFML/Graphics/RenderWindow.hpp>

/* Handles basic exceptions, with custom text */
class GameException : public std::exception
{
public:
	enum ExceptionType { /* Refers to the type and severity of the error. Handling will vary accordingly */
		DEBUG = 0,
		INFO = 1,
		WARNING = 2,
		ERROR = 3,
		FATAL = 4
	};

	GameException(char * text, ExceptionType type);
	virtual const char* what() const throw(); 
	ExceptionType type();

private:
	char * exception_text;
	ExceptionType exception_type;
};