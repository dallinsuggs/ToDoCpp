#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>

#include "FileManager.hpp"


FileManager::FileManager()
{
}

void FileManager::saveTasks(std::vector<Task>& tasks, const std::string& filename)
{
	std::ofstream outFile(filename);

	// Make sure myFile was successfully created and accessed
	if (!outFile) {
		std::cerr << "Could not open file for writing\n";
		return;
	}

	for (Task& task : tasks) {
		outFile << task.getStatus() << "|" << task.getDescription() << "\n";
	}
}

std::vector<Task> FileManager::loadTasks(const std::string& filename)
{
	std::vector<Task> tasks;
	std::ifstream inFile(filename);

	if (!inFile) {
		std::cerr << "Could not open file for writing\n";
		return tasks;
	}

	std::string line;
	while (std::getline(inFile, line)) {
		std::stringstream ss(line);
		std::string statusString, description;

		if (std::getline(ss, statusString, '|') && std::getline(ss, description)) {
			bool status = (statusString == "1");
			tasks.push_back(Task(description, status));
		}

	}

	return tasks;
}
