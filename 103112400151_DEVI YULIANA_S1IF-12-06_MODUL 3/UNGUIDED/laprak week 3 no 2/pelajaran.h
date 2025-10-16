#ifndef PELAJARAN_H_INCLUDED
#define PELAJARAN_H_INCLUDED

#include <string>
using namespace std;

// Definisi tipe ADT pelajaran
struct pelajaran {
    string namaMapel;
    string kodeMapel;
};

// Fungsi dan prosedur ADT
pelajaran create_pelajaran(string namapel, string kodepel);
void tampil_pelajaran(pelajaran pel);

#endif // PELAJARAN_H_INCLUDED
