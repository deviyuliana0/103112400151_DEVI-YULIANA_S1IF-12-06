#ifndef CIRCULARLIST_H_INCLUDED
#define CIRCULARLIST_H_INCLUDED

#include <string>
using namespace std;

#define Nil NULL

// ====== TIPE DATA ======

struct mahasiswa {
    string nama;
    string nim;
    char   jenis_kelamin;
    float  ipk;
};

typedef mahasiswa infotype;
struct ElmList;
typedef ElmList* address;

struct ElmList {
    infotype info;
    address  next;
};

struct List {
    address first;
};

// ====== PROTOTYPE FUNGSI/PROSEDUR ======

void createList(List &L);

address alokasi(infotype x);
void dealokasi(address P);

void insertFirst(List &L, address P);
void insertAfter(List &L, address Prec, address P);
void insertLast(List &L, address P);

void deleteFirst(List &L, address &P);
void deleteAfter(List &L, address Prec, address &P);
void deleteLast(List &L, address &P);

address findElm(List L, infotype x);   // cari berdasarkan x.nim
void printInfo(List L);

#endif