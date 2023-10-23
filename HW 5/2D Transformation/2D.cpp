#include <GL/glut.h>

float A[2] = {8.0, 2.0};
float B[2] = {8.0, 3.0};

void drawLine(float* p1, float* p2) {
   glBegin(GL_LINES);
   glVertex2fv(p1);
   glVertex2fv(p2);
   glEnd(); 
}

void display(void) {
    glClear(GL_COLOR_BUFFER_BIT); 
    glColor3f(1.0, 1.0, 1.0); 
    drawLine(A, B);

    //transformasi translasi
    glPushMatrix();
    glTranslatef(2.0, 2.0, 0.0);

    glColor3f(1.0, 0.0, 0.0);
    drawLine(A, B);

    glPopMatrix();

    glPushMatrix();
    glRotatef(90.0, 0.0, 0.0, 1.0);

    glColor3f(0.0, 1.0, 0.0);
    drawLine(A, B);

    glPopMatrix();

    glPushMatrix();
    glScalef(2.0, 2.0, 1.0);

    glColor3f(0.0, 0.0, 1.0);
    drawLine(A, B);

    glPopMatrix();
    glFlush(); 
}

void init() {
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, 16.0, 0.0, 12.0);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv); 
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); 
    glutInitWindowSize(800, 600);
    glutCreateWindow("Transformasi 2D"); 
    glutDisplayFunc(display);
    init(); 
    glutMainLoop(); 
    return 0;
}