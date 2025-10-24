#ifndef PLAYLIST_H_INCLUDED
#define PLAYLIST_H_INCLUDED
#include <iostream>
#include <string>
using namespace std;

// Struktur data lagu
struct Lagu {
    string judul;
    string penyanyi;
    float durasi; // dalam menit
};

// Node untuk setiap lagu
struct Node {
    Lagu data;
    Node *next;
};

// Playlist (linked list)
struct Playlist {
    Node *head;
};

// Fungsi dasar
void buatPlaylist(Playlist &P);
bool cekKosong(Playlist P);
Node* buatNode(Lagu laguBaru);
void hapusNode(Node* node);

// Operasi tambah lagu
void tambahDepan(Playlist &P, Node* node);
void tambahBelakang(Playlist &P, Node* node);
void tambahSetelah(Playlist &P, Node* node, int posisi);

// Operasi hapus lagu
void hapusBerdasarkanJudul(Playlist &P, string judul);

// Operasi tampilkan
void tampilkanPlaylist(Playlist P);

#endif