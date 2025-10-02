#include <iostream>
using namespace std;

string angkaKeTulisan(int n) {
    string satuan[] = {"nol", "satu", "dua", "tiga", "empat", "lima",
                       "enam", "tujuh", "delapan", "sembilan", "sepuluh",
                       "sebelas", "dua belas", "tiga belas", "empat belas",
                       "lima belas", "enam belas", "tujuh belas", "delapan belas",
                       "sembilan belas"};

    string puluhan[] = {"", "", "dua puluh", "tiga puluh", "empat puluh",
                        "lima puluh", "enam puluh", "tujuh puluh",
                        "delapan puluh", "sembilan puluh"};

    if (n < 20) {
        return satuan[n];
    } else if (n < 100) {
        if (n % 10 == 0) {
            return puluhan[n / 10];
        } else {
            return puluhan[n / 10] + " " + satuan[n % 10];
        }
    } else if (n == 100) {
        return "seratus";
    } else {
        return "di luar jangkauan";
    }
}

int main() {
    int angka;
    cout << "Masukkan bilangan (0 - 100): ";
    cin >> angka;

    cout << angka << " : " << angkaKeTulisan(angka) << endl;
    return 0;
}