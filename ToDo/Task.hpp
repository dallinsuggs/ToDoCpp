#ifndef TASK_HPP
#define TASK_HPP

#include <string>

class Task {

private:
	std::string description;
	bool isComplete;

public:

	// Constructor declaration
	Task(std::string description, bool isComplete = false);

	std::string getDescription();
	bool getStatus();
	void setStatus(bool status);

};

#endif