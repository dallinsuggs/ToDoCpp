#include <iostream>
#include <string>
#include <sstream>

#include "Task.hpp"
#include "List.hpp"


int getIntInput() {
	std::string input;

	std::getline(std::cin, input);
	std::stringstream ss(input);
	int num = 0;
	if (ss >> num) {
		return num;
	}
	std::cout << "Invalid number.\n";
	return -1;
	
}

int main() {

	// Initialize variables
	List myList;
	bool running = true;
	std::string input;

	// Main program loop
	while (true) {

		// If running is false quit program
		if (running == false) {
			break;
		}

		// Display to-do list, then list user options
		myList.showTasks();
		myList.showOptions();

		// Accept choice input from user
		std::cout << "\n";
		std::getline(std::cin, input);
		std::cout << "\n";

		// Check for empty input
		if (input.empty()) continue;

		// Take the first char of input string to use as choice char for menu options
		char choice = std::toupper(input[0]);
		

		// Switch case handling logic for each of the available choices
		switch (choice) {

		// Accept description input from user and create a new task on the list
		case 'a':
		case 'A': {
				std::cout << "Please enter a task description: \n";
				std::string desc;

				// Accept the user input
				std::getline(std::cin, desc);
				myList.addTask(Task(desc));
				break;
		}

		// Remove a chosen task from the list based on index. If list empty, unavailable
		case 'r':
		case 'R': {
			if (myList.isEmpty()) {
				std::cout << "This option is not available as the list is empty right now.\n";
				break;
			} 
			else {
				std::cout << "Please enter the number of the task you wish to remove: \n";
				myList.showTasks();
				std::cout << "\n";

				// Call helper function to get input as an int
				int num = getIntInput();
				myList.removeTask(num - 1);
				break;
			}
		}

		// Mark complete/incomplete a chosen task from the list based on index. If list empty, unavailable
		case 'c':
		case 'C': {
			if (myList.isEmpty()) {
				std::cout << "This option is not available as the list is empty right now.\n";
				break;
			}

			std::cout << "Please enter the number of the task you wish mark complete or incomplete: \n";
			myList.showTasks();

			// Call helper function to get input as an int
			int num = getIntInput();
			Task& task = myList.getTask(num - 1);
			task.setStatus(!task.getStatus());
			break;
		}

		// Break out of switch case to simply re-display the list
		case 's':
		case 'S':
			break;

		// Quit out of program by setting running to false
		case 'q':
		case 'Q':
			running = false;
			break;

		}
	}

}