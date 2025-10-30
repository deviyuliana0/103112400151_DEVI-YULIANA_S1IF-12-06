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

// Menambahkan elemen di depan list
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

// Mencari elemen berdasarkan nopol
ElmList* findElm(List L, string nopol) {
    ElmList* P = L.first;
    while (P != Nil) {
        if (P->info.nopol == nopol)
            return P;
        P = P->next;
    }
    return Nil;
}

// Menampilkan seluruh isi list
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

// Program Utama
int main() {
    List L;
    createList(L);
    infotype x;
    char lanjut;

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

    return 0;
}