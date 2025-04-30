#include <iostream>
using namespace std;

void swap(string &a, string &b) {
    string temp = a;
    a = b;
    b = temp;
}

void sortBooks(string books[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (books[j] > books[j + 1]) {
                swap(books[j], books[j + 1]);
            }
        }
    }
}

int binarySearch(string books[], int size, string target) {
    int left = 0, right = size - 1;
    while (left <= right) {
        int mid = (left + right) / 2;
        if (books[mid] == target) {
            return mid;
        } else if (books[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return -1;
}

int main() {
    const int size = 5;
    string books[size] = {
        "Kalkulus Dasar",
        "Dasar Pemrograman C++",
        "Sistem Operasi",
        "Algoritma dan Struktur Data",
        "Jaringan Komputer"
    };

    sortBooks(books, size);

    string searchTitle;
    cout << "Masukkan judul buku yang ingin dicari: ";
    getline(cin, searchTitle);

    int index = binarySearch(books, size, searchTitle);

    if (index != -1) {
        cout << "Buku ditemukan di indeks ke-" << index << ": " << books[index] << endl;
    } else {
        cout << "Buku tidak ditemukan." << endl;
    };
}
