#include <iostream>
#include <string>
#include <sstream>

#include "Task.hpp"
#include "List.hpp"
#include "FileManager.hpp"


//                     ############### GLOBAL CONSTS ##################

const std::string msgInvalidError = "Error: invalid input.\n";
const std::string msgOptionUnavailable = "This option is not available as the list is empty right now.\n";




//                     ############### HELPER FUNCTIONS ##################

int getIntInput() {                     // GET INTEGER INPUT
	while (true) {

		std::string input;
		std::getline(std::cin, input);
		std::stringstream ss(input);
		int num = 0;
		if (ss >> num) {
			return num;
		}
		std::cout << msgInvalidError;
	}
	
}

bool isAvailable(const List& someList) {  // CHECK IF OPTION IS AVAILABLE
	if (someList.isEmpty()) {
		std::cout << msgOptionUnavailable;
		return false;
	}
	else {
		return true;
	}
}

int promptForIndex(const List& someList, const std::string& promptActionString) {                   // PROMPT FOR INDEX
	std::cout << "Please enter the number of the task you wish to " << promptActionString << ":\n";
	someList.showTasks();
	std::cout << "\n";
	return getIntInput();
}

void promptForDesc(List& someList) {                    // PROMPT FOR DESCRIPTION
	std::cout << "Please enter a task description: \n";

	while(true) {
		std::string desc;
		std::getline(std::cin, desc);

		if (desc.empty()) {
			std::cout << "You must enter a description: \n";
		}
		else {
			someList.addTask(Task(desc));
			break;
		}
	}
}

int main() {                                       // MAIN FUNCTION

	// Initialize variables
	FileManager myFileManager;
	List myList;
	bool running = true;
	const std::string myFileName = "toDoList.txt";
	std::string input;

	// Set myList's vector to whatever is returned by loadTasks
	myList.setTasks(myFileManager.loadTasks(myFileName));

	// Main program loop
	while (running) {

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
		




		// Switch case handling logic for each of the available choices         ############ SWITCH CASE BEGIN ###########
		switch (choice) {


		// Accept description input from user and create a new task on the list
		case 'A':
			promptForDesc(myList);

			break;


		// Remove a chosen task from the list based on index. If list empty, unavailable
		case 'R':
			
			// Check if the option is available
			if (isAvailable(myList)) {

				// Call helper function to prompt for input and return answer as an int
				int num = promptForIndex(myList, "remove");

				if (1 <= num && num <= myList.getTasks().size()) {
					myList.removeTask(num - 1);
				}
				else {
					std::cout << msgInvalidError;
				}
				
			}

			break;


		// Mark complete/incomplete a chosen task from the list based on index. If list empty, unavailable
		case 'C':
			
			// Check if the option is available
			if (isAvailable(myList)) {

				// Call helper function to prompt for input and return answer as an int
				int num = promptForIndex(myList, "mark complete/incomplete");

				if (1 <= num && num <= myList.getTasks().size()) {
					Task& task = myList.getTask(num - 1);
					task.setStatus(!task.getStatus());
				}
				else {
					std::cout << msgInvalidError;
				}
			}

			break;


		// Break out of switch case to simply re-display the list
		case 'S':
			break;


		// Quit out of program by setting running to false
		case 'Q':
			running = false;
			break;


		// Default case lets user know if their input is invalid
		default:
			std::cout << msgInvalidError;
			break;

		} //                                                       ########### SWITCH CASE END ##############
	}

	// Save list to a local file
	myFileManager.saveTasks(myList.getTasks(), myFileName);

}