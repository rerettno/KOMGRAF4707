#include <iostream>
#include <cmath>
#include <limits>

using namespace std;
//data 
double matrix [100][100];
double pAwal [100];
double pAkhir [100];
double temp = 0 ;
double hasil;
int i, j;
double derajat;
double nilaiSin,nilaiCos,radian;
char akhir, sumbu;

//1. Translasi
void matrixTranslasi2D(int xAwal, int yAwal, int xt, int yt) 
{

    cout << "--------------------------------Matrix Translasi 2D--------------------------------" << endl;

    // Define the 4x4 translation matrix
    int matrix[3][3] = 
    {
        {1, 0, 0},
        {0, 1, 0},
        {xt, yt, 1}
    };

    // Define the initial coordinates as a column vector
    int pAwal[3] = {xAwal, yAwal, 1};

    // Perform matrix multiplication
    int pAkhir[3];
    for (int j = 0; j < 3; j++) {
        pAkhir[j] = 0;
        for (int i = 0; i < 3; i++) {
            pAkhir[j] += matrix[i][j] * pAwal[i];
        }
    }
    cout << "\nMatrix Koordinat Translasi 2D:" << endl;

    // Print the resulting translated coordinates
    for (int j = 0; j < 2; j++) {
        cout <<pAkhir[j] << " ";
    }

    cout << endl;
}

//2. Skala
void matrixSkala2D (int xAwal, int yAwal, int xs, int ys )
{

    cout << "--------------- Hasil ---------------" << endl;

    // Define the 4x4 translation matrix
    int matrix[3][3] = 
    {
        {xs, 0, 0},
        {0, ys, 0},
        {0, 0, 1}
    };

    // Define the initial coordinates as a column vector
    int pAwal[3] = {xAwal, yAwal, 1};

    // Perform matrix multiplication to apply scaling
    int pAkhir[3];
    for (int j = 0; j < 3; j++) {
        pAkhir[j] = 0;
        for (int i = 0; i < 3; i++) {
            pAkhir[j] += matrix[i][j] * pAwal[i];
        }
    }

    // Print the resulting scaled coordinates
    cout << "\nMatrix Koordinat Skala 2D:" << endl;
    for (int j = 0; j < 2; j++) {
        cout << pAkhir[j] << " ";
    }

    cout << endl;
}


//3. Rotasi
void matrixRotasi2D (int xAwal, int yAwal,  double derajat)
{
    cout << "--------------- Hasil ---------------" << endl;

    // Define sin cos
    radian = derajat * M_PI / 180;
    nilaiCos = cos(radian);
    nilaiSin = sin(radian);

    // Define the initial coordinates as a column vector
    int pAwal[3] = {xAwal, yAwal, 1};

    // Define the 4x4 translation matrix
    double matrix[3][3] = {
        {nilaiCos, nilaiSin, 0 },
        {-nilaiSin, nilaiCos, 0 },
        {0, 0, 1 }
    };
    
    /// Perform matrix multiplication to apply rotation
    double pAkhir[3];
    for ( j = 0; j < 3; j++) {
        pAkhir[j] = 0;
        for ( i = 0; i < 3; i++) {
            pAkhir[j] += matrix[i][j] * pAwal[i];
        }
    }

    // Print the resulting rotated coordinates
    cout << "Koordinat awal: " << endl;
    for (int i = 0; i < 2; i++) {
        cout << pAwal[i] << " ";
    }
    cout << endl;
    cout << "Koordinat akhir: " << endl;
    for (int i = 0; i < 2; i++) {
        cout << pAkhir[i] << " ";
    }
    cout << endl;
}

//4. Refleksi
void matrixRefleksi2D(int xAwal, int yAwal) {
    do {
        cout << "\nMasukkan sumbu refleksi \na. Terhadap sumbu x\nb. Terhadap sumbu y\nc. Terhadap sumbu y = x\nd. Terhadap sumbu y = -x"<<endl;
        cin >> sumbu;

        cout << "--------------- Hasil Refleksi ---------------" << endl;
    
        // Define the initial coordinates as a column vector
        int pAwal[3] = {xAwal, yAwal, 1};

        // Define the reflection matrix based on the chosen axis
        int matrix[3][3] = {
            {1, 0, 0},
            {0, 1, 0},
            {0, 0, 1}
        };
        switch (sumbu) {
            case 'a':
                matrix[1][1] = -1;
                break;

            case 'b':
                matrix[0][0] = -1;
                break;

            case 'c':  // Refleksi terhadap garis y = x
                matrix[0][0] = 0;
                matrix[0][1] = 1;
                matrix[1][0] = 1;
                matrix[1][1] = 0;
                break;

            case 'd': // Refleksi terhadap garis y = -x
                matrix[0][0] = 0;
                matrix[0][1] = -1;
                matrix[1][0] = -1;
                matrix[1][1] = 0; 
                break;

            default:
            cout << "Sumbu refleksi tidak valid!" << endl;
            return;
        }

        // Perform matrix multiplication to apply reflection
        int pAkhir[3];
        for (int j = 0; j < 3; j++) {
            pAkhir[j] = 0;
            for (int i = 0; i < 3; i++) {
            pAkhir[j] += matrix[i][j] * pAwal[i];
            }
        }

        // Print the resulting reflected coordinates
        cout << "Koordinat awal: " << endl;
        for (int i = 0; i < 2; i++) {
            cout << pAwal[i] << " ";
        }
        cout << endl;
        cout << "Koordinat akhir (refleksi): " << endl;
        for (int i = 0; i < 2; i++) {
            cout << pAkhir[i] << " ";
        }
        cout << endl;

        cout << "\nIngin Mencoba Sumbu Lain? (Y/T) :" << endl;
        cin >> akhir;

    }
    while (akhir == 'Y' || akhir == 'y');
    if (akhir == 'T' || akhir == 't') {
        return;
    }
    //matrixRefleksi2D(xAwal, yAwal);

}




int main ()
{    
    int pilih;
    char akhir;
    int x,y;
    int xt,yt;
    int xs,ys;
    double derajat;

    do{
        cout << "~~~~~~~~~ Transformasi Matrix 2D ~~~~~~~~~\n"<<endl;
        cout << "Pilih 4 rumus matrix berikut \n1. Matrix Translasi\n2. Matrix Skala\n3. Matrix Rotasi\n4. Matrix Refleksi"<<endl;
        cin >> pilih;

        switch (pilih)
        {
            case 1:
                cout <<"---------- Matrix Translasi 2D ----------"<<endl;

                cout << "Masukkan koordinat Awal ( 2 titik ): ";
                cin >> x;
                cin >> y;

                cout << "Masukkan nilai t : ";
                cin >> xt;
                cin >> yt;

                matrixTranslasi2D(x, y, xt, yt);
                break;
            
            case 2:
                cout <<"---------- Matrix Skala 2D ----------"<<endl;

                cout << "Masukkan koordinat Awal ( 2 titik ): ";
                cin >> x;
                cin >> y;

                cout << "Masukkan nilai Skala : ";
                cin >> xs;
                cin >> ys;

                matrixSkala2D(x, y, xs, ys);
                break;

            case 3:
                cout <<"---------- Matrix Rotasi 2D ----------"<<endl;

                cout << "Masukkan koordinat Awal ( 2 titik ): ";
                cin >> x;
                cin >> y;

                cout << "Masukkan nilai derajat : ";
                cin >> derajat;

                matrixRotasi2D(x, y, derajat);
                break;

            case 4:
                cout <<"---------- Matrix Refleksi 2D ----------"<<endl;

                cout << "Masukkan koordinat Awal ( 2 titik ): ";
                cin >> x;
                cin >> y;
                
                matrixRefleksi2D(x, y);
                break;

            default:
                cout << "Pilihan Tidak Valid!!!"<<endl; 
                break;
        }
        

        cout << "\nUlang Program Transformasi 2D (Y/T) :" << endl;
        cin >> akhir;

    }
    while (akhir == 'Y' || akhir == 'y');
    return 0;    
}



