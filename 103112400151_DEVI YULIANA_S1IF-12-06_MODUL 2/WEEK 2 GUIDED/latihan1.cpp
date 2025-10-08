#include <iostream>
using namespace std;

int main() {
    int x, y;
    int *px;
    x = 87;
    px = &x;
    y = *px;

    // Menampilan informasi
    cout << "Alamat x =" << &x << endl;
    cout << "Isi px =" << px << endl;
    cout << "Isi x =" << x << endl;
    cout << "Nilai *px =" << *px << endl;
    cout << "Nilai y =" << y << endl;
}
