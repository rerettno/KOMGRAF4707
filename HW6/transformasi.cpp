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

void matrixTranslasi ()
{
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
     cout << "\nMatrix Koordinat Baru :" << endl;

    for (j = 0; j < 3 ; j++)
    {
        cout << c[j] << " ";                    
    }    
}

void matrixRotasi ()
{
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
     cout << "\nMatrix Koordinat Baru :" << endl;

    for (j = 0; j < 3 ; j++)
    {
        cout << c[j] << " ";
        cout << endl;
    }
}

void matrixSkala ()
{
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
     cout << "\nMatrix Koordinat Baru :" << endl;

    for (j = 0; j < 3 ; j++)
    {
        cout << c[j] << " ";                    
    }    
}


int main ()
{    
    int pilih;
    char akhir;
    do{
        cout << "Pilih 3 rumus matrix berikut \n1. Matrix Translasi\n2. Matrix Rotasi\n3. Matrix Skalar"<<endl;
        cin >> pilih;
        
        switch (pilih)
        {
            case 1:
                cout << "---------- Matrix Translasi ----------"<<endl;
                cout << "Masukkan nilai matrix :" << endl;
                for (j = 0; j < 3 ; j++)
                {
                    cout << "Baris Matrix " << j+1 << " :" << endl;
                    for (i = 0; i < 3 ; i++)        
                    {
                        
                        cin >> a[i][j];            
                    }               
                }
                cout << "\nMatrix Translasi:" << endl;
                    
                for (j = 0; j < 3 ; j++)
                {
                    for (i = 0; i < 3 ; i++)        
                    {
                        cout << a[i][j] << " " ;            
                    }       
                    cout << endl;        
                }
                

                cout << "Masukkkan  titik kordinat " << endl;

                for (j = 0; j < 3 ; j++)
                {        
                    cin >> b[j];                    
                }

                cout << "\nMatrix Koordinat :" << endl;

                for (j = 0; j < 3 ; j++)
                {        
                    cout << b[j] << " ";                    
                    cout << endl;        
                }

                matrixTranslasi();
                break;
            case 2 :
                cout << "---------- Matrix Rotasi ----------"<<endl;
                cout << "Masukkan nilai derajat : ";
                cin >> derajat;            

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
                        }else if ((i == 2 && j == 0)||(i == 2 && j == 1)||(i == 0 && j == 2)||(i == 1 && j == 2))
                        {
                            a[i][j]=0;
                        }else
                        {
                            a[i][j]=1;
                        }
                    }
                }
                cout << "\nMatrix Rotasi:" << endl;                
                for (j = 0; j < 3 ; j++)
                {
                    for (i = 0; i < 3 ; i++)        
                    {
                        cout << a[i][j] << " " ;            
                    }       
                    cout << endl;        
                }

                cout << "Masukkkan  titik kordinat " << endl;
                for (j = 0; j < 3 ; j++)
                {        
                    cin >> b[j];                    
                }

                cout << "\nMatrix Koordinat :" << endl;

                for (j = 0; j < 3 ; j++)
                {        
                    cout << b[j] << " ";                    
                    cout << endl;        
                }

                matrixRotasi();
                break;
            case 3:
                cout << "---------- Matrix Skala ----------"<<endl;     
                cout << " Masukkan nilai matrix :"<<endl;
                for (j = 0; j < 3 ; j++)
                {
                    cout << "Baris Matrix " << j+1 << " :" << endl;
                    for (i = 0; i < 3 ; i++)        
                    {
                        
                        cin >> a[i][j];            
                    }               
                }
                cout << "\nMatrix Skala :" << endl;
                    
                for (j = 0; j < 3 ; j++)
                {
                    for (i = 0; i < 3 ; i++)        
                    {
                        cout << a[i][j] << " " ;            
                    }       
                    cout << endl;        
                }
                

                cout << "Masukkkan  titik kordinat " << endl;

                for (j = 0; j < 3 ; j++)
                {        
                    cin >> b[j];                    
                }

                cout << "\nMatrix Koordinat :" << endl;

                for (j = 0; j < 3 ; j++)
                {        
                    cout << b[j] << " ";                    
                    cout << endl;        
                }

                matrixSkala();
                break; 
            default :
                cout << "Pilihan Tidak Valid!!!"<<endl; 
                break;
        }
    cout << "Ulang lagi (Y/T) :" << endl;
    cin >> akhir;
    }while (akhir == 'T' || akhir != 't');
    return 0;    
}