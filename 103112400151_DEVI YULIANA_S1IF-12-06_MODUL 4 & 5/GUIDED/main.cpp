#include<iostream>
#include<cstdlib>
#include "singlylist.h"
#include "singlylist.cpp"
using namespace std;
int main(){
    List L;
    CreateList(L);
    cout<<"Mengisi List menggunakan interLast..."<<endl;
    address P;
    
    P = alokasi(9);
    insertLast(L,P);

    P = alokasi(12);
    insertLast(L,P);

    P = alokasi(8);
    insertLast(L,P);

    P = alokasi(0);
    insertLast(L,P);

    P = alokasi(2);
    insertLast(L,P);

    cout<<"Isi List sekarang adalah : ";
    printInfo(L);

    system("pause");
    return 0;
}
