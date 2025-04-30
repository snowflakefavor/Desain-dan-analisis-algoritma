#include <iostream>
#include <string>
using namespace std;

void bubbleSort(string arr[], int n) {
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                // Tukar posisi
                string temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

int main() {
    string buku[] = {
        "Struktur Data",
        "Algoritma Dasar",
        "Pemrograman C++",
        "Jaringan Komputer",
        "Basis Data"
    };
    int jumlah = sizeof(buku) / sizeof(buku[0]);

    cout << "Sebelum sorting:" << endl;
    for (int i = 0; i < jumlah; i++) {
        cout << buku[i] << endl;
    }

    // Lakukan pengurutan
    bubbleSort(buku, jumlah);

    cout << "\nSetelah sorting (alfabetis):" << endl;
    for (int i = 0; i < jumlah; i++) {
        cout << buku[i] << endl;
    };
}
