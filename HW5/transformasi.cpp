#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <GL/glut.h>


float xAwal, yAwal, xEnd, yEnd;

void tampilan(void) {
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(-40, 60, -40, 60);
}

void aturPixel(GLint xCoordinate, GLint yCoordinate, GLfloat red, GLfloat green, GLfloat blue) {
    glColor3f(red, green,blue);
    glBegin(GL_POINTS);
    glVertex2i(xCoordinate, yCoordinate);
    glEnd();
    glFlush();
}

void aturPixelAkhir(GLint xCoordinate, GLint yCoordinate, GLfloat red, GLfloat green, GLfloat blue) {
    glColor3f(red, green,blue);
    glBegin(GL_POINTS);
    glVertex2i(xCoordinate, yCoordinate);
    glEnd();
    glFlush();
}

void aturPixelAwal(GLint xCoordinate, GLint yCoordinate, GLfloat red, GLfloat green, GLfloat blue) {
    glColor3f(red, green,blue);
    glBegin(GL_POINTS);
    glVertex2i(xCoordinate, yCoordinate);
    glEnd();
    glFlush();
}

void translasi (GLint x0, GLint y0, GLint x1, GLint y1)
{
    aturPixelAwal(x0, y0, 0, 1,0);
    GLint xAkhir = x0 + x1;
    GLint yAkhir = y0 + y1;
    GLint xtemp= x0;
    GLint ytemp= y0;
    while (xtemp < xAkhir || ytemp < yAkhir) {
        if (xtemp < xAkhir)
        {
            xtemp++;
        }else if (ytemp < yAkhir) {
            ytemp++;
        }
        aturPixel(xtemp, ytemp, 1, 0, 0);
    }
    aturPixelAkhir(xAkhir, yAkhir, 0, 0, 0);
}

void scalar (GLint x0, GLint y0, GLint sx, GLint sy)
{
    aturPixelAwal(x0, y0, 0, 1,0);
    GLint xAkhir = x0 * sx;
    GLint yAkhir = y0 * sy;
    GLint xtemp= x0;
    GLint ytemp= y0;
    while (xtemp < xAkhir || ytemp < yAkhir) {
        if (xtemp < xAkhir)
        {
            xtemp++;
        }else if (ytemp < yAkhir) {
            ytemp++;
        }
        aturPixel(xtemp, ytemp, 1, 0,0);
    }
    aturPixelAkhir(xAkhir, yAkhir, 0 ,0,0);
}

void rotation (GLint x0, GLint y0, GLint xp, GLint yp)
{
    aturPixelAwal(x0, y0, 0, 1,0);
    GLint x1,y1;
    GLint xAkhir;
    GLint yAkhir;
    x1 =  1 * -xp;
    y1 =  1 * -yp;
    GLint a,b,c,d;
    a = 0;
    b = -1;
    c = 1;
    d = 0;
    GLint xpatok = x0 -  xp;
    GLint ypatok = y0 - yp;
    GLint x2 = (a*xpatok) + (c * xpatok);
    GLint y2 = (b*ypatok) + (d * ypatok);

    if (x1 < 0)
    {
        xAkhir = x2 + x1;
    }else if (x1 > 0)
    {
        xAkhir = x2 - x1;
    }
    if (y1 < 0)
    {
        yAkhir = y2 + y1;
    }else if (y1 > 0)
    {
        yAkhir = y2 - y1;
    }

    GLint xtemp = x0;
    GLint ytemp = y0;
    
    while (xtemp < xAkhir || ytemp < yAkhir) {
        if (xtemp < xAkhir)
        {
            xtemp++;
        }else if (ytemp < yAkhir) {
            ytemp++;
        }
        aturPixel(xtemp, ytemp , 1, 0, 0);
    }
    
    while (xtemp > xAkhir || ytemp > yAkhir) {
        if (xtemp > xAkhir)
        {
            xtemp--;
        }else if (ytemp > yAkhir) {
            ytemp--;
        }
        aturPixel(xtemp,  ytemp , 1, 0, 0);
    }    
    aturPixelAkhir(xAkhir, yAkhir, 0 ,0,0);
}

void gambarTranslasi(void) {
    glClear(GL_COLOR_BUFFER_BIT);
    glPointSize(2.0);    
    translasi(xAwal, yAwal, xEnd, yEnd);    
}

void gambarScalar(void) {
    glClear(GL_COLOR_BUFFER_BIT);
    glPointSize(2.0);    
    scalar(xAwal, yAwal, xEnd, yEnd);    
}

void gambarRotation(void) {
    glClear(GL_COLOR_BUFFER_BIT);
    glPointSize(2.0);            
    rotation(xAwal, yAwal, xEnd, yEnd);
}

int main(int argc, char** argv) {
    int pilih;
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("Transformasi 2d");
    tampilan();

    printf("1.Translasi \n2.Scalar \n3.Rotation \nPilih salah satu dari rumus diatas :");
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
            glutDisplayFunc(gambarRotation);            
            glutMainLoop();
            break;
        default:
            printf("Pilihan tidak valid.\n");
            return 1;
    }    
    return 0;
}