#include <windows.h>
#include <stdio.h>
#include <GL/glut.h>
#include <GL/glu.h>
#include <iostream>
#include <iomanip>
using namespace std;

int round(float n) {
    if (n - (int)n < 0.5)
        return (int)n;
    return (int)(n + 1);
}

void DDA(int x0, int y0, int xn, int yn) {
    int dx = xn - x0;
    int dy = yn - y0;

    int step;

    if (abs(dx) > abs(dy))
        step = abs(dx);
    else
        step = abs(dy);

    glPointSize(2.0);  // Atur ukuran titik

    glBegin(GL_POINTS);  // Mulai menggambar titik
    glColor3f(1.0, 1.0, 1.0);  // Warna titik (putih)

    float x = x0;
    float y = y0;
    float x_incr = (float)dx / step;
    float y_incr = (float)dy / step;

    for (int i = 0; i <= step; i++) {
        int roundedX = round(x);
        int roundedY = round(y);
        glVertex2i(roundedX, roundedY);
        x += x_incr;
        y += y_incr;
    }

    glEnd();  // Selesai menggambar titik
    glFlush();  // Memastikan titik tergambar
}

void display() {
    glClearColor(0.0, 0.0, 0.0, 0.0);  // Warna latar belakang (hitam)
    glClear(GL_COLOR_BUFFER_BIT);

    // Panggil fungsi DDA untuk menggambar garis antara A(2, 8) dan B(4, 10)
    DDA(2, 8, 4, 10);

    glFlush();
}

void reshape(int w, int h) {
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, w, 0, h);
    glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(100, 100);
    glutCreateWindow("DDA Line Drawing Algorithm");
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutMainLoop();
    return 0;
}
