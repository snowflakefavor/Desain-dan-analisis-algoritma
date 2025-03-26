#include <iostream>
using namespace std;

class Buku {
private:
    string judul;
    string pengarang;
    int tahunTerbit;
    int stok;

public:
    Buku(string j, string p, int t, int s) {
        judul = j;
        pengarang = p;
        tahunTerbit = t;
        stok = s;
    }

    string getJudul() {
        return judul;
    }

    string getPengarang() {
        return pengarang;
    }

    int getTahunTerbit() {
        return tahunTerbit;
    }

    int getStok() {
        return stok;
    }

    void pinjamBuku() {
        if (stok > 0) {
            stok--;
            cout << "Buku '" << judul << "' berhasil dipinjam.\n";
        } else {
            cout << "Buku '" << judul << "' sedang tidak tersedia.\n";
        }
    }

    void kembalikanBuku() {
        stok++;
        cout << "Buku '" << judul << "' telah dikembalikan.\n";
    }
};

int main() {
    Buku buku1("Bumi Manusia", "Pramoedya Ananta Toer", 1980, 3);
    Buku buku2("Ayah Ini Arahnya Kemana, Ya?", "Khoirul Trian", 2024, 2);

    cout << "Daftar BuAyah Ini Arahnya Kemana, Ya?ku di Perpustakaan:\n";
    cout << "1. " << buku1.getJudul() << " - " << buku1.getPengarang() 
         << " (" << buku1.getTahunTerbit() << ") [Stok: " << buku1.getStok() << "]\n";
    cout << "2. " << buku2.getJudul() << " - " << buku2.getPengarang() 
         << " (" << buku2.getTahunTerbit() << ") [Stok: " << buku2.getStok() << "]\n";

    buku1.pinjamBuku();
    buku2.pinjamBuku();

    cout << "\nStok setelah peminjaman:\n";
    cout << "1. " << buku1.getJudul() << " [Stok: " << buku1.getStok() << "]\n";
    cout << "2. " << buku2.getJudul() << " [Stok: " << buku2.getStok() << "]\n";

    buku1.kembalikanBuku();

    cout << "\nStok setelah pengembalian:\n";
    cout << "1. " << buku1.getJudul() << " [Stok: " << buku1.getStok() << "]\n";
    cout << "2. " << buku2.getJudul() << " [Stok: " << buku2.getStok() << "]\n";

    return 0;
}

