#pragma once
#include <string>

class AbstractCommand {
public:
	~AbstractCommand() = default;
	virtual int execute(std::string) = 0;
	virtual void displayInfo() = 0;

};