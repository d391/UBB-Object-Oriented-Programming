#pragma once
#include <string>
#include <exception>

class Exception: public std::exception
{
private:
	std::string message;

public:
	Exception(std::string _message) : message{ _message } {};
	const char* what() const noexcept override;
	~Exception();
};

