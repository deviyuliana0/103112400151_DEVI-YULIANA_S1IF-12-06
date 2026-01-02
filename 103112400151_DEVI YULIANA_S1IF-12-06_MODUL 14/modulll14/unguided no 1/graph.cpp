#include "graph.h"

void CreateGraph(Graph &G) {
    G.first = NULL;
}

// Alokasi node baru
adrNode AllocateNode(infoGraph X) {
    adrNode P = new ElmNode;
    P->info = X;
    P->visited = 0;
    P->firstEdge = NULL;
    P->next = NULL;
    return P;
}

// Alokasi edge baru
adrEdge AllocateEdge(adrNode N) {
    adrEdge E = new ElmEdge;
    E->node = N;
    E->next = NULL;
    return E;
}

// Insert node ke list node (InsertFirst)
void InsertNode(Graph &G, infoGraph X) {
    adrNode P = AllocateNode(X);
    P->next = G.first;
    G.first = P;
}

// Mencari node berdasarkan info
adrNode FindNode(Graph G, infoGraph X) {
    adrNode P = G.first;
    while (P != NULL) {
        if (P->info == X) return P;
        P = P->next;
    }
    return NULL;
}

// Menghubungkan dua node (graph tak berarah)
void ConnectNode(adrNode N1, adrNode N2) {
    if (N1 == NULL || N2 == NULL) return;

    // edge dari N1 ke N2
    adrEdge E1 = AllocateEdge(N2);
    E1->next = N1->firstEdge;
    N1->firstEdge = E1;

    // edge dari N2 ke N1 (karena tak berarah)
    adrEdge E2 = AllocateEdge(N1);
    E2->next = N2->firstEdge;
    N2->firstEdge = E2;
}

// Cetak struktur graph: setiap node dan tetangganya
void PrintInfoGraph(Graph G) {
    adrNode P = G.first;
    while (P != NULL) {
        cout << P->info << " -> ";
        adrEdge E = P->firstEdge;
        while (E != NULL) {
            cout << E->node->info << " ";
            E = E->next;
        }
        cout << endl;
        P = P->next;
    }
}
