#include <iostream>
#include <string>
using namespace std;

class Kontak {
private:
    string nama;
    string nomor;

public:
    Kontak(string n, string no) {
        nama = n;
        nomor = no;
        cout << "Kontak berhasil ditambahkan\n";
    }

    ~Kontak() {
        cout << "Kontak \"" << nama << "\" dihapus dari memori\n";
    }

    void tampilkan(int index) {
        cout << "Kontak ke - " << index + 1 << endl;
        cout << "Nama : " << nama << endl;
        cout << "Nomor Telepon : " << nomor << endl;
        cout << "-------------------------------" << endl;
    }
};

int main() {
    const int maksimal = 10;
    Kontak* daftarKontak[maksimal]; 
    int jumlah = 0;
    char tambah;

    cout << "Masukkan kontak (maksimal 10 kontak)\n\n";

    do {
        string nama, nomor;
        cout << "Masukkan nama kontak ke - " << jumlah + 1 << " : ";
        getline(cin, nama);
        cout << "Masukkan nomor telepon kontak ke - " << jumlah + 1 << " : ";
        getline(cin, nomor);

        daftarKontak[jumlah] = new Kontak(nama, nomor);
        jumlah++;

        if (jumlah >= maksimal) break;

        cout << "Tambahkan kontak lagi? (y/n): ";
        cin >> tambah;
        cin.ignore(); // Membersihkan newline character dari buffer
        cout << endl;
    } while (tambah == 'y' || tambah == 'Y');

    cout << "\nDaftar Kontak:\n";
    for (int i = 0; i < jumlah; i++) {
        daftarKontak[i]->tampilkan(i);
    }

    for (int i = 0; i < jumlah; i++) {
        delete daftarKontak[i];
    }

    return 0;
}

