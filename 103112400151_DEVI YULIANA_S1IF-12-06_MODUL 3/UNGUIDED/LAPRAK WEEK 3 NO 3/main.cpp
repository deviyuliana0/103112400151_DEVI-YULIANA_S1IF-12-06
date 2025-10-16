#include <iostream>
using namespace std;

void tampilArray(int matriks[3][3]) {
    for (int baris = 0; baris < 3; baris++) {
        for (int kolom = 0; kolom < 3; kolom++) {
            cout << matriks[baris][kolom] << "\t";
        }
        cout << endl;
    }
}

void tukarArray(int matriks1[3][3], int matriks2[3][3], int baris, int kolom) {
    int sementara = matriks1[baris][kolom];
    matriks1[baris][kolom] = matriks2[baris][kolom];
    matriks2[baris][kolom] = sementara;
}

void tukarPointer(int *ptrA, int *ptrB) {
    int sementara = *ptrA;
    *ptrA = *ptrB;
    *ptrB = sementara;
}

int main() {
    int arrayA[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    int arrayB[3][3] = {
        {9, 8, 7},
        {6, 5, 4},
        {3, 2, 1}
    };

    int *penunjuk1, *penunjuk2;
    int angka1 = 10, angka2 = 20;

    cout << "Isi arrayA sebelum ditukar:\n";
    tampilArray(arrayA);
    cout << "\nIsi arrayB sebelum ditukar:\n";
    tampilArray(arrayB);

    tukarArray(arrayA, arrayB, 1, 1);

    cout << "\nSetelah pertukaran elemen pada posisi (1,1):\n";
    cout << "arrayA:\n";
    tampilArray(arrayA);
    cout << "\narrayB:\n";
    tampilArray(arrayB);

    penunjuk1 = &angka1;
    penunjuk2 = &angka2;

    cout << "\nNilai sebelum ditukar:\n";
    cout << "angka1 = " << angka1 << ", angka2 = " << angka2 << endl;

    tukarPointer(penunjuk1, penunjuk2);

    cout << "Nilai setelah ditukar:\n";
    cout << "angka1 = " << angka1 << ", angka2 = " << angka2 << endl;

    return 0;
}
