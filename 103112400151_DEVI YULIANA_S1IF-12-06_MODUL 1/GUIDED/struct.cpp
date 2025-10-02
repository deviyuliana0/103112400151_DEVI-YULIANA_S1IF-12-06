#include <iostream>
using namespace std;

struct Mahasiswa
{
    string nama;
    string NIM;
};

int main()
{
    Mahasiswa mhs;
    mhs.nama = "Devi";
    mhs.NIM = "103112400151";

    cout << "Nama : " << mhs.nama << endl
         << "NIM : " << mhs.NIM;

}