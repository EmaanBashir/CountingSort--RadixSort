#include "SortingAlgorithm.h"
#include <time.h>

//main method
int main() {
	int n;
	srand(time(0));
	SortingAlgorithm s;
	clock_t start;
	long* array1, * array2;

	//loop to create arrays of size 100, 1000, 10000, 100000, 1000000
	for (int i = 100; i <= 1000000; i *= 10) {
		cout << "Array of size: " << i << endl;
		array1 = new long[i];
		array2 = new long[i];

		//loop to assign random integers to the arrays
		for (int j = 0; j < i; j++) {
			n = 1 + rand() % 100;
			array1[j] = n;
			array2[j] = n;
		}

		//calculating execution time for bubble sort
		cout << "\nCounting Sort: ";
		start = clock();
		s.countingSort(array1, i);
		cout << (double)(clock() - start) / CLOCKS_PER_SEC << "s";

		//calculating execution time for insertion sort
		cout << "\nRadix Sort: ";
		start = clock();
		s.radixSort(array2, i);
		cout << (double)(clock() - start) / CLOCKS_PER_SEC <<"s";

		cout << endl << endl;
	}
	return 0;
}
