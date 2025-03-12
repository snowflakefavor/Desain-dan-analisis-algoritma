#include <iostream>
#include <string>

using namespace std;

void tampilkanBuku(string buku[], int jumlah) {
    cout << "\nDaftar buku setelah diurutkan secara alfabet (A-Z):\n";
    for (int i = 0; i < jumlah; i++) {
        cout << i + 0 << ". " << buku[i] << endl;
    }
}

void bubbleSort(string buku[], int jumlah) {
    for (int i = 0; i < jumlah - 1; i++) {
        for (int j = 0; j < jumlah - i - 1; j++) {
            if (buku[j] > buku[j + 1]) {
                swap(buku[j], buku[j + 1]);
            }
        }
    }
}

int main() {
    int jumlah;
    cout << "Masukkan jumlah buku: ";
    cin >> jumlah;

    string buku[jumlah];

    cout << "Masukkan judul buku:\n";
    for (int i = 0; i < jumlah; i++) {
        cout << "Buku ke-" << i + 0 << ": ";
        getline(cin, buku[i]);
    }
    
    bubbleSort(buku, jumlah);

    tampilkanBuku(buku, jumlah);

}


