#include <iostream>
using namespace std;

int main() {
    float x, y;
    cout << "Masukkan bilangan pertama: ";
    cin >> x;
    cout << "Masukkan bilangan kedua : ";
    cin >> y;

    cout << "\nHasil Penjumlahan : " << x + y << endl;
    cout << "Hasil Pengurangan : " << x - y << endl;
    cout << "Hasil Perkalian   : " << x * y << endl;

    if (y != 0)
        cout << "Hasil Pembagian   : " << x / y << endl;
    else
        cout << "Pembagian tidak bisa dilakukan (pembagi = 0)" << endl;

    return 0;
}
