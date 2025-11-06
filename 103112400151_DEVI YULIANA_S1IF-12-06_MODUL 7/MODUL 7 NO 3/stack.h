#ifndef STACK_H
#define STACK_H
#include <iostream>
#include <string>  // untuk membaca input string
using namespace std;

const int maxEl = 20;
typedef int infotype;

struct Stack {
    infotype info[maxEl];
    int top;
};

// Membuat stack kosong
void createStack(Stack &S) {
    S.top = -1;
}

bool isEmpty(Stack S) {
    return S.top == -1;
}

bool isFull(Stack S) {
    return S.top == maxEl - 1;
}

// Menambahkan elemen ke atas stack
void push(Stack &S, infotype x) {
    if (isFull(S)) {
        cout << "Stack penuh!" << endl;
    } else {
        S.top++;
        S.info[S.top] = x;
    }
}

// Menghapus dan mengembalikan elemen paling atas
infotype pop(Stack &S) {
    if (isEmpty(S)) {
        cout << "Stack kosong!" << endl;
        return -1;
    } else {
        infotype x = S.info[S.top];
        S.top--;
        return x;
    }
}

// Menampilkan isi stack dari atas ke bawah
void printInfo(Stack S) {
    if (isEmpty(S)) {
        cout << "Stack kosong!" << endl;
    } else {
        cout << "[TOP] ";
        for (int i = S.top; i >= 0; i--) {
            cout << S.info[i] << " ";
        }
        cout << endl;
    }
}

// Membalik urutan stack
void balikStack(Stack &S) {
    Stack temp;
    createStack(temp);

    while (!isEmpty(S)) {
        push(temp, pop(S));
    }
    S = temp;
}

// 🟩 getInputStream: membaca input angka dari user (tanpa spasi)
void getInputStream(Stack &S) {
    string input;
    cout << "Masukkan angka: ";
    getline(cin, input); // baca satu baris input

    for (char c : input) {
        if (isdigit(c)) { // hanya proses karakter angka
            int x = c - '0'; // konversi char ke int
            push(S, x);
        }
    }
}
#endif