/*
 * heapsort.c
 *
 *  Created on: Jul 1, 2013
 *      Author:
 */
#include <stdio.h>
#include <stdlib.h>
#include "employee.h"
#include "heap.h"
#include <math.h>

/**
 * Sorts a list of n employees in descending order
 *
 * @param	*A	Pointer to the list of employees
 * @param	n	Size of the heap
 */
void heapSort(Employee *A, int n)
{
	// TODO - BuildHeap on the heap
	// Print unsorted Heap
	printf("\n");
	for (int i = 0; i < 5; i++)
	{
		printf("Name: %s\n", A[i].name);
		printf("Salary: %d\n\n", A[i].salary);
	}
	buildHeap(A, n);
	// TODO - while n > 0:
	while (n > 0) {
		// TODO - swap A[n-1] with A[0], since A[0] is the smallest number.
		swap(&A[n - 1], &A[0]);

		// TODO - A[n-1] now sorted in place, so decrement n
		n--;

		// TODO - Heapify the elements from A[0] up to A[n-1] (which leaves the newly sorted element alone)
		for (int i=0; i < n; i++) {
			heapify(&A[0], n - 1, MAX_EMPLOYEES);
		}
	}
}

/**
 * Given an array A[], we want to get A[] into min-heap property
 * We only need to run heapify() on internal nodes (there are floor(n/2) of them)
 * and we need to run it bottom up (top-down cannot build a heap)
 *
 * @param	*A	Pointer to the list of employees
 * @param	n	Size of the heap
 */
void buildHeap(Employee *A, int n)
{
	// TODO - heapify() every element from A[n/2] down-to A[0]
	int val = floor(n / 2) - 1;
	for (int i = val; i >= 0; i--) {
		heapify(A, i, n);
	}
}

/**
 * We want to start with A[i] and percolate it downward
 * if it is greater than either left or right child.
 *
 * @param	*A	Pointer to the list of employees
 * @param	i	Index of current element to heapify
 * @param	n	Size of the heap
 */
void heapify(Employee *A, int i, int n)
{
		// TODO - get index of left child of element i
		int leftIndex = i;
		// TODO - get index of right child of element i
		int rightIndex = i + 1;
		// TODO - determine which child has a smaller salary. We'll call the index of this
		//		element: "smaller"
		// TODO - Continue recursion as long as i is within range AND either right_child and left_child are still within range.
		int smaller = i;
		if (A[leftIndex].salary < A[smaller].salary  &&  leftIndex < n) {
			smaller = leftIndex;
		}
		if (A[rightIndex].salary < A[smaller].salary  && rightIndex < n) { 
			smaller = rightIndex;
		}
		// TODO - recursively check if the salary at A[i] > the salary at A[smaller]. If it is, swap the two.
		//			Then recursively heapify A[smaller].
		if (A[smaller].salary < A[i].salary) {
			swap(&A[i], &A[smaller]);
			heapify(A, smaller, n);
		}
}

/**
 * Swaps the locations of two Employees
 * @param *e1 An Employee
 * @param *e2 Another Employee to swap with
 */
void swap(Employee *e1, Employee *e2)
{
	// TODO
	Employee tempEmployee = *e1; // Holds the pointer to e1 for temporary storage
	*e1 = *e2;					 // E1 now = E2
	*e2 = tempEmployee;			 // E2 now = tempEmployee which = E1
}


/**
 * Reverses the elements of an Employee array
 * 
 * @param	*A		Pointer to the list of employees
 * @param	start	Starting index
 * @param	end		Ending index
*/
void reverse(Employee *A, int start, int end) {
	// In place traversal of the Employee array
	while (start < end) {
		// Temporary Employee var to preserve order
		Employee tempEmployee = A[start];

		// Set the end of the array to the start
		// Set the start of the array to the end
		A[start] = A[end];
		A[end] = tempEmployee;

		// Properly increment and decrement the parameters
		start++;
		end--;
	}
}

/**
 * Outputs an array of Employees
 * @param	*A	Pointer to the list of employees
 * @param	n	Size of the list
 */
void printList(Employee *A, int n)
{
	// TODO
	for (int i = 0; i < n - 1; i++) {
		// Print up until size-1
		printf("[id=%s sal=%d], ", A[i].name, A[i].salary);
	}

	// Print the last element
	printf("[id=%s sal=%d]\n", A[n - 1].name, A[n - 1].salary);
}