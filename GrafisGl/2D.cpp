#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <GL/glut.h>



float xAwal, yAwal, xEnd, yEnd;
int sudut;

void tampilan(void) {
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(-50, 60, -50, 60);
}

void aturPixelAwal(GLint xCoordinate, GLint yCoordinate, GLfloat red, GLfloat green, GLfloat blue) {
    glColor3f(red, green, blue);
    glBegin(GL_POINTS);
    glVertex2i(xCoordinate, yCoordinate);
    glEnd();
    glFlush();
}

void aturPixelAkhir(GLint xCoordinate, GLint yCoordinate, GLfloat red, GLfloat green, GLfloat blue) {
    glColor3f(red, green, blue);
    glBegin(GL_POINTS);
    glVertex2i(xCoordinate, yCoordinate);
    glEnd();
    glFlush();
}

void aturPixel(GLint xCoordinate, GLint yCoordinate, GLfloat red, GLfloat green, GLfloat blue) {
    glColor3f(red, green, blue);
    glBegin(GL_POINTS);
    glVertex2i(xCoordinate, yCoordinate);
    glEnd();
    glFlush();
}
void translasi (GLint x0, GLint y0, GLint x1, GLint y1)
{
    aturPixelAwal(x0, y0,1,0,0);
    GLint xAkhir = x0 + x1;
    GLint yAkhir = y0 + y1;
    GLint xtemp= x0;
    GLint ytemp= y0;
    while (xtemp != xAkhir){
        if (xtemp >xAkhir)
        {
            xtemp--;
        }else{
            xtemp++;
        }
        aturPixel(xtemp, ytemp,0,0,0);
    }
    while (ytemp != yAkhir)
    {
        if (ytemp >yAkhir)
        {
            ytemp--;
        }else{
            ytemp++;
        }
        aturPixel(xtemp, ytemp,0,0,0);
    }
    aturPixelAkhir(xAkhir, yAkhir,0,0,1);
}

void scalar (GLint x0, GLint y0, GLint sx, GLint sy)
{
    aturPixelAwal(x0, y0,1,0,0);
    GLint xAkhir = x0 * sx;
    GLint yAkhir = y0 * sy;
    GLint xtemp= x0;
    GLint ytemp= y0;
    // while (xtemp != xAkhir){
    //     if (xtemp >xAkhir)
    //     {
    //         xtemp--;
    //     }else{
    //         xtemp++;
    //     }
    //     aturPixel(xtemp, ytemp,0,0,0);
    // }
    // while (ytemp != yAkhir)
    // {
    //     if (ytemp >yAkhir)
    //     {
    //         ytemp--;
    //     }else{
    //         ytemp++;
    //     }
    //     aturPixel(xtemp, ytemp,0,0,0);
    // }
    aturPixel(xtemp, ytemp,1,0,0); //titik awal merah
    aturPixelAkhir(xAkhir, yAkhir,0,0,1);
}

void rotation (GLint x0, GLint y0, GLint xp, GLint yp  , GLint sudut)
{
    aturPixelAwal(x0, y0 , 1,0,0);
    GLint x1,y1;
    GLint xAkhir;
    GLint yAkhir;
    
    x1 =  -(xp);
    y1 =  -(yp);

    //define sin cos
    GLfloat radian,nilaiCos,nilaiSin;
    radian = sudut * M_PI / 180;
    nilaiCos = cos(radian);
    nilaiSin = sin(radian);

    GLint xpatok = x0 -  xp;
    GLint ypatok = y0 - yp;

    GLfloat x2 = (nilaiCos*xpatok) + (-nilaiSin * ypatok);
    GLfloat y2 = (nilaiSin*xpatok) + (nilaiCos * ypatok);

    xAkhir = x2 - x1;
    yAkhir = y2 - y1;

    GLint xtemp = x0;
    GLint ytemp = y0;
    
    // while (xtemp != xAkhir)
    // {
    //     if (xtemp >= xAkhir)        
    //     {
    //         xtemp--;
    //     }else 
    //     {
    //         xtemp++;
    //     }
    //     aturPixel(xtemp, ytemp,0,0,0);
    // }

    // while (ytemp != yAkhir)
    // {
    //     if (ytemp >= yAkhir)        
    //     {
    //         ytemp--;
    //     }else 
    //     {
    //         ytemp++;
    //     }
    //     aturPixel(xtemp, ytemp,0,0,0);
    // }
    aturPixel(xtemp, ytemp,1,0,0);//titik awal merah
    aturPixel(xp, yp,0,0,0);//titik patokan hitam
    aturPixelAkhir(xAkhir, yAkhir,0,0,1);//titik akhir biru
}
void bresenham(GLfloat x0, GLfloat y0, GLfloat x1, GLfloat y1)
{
    aturPixelAwal(x0,y0,1,0,0);
    GLfloat xEnd,yEnd,sx,sy,dx,dy,p0;   

    //hitung nilai dx dy
    dx = x1-x0;
    dy = y1-y0;

    // Tentukan arah penggambaran pada titik awal ke titik akhir
    sx = dx > 0 ? 1 : -1;  
    sy = dy > 0 ? 1 : -1;

    // Perbaiki nilai dx dan dy jika negatif
    dx = abs(dx);
    dy = abs(dy);

    // Hitung parameter p0
    p0 = 2 * dy - dx;


    GLint x;
    GLint y;
    x = x0 ,y = y0;


    while (x != x1) {
        aturPixel(x,y,0,0,0);
        if (p0 < 0) {
            p0 += 2 * dy;
            x += sx;
        } else {
            p0 += 2 * (dy - dx);
            x += sx;
            y += sy;
        }
    }      
    aturPixelAkhir(x1,y1,0,0,1);
}

void dda(GLfloat x0, GLfloat y0, GLfloat xA, GLfloat yA)
{    
    aturPixelAwal(x0,y0,1,0,0);
    GLfloat dx,dy,steps;
    GLfloat xR,yR;
    GLfloat r;
    GLfloat xtemp = x0;    
    GLfloat ytemp = y0;

    // menghitung perbedaan koordinat
    dx= xA - x0;
    dy= yA - y0;

    // Menentukan langkah iterasi (perbedaan maksimum antara x dan y)
    steps = abs(dx) > abs(dy) ? abs(dx) : abs(dy);

    // Menghitung perubahan x dan y setiap iterasi
    xR = dx/r;
    yR = dy/r;
    
    GLint i = 0;
    while (i < r)
    {
        x0 = x0 + xR;        
        y0 = y0 + yR;
        xtemp = round(x0);        
        ytemp = round(y0);
        i++;
        aturPixel(xtemp,ytemp,0,0,0);    
    }    
    aturPixelAkhir(xA,yA,0,0,1);
}

void gambarTranslasi(void) {
    glClear(GL_COLOR_BUFFER_BIT);

    //glColor3f(0.0, 0.0, 0.0);
    glPointSize(2.0);    
    translasi(xAwal, yAwal, xEnd, yEnd);    
}

void gambarScalar(void) {
    glClear(GL_COLOR_BUFFER_BIT);

    //glColor3f(0.0, 0.0, 0.0);
    glPointSize(2.0);    
    scalar(xAwal, yAwal, xEnd, yEnd);    
}

void gambarRotation(void) {
    glClear(GL_COLOR_BUFFER_BIT);

    //glColor3f(0.0, 0.0, 0.0);
    glPointSize(2.0);            
    rotation(xAwal, yAwal, xEnd, yEnd,sudut);
}

void gambarBresenham (void)
{
    glClear(GL_COLOR_BUFFER_BIT);

    //glColor3f(0.0, 0.0, 0.0);
    glPointSize(2.0);            
    bresenham(xAwal, yAwal, xEnd, yEnd);
}

void gambarDDA (void)
{
    glClear(GL_COLOR_BUFFER_BIT);

    //glColor3f(0.0, 0.0, 0.0);
    glPointSize(2.0);            
    dda(xAwal, yAwal, xEnd, yEnd);
}

int main(int argc, char** argv) {
    int pilih;
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("Algoritma Garis dan Transformasi 2D");
    tampilan();

    printf("1.Translasi \n2.Scalar \n3.Rotation \n4.Bresenham \n5.DDA \nPilih salah satu dari rumus diatas :");
    scanf("%d", &pilih);
    switch(pilih) {
        case 1:
            printf("Masukkan koordinat titik awal (x0 y0): ");
            scanf("%f %f", &xAwal, &yAwal);    
            printf("Masukkan titik geser (x1 y1): ");
	        scanf("%f %f", &xEnd, &yEnd);
            glutDisplayFunc(gambarTranslasi);            
            glutMainLoop();
            break;
        case 2:
            printf("Masukkan koordinat titik awal (x0 y0): ");
            scanf("%f %f", &xAwal, &yAwal);    
            printf("Masukkan titik skala (sx sy): ");
	        scanf("%f %f", &xEnd, &yEnd);            
            glutDisplayFunc(gambarScalar);            
            glutMainLoop();
            break;
        case 3:
            printf("Masukkan koordinat titik awal (x0 y0): ");
            scanf("%f %f", &xAwal, &yAwal);
            printf("Masukkan titik pusat (xp yp): ");
            scanf("%f %f", &xEnd, &yEnd);
            printf("Masukkan besar sudut : ");
            scanf("%d", &sudut);
            glutDisplayFunc(gambarRotation);            
            glutMainLoop();
            break;
        case 4:
            printf("Masukkan koordinat titik awal (x0 y0): ");
            scanf("%f %f", &xAwal, &yAwal);
            printf("Masukkan titik akhir (x1 y1): ");
            scanf("%f %f", &xEnd, &yEnd);
            glutDisplayFunc(gambarBresenham);            
            glutMainLoop();
            break;
        case 5:
            printf("Masukkan koordinat titik awal (x0 y0): ");
            scanf("%f %f", &xAwal, &yAwal);
            printf("Masukkan titik akhir (x1 y1): ");
            scanf("%f %f", &xEnd, &yEnd);
            glutDisplayFunc(gambarDDA);            
            glutMainLoop();
            break;
        default:
            printf("Pilihan tidak valid.\n");
            return 1;
    }    
    return 0;
}
