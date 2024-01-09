#include <iostream>
#include <cmath>
#include <GL/glut.h>

// Window size
const int maxWD = 640;
const int maxHT = 480;

// Rotation speed
const double thetaSpeed = 0.05;

// Function prototypes
void myInit(void);
void drawPoint(int x, int y);
void rotateAroundPt(int px, int py, int cx, int cy, double theta);
void translatePoint(int px, int py, int tx, int ty);
void scalePoint(int px, int py, int sx, int sy);
void myDisplay(void);

// Main function
int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(maxWD, maxHT);
    glutInitWindowPosition(100, 150);
    glutCreateWindow("Transforming point");
    glutDisplayFunc(myDisplay);
    myInit();
    glutMainLoop();
    return 0;
}

// Initialization function
void myInit(void) {
    glClearColor(1.0, 1.0, 1.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, maxWD, 0.0, maxHT);
    glClear(GL_COLOR_BUFFER_BIT);
    glFlush();
}

// Function to draw a point
void drawPoint(int x, int y) {
    glPointSize(7.0);
    glColor3f(0.0f, 0.0f, 1.0f);
    glBegin(GL_POINTS);
    glVertex2i(x, y);
    glEnd();
}

// Function to rotate a point around another point
void rotateAroundPt(int px, int py, int cx, int cy, double theta) {
    int xf, yf;
    while (true) {
        glClear(GL_COLOR_BUFFER_BIT);

        // Update theta
        theta += thetaSpeed;
        if (theta >= 2 * M_PI) {
            theta -= 2 * M_PI;
        }

        // Calculate rotated coordinates
        xf = cx + int((px - cx) * cos(theta) - (py - cy) * sin(theta));
        yf = cy + int((px - cx) * sin(theta) + (py - cy) * cos(theta));

        drawPoint(cx, cy);  // Draw the center point
        drawPoint(xf, yf);  // Draw the rotating point
        glFlush();
        glutPostRedisplay();  // Use glutPostRedisplay instead of delay
    }
}

// Function to translate a point
void translatePoint(int px, int py, int tx, int ty) {
    int fx = px, fy = py;
    while (true) {
        glClear(GL_COLOR_BUFFER_BIT);

        // Update coordinates
        px += tx;
        py += ty;

        // Check overflow
        if (px > maxWD || px < 0 || py > maxHT || py < 0) {
            px = fx;
            py = fy;
        }

        drawPoint(px, py);
        glFlush();
        glutPostRedisplay();  // Use glutPostRedisplay instead of delay
    }
}

// Function to scale a point
void scalePoint(int px, int py, int sx, int sy) {
    int fx, fy;
    while (true) {
        glClear(GL_COLOR_BUFFER_BIT);

        // Update coordinates
        fx = px * sx;
        fy = py * sy;

        drawPoint(fx, fy);
        glFlush();
        glutPostRedisplay();  // Use glutPostRedisplay instead of delay

       // delay(500);  // Keep the delay for scaling animation
 }
}

// Actual display function
void myDisplay(void) {
    int opt;
    int x, y, dx, dy, sx, sy;

    printf("\nEnter\n\t for translation\n\t for rotation\n\t for scaling\n\t:");
    scanf("%d", &opt);

    switch (opt) {
        case 1:
            printf("\nEnter x-coordinate of initial point: ");
            scanf("%d", &x);
            printf("\nEnter y-coordinate of initial point: ");
            scanf("%d", &y);
            printf("\nEnter x-coordinate of translation: ");
            scanf("%d", &dx);
            printf("\nEnter y-coordinate of translation: ");
            scanf("%d", &dy);
            translatePoint(x, y, dx, dy);
            printf("\nGo to the window...");
            break;
        case 2:
            printf("\nEnter x-coordinate of initial point: ");
            scanf("%d", &x);
            printf("\nEnter y-coordinate of initial point: ");
            scanf("%d", &y);
            printf("\nEnter angle of rotation (in degrees): ");
            scanf("%d", &sx);
            sx = sx * M_PI / 180;  // Convert to radians
            rotateAroundPt(x, y, x, y, sx);  // Rotate around itself
            printf("\nGo to the window...");
            break;
        case 3:
            printf("\nEnter x-coordinate of initial point: ");
            scanf("%d", &x);
            printf("\nEnter y-coordinate of initial point: ");
            scanf("%d", &y);
            printf("\nEnter x-coordinate of scaling: ");
            scanf("%d", &sx);
            printf("\nEnter y-coordinate of scaling: ");
            scanf("%d", &sy);
            printf("\nGo to the window...");
            scalePoint(x, y, sx, sy);
            break;
    }
}