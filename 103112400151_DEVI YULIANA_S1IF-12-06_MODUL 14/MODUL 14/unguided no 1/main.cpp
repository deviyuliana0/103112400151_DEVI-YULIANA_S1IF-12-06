#include <iostream>
#include "graph.h"

using namespace std;

int main() {
    Graph G;
    CreateGraph(G);

    // Membuat node A–H (sesuai gambar di modul)
    InsertNode(G, 'A');
    InsertNode(G, 'B');
    InsertNode(G, 'C');
    InsertNode(G, 'D');
    InsertNode(G, 'E');
    InsertNode(G, 'F');
    InsertNode(G, 'G');
    InsertNode(G, 'H');

    // Menghubungkan node (sesuai ilustrasi graph di modul)
    ConnectNode(FindNode(G, 'A'), FindNode(G, 'B'));
    ConnectNode(FindNode(G, 'A'), FindNode(G, 'C'));
    ConnectNode(FindNode(G, 'B'), FindNode(G, 'D'));
    ConnectNode(FindNode(G, 'D'), FindNode(G, 'H'));
    ConnectNode(FindNode(G, 'C'), FindNode(G, 'E'));
    ConnectNode(FindNode(G, 'C'), FindNode(G, 'F'));
    ConnectNode(FindNode(G, 'F'), FindNode(G, 'G'));

    cout << "=== Struktur Graph ===" << endl;
    PrintInfoGraph(G);

    return 0;
}