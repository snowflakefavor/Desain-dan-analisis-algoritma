#include <iostream>
#include <algorithm>

using namespace std;

const int D = 100;
int angka [D] = {11, 22, 33, 44, 55, 66, 77};

int binarySearch(int x, int l, int r) {
    if (r >= l) {
        int mid = l + (r - l) / 2;

        if (angka[mid] == x)
            return mid;

        if (angka[mid] > x)
            return binarySearch(x, l, mid - 1);

        return binarySearch(x, mid + 1, r);
    }

    return -1;
}

int main() {
    int n;
    cout << "Masukkan jumlah angka: ";
    cin >> n;

    cout << "Masukkan angka :" << endl;
    for (int i = 0; i < n; i++) {
        cin >> angka[i];
    }
    
    sort(angka, angka + n);

    int x;
    cout << "Masukkan angka yang dicari: ";
    cin >> x;

    int hasil = binarySearch(x, 0, n - 1);

    if (hasil == -1)
        cout << "angka tidak ditemukan" << endl;
    else
        cout << "angka ditemukan pada indeks " << hasil << endl;

    return 0;
}
