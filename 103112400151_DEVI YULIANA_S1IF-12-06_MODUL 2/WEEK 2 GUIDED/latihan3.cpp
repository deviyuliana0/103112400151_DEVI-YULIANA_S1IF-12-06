#include <iostream> // input output program
using namespace std;

// Mendeklarasikan PROTOTYPE FUNGSI
int maks3(int a, int b, int c); 

int main() {
    int x, y, z;
    cout << "Masukkan nilai bilangan ke-1 = ";
    cin >> x;
    cout << "Masukkan nilai bilangan ke-2 = ";
    cin >> y;
    cout << "Masukkan nilai bilangan ke-3 = ";
    cin >> z;
    
    cout << "Nilai maksimumnya adalah = "
    << maks3 (x, y, z);
    return 0;
}

 // Badan Fungsi ( diolah utuk dibandingkan )
int maks3(int a, int b, int c) {
    int temp_max = a;
    if (b > temp_max)
        temp_max = b;
    if (c > temp_max)
        temp_max = c;
        return temp_max;
}
