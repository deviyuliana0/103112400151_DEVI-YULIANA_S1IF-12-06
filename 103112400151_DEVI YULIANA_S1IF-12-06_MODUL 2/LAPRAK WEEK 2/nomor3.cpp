#include <iostream>
using namespace std;

float hitungRata(int *data, int jumlah) {
    float total = 0;
    for (int i = 0; i < jumlah; i++)
        total += *(data + i);
    return total / jumlah;
}

void cariMaxMin(int *data, int jumlah, int &tertinggi, int &terendah) {
    tertinggi = terendah = *data;
    for (int i = 1; i < jumlah; i++) {
        if (*(data + i) > tertinggi) tertinggi = *(data + i);
        if (*(data + i) < terendah)  terendah = *(data + i);
    }
}

int main() {
    int nSiswa;
    cout << "Masukkan jumlah siswa: ";
    cin >> nSiswa;

    int *nilaiUjian = new int[nSiswa];
    for (int i = 0; i < nSiswa; i++) {
        cout << "Nilai siswa ke-" << i + 1 << ": ";
        cin >> *(nilaiUjian + i);
    }

    float rataKelas = hitungRata(nilaiUjian, nSiswa);
    int nilaiTinggi, nilaiRendah;
    cariMaxMin(nilaiUjian, nSiswa, nilaiTinggi, nilaiRendah);

    cout << "\nRata-rata kelas : " << rataKelas;
    cout << "\nNilai tertinggi : " << nilaiTinggi;
    cout << "\nNilai terendah  : " << nilaiRendah << endl;

    delete[] nilaiUjian;
    return 0;
}
