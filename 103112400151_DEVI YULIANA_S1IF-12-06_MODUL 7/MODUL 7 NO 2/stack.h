#ifndef STACK_H
#define STACK_H
#include <iostream>
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

// 🟩 Push Ascending: memasukkan elemen agar stack tetap terurut menaik
void pushAscending(Stack &S, infotype x) {
    Stack temp;
    createStack(temp);

    // Pindahkan elemen sementara ke temp sampai posisi yang tepat ditemukan
    while (!isEmpty(S) && S.info[S.top] > x) {
        push(temp, pop(S));
    }

    // Masukkan elemen baru di posisi yang tepat
    push(S, x);

    // Kembalikan elemen dari temp ke stack utama
    while (!isEmpty(temp)) {
        push(S, pop(temp));
    }
}

#endif