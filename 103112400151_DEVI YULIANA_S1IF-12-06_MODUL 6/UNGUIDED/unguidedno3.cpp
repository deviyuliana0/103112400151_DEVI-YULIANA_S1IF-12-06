#include <iostream>
#include <string>
using namespace std;

#define Nil NULL

// Deklarasi Tipe Data
struct kendaraan {
    string nopol;
    string warna;
    int thnBuat;
};

typedef kendaraan infotype;

struct ElmList {
    infotype info;
    ElmList* next;
    ElmList* prev;
};

struct List {
    ElmList* first;
    ElmList* last;
};

// Deklarasi Fungsi / Prosedur
void createList(List &L);
ElmList* alokasi(infotype x);
void dealokasi(ElmList* &P);
void insertFirst(List &L, ElmList* P);
ElmList* findElm(List L, string nopol);
void printInfo(List L);
void cariKendaraan(List L);

// delete operations
void deleteFirst(List &L, ElmList* &P);
void deleteLast(List &L, ElmList* &P);
void deleteAfter(ElmList* Prec, ElmList* &P);
void deleteByNopol(List &L, string nopol);

// Implementasi
void createList(List &L) {
    L.first = Nil;
    L.last = Nil;
}

ElmList* alokasi(infotype x) {
    ElmList* P = new ElmList;
    P->info = x;
    P->next = Nil;
    P->prev = Nil;
    return P;
}

void dealokasi(ElmList* &P) {
    delete P;
    P = Nil;
}

void insertFirst(List &L, ElmList* P) {
    if (L.first == Nil) {
        L.first = P;
        L.last = P;
    } else {
        P->next = L.first;
        L.first->prev = P;
        L.first = P;
    }
}

ElmList* findElm(List L, string nopol) {
    ElmList* P = L.first;
    while (P != Nil) {
        if (P->info.nopol == nopol)
            return P;
        P = P->next;
    }
    return Nil;
}

void printInfo(List L) {
    ElmList* P = L.first;
    if (P == Nil) {
        cout << "List kosong" << endl;
    } else {
        cout << "DATA LIST 1" << endl;
        while (P != Nil) {
            cout << "no polisi : " << P->info.nopol << endl;
            cout << "warna     : " << P->info.warna << endl;
            cout << "tahun     : " << P->info.thnBuat << endl;
            P = P->next;
        }
    }
}

void cariKendaraan(List L) {
    string cari;
    cout << "Masukkan Nomor Polisi yang dicari : ";
    cin >> cari;

    ElmList* P = findElm(L, cari);
    if (P != Nil) {
        cout << "Nomor Polisi : " << P->info.nopol << endl;
        cout << "Warna        : " << P->info.warna << endl;
        cout << "Tahun        : " << P->info.thnBuat << endl;
    } else {
        cout << "Data dengan nomor polisi " << cari << " tidak ditemukan." << endl;
    }
}

// DELETE OPERATIONS

// Hapus elemen pertama
void deleteFirst(List &L, ElmList* &P) {
    if (L.first == Nil) {
        P = Nil;
    } else if (L.first == L.last) {
        P = L.first;
        L.first = Nil;
        L.last = Nil;
    } else {
        P = L.first;
        L.first = L.first->next;
        L.first->prev = Nil;
        P->next = Nil;
    }
}

// Hapus elemen terakhir
void deleteLast(List &L, ElmList* &P) {
    if (L.first == Nil) {
        P = Nil;
    } else if (L.first == L.last) {
        P = L.last;
        L.first = Nil;
        L.last = Nil;
    } else {
        P = L.last;
        L.last = L.last->prev;
        L.last->next = Nil;
        P->prev = Nil;
    }
}

// Hapus elemen setelah Prec
void deleteAfter(ElmList* Prec, ElmList* &P) {
    if (Prec != Nil && Prec->next != Nil) {
        P = Prec->next;
        Prec->next = P->next;
        if (P->next != Nil) {
            P->next->prev = Prec;
        }
        P->next = Nil;
        P->prev = Nil;
    }
}

// Hapus elemen berdasarkan nopol
void deleteByNopol(List &L, string nopol) {
    ElmList* P = findElm(L, nopol);
    if (P == Nil) {
        cout << "Data tidak ditemukan." << endl;
        return;
    }

    if (P == L.first) {
        deleteFirst(L, P);
    } else if (P == L.last) {
        deleteLast(L, P);
    } else {
        deleteAfter(P->prev, P);
    }

    cout << "Data dengan nopol " << nopol << " berhasil dihapus." << endl;
    dealokasi(P);
}

// Program Utama
int main() {
    List L;
    createList(L);
    infotype x;
    char lanjut;

    // Input data kendaraan
    do {
        cout << "masukkan nomor polisi: ";
        cin >> x.nopol;
        cout << "masukkan warna kendaraan: ";
        cin >> x.warna;
        cout << "masukkan tahun kendaraan: ";
        cin >> x.thnBuat;

        if (findElm(L, x.nopol) != Nil) {
            cout << "nomor polisi sudah terdaftar" << endl;
        } else {
            ElmList* P = alokasi(x);
            insertFirst(L, P);
        }

        cout << "Tambah data lagi? (y/t): ";
        cin >> lanjut;
        cout << endl;
    } while (lanjut == 'y' || lanjut == 'Y');

    cout << endl;
    printInfo(L);
    cout << endl;

    // Cari kendaraan
    cariKendaraan(L);
    cout << endl;

    // Hapus kendaraan
    string hapus;
    cout << "Masukkan nomor polisi yang ingin dihapus: ";
    cin >> hapus;
    deleteByNopol(L, hapus);

    cout << endl;
    printInfo(L);

    return 0;
}