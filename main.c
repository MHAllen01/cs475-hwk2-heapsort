#include <stdio.h>
#include <string.h>
#include "employee.h"
#include "heap.h"

int main(int argc, char *argv[])
{
	//TODO
	Employee employeeArray[MAX_EMPLOYEES]; // Array of employees to heapsort
	char inputName[MAX_NAME_LEN]; // Array of chars to get the input string name
	int inputSalary = 0; // int variable to get the input salary
	int counter = 0; // Counter for the while condition

	while (counter < MAX_EMPLOYEES) {
		// Get the name of the employee
		scanf("%s", inputName);
		strcpy(employeeArray[counter].name, inputName);
		
		// Get the salary of the employee
		scanf("%d", &inputSalary);
		employeeArray[counter].salary = inputSalary;

		// Increment counter by 1
		counter++;
	}
	// Call the HeapSort algorithm
	heapSort(employeeArray, MAX_EMPLOYEES);

	// Reverse the final list
	reverse(employeeArray, 0, MAX_EMPLOYEES - 1);

	// Print neatly
	printList(employeeArray, MAX_EMPLOYEES);
	return 0;
}
