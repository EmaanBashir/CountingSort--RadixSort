#include <iostream>
#include <queue>
using namespace std;

//class SortingAlgorithm
class SortingAlgorithm {

	//public methods
public:

	//Counting sort
	void countingSort(long data[], const long size) {
		long i, largest = data[0], *temp = new long[size];

		//find the largest number
		for (i = 1; i < size; i++) if (largest < data[i]) largest = data[i];

		//create an array to count the occurance of each number
		unsigned long* count = new unsigned long[largest + 1]; 

		//initialize all indexes of the array to zero
		for (i = 0; i <= largest; i++) count[i] = 0;

		//count the occurances of each number
		for (i = 0; i < size; i++) count[data[i]]++; 

		//convert to cumulative frequency form
		for (i = 1; i <= largest; i++) count[i] += count[i - 1]; 
		
		//put numbers in temp
		for (i = size - 1; i >= 0; i--) temp[--count[data[i]]] = data[i]; 

		//transfer numbers from temp to data
		for (i = 0; i < size; i++) data[i] = temp[i];
	}

	//Radix sort
	void radixSort(long data[], int n) {
		register int d, j, k, factor;
		const int radix = 10, digits = 10;

		//queues
		queue<long> queues[radix];

		//loop to access the dth digit of each number
		for (d = 0, factor = 1; d < digits; factor *= radix, d++) {

			//put the numbers with the same dth digit in separate queues
			for (j = 0; j < n; j++) {
				queues[(data[j] / factor) % radix].push(data[j]);
			}

			//insert the sorted numbers in the array
			for (j = k = 0; j < radix; j++) {
				while (!queues[j].empty()) {
					data[k++] = queues[j].front();
					queues[j].pop();
				}
			}
		}
	}
};
