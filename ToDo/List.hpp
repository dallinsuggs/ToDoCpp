#ifndef LIST_HPP
#define LIST_HPP

#include <vector>
#include "Task.hpp"

class List {

private:
	std::vector<Task> tasks;

public:

	// Constructor declaration
	List();

	void addTask(const Task& task);
	void removeTask(int index);
	void setStatus(int index, bool status);
	Task& getTask(int index);
	void showTasks();
	bool isEmpty();
	void showOptions();
};

#endif