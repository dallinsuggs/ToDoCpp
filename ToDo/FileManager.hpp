#ifndef FILE_MANAGER_HPP
#define FILE_MANAGER_HPP
#include "Task.hpp"

class FileManager {

private:


public:

	// Constructor declaration
	FileManager();

	// File Manager methods
	void saveTasks(std::vector<Task>& tasks, const std::string& filename);
	std::vector<Task> loadTasks(const std::string& filename);


};

#endif