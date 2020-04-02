#include "Exception.h"


const char* Exception::what() const noexcept 
{
	return this->message.c_str();
}


Exception::~Exception()
{
}
