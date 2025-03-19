#include <iostream>  // Menggunakan pustaka iostream untuk input dan output
using namespace std; // Menggunakan namespace std agar tidak perlu menuliskan std::

// Fungsi untuk menggabungkan dua bagian array yang sudah terurut
void merge(int arr[], int l, int m, int r) {
    int x, y, z;
    int n1 = m - l + 1; // Panjang subarray kiri
    int n2 = r - m;     // Panjang subarray kanan

    // Membuat array sementara untuk menampung elemen dari subarray kiri dan kanan
    int L[n1], R[n2];

    // Menyalin data ke array sementara L dan R
    for (x = 0; x < n1; x++)
        L[x] = arr[l + x];
    for (y = 0; y < n2; y++)
        R[y] = arr[m + 1 + y];

    x = 0; // Indeks awal subarray kiri
    y = 0; // Indeks awal subarray kanan
    z = l; // Indeks awal subarray yang akan digabungkan ke array utama

    // Menggabungkan kembali kedua subarray ke dalam array utama
    while (x < n1 && y < n2) {
        if (L[x] <= R[y]) { // Jika elemen di L lebih kecil, masukkan ke array utama
            arr[z] = L[x];
            x++;
        } else { // Jika elemen di R lebih kecil, masukkan ke array utama
            arr[z] = R[y];
            y++;
        }
        z++;
    }

    // Menyalin sisa elemen di subarray kiri (jika masih ada)
    while (x < n1) {
        arr[z] = L[x];
        x++;
        z++;
    }

    // Menyalin sisa elemen di subarray kanan (jika masih ada)
    while (y < n2) {
        arr[z] = R[y];
        y++;
        z++;
    }
}

// Fungsi rekursif untuk mengimplementasikan Merge Sort
void mergeSort(int arr[], int l, int r) {
    if (l < r) { 
        int m = l + (r - l) / 2; // Menentukan titik tengah array

        // Rekursif membagi array menjadi dua bagian
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        // Menggabungkan kembali subarray yang telah diurutkan
        merge(arr, l, m, r);
    }
}

// Fungsi untuk menampilkan isi array
void show(int A[], int size) {
    for (int i = 0; i < size; i++)
        cout << A[i] << " ";
    cout << endl;
}

int main() {
    int size;
    cout << "\nMasukan Banyak Data : ";
    cin >> size;

    int arr[size];

    // Memasukkan elemen array dari input user
    for (int i = 0; i < size; ++i) {
        cout << "\nMasukan Data array ke " << i << " : ";
        cin >> arr[i];
    }

    // Memanggil fungsi mergeSort untuk mengurutkan array
    mergeSort(arr, 0, size - 1);

    // Menampilkan hasil array yang telah diurutkan
    cout << "Hasil\n";
    show(arr, size);

    return 0; // Selesai menjalankan program
}
