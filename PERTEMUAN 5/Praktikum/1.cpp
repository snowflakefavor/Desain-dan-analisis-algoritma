#include <iostream>
using namespace std;

class Kalkulator {
public:
    float a, b;

    Kalkulator(float x, float y) {
        a = x;
        b = y;
    }

    float tambah() { return a + b; }
    float kurang() { return a - b; }
    float kali() { return a * b; }
    float bagi() {
        if (b == 0) {
            cout << "ERROR! Pembagian dengan nol tidak bisa.\n";
            return 0;
        } else {
            return a / b;
        }
    }
};

int main() {
    float num1, num2;
    char choice, lanjut;

    do {
        cout << "Masukkan angka pertama = ";
        cin >> num1;
        cout << "Masukkan angka kedua = ";
        cin >> num2;

        Kalkulator k(num1, num2);

        cout << "Pilih operasi (+, -, *, /): ";
        cin >> choice;

        switch (choice) {
            case '+': cout << "Hasil pertambahan = " << k.tambah() << endl; break;
            case '-': cout << "Hasil pengurangan = " << k.kurang() << endl; break;
            case '*': cout << "Hasil perkalian = " << k.kali() << endl; break;
            case '/': cout << "Hasil pembagian = " << k.bagi() << endl; break;
            default: cout << "Pilihan tidak valid!\n";
        }
		
		cout << "\n\nitung lagi? (y/n): ";
		cin >> lanjut;
	
	} while (toupper(lanjut) == 'Y');
	
	return 0;
}
