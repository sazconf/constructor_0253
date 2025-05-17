#include <iostream>
#include <string>
using namespace std;

// Forward declaration
class Mahasiswa;

// ===== Class Dosen =====
class Dosen {
private:
    string nama;
    string nidn;
    string pangkat;
    float gaji;

public:
    // Constructor
    Dosen(string n, string id, string p, float g)
        : nama(n), nidn(id), pangkat(p), gaji(g) {}

    // Dosen can assign grade to Mahasiswa (friend access)
    void beriNilai(Mahasiswa* m, float nilai);

    // Allow Universitas to view gaji using this friend function
    friend string lihatGajiDosen(Dosen* d);

    // Allow Staff to access and change private attributes of Dosen
    friend class Staff;
};

// ===== Class Mahasiswa =====
class Mahasiswa {
private:
    string nama;
    int nim;
    float nilai; // This is private and can only be modified by Dosen

public:
    // Constructor
    Mahasiswa(string n, int i) : nama(n), nim(i), nilai(0.0f) {}

    // Display Mahasiswa data
    void tampilkan() {
        cout << "Mahasiswa: " << nama << " (NIM: " << nim << ") - Nilai: " << nilai << endl;
    }

    // Give Dosen access to modify nilai
    friend void Dosen::beriNilai(Mahasiswa* m, float nilai);
};

// Function defined outside to access private gaji of Dosen
string lihatGajiDosen(Dosen* d) {
    return "Gaji Dosen: " + to_string(d->gaji);
}

// ===== Class Staff =====
class Staff {
private:
    string nama;
    int idStaff;
    float gaji;

public:
    // Constructor
    Staff(string n, int id, float g) : nama(n), idStaff(id), gaji(g) {}

    // Staff can change Dosen's pangkat using pointer
    void ubahPangkat(Dosen* d, string pangkatBaru) {
        d->pangkat = pangkatBaru;
    }

    // Allow Universitas to see gaji of Staff via this friend function
    friend string lihatGajiStaff(Staff* s);
};

// Function to access Staff's gaji
string lihatGajiStaff(Staff* s) {
    return "Gaji Staff: " + to_string(s->gaji);
}

// ===== Class Universitas =====
class Universitas {
public:
    // Universitas can view gaji of Dosen via friend function
    void tampilkanGajiDosen(Dosen* d) {
        cout << lihatGajiDosen(d) << endl;
    }

    // Universitas can view gaji of Staff via friend function
    void tampilkanGajiStaff(Staff* s) {
        cout << lihatGajiStaff(s) << endl;
    }
};

int main() {
    // Create a Mahasiswa
    Mahasiswa m1("Alice", 12345);

    // Create a Dosen
    Dosen d1("Dr. Budi", "D123", "Lektor", 8500000);

    // Create a Staff
    Staff s1("Pak Joko", 2022, 4500000);

    // Create Universitas instance
    Universitas u;

    // Dosen gives grade to Mahasiswa
    d1.beriNilai(&m1, 88.5);

    // Display Mahasiswa info
    m1.tampilkan();

    // Staff updates the Dosen's pangkat
    s1.ubahPangkat(&d1, "Guru Besar");

    // Universitas accesses gaji data from both Dosen and Staff
    u.tampilkanGajiDosen(&d1);
    u.tampilkanGajiStaff(&s1);

    return 0;
}