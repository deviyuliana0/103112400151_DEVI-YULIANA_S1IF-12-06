#ifndef MAHASISWA_H_INCLUDED
#define MAHASISWA_H_INCLUDED

#include <string>
using namespace std;

struct Mahasiswa {
    string nama;
    string nim;
    float uts;
    float uas;
    float tugas;
    float nilaiAkhir;
};

void inputMhs(Mahasiswa &m);
float hitungNilaiAkhir(Mahasiswa m);
void tampilMhs(Mahasiswa m);

#endif
