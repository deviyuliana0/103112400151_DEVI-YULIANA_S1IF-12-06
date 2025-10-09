#include <iostream>
using namespace std;

int main() {
    const int jumlahMhs = 5, jumlahMk = 3;
    string nama[jumlahMhs];
    float nilai[jumlahMhs][jumlahMk];
    float rata[jumlahMhs];

    for (int i = 0; i < jumlahMhs; i++) {
        cout << "Masukkan nama mahasiswa ke-" << i + 1 << ": ";
        cin >> nama[i];
        float total = 0;
        for (int j = 0; j < jumlahMk; j++) {
            cout << "Nilai mata kuliah ke-" << j + 1 << ": ";
            cin >> nilai[i][j];
            total += nilai[i][j];
        }
        rata[i] = total / jumlahMk;
        cout << endl;
    }

    int terbaik = 0;
    for (int i = 1; i < jumlahMhs; i++) {
        if (rata[i] > rata[terbaik])
            terbaik = i;
    }

    cout << "Nama\tNilai1\tNilai2\tNilai3\tRata-rata\n";
    for (int i = 0; i < jumlahMhs; i++) {
        cout << nama[i] << "\t";
        for (int j = 0; j < jumlahMk; j++) {
            cout << nilai[i][j] << "\t";
        }
        cout << rata[i];
        if (i == terbaik) cout << "  <-- Terbaik";
        cout << endl;
    }

    return 0;
}
