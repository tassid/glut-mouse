#include <GL/gl.h>
#include <GL/glut.h>

int movex = 0, movey = 0;

void ponto(){
    glPointSize(20);
    glBegin(GL_POINTS);
        glColor3f(0,1,0);
        glVertex2f(movex,movey);
    glEnd();
}

void desenhaObjetos(void){
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0,800,600,0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glPushMatrix();
        ponto();
    glPopMatrix();

glutSwapBuffers();
}

void movimentaMouse (int x, int y){
    movex = x;
    movey = y;
    glutPostRedisplay();
}


void gerenciaMouse (int botao, int estado, int x, int y){
    if (botao == GLUT_LEFT_BUTTON)
    if (estado == GLUT_DOWN){
            glutMotionFunc(movimentaMouse);
    }
}

int main(void){
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(800,600);
    glutInitWindowPosition(320,150);
        glutCreateWindow("Funcao Mouse - Interacao");
    glutDisplayFunc(desenhaObjetos);
    glutMouseFunc(gerenciaMouse);
    glClearColor(1,1,1,0);
    glutMainLoop();
return 0;
}
