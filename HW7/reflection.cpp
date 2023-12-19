#include <iostream>
#include <cmath>
#include <limits>

using namespace std;
double a [100][100];
double b [100];
double c [100];
double temp = 0 ;
double hasil;
int i, j;
double derajat;
double nilaiSin,nilaiCos,radian,epsilon;

void matrixMirrorSumbuX(double xAkhir,double yAkhir,double hasil_rotasi[10])
{
    cout << endl;
    cout << "--------------------------------Matirx Mirror--------------------------------"<<endl;
    for (j = 0; j < 3 ; j++)
    {           
        for (i = 0; i < 3 ; i++)        
        {            
            if ((j == 0 && i == 0)||(j == 2 && i == 2))
            {
                a[i][j]=1;
            }
            else if (j == 1 && i == 1)
            {
                a[i][j]=-1;
            }
            else{
                a[i][j]=0;
            }
        }

        if (j == 0)
        {
            b[j]=xAkhir;
        }
        else if (j == 1)
        {
            b[j]=yAkhir;
        }else{
            b[j]=1;
        }
    }for (j = 0; j < 3 ; j++)
    {   
        b[i]=b[j];
        for (i = 0; i < 3 ; i++)        
        {            
            temp = a[i][j] * b[i] ;   
            hasil +=temp;        
        }       
        c[j] = hasil;
        
        temp = 0;
        hasil = 0;
    }
     cout << "\nMatrix Koordinat Mirror (Sumbu X) :" << endl;

    for (j = 0; j < 3 ; j++)
    {
        cout << c[j] << " ";                    
    }

    double hasil_mirror[10];
    cout << endl;

    cout << "--------------------------------Matirx Composite--------------------------------"<<endl;        
    for (j = 0; j < 3; j++)
    {
        hasil_mirror[j] = c[j] * hasil_rotasi[j];        
        cout << " " << hasil_mirror[j];
    }        
}

void matrixRotasi (double derajat,int xAkhir,int yAkhir,double hasil_skala[10])
{   
    cout << endl;
    cout << "--------------------------------Matirx Rotasi--------------------------------"<<endl; 
    radian = derajat * M_PI / 180;
    nilaiSin = sin(radian);
    nilaiCos = cos(radian);
    epsilon = numeric_limits<double>::epsilon();
    if (fabs(nilaiCos) < epsilon) {
        nilaiCos = 0.0;
    }else if (fabs(nilaiSin) < epsilon) {
        nilaiSin = 0.0;
    }
    for (j = 0 ; j  < 3;j++)
    {
        for (i = 0 ; i <3 ; i++)
        {
            if ((i == 0 && j == 0)||(i == 1 && j == 1))
            {
                a[i][j] = nilaiCos;
            }else if (i == 1 && j == 0)
            {
                a[i][j]=-nilaiSin;
            }
            else if (i == 0 && j == 1)
            {
                a[i][j]= nilaiSin;
            }else if (i==2 && j==2)
            {
                a[i][j]=1;
            }else
            {
                a[i][j]=0;
            }
        }
        if (j == 0)
        {
            b[j]=xAkhir;
        }
        else if (j == 1)
        {
            b[j]=yAkhir;
        }else{
            b[j]=1;
        }
    }            
    for (j = 0; j < 3 ; j++)
    {   
        b[i]=b[j];
        for (i = 0; i < 3 ; i++)        
        {            
            temp = a[i][j] * b[i] ;   
            hasil +=temp;        
        }       
        c[j] = hasil;
        
        temp = 0;
        hasil = 0;
    }
     cout << "\nMatrix Koordinat Rotasi :" << endl;

    for (j = 0; j < 3 ; j++)
    {
        cout << c[j] << " ";                    
    }    

    double hasil_rotasi[10];
    for (j = 0; j < 3; j++)
    {
        hasil_rotasi[j] = c[j] * hasil_skala[j];
        cout << hasil_rotasi[j];
    }
    matrixMirrorSumbuX(xAkhir,yAkhir,hasil_rotasi);
    cout << endl;
}


void matrixSkala (int xAwal, int yAwal, int xAkhir,int yAkhir,double derajat,double hasil_translasi[10])
{
    cout << endl;    
    cout << "--------------------------------Matirx Skala--------------------------------"<<endl;
    for (j = 0; j < 3 ; j++)
    {           
        for (i = 0; i < 3 ; i++)        
        {            
            if (j == 0 && i == 0)
            {
                a[i][j]=xAwal;
            }
            else if (j == 1 && i == 1)
            {
                a[i][j]=yAwal;
            }
            else if (j==2 && i == 2)
            {
                a[i][j]=1;
            }else{
                a[i][j]=0;
            }
        }

        if (j == 0)
        {
            b[j]=xAkhir;
        }
        else if (j == 1)
        {
            b[j]=yAkhir;
        }else{
            b[j]=1;
        }
    }            
    for (j = 0; j < 3 ; j++)
    {   
        b[i]=b[j];
        for (i = 0; i < 3 ; i++)        
        {            
            temp = a[i][j] * b[i] ;   
            hasil +=temp;        
        }       
        c[j] = hasil;
        
        temp = 0;
        hasil = 0;
    }
     cout << "\nMatrix Koordinat Skala :" << endl;

    for (j = 0; j < 3 ; j++)
    {
        cout << c[j] << " ";                    
    }
    double hasil_skala[10];

    for (j = 0; j < 3; j++)
    {
        hasil_skala[j] = c[j] * hasil_translasi[j];
        cout << hasil_skala[j];
    }
    matrixRotasi(derajat,xAkhir,yAkhir,hasil_skala);
    cout << endl;
}

void matrixTranslasi (int xAwal,int yAwal,int xAkhir,int yAkhir,double derajat)
{
    cout << "--------------------------------Matirx Translasi--------------------------------"<<endl;
    for (j = 0; j < 3 ; j++)
    {           
        for (i = 0; i < 3 ; i++)        
        {            
            if (j == 0 && i == 2)
            {
                a[i][j]=xAwal;
            }
            else if (j == 1 && i == 2)
            {
                a[i][j]=yAwal;
            }
            else if ((j == 0 && i == 0)||(j == 1 && i == 1)||(j ==2 && i == 2))
            {
                a[i][j]=1;
            }else{
                a[i][j]=0;
            }
        }

        if (j == 0)
        {
            b[j]=xAkhir;
        }
        else if (j == 1)
        {
            b[j]=yAkhir;
        }else{
            b[j]=1;
        }
    }            
    for (j = 0; j < 3 ; j++)
    {   
        b[i]=b[j];
        for (i = 0; i < 3 ; i++)        
        {            
            temp = a[i][j] * b[i] ;   
            hasil +=temp;        
        }       
        c[j] = hasil;
        
        temp = 0;
        hasil = 0;
    }
     cout << "\nMatrix Koordinat Translasi :" << endl;

    for (j = 0; j < 3 ; j++)
    {
        cout << c[j] << " ";                    
    }
    matrixSkala(xAwal,yAwal,xAkhir,yAkhir,derajat,c);
    cout << endl;
}

int main ()
{    
    int pilih;
    char akhir;
    int x0,y0,x1,y1;
    do{
        cout << "Masukkan titik A : ";
        cin >> x0;
        cin >> y0;
        cout << "Masukkan titik B : ";
        cin >> x1;
        cin >> y1;
        cout << "Masukkan nilai derajat : ";
        cin >> derajat;
        matrixTranslasi(x0, y0, x1, y1, derajat);

        cout << "Ulang lagi (Y/T) :" << endl;
        cin >> akhir;

    }while (akhir == 'Y' || akhir == 'y');
    return 0;    
}