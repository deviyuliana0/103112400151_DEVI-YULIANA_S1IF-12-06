#include <iostream>
#include "graph.h"

using namespace std;

int main() {
    Graph G;
    CreateGraph(G);

    // Membuat node A–H
    InsertNode(G, 'A');
    InsertNode(G, 'B');
    InsertNode(G, 'C');
    InsertNode(G, 'D');
    InsertNode(G, 'E');
    InsertNode(G, 'F');
    InsertNode(G, 'G');
    InsertNode(G, 'H');

    // Menghubungkan sesuai modul
    ConnectNode(G, 'A', 'B');
    ConnectNode(G, 'A', 'C');
    ConnectNode(G, 'B', 'D');
    ConnectNode(G, 'D', 'H');
    ConnectNode(G, 'C', 'E');
    ConnectNode(G, 'C', 'F');
    ConnectNode(G, 'F', 'G');

    cout << "=== Struktur Graph ===" << endl;
    PrintInfoGraph(G);

    cout << "\n=== BFS dari node A ===" << endl;
    ResetVisited(G);
    PrintBFS(G, FindNode(G, 'A'));    // INI JAWABAN LATIHAN 3

    cout << endl;
    return 0;
}