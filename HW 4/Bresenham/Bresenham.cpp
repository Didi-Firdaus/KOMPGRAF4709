#include <GL/glut.h>
#include <math.h>

void drawLine(int x1, int y1, int x2, int y2);

void init(void) {
    glClearColor(0.0, 0.0, 0.0, 0.0); 
    glMatrixMode(GL_PROJECTION); 
    gluOrtho2D(0.0, 10.0, 0.0, 10.0); 
}

void display(void) {
    glClear(GL_COLOR_BUFFER_BIT); 
    glColor3f(1.0, 1.0, 1.0); 
    drawLine(3, 8, 2, 8);
    glFlush(); 
}

void drawLine(int x1, int y1, int x2, int y2) {
    int dx = abs(x2 - x1); 
    int dy = abs(y2 - y1); 
    int p = 2 * dy - dx; 
    int twoDy = 2 * dy; 
    int twoDyDx = 2 * (dy - dx); 
    int x, y; 

    
    if (x1 > x2) {
        x = x2;
        y = y2;
        x2 = x1;
    } else {
        x = x1;
        y = y1;
    }

    glBegin(GL_POINTS); 
    glVertex2i(x, y); 

    while (x < x2) { 
        x++; 
        if (p < 0) { 
            p += twoDy; 
        } else { 
            y++; 
            p += twoDyDx; 
        }
        glVertex2i(x, y); 
    }

    glEnd(); 
}

int main(int argc, char** argv) {
    glutInit(&argc, argv); 
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowPosition(100, 100); 
    glutInitWindowSize(500, 500);
    glutCreateWindow("Bresenham Algorithm"); 
    init(); 
    glutDisplayFunc(display);
    glutMainLoop(); 
}