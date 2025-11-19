#include <iostream>
#include <iomanip>
#include "queue.h"
using namespace std;

void createQueue(Queue &Q) {
    Q.head = -1;
    Q.tail = -1;
    // optional: initialize array values (not required)
    for (int i = 0; i < MAX; ++i) Q.info[i] = 0;
}

bool isEmptyQueue(const Queue &Q) {
    return (Q.head == -1 && Q.tail == -1);
}

bool isFullQueue(const Queue &Q) {
    return (Q.tail == MAX - 1);
}

void enqueue(Queue &Q, infotype x) {
    if (isFullQueue(Q)) {
        cout << "Queue penuh!" << endl;
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
        cout << "Queue kosong!" << endl;
        return -1;
    }

    infotype x = Q.info[Q.head];

    // geser semua elemen ke kiri (head tetap 0)
    for (int i = Q.head; i < Q.tail; ++i) {
        Q.info[i] = Q.info[i + 1];
    }
    // optional clear last
    Q.info[Q.tail] = 0;
    Q.tail--;

    if (Q.tail < Q.head) {
        Q.head = -1;
        Q.tail = -1;
    }

    return x;
}

void printInfo(const Queue &Q) {
    // Cetak baris sesuai contoh
    // Format: H - T  !  Queue Info
    // Example: -1 - -1  !  empty queue
    // We'll align roughly similar to gambar
    if (isEmptyQueue(Q)) {
        cout << setw(2) << Q.head << " - " << setw(2) << Q.tail << "  ! ";
        cout << "empty queue" << endl;
        return;
    }

    cout << setw(2) << Q.head << " - " << setw(2) << Q.tail << "  ! ";
    // print queue contents left to right
    for (int i = Q.head; i <= Q.tail; ++i) {
        cout << Q.info[i];
        if (i < Q.tail) cout << " ";
    }
    cout << endl;
}