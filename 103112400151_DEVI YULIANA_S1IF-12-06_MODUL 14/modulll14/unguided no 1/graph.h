#ifndef GRAPH_H_INCLUDED
#define GRAPH_H_INCLUDED

#include <iostream>
using namespace std;

typedef char infoGraph;

struct ElmNode;
struct ElmEdge;

typedef ElmNode* adrNode;
typedef ElmEdge* adrEdge;

struct ElmNode {
    infoGraph info;
    int visited;        // disiapkan untuk latihan DFS/BFS berikutnya
    adrEdge firstEdge;  // pointer ke list edge
    adrNode next;       // pointer ke node berikutnya
};

struct ElmEdge {
    adrNode node;       // node tetangga
    adrEdge next;       // edge berikutnya dari node yang sama
};

struct Graph {
    adrNode first;      // node pertama dalam graph
};

// Primitif yang diminta soal
void CreateGraph(Graph &G);
void InsertNode(Graph &G, infoGraph X);
void ConnectNode(adrNode N1, adrNode N2);
void PrintInfoGraph(Graph G);

// Fungsi bantu (boleh dipakai untuk implementasi)
adrNode AllocateNode(infoGraph X);
adrEdge AllocateEdge(adrNode N);
adrNode FindNode(Graph G, infoGraph X);

#endif