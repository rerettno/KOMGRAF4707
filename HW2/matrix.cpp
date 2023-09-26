#include <iostream>
#include <vector>

using namespace std;

// Fungsi untuk menampilkan matriks
void tampilkanMatriks(const vector<vector<int>>& matriks) {
    for (const vector<int>& baris : matriks) {
        for (int elemen : baris) {
            cout << elemen << " ";
        }
        cout << endl;
    }
}

// Fungsi untuk menambahkan dua matriks
vector<vector<int>> tambahMatriks(const vector<vector<int>>& matriksA, const vector<vector<int>>& matriksB) {
    int baris = matriksA.size();
    int kolom = matriksA[0].size();
    vector<vector<int>> hasil(baris, vector<int>(kolom));

    for (int i = 0; i < baris; i++) {
        for (int j = 0; j < kolom; j++) {
            hasil[i][j] = matriksA[i][j] + matriksB[i][j];
        }
    }

    return hasil;
}

// Fungsi untuk mengurangkan dua matriks
vector<vector<int>> kurangMatriks(const vector<vector<int>>& matriksA, const vector<vector<int>>& matriksB) {
    int baris = matriksA.size();
    int kolom = matriksA[0].size();
    vector<vector<int>> hasil(baris, vector<int>(kolom));

    for (int i = 0; i < baris; i++) {
        for (int j = 0; j < kolom; j++) {
            hasil[i][j] = matriksA[i][j] - matriksB[i][j];
        }
    }

    return hasil;
}

// Fungsi untuk mengalikan dua matriks 2x2
vector<vector<int>> kaliMatriks(const vector<vector<int>>& matriksA, const vector<vector<int>>& matriksB) {
    vector<vector<int>> hasil(2, vector<int>(2));

    hasil[0][0] = (matriksA[0][0] * matriksB[0][0]) + (matriksA[0][1] * matriksB[1][0]);
    hasil[0][1] = (matriksA[0][0] * matriksB[0][1]) + (matriksA[0][1] * matriksB[1][1]);
    hasil[1][0] = (matriksA[1][0] * matriksB[0][0]) + (matriksA[1][1] * matriksB[1][0]);
    hasil[1][1] = (matriksA[1][0] * matriksB[0][1]) + (matriksA[1][1] * matriksB[1][1]);

    return hasil;
}

int main() {
    // Contoh matriks A dan B
    vector<vector<int>> matriksA = {{1, 2}, {3, 4}};
    vector<vector<int>> matriksB = {{5, 6}, {7, 8}};

    cout << "Matriks A:" << endl;
    tampilkanMatriks(matriksA);

    cout << "Matriks B:" << endl;
    tampilkanMatriks(matriksB);

    cout << "Penjumlahan matriks A + B:" << endl;
    tampilkanMatriks(tambahMatriks(matriksA, matriksB));

    cout << "Pengurangan matriks A - B:" << endl;
    tampilkanMatriks(kurangMatriks(matriksA, matriksB));

    cout << "Perkalian matriks A * B:" << endl;
    tampilkanMatriks(kaliMatriks(matriksA, matriksB));

    return 0;
}
