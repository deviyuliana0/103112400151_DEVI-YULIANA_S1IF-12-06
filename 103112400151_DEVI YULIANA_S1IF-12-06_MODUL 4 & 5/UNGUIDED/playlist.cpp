#include "Playlist.h"

// Membuat playlist kosong
void buatPlaylist(Playlist &P) {
    P.head = NULL;
}

// Mengecek apakah playlist kosong
bool cekKosong(Playlist P) {
    return (P.head == NULL);
}

// Membuat node baru
Node* buatNode(Lagu laguBaru) {
    Node* node = new Node;
    node->data = laguBaru;
    node->next = NULL;
    return node;
}

// Menghapus node dari memori
void hapusNode(Node* node) {
    delete node;
}

// Menambah lagu di awal playlist
void tambahDepan(Playlist &P, Node* node) {
    if (cekKosong(P)) {
        P.head = node;
    } else {
        node->next = P.head;
        P.head = node;
    }
}

// Menambah lagu di akhir playlist
void tambahBelakang(Playlist &P, Node* node) {
    if (cekKosong(P)) {
        P.head = node;
    } else {
        Node* bantu = P.head;
        while (bantu->next != NULL) {
            bantu = bantu->next;
        }
        bantu->next = node;
    }
}

// Menambah lagu setelah posisi tertentu
void tambahSetelah(Playlist &P, Node* node, int posisi) {
    if (cekKosong(P)) {
        cout << "Playlist masih kosong!\n";
        return;
    }

    Node* bantu = P.head;
    int i = 1;
    while (bantu != NULL && i < posisi) {
        bantu = bantu->next;
        i++;
    }

    if (bantu != NULL) {
        node->next = bantu->next;
        bantu->next = node;
    } else {
        cout << "Posisi tidak ditemukan!\n";
    }
}

// Menghapus lagu berdasarkan judul
void hapusBerdasarkanJudul(Playlist &P, string judul) {
    if (cekKosong(P)) {
        cout << "Playlist kosong.\n";
        return;
    }

    Node *hapus = P.head, *sebelum = NULL;
    while (hapus != NULL && hapus->data.judul != judul) {
        sebelum = hapus;
        hapus = hapus->next;
    }

    if (hapus == NULL) {
        cout << "Lagu \"" << judul << "\" tidak ditemukan.\n";
        return;
    }

    if (sebelum == NULL) { // hapus di awal
        P.head = hapus->next;
    } else {
        sebelum->next = hapus->next;
    }

    hapusNode(hapus);
    cout << "Lagu \"" << judul << "\" berhasil dihapus.\n";
}

// Menampilkan seluruh playlist
void tampilkanPlaylist(Playlist P) {
    if (cekKosong(P)) {
        cout << "Playlist kosong.\n";
    } else {
        Node* bantu = P.head;
        int i = 1;
        cout << "\n=== DAFTAR LAGU DALAM PLAYLIST ===\n";
        while (bantu != NULL) {
            cout << i << ". Judul    : " << bantu->data.judul << endl;
            cout << "   Penyanyi : " << bantu->data.penyanyi << endl;
            cout << "   Durasi   : " << bantu->data.durasi << " menit\n";
            bantu = bantu->next;
            i++;
        }
        cout << "==================================\n";
    }
}
