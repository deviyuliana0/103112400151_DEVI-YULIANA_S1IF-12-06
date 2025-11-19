#include <iostream>
#include "queue.h"
using namespace std;

int main() {
    cout << "Hello World!" << endl;
    cout << "----------------------------------------" << endl;
    cout << "H - T  ! Queue Info" << endl;
    cout << "----------------------------------------" << endl;

    Queue Q;
    createQueue(Q);

    // urutan operasi sesuai contoh -> hasil akhir empty queue
    printInfo(Q);           // awal: empty

    enqueue(Q, 5); printInfo(Q);   // setelah enqueue 5
    enqueue(Q, 2); printInfo(Q);   // setelah enqueue 2
    enqueue(Q, 7); printInfo(Q);   // setelah enqueue 7

    dequeue(Q); printInfo(Q);      // dequeue (menghapus 5)
    enqueue(Q, 4); printInfo(Q);   // enqueue 4
    dequeue(Q); printInfo(Q);      // dequeue (menghapus 2)
    dequeue(Q); printInfo(Q);      // dequeue (menghapus 7)
    dequeue(Q); printInfo(Q);      // dequeue (menghapus 4) -> empty

    return 0;
}