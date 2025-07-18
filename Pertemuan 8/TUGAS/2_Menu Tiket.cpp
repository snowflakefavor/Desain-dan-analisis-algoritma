#include <iostream>
#define MAX 100

using namespace std;

class AntrianTiket {
private:
    string queue[MAX];
    int front, rear;

public:
    AntrianTiket() {
        front = rear = -1;
    }

    bool isFull() {
        return rear == MAX - 1;
    }

    bool isEmpty() {
        return front == -1 || front > rear;
    }

    void enqueue(string nama) {
        if (isFull()) {
            cout << "Antrian penuh! " << nama << " tidak dapat masuk.\n";
            return;
        }
        if (isEmpty()) {
            front = rear = 0;
        } else {
            rear++;
        }
        queue[rear] = nama;
        cout << nama << " masuk ke dalam antrian.\n";
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Antrian kosong! Tidak ada yang bisa diproses.\n";
            return;
        }
        cout << queue[front] << " telah dilayani dan keluar dari antrian.\n";
        front++;
    }

    void tampilkanAntrian() {
        if (isEmpty()) {
            cout << "Antrian kosong.\n";
            return;
        }
        cout << "Daftar antrian saat ini:\n";
        for (int i = front; i <= rear; i++) {
            cout << i - front + 1 << ". " << queue[i] << endl;
        }
    }
};

int main() {
    AntrianTiket antrian;
    int pilihan;
    string nama;

    do {
        cout << "\n--- Menu Loket Tiket ---\n";
        cout << "1. Tambah Antrian\n";
        cout << "2. Layani Antrian\n";
        cout << "3. Tampilkan Antrian\n";
        cout << "4. Keluar\n";
        cout << "Pilihan: ";
        cin >> pilihan;

        switch (pilihan) {
        case 1:
            cout << "Masukkan nama: ";
            cin >> nama;
            antrian.enqueue(nama);
            break;
        case 2:
            antrian.dequeue();
            break;
        case 3:
            antrian.tampilkanAntrian();
            break;
        case 4:
            cout << "Terima kasih, program selesai.\n";
            break;
        default:
            cout << "Pilihan tidak valid.\n";
        }
    } while (pilihan != 4);
}
