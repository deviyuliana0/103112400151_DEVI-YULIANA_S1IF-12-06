#include <iostream>
#include "mahasiswa.h"
using namespace std;

void inputMhs(Mahasiswa &m) {
    cout << "Nama  : ";
    cin >> m.nama;
    cout << "NIM   : ";
    cin >> m.nim;
    cout << "Nilai UTS   : ";
    cin >> m.uts;
    cout << "Nilai UAS   : ";
    cin >> m.uas;
    cout << "Nilai Tugas : ";
    cin >> m.tugas;
    m.nilaiAkhir = hitungNilaiAkhir(m);
}

float hitungNilaiAkhir(Mahasiswa m) {
    return (0.3 * m.uts) + (0.4 * m.uas) + (0.3 * m.tugas);
}

void tampilMhs(Mahasiswa m) {
    cout << m.nama << "\t" << m.nim << "\t"
         << m.uts << "\t" << m.uas << "\t"
         << m.tugas << "\t" << m.nilaiAkhir << endl;
}
