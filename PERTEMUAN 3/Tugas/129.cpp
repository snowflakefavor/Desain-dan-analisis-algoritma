#include <iostream>
#include <vector>

using namespace std;

class Mahasiswa {
protected:
    string nama;
    int umur;
    string jurusan;
    string fakultas;

public:
    Mahasiswa(string n, int u, string j, string f)
        : nama(n), umur(u), jurusan(j), fakultas(f) {}

    virtual void tampilkanInfo() {
        cout << "Nama     : " << nama << endl;
        cout << "Umur     : " << umur << " tahun" << endl;
        cout << "Jurusan  : " << jurusan << endl;
        cout << "Fakultas : " << fakultas << endl;
    }

    virtual ~Mahasiswa() {}
};

class MahasiswaAktif : public Mahasiswa {
private:
    int semester;
    string status;

public:
    MahasiswaAktif(string n, int u, string j, string f, int s)
        : Mahasiswa(n, u, j, f), semester(s), status("Mahasiswa Aktif") {}

    void tampilkanInfo() {
        Mahasiswa::tampilkanInfo();
        cout << "Semester : " << semester << endl;
        cout << "Status   : " << status << endl;
        cout << "-----------------------------" << endl;
    }
};

class Alumni : public Mahasiswa {
private:
    int tahunLulus;
    string status;

public:
    Alumni(string n, int u, string j, string f, int t)
        : Mahasiswa(n, u, j, f), tahunLulus(t), status("Alumni") {}

    void tampilkanInfo() { 
        Mahasiswa::tampilkanInfo();
        cout << "Tahun Lulus : " << tahunLulus << endl;
        cout << "Status      : " << status << endl;
        cout << "-----------------------------" << endl;
    }
};

int main() {

    vector<Mahasiswa*> daftarMahasiswa;

    daftarMahasiswa.push_back(new MahasiswaAktif("Yunita Puspitasari", 20, "Teknologi Informasi", "Informatika dan Pariwisata", 2));
    daftarMahasiswa.push_back(new Alumni("Rizky Febrian", 23, "Teknik Elektro", "Teknik", 2024));

    if (!daftarMahasiswa.empty()) {
        for (size_t i = 0; i < daftarMahasiswa.size(); i++) {
            if (daftarMahasiswa[i]) {
                daftarMahasiswa[i]->tampilkanInfo();
            }
        }
    } else {
        cout << "Tidak ada data mahasiswa untuk ditampilkan.\n";
    }

    if (!daftarMahasiswa.empty()) {
        for (size_t i = 0; i < daftarMahasiswa.size(); i++) {
            if (daftarMahasiswa[i]) {
                delete daftarMahasiswa[i];
            }
        }
        daftarMahasiswa.clear(); 
    }

    return 0;
}

