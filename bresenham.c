#include <GL/glut.h>
#include <stdlib.h>

void display()
{
    int x1 = 100, y1 = 100;
    int x2 = 400, y2 = 250;

    int dx = x2 - x1;
    int dy = y2 - y1;

    int p = 2 * dy - dx;

    int x = x1;
    int y = y1;

    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(1.0, 0.0, 0.0);
    glPointSize(5.0);

    glBegin(GL_POINTS);

    while (x <= x2)
    {
        glVertex2i(x, y);

        x++;

        if (p < 0)
        {
            p = p + 2 * dy;
        }
        else
        {
            y++;
            p = p + 2 * dy - 2 * dx;
        }
    }

    glEnd();
    glFlush();
}

void init()
{
    glClearColor(1.0, 1.0, 1.0, 1.0);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    gluOrtho2D(0, 500, 0, 500);
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);

    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);

    glutCreateWindow("Bresenham Line Drawing Algorithm");

    init();

    glutDisplayFunc(display);

    glutMainLoop();

    return 0;
}
