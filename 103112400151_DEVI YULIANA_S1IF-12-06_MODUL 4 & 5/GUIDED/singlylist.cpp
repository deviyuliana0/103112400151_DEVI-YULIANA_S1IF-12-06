#include "singlylist.h"
using namespace std;

void CreateList(List &L) {
    L.first = Nil;
}

address alokasi(infotype x) {
    address P = new Elmist;
    P->info = x;
    P->next = Nil;
    return P;
}

void dealokasi(address &P) {
    delete P;
}

void insertFirst(List &L, address P) {
    P->next = L.first;
    L.first = P;
}

void insertLast(List &L, address P) {
    if (L.first == Nil) {
        // jika list kosong insert last sama dengan insert first
        insertFirst(L, P);
    } else {
        // Jika list tidak kosong, cari elemen terakhir
        address Last = L.first;
        while (Last->next != Nil) {
            Last = Last->next;
        }
        // sambungkan elemen terakhir ke elemen baru (p)
        Last->next = P;
    }
}

void printInfo(List L) {
    address P = L.first;
    if (P == Nil) {
        std::cout << "List Kosong!" << std::endl;
    } else {
        while (P != Nil) {
        std::cout << P->info << " ";
        P = P->next;
    }
    std::cout << std::endl;
    }
}
