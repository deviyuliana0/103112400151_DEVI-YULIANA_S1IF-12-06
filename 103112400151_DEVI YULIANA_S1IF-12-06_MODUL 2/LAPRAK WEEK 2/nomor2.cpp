#include <iostream>
using namespace std;

int main() {
    int N;
    cout << "Masukkan jumlah elemen array (N): ";
    cin >> N;

    int *arr = new int[N];

    cout << "Masukkan " << N << " bilangan bulat:\n";
    for (int i = 0; i < N; i++) {
        cout << "Elemen ke-" << i + 1 << ": ";
        cin >> *(arr + i);
    }

    int jumlah = 0;
    int maksimum = *arr;
    int minimum = *arr;

    for (int *p = arr; p < arr + N; p++) {
        jumlah += *p;
        if (*p > maksimum) maksimum = *p;
        if (*p < minimum) minimum = *p;
    }

    cout << "\n=== HASIL PERHITUNGAN ===\n";
    cout << "Jumlah seluruh bilangan : " << jumlah << endl;
    cout << "Nilai maksimum          : " << maksimum << endl;
    cout << "Nilai minimum           : " << minimum << endl;

    delete[] arr;
    return 0;
}
