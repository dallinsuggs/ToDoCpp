/*
* Task class

- Default status is false (incomplete).

- getDescription() returns what you passed into the constructor.

- setStatus(true) changes it to complete, and toggling works.
*/
/*

* List class

- New list is empty.

- addTask() increases size by 1.

- removeTask() decreases size by 1.

- getTask(i) returns the correct task.

- Removing the only task makes list empty again.

- Optional: Try removing at an invalid index (see what happens — your code might not check yet).
*/
/*
* FileManager class

- Saving a list to file and reloading gives you the same number of tasks.

- Loaded tasks preserve description and status correctly.
*/
/*
* Integration (end-to-end)

- Add > Save > Load > Confirm that loaded tasks match the original.
*/

#include <cassert>
#include <iostream>

#include "Task.hpp"
#include "List.hpp"
#include "FileManager.hpp"

int main() {
	// Task class tests
	Task t("Walk dog");
	assert(t.getDescription() == "Walk dog");
	assert(t.getStatus() == false);

	t.setStatus(true);
	assert(t.getStatus() == true);

	t.setStatus(false);
	assert(t.getStatus() == false);

	// List class tests
	List myList;
	assert(myList.isEmpty());

	myList.addTask(Task("Write code"));
	assert(!myList.isEmpty());
	assert(myList.getTasks().size() == 1);

	myList.removeTask(3);
	assert(!myList.isEmpty());
	assert(myList.getTasks().size() == 1);

	assert(myList.getTask(0).getDescription() == "Write code");

	myList.setStatus(0, true);

	// FileManager class tests
	FileManager myFileManager;

	std::string myFileName = "toDoList.txt";
	List newList;

	myFileManager.saveTasks(myList.getTasks(), myFileName);
	newList.setTasks(myFileManager.loadTasks(myFileName));

	assert(myList.getTasks().size() == newList.getTasks().size());

	for (int i = 0; i < myList.getTasks().size(); i++) {
		assert(myList.getTasks()[i].getDescription() == newList.getTasks()[i].getDescription());
		assert(myList.getTasks()[i].getStatus() == newList.getTasks()[i].getStatus());
	}

	assert(!myList.isEmpty());
	assert(myList.getTasks().size() == 1);

	assert(myList.getTask(0).getDescription() == "Write code");
	assert(myList.getTask(0).getStatus() == true);

	// Final List test
	myList.removeTask(0);
	assert(myList.isEmpty());

	std::cout << "All tests passed!\n";
}