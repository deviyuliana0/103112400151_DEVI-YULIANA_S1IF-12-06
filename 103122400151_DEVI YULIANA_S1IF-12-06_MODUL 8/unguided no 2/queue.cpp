// queue.cpp  (ALTERNATIF 2: head & tail bergerak, non-circular)
#include <iostream>
#include "queue.h"
using namespace std;

void createQueue(Queue &Q) {
    Q.head = -1;
    Q.tail = -1;
}

bool isEmptyQueue(Queue Q) {
    return Q.head == -1;
}

bool isFullQueue(Queue Q) {
    return Q.tail == MaxEl - 1;
}

void enqueue(Queue &Q, infotype x) {
    if (isFullQueue(Q)) {
        cout << "Queue penuh" << endl;
        return;
    }

    if (isEmptyQueue(Q)) {
        Q.head = 0;
        Q.tail = 0;
    } else {
        Q.tail++;
    }

    Q.info[Q.tail] = x;
}

infotype dequeue(Queue &Q) {
    if (isEmptyQueue(Q)) {
        cout << "Queue kosong" << endl;
        return 0;      // nilai dummy
    }

    infotype x = Q.info[Q.head];

    if (Q.head == Q.tail) {
        // elemen tinggal 1, setelah diambil -> kosong
        Q.head = -1;
        Q.tail = -1;
    } else {
        // head maju satu posisi, tail tetap
        Q.head++;
    }

    return x;
}

void printInfo(Queue Q) {
    if (isEmptyQueue(Q)) {
        cout << "-1 - -1\t| empty queue" << endl;
    } else {
        cout << Q.head << " - " << Q.tail << "\t| ";
        for (int i = Q.head; i <= Q.tail; ++i) {
            cout << Q.info[i] << " ";
        }
        cout << endl;
    }
}
