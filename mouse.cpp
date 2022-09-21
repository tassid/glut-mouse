#include <GL/gl.h>
#include <GL/glut.h>

int movex = 0, int movey = 0;

void ponto(){
    glPointSize(20);
    glBegin(GL_POINTS);
        glColor 3f(0,1,0);
        glVertex2f(movex,movey);
    glEnd();
}

void desenhaObjetos(void){
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0,800,600,0);
    glMatrixMode(GL_MODELVIEW):
    glLoadIdentity();

    glPushMatrix();
        ponto();
    glPopMatrix();

    glut SwapBuffers();
}

int main(void){
    glutInitDisplayMode(GLUT DOUBLE | GLUT_RGB);
    glutInitWindowSize(800,600);
    glutInitWindowPosition(320,150);
    glutCreateWindow("Função Mouse - Interacão");
    glutDisplayFunc(desenhaObjetos):
    glutMouseFunc(gerenciaMouse);
    glClearColor(1,1,1,0);
    glutMainLoop();
return 0;
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

