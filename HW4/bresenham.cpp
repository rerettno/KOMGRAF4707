#include <iostream>

using namespace std;

int main() {
    int x0, y0, x1, y1;

    cout << "Masukkan koordinat titik awal (x0, y0): ";
    cin >> x0 >> y0;

    cout << "Masukkan koordinat titik akhir (x1, y1): ";
    cin >> x1 >> y1;

    // Hitung dx dan dy
    int dx = x1 - x0;
    int dy = y1 - y0;

    // Tentukan arah penggambaran pada titik awal ke titik akhir
    int sx = dx > 0 ? 1 : -1;  
    int sy = dy > 0 ? 1 : -1;

    // Perbaiki nilai dx dan dy jika negatif
    dx = abs(dx);
    dy = abs(dy);

    // Hitung parameter p0
    int p0 = 2 * dy - dx;

    int x = x0, y = y0;

    cout << "Titik-titik pada garis: " << endl;

    while (x != x1) {
        cout << "(" << x << ", " << y << ")" << endl;
        if (p0 < 0) {
            p0 += 2 * dy;
            x += sx;
        } else {
            p0 += 2 * (dy - dx);
            x += sx;
            y += sy;
        }
    }

    // Tampilkan titik akhir
    cout << "(" << x1 << ", " << y1 << ")" << endl;

    return 0;
}
