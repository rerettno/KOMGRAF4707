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
int i, j; // i kolom j baris
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
    int pAwal[3] = {xAwal, yAwal,1};

    // Perform matrix multiplication

    for ( j = 0; j < 3; j++) {
        pAkhir[j] = 0;
        for ( i = 0; i < 3; i++) {
            pAkhir[j] += matrix[i][j] * pAwal[i];
        }
    }
    cout << "\nMatrix Koordinat Translasi 2D:" << endl;

    // Print the resulting translated coordinates
    for ( j = 0; j < 2; j++) {
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
    for ( j = 0; j < 3; j++) {
        pAkhir[j] = 0;
        for ( i = 0; i < 3; i++) {
            pAkhir[j] += matrix[i][j] * pAwal[i];
        }
    }

    // Print the resulting scaled coordinates
    cout << "\nMatrix Koordinat Skala 2D:" << endl;
    for ( j = 0; j < 2; j++) {
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
        cout << "Pilih 3 rumus matrix berikut \n1. Matrix Translasi\n2. Matrix Skala\n3. Matrix Rotasi"<<endl;
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

            default:
                cout << "Pilihan Tidak Valid!!!"<<endl; 
                break;
        }
        

        cout << "\nUlang Program (Y/T) :" << endl;
        cin >> akhir;

    }
    while (akhir == 'Y' || akhir == 'y');
    return 0;    
}