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