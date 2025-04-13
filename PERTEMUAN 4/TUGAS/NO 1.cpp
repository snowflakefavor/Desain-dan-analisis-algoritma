#include <iostream> // Perpustakaan untuk input dan output
using namespace std; // Supaya tidak perlu menulis std:: di depan cout, endl, dll

// Deklarasi class dengan nama 'contoh'
class contoh {
	private:
		int nilai; // Data member yang bersifat private, hanya bisa diakses dari dalam class
		
	public:
		// Constructor: otomatis dipanggil saat objek dibuat
		contoh (int n) {
			nilai = n; // Menyimpan nilai dari parameter ke data member
		}
		
		// Method untuk mengambil nilai dari data member 'nilai'
		int getNum () {
			return nilai; 
		}
};

// Fungsi utama program
int main () {
	contoh obj (10); // Membuat objek 'obj' dari class 'contoh' dan menginisialisasi dengan nilai 10 (memanggil constructor)
	cout << "nilai yang diinput : " << obj.getNum () << endl; // Menampilkan nilai yang disimpan
	return 0; // Program selesai
}

