#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    int n;
    cout << "Input: ";
    if (!(cin >> n) || n <= 0) return 0;

    vector<string> lines;
    // buat setiap baris sebagai string
    for (int i = n; i >= 1; --i) {
        string s;
        // kiri (mundur)
        for (int j = i; j >= 1; --j) {
            s += to_string(j);
            if (j > 1) s += " ";
        }
        s += " * ";
        // kanan (maju)
        for (int j = 1; j <= i; ++j) {
            s += to_string(j);
            if (j < i) s += " ";
        }
        lines.push_back(s);
    }

    // cetak semua baris
    for (const auto &ln : lines) cout << ln << '\n';

    // cari posisi '*' pada baris pertama, lalu cetak '*' penutup di bawahnya
    size_t pos = lines.front().find('*');
    if (pos != string::npos) {
        cout << string(pos, ' ') << '*' << '\n';
    } else {
        cout << '*' << '\n';
    }

    return 0;
}
