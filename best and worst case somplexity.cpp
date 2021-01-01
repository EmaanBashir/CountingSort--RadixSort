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

		//'''Bubble sort'''
		cout << "\n\n\t'Counting Sort'";

		//Descending Order
		cout << "\nDescending Order: ";
		sort(array1, array1 + i, greater<int>());
		start = clock();
		s.countingSort(array1, i);
		cout << (double)(clock() - start) / CLOCKS_PER_SEC << " s";

		//Ascending Order
		cout << "\nAscending Order: ";
		start = clock();
		s.countingSort(array1, i);
		cout << (double)(clock() - start) / CLOCKS_PER_SEC << " s";

		//'''Selection Sort'''
		cout << "\n\n\t'Radix Sort'";

		//Descending Order
		cout << "\nDescending Order: ";
		sort(array2, array2 + i, greater<int>());
		start = clock();
		s.radixSort(array2, i);
		cout << (double)(clock() - start) / CLOCKS_PER_SEC << " s";

		//Ascending Order
		cout << "\nAscending Order: ";
		start = clock();
		s.radixSort(array2, i);
		cout << (double)(clock() - start) / CLOCKS_PER_SEC << " s";

		cout << "\n\n\n";
	}
	return 0;
}
