#include <iostream>
#include "mahasiswa.h"
using namespace std;

int main() {
    const int maks = 10;
    Mahasiswa mhs[maks];
    int jumlah;

    cout << "Masukkan jumlah mahasiswa (maks 10): ";
    cin >> jumlah;

    if (jumlah > maks) {
        cout << "Jumlah melebihi batas!\n";
        return 0;
    }

    for (int i = 0; i < jumlah; i++) {
        cout << "\nData Mahasiswa ke-" << i + 1 << endl;
        inputMhs(mhs[i]);
    }

    cout << "\n=============================================\n";
    cout << "No\tNama\tNIM\tUTS\tUAS\tTugas\tNilai Akhir\n";
    cout << "---------------------------------------------\n";

    for (int i = 0; i < jumlah; i++) {
        cout << i + 1 << "\t";
        tampilMhs(mhs[i]);
    }

    return 0;
}

