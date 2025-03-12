#include <iostream>
using namespace std;

void bubbleSort (int arr[], int n){
	int i, j, tmp;
	for (i = 0; i < n; i++){
		for (j = 0; j < n - i - l; j++){
			if (arr [j] > arr [j + l]) {
				tmp = arr [j] ;
				arr [j] = arr [j + l];
				arr [j + l] = tmp;
			}
		}
	}	
}
int main (){
	int array [100], n , i, j;
	cout << "Masukkan banyak elemen: " ;
	cin>> n;
	cout << "Masukkan nilai: \n" ;
	for (i = 0; i < n; i++){
		cin >> array [i];
	}
	bubbleSort (array, n);
	cout << "Hasil pengurutan dengan algoritma bubble sort: \n";
	for (i = 0; i < n; i++){
		cout << array [i] << " ";
	}
	cout <<< "\n";
}
