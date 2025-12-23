#ifndef BSTREE_H
#define BSTREE_H

#define Nil NULL

typedef int infotype;

struct Node{
    infotype info;
    Node *left;
    Node *right;
};

typedef Node* address;

void alokasi(address &P, infotype X);
void insertNode(address &root, infotype X);
address findNode(address root, infotype X);
void printInOrder(address root);
void printPreOrder(address root);
void printPostOrder(address root);

int hitungNode(address root);
int hitungTotal(address root);
int hitungKedalaman(address root, int start);

#endif