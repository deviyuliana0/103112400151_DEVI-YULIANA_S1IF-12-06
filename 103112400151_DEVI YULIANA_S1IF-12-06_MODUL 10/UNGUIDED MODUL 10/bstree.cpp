#include <iostream>
#include "bstree.h"
using namespace std;

void alokasi(address &P, infotype X){
    P = new Node;
    P->info = X;
    P->left = Nil;
    P->right = Nil;
}

void insertNode(address &root, infotype X){
    if(root == Nil){
        alokasi(root, X);
    } else {
        if(X < root->info){
            insertNode(root->left, X);
        } else if(X > root->info){
            insertNode(root->right, X);
        }
    }
}

address findNode(address root, infotype X){
    if(root == Nil || root->info == X){
        return root;
    } else if(X < root->info){
        return findNode(root->left, X);
    } else {
        return findNode(root->right, X);
    }
}

void printInOrder(address root){
    if(root != Nil){
        printInOrder(root->left);
        cout << root->info << " - ";
        printInOrder(root->right);
    }
}

void printPreOrder(address root){
    if(root != Nil){
        cout << root->info << " - ";
        printPreOrder(root->left);
        printPreOrder(root->right);
    }
}

void printPostOrder(address root){
    if(root != Nil){
        printPostOrder(root->left);
        printPostOrder(root->right);
        cout << root->info << " - ";
    }
}

int hitungNode(address root){
    if(root == Nil){
        return 0;
    } else {
        return 1 + hitungNode(root->left) + hitungNode(root->right);
    }
}

int hitungTotal(address root){
    if(root == Nil){
        return 0;
    } else {
        return root->info + hitungTotal(root->left) + hitungTotal(root->right);
    }
}

int hitungKedalaman(address root, int start){
    if(root == Nil){
        return start;
    } else {
        int kiri = hitungKedalaman(root->left, start + 1);
        int kanan = hitungKedalaman(root->right, start + 1);
        return (kiri > kanan ? kiri : kanan);
    }
}
