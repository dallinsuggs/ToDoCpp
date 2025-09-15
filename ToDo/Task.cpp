#include "Task.hpp"

// Constructor definition
Task::Task(std::string description)
	: description(description), isComplete(false) {
}

// Get Description
std::string Task::getDescription()
{
	return description;
}

// Get completion status
bool Task::getStatus()
{
	return isComplete;
}

// Set completion status
void Task::setStatus(bool status)
{
	isComplete = status;
}
