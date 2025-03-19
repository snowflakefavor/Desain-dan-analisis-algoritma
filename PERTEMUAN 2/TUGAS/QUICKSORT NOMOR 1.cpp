#include<iostream>  // Menggunakan pustaka iostream untuk input dan output
using namespace std; // Menggunakan namespace std agar tidak perlu menuliskan std::

// Fungsi untuk menukar dua elemen dalam array
void swap(int arr[], int pos1, int pos2) {
    int temp;
    temp = arr[pos1];   // Simpan nilai dari posisi pertama
    arr[pos1] = arr[pos2];  // Gantikan nilai posisi pertama dengan posisi kedua
    arr[pos2] = temp;   // Pindahkan nilai awal posisi pertama ke posisi kedua
}

// Fungsi untuk melakukan partisi dalam quick sort
int partition(int arr[], int low, int high, int pivot) {
    int i = low;  // Inisialisasi indeks pertama
    int j = low;  // Inisialisasi indeks kedua untuk elemen yang lebih kecil dari pivot

    while (i <= high) {  // Iterasi hingga indeks i mencapai batas high
        if (arr[i] > pivot) {  // Jika elemen lebih besar dari pivot, lanjut ke elemen berikutnya
            i++;
        } else {
            swap(arr, i, j);  // Jika elemen lebih kecil atau sama dengan pivot, tukar elemen
            i++;
            j++;  // Geser indeks j ke kanan
        }
    }
    return j - 1;  // Mengembalikan posisi akhir dari elemen pivot
}

// Fungsi utama quick sort
void quickSort(int arr[], int low, int high) {
    if (low < high) {  // Jika masih ada lebih dari satu elemen
        int pivot = arr[high];  // Menentukan pivot sebagai elemen terakhir
        int pos = partition(arr, low, high, pivot);  // Partisi array berdasarkan pivot

        quickSort(arr, low, pos - 1);  // Rekursi untuk bagian kiri dari pivot
        quickSort(arr, pos + 1, high); // Rekursi untuk bagian kanan dari pivot
    }
}

int main() {
    int n;
    cout << "Tentukan panjang array : ";  // Minta input panjang array
    cin >> n;  // Baca panjang array dari pengguna

    int arr[n];  // Deklarasi array dengan ukuran yang diinputkan
    for (int i = 0; i < n; i++) {
        cin >> arr[i];  // Input elemen array
    }

    quickSort(arr, 0, n - 1);  // Panggil fungsi quickSort untuk mengurutkan array

    cout << "Berikut adalah array yang telah di sortir: ";
    for (int i = 0; i < n; i++) {  // Cetak hasil array yang telah diurutkan
        cout << arr[i] << "\t";
    }

    return 0;  // Selesai menjalankan program
}
