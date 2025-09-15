#include<iostream>
#include<string>

#include "Task.hpp"
#include "List.hpp"




int main() {

	// Initialize variables
	List myList;
	bool running = true;

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
		char choice;
		std::cout << "\n";
		std::cin >> choice;
		std::cout << "\n";

		// Switch case handling logic for each of the available choices
		switch (choice) {

		// Accept description input from user and create a new task on the list
		case 'a':
		case 'A': {
				std::cout << "Please enter a task description: \n";
				std::string desc;
				std::cin >> desc;
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

				int num;
				std::cin >> num;
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
			else {
				std::cout << "Please enter the number of the task you wish mark complete or incomplete: \n";
				myList.showTasks();

				std::cout << "\n";
				int num;
				std::cin >> num;
				myList.setStatus(num - 1, !myList.getTask(num).getStatus());
				break;
			}
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