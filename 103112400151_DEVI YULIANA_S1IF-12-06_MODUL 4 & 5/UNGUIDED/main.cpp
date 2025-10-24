#include "Playlist.h"

int main() {
    Playlist playlistSaya;
    buatPlaylist(playlistSaya);

    Lagu l1 = {"Hati-Hati di Jalan", "Tulus", 4.3};
    Lagu l2 = {"Sempurna", "Andra and The Backbone", 5.1};
    Lagu l3 = {"Celengan Rindu", "Fiersa Besari", 4.5};
    Lagu l4 = {"Laskar Pelangi", "Nidji", 5.0};

    // Tambah lagu sesuai perintah soal
    tambahDepan(playlistSaya, buatNode(l1));     // di awal
    tambahBelakang(playlistSaya, buatNode(l2));  // di akhir
    tambahBelakang(playlistSaya, buatNode(l3));  // di akhir
    tambahSetelah(playlistSaya, buatNode(l4), 3); // setelah lagu ke-3

    tampilkanPlaylist(playlistSaya);

    cout << "\nMenghapus lagu 'Sempurna'...\n";
    hapusBerdasarkanJudul(playlistSaya, "Sempurna");

    tampilkanPlaylist(playlistSaya);

    return 0;
}