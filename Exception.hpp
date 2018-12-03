#pragma once
#include <string>

class Exception{
	std::string message;//soobsheniye isklucheniya
public:
	Exception(const std::string& message = "Exception");
	Exception(const Exception& e);
	~Exception();
	const std::string& what()const;//vivodim soobsheniye isklucheniya
};