#include "SortingAlgorithm.h"
#include <time.h>

//main method to test the sorting algorithms
int main() {
	long array[20];
	srand(time(0));
	SortingAlgorithm s;

	//for loop to test each algorithm
	for (string x : {"counting sort", "radix sort"}) {

		cout << "\n		Sorting by " << x << endl;
		cout << "Unsorted array:\t";

		//for loop to generate a random array
		for (int i = 0; i < 20; i++) {
			array[i] = 1 + rand() % 100;
			cout << array[i] << " ";
		}

		cout << "\nSorted array:\t";

		//if statements to select the type of sort
		if (x == "counting sort")s.countingSort(array, (long)(sizeof(array) / sizeof(array[0])));
		if (x == "radix sort")s.radixSort(array, sizeof(array) / sizeof(array[0]));

		//for loop to print the sorted array
		for (int i = 0; i < 20; i++) {
			cout << array[i] << " ";
		}
		cout << endl;
	}
	return 0;
}
