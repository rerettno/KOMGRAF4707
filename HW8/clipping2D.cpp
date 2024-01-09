#include <iostream>

using namespace std;

int main()
{
    double garis1[100],garis2[100],t[100],b[100],r[100],l[100];
    int i;
    double xv[2], yv[2];
    // Input viewport dimensions
    cout << "Masukkan nilai viewport (x min , y min, x max, y max) : " <<endl;
    cin >> xv[0] >> yv[0] >> xv[1] >> yv[1];

    
    //garis 1
    cout << "Masukkan nilai pada garis 1 :"<<endl;
    cout << "   Nilai titik a : ";
    for (i = 0; i < 2; i++)
    {
        cin >> garis1[i];       
    }    
    cout << "   Nilai titik b : ";
    for (i=2; i < 4; i++)
    {
        cin >> garis1[i];        
    }
    cout << endl;  

    //garis 2
    cout << "Masukkan nilai pada garis 2 :"<<endl;
    cout << "   Nilai titik a : ";
    for (i = 0; i < 2; i++)
    {
        cin >> garis2[i];       
    }    
    cout << "   Nilai titik b : ";
    for (i=2; i < 4; i++)
    {
        cin >> garis2[i];        
    }
    cout << endl;  


    // Region bits
    cout << "Region garis 1 " << endl;

    for (int i = 0; i < 2; i++) {
        // Region titik A or B
        if (garis1[i * 2 + 1] <= yv[1]) {
            t[i] = 0;
        } else {
            t[i] = 1;
        }

        if (garis1[i * 2 + 1] < yv[0]) {
            b[i] = 1;
        } else {
            b[i] = 0;
        }

        if (garis1[i * 2] > xv[1]) {
            r[i] = 1;
        } else {
            r[i] = 0;
        }

        if (garis1[i * 2] < xv[0]) {
            l[i] = 1;
        } else {
            l[i] = 0;
        }

        cout << "   Nilai region titik " << char('a' + i) << ": ";
        cout << t[i] << b[i] << r[i] << l[i] << endl;
    }

    cout << "Region garis 2 " << endl;

    for (int i = 2; i < 4; i++) {
        // Region titik C or D
        if (garis2[i * 2 - 3] <= yv[1]) {
            t[i] = 0;
        } else {
            t[i] = 1;
        }

        if (garis2[i * 2 - 3] < yv[0]) {
            b[i] = 1;
        } else {
            b[i] = 0;
        }

        if (garis2[i * 2 - 4] > xv[1]) {
            r[i] = 1;
        } else {
            r[i] = 0;
        }

        if (garis2[i * 2 - 4] < xv[0]) {
            l[i] = 1;
        } else {
            l[i] = 0;
        }

        cout << "   Nilai region titik " << char('a' + i - 2) << ": ";
        cout << t[i] << b[i] << r[i] << l[i] << endl;

    }


    // Menentukan titik potong
    cout << endl;
    cout << "Mencari titik potong" << endl;
    cout<<"Garis 1"<<endl;
    double xp1[100], xp2[100], yp1[100], yp2[100], m1, m2;

    // Garis 1
    for (int i = 0; i < 2; i++) {
        cout << "   Titik Potong " << char('a' + i) << ": " << endl;

        // Hitung slope untuk titik saat ini
        if (i == 0) {
            m1 = (garis1[3] - garis1[1]) / (garis1[2] - garis1[0]);
        }

        // Periksa kondisi berdasarkan nilai region bits
        if (t[i] == 1) {
            xp2[i] = garis1[i * 2] + (yv[1] - garis1[i * 2 + 1]) / m1;
            cout << "   (" << xp2[i] << "," << yv[1] << ")" << endl;
        }
        if (b[i] == 1) {
            xp1[i] = garis1[i * 2] + (yv[0] - garis1[i * 2 + 1]) / m1;
            cout << "   (" << xp1[i] << "," << yv[0] << ")" << endl;
        }
        if (r[i] == 1) {
            yp2[i] = garis1[i * 2 + 1] + m1 * (xv[1] - garis1[i * 2]);
            cout << "   (" << xv[1] << "," << yp2[i] << ")" << endl;
        }
        if (l[i] == 1) {
            yp1[i] = garis1[i * 2 + 1] + m1 * (xv[0] - garis1[i * 2]);
            cout << "   (" << xv[0] << "," << yp1[i] << ")" << endl;
        }
        cout << endl;
    }

    // Garis 2
    cout << "Garis 2" << endl;
    m2 = (garis2[3] - garis2[1]) / (garis2[2] - garis2[0]);

    for (int i = 2; i < 4; i++) {
        cout << "   Titik Potong " << char('a' + i - 2) << ": " << endl;

        // Periksa kondisi berdasarkan nilai region bits
        if (t[i] == 1) {
            xp2[i] = garis2[i * 2 - 4] + (yv[1] - garis2[i * 2 - 3]) / m2;
            cout << "   (" << xp2[i] << "," << yv[1] << ")" << endl;
        }
        if (b[i] == 1) {
            xp1[i] = garis2[i * 2 - 4] + (yv[0] - garis2[i * 2 - 3]) / m2;
            cout << "   (" << xp1[i] << "," << yv[0] << ")" << endl;
        }
        if (r[i] == 1) {
            yp2[i] = garis2[i * 2 - 3] + m2 * (xv[1] - garis2[i * 2 - 4]);
            cout << "   (" << xv[1] << "," << yp2[i] << ")" << endl;
        }
        if (l[i] == 1) {
            yp1[i] = garis2[i * 2 - 3] + m2 * (xv[0] - garis2[i * 2 - 4]);
            cout << "   (" << xv[0] << "," << yp1[i] << ")" << endl;
        }
        cout << endl;
        }

    cout << "Menentukan titik potong yang masuk dalam viewport" << endl;

    cout << "Garis 1 " << endl;
    for (int i = 0; i < 2; i++) {
        cout << "   Titik Potong " << char('a' + i) << endl;

        if (xp1[i] > xv[0] && xp1[i] <= xv[1]) {
            cout << "   (" << xp1[i] << "," << yv[0] << ")" << endl;
        }
        if (yp1[i] > yv[0] && yp1[i] <= yv[1]) {
            cout << "   (" << yp1[i] << "," << xv[0] << ")" << endl;
        }
        if (xp2[i] > xv[0] && xp2[i] <= xv[1]) {
            cout << "   (" << xp2[i] << "," << yv[1] << ")" << endl;
        }
        if (yp2[i] > yv[0] && yp2[i] <= yv[1]) {
            cout << "   (" << yp2[i] << "," << xv[1] << ")" << endl;
        }
        cout << endl;
    }

    cout << "Garis 2 " << endl;
    for (int i = 2; i < 4; i++) {
        cout << "   Titik Potong " << char('a' + i - 2) << endl;

        if (xp1[i] > xv[0] && xp1[i] <= xv[1]) {
            cout << "   (" << xp1[i] << "," << yv[0] << ")" << endl;
        }
        if (yp1[i] > yv[0] && yp1[i] <= yv[1]) {
            cout << "   (" << yp1[i] << "," << xv[0] << ")" << endl;
        }
        if (xp2[i] > xv[0] && xp2[i] <= xv[1]) {
            cout << "   (" << xp2[i] << "," << yv[1] << ")" << endl;
        }
        if (yp2[i] > yv[0] && yp2[i] <= yv[1]) {
            cout << "   (" << yp2[i] << "," << xv[1] << ")" << endl;
        }
        cout << endl;
    }

    return 0;
}
