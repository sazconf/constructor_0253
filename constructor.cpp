#include <iostream>
#include <string>
using namespace std;

class mahasiswa {
private:
    int nim;
    string nama;

public:
    mahasiswa();                         // Default constructor
    mahasiswa(int);                      // Constructor dengan parameter int
    mahasiswa(string);                   // Constructor dengan parameter string
    mahasiswa(int iNim, string iNama);   // Constructor dengan 2 parameter
    void cetak();                        // Fungsi cetak
};