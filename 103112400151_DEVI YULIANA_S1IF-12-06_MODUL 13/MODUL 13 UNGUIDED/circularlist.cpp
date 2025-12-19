#include <iostream>
#include "circularlist.h"
using namespace std;

// ================== HELPER ==================

static address getLast(List &L) {
    if (L.first == Nil) return Nil;
    address p = L.first;
    while (p->next != L.first) {
        p = p->next;
    }
    return p;
}

// ================== CREATE LIST ==================

void createList(List &L) {
    L.first = Nil;
}

// ================== ALOKASI / DEALOKASI ==================

address alokasi(infotype x) {
    address P = new ElmList;
    if (P != Nil) {
        P->info = x;
        P->next = Nil;
    }
    return P;
}

void dealokasi(address P) {
    delete P;
}

// ================== INSERT ==================

void insertFirst(List &L, address P) {
    if (P == Nil) return;

    if (L.first == Nil) {
        // list kosong
        L.first = P;
        P->next = P;      // circular
    } else {
        address last = getLast(L);
        P->next = L.first;
        last->next = P;
        L.first = P;
    }
}

void insertAfter(List &L, address Prec, address P) {
    if (L.first == Nil || Prec == Nil || P == Nil) return;

    P->next = Prec->next;
    Prec->next = P;
}

void insertLast(List &L, address P) {
    if (P == Nil) return;

    if (L.first == Nil) {
        L.first = P;
        P->next = P;
    } else {
        address last = getLast(L);
        last->next = P;
        P->next = L.first;
    }
}

// ================== DELETE ==================

void deleteFirst(List &L, address &P) {
    P = Nil;
    if (L.first == Nil) return;

    if (L.first->next == L.first) {
        // hanya satu elemen
        P = L.first;
        L.first = Nil;
    } else {
        address last = getLast(L);
        P = L.first;
        L.first = P->next;
        last->next = L.first;
    }
    P->next = Nil;
}

void deleteLast(List &L, address &P) {
    P = Nil;
    if (L.first == Nil) return;

    if (L.first->next == L.first) {
        // satu elemen
        P = L.first;
        L.first = Nil;
        P->next = Nil;
        return;
    }

    address prev = Nil;
    address curr = L.first;
    while (curr->next != L.first) {
        prev = curr;
        curr = curr->next;
    }
    // curr = last, prev = before last
    P = curr;
    prev->next = L.first;
    P->next = Nil;
}

void deleteAfter(List &L, address Prec, address &P) {
    P = Nil;
    if (L.first == Nil || Prec == Nil || Prec->next == Nil) return;

    P = Prec->next;

    // jika yang dihapus adalah first
    if (P == L.first) {
        address last = getLast(L);
        L.first = P->next;
        last->next = L.first;
    }

    Prec->next = P->next;
    P->next = Nil;

    // kalau setelah ini list cuma satu elemen, tetap circular
    if (L.first != Nil && L.first->next == Nil)
        L.first->next = L.first;
}

// ================== FIND ==================

address findElm(List L, infotype x) {
    if (L.first == Nil) return Nil;

    address p = L.first;
    do {
        if (p->info.nim == x.nim) {
            return p;
        }
        p = p->next;
    } while (p != L.first);

    return Nil;
}

// ================== PRINT ==================

void printInfo(List L) {
    if (L.first == Nil) return;

    address p = L.first;
    do {
        cout << "NIM  : " << p->info.nim  << endl;
        cout << "Nama : " << p->info.nama << endl;
        cout << "JK   : " << p->info.jenis_kelamin << endl;
        cout << "IPK  : " << p->info.ipk << endl;
        cout << endl;
        p = p->next;
    } while (p != L.first);
}