#ifndef SINGLYLIST_H_INCLUDED
#define SINGLYLIST_H_INCLUDED

#include <iostream>

#define Nil NULL

typedef int infotype;
typedef struct Elmist *address;

struct Elmist {
    infotype info;
    address next;
};

struct List {
    address first;
};

// Deklarasi Prosedur dan Fungsi Primitif
void CreateList(List &L);
address alokasi(infotype x);
void dealokasi(address &P);
void insertFirst(List &L, address P);
void printInfo(List L);

#endif 
