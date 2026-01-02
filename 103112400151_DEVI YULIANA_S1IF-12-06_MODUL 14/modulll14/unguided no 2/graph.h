#ifndef GRAPH_H_INCLUDED
#define GRAPH_H_INCLUDED

#include <iostream>
using namespace std;

typedef char infoGraph;

struct ElmNode;
struct ElmEdge;

typedef ElmNode* adrNode;
typedef ElmEdge* adrEdge;

// STRUCT NODE
struct ElmNode {
    infoGraph info;
    int visited;
    adrEdge firstEdge;
    adrNode next;
};

// STRUCT EDGE
struct ElmEdge {
    adrNode node;
    adrEdge next;
};

// STRUCT GRAPH
struct Graph {
    adrNode first;
};

// ===== PRIMITIF ADT (LATIHAN 1) =====
void CreateGraph(Graph &G);
adrNode AllocateNode(infoGraph X);
adrEdge AllocateEdge(adrNode N);
void InsertNode(Graph &G, infoGraph X);
adrNode FindNode(Graph G, infoGraph X);
void ConnectNode(Graph &G, infoGraph A, infoGraph B);
void PrintInfoGraph(Graph G);

// ====== LATIHAN NOMOR 2 (DFS) ======
void ResetVisited(Graph &G);
void PrintDFS(Graph &G, adrNode N);

#endif