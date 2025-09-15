#include <iostream>
#include <unordered_map>
#include <string>

#include "List.hpp"

List::List()
{
}

void List::addTask(const Task& task)
{
	tasks.push_back(task);
}

void List::removeTask(int index)
{
	tasks.erase(tasks.begin() + index);
}

void List::setStatus(int index, bool status)
{
	tasks[index].setStatus(status);
}

Task List::getTask(int index)
{
	return tasks[index];
}

void List::showTasks()
{
	// Create unordered map to tell cout what to print if completed is false or true
	std::unordered_map<bool, std::string> completedStatus = {
		{true, "[x]"},
		{false, "[ ]"}
	};

	std::cout << "\n-------------------------------\n";

	for (int i = 0; i < tasks.size(); i++) {
		std::cout << i + 1 << completedStatus[tasks[i].getStatus()] << " " << tasks[i].getDescription() << "\n";
	}
	if (isEmpty()) {
		std::cout << "Your to-do list is empty.\n";
	}

	std::cout << "-------------------------------\n\n";
}

bool List::isEmpty()
{
	if (tasks.size() == 0) {
		return true;
	}
	else {
		return false;
	}
}

void List::showOptions()
{
	std::cout << "A = add task\n";
	std::cout << "R = remove task"
		<< (isEmpty() ? " (unavailable)" : "")
		<< "\n";
	std::cout << "C = mark/unmark complete"
		<< (isEmpty() ? " (unavailable)" : "")
		<< "\n";
	std::cout << "S = show list\n";
	std::cout << "Q = quit\n";
}

