#include "pch.h"
#include <iostream> 
#include <conio.h> 
#include <stdio.h>

using namespace std;

int main() {
	setlocale(0, "");
	cout << "Random array: ";
	int const n = 7;
	int i,j;
	int arr[n];
	for (i = 0; i < n; i++)
		arr[i] = rand() ;
	for (i = 0; i < n; i++)
		cout << arr[i] << " ";

	i = 1;
	cout << endl << "Sorted random array: ";
	while (i < n) {
		j = i;
			while (arr[j] < arr[j - 1]) {
				int p = arr[j];
				arr[j] = arr[j - 1];
				arr[j - 1] = p;
				j--;
			}
		i++;
	}
	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}
	cout <<endl<< "Second array: ";
	int g = 0, k = 0;
	int nechet[7];
	for (i = 0; i < n; i++) {
		if (arr[i] % 2 == 1) {
			nechet[g] = arr[i];
			g++;
			k++;
		}
	}
	for (g = 0; g < k; g++) {
		cout << nechet[g] << " ";
	}
	cout << endl;
	cout <<"Min element of second array: "<< nechet[0] << endl;
	cout <<"Max element of second array: "<< nechet[k-1] << endl;
	int sum = 0;
	for (g = 0; g < k; g++) {
		sum = sum + nechet[g];
	}
	cout <<"Arithmetic average of the array: "<< float(sum / k);
return 0;
}