#include <iostream>
using namespace std;

int main() {
    int data[] = {0, 6, 12, 18, 24};
    int jumlah = sizeof(data) / sizeof(data[0]);
    int cari, i;
    bool ditemukan = false;

    cout << "Masukkan data yang dicari: ";
    cin >> cari;

    for (i = 0; i < jumlah; i++) {
        if (data[i] == cari) {
            ditemukan = true;
            break;
        }
    }

    if (ditemukan) {
        cout << "Bilangan ditemukan di indeks ke-" << i << "." << endl;
    } else {
        cout << "Bilangan tidak ditemukan." << endl;
    };
}
