#include "Task.hpp"

// Constructor definition
Task::Task(std::string description, bool isComplete)
	: description(description), isComplete(isComplete) {
}

// Get Description
std::string Task::getDescription() const
{
	return description;
}

// Get completion status
bool Task::getStatus() const
{
	return isComplete;
}

// Set completion status
void Task::setStatus(bool status)
{
	isComplete = status;
}
