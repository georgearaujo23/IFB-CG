/**
 * @file Q5Quadrados.c
 * @brief esse código desenha numa janela com fundo branco, de dimensões 256x256 pixels, quatro quadrados de cores diferentes arranjados na janela.
 * @author George Araújo - george.ifrn@gmail.com
 * @since 23/09/2016
 */

#include <GL/glut.h>
#include <iostream>

/**
 * Função inicializa parâmetros de rendering
 */
void init(){
    glClearColor(1.0,  1.0, 1.0, 1.0);
    glOrtho(0.0, 256.0, 0.0, 256.0, -2.0, 2.0);
}

/**Função callback display desenha as primitivas na tela
 */
void display(){
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(1.0, 0.0, 0.0);
    glBegin(GL_QUADS);
            glVertex2i(0, 0);
            glVertex2i(0, 50);
            glVertex2i(50, 50);
            glVertex2i(50, 0);
    glEnd();

    glColor3f(0.0, 1.0, 0.0);
    glBegin(GL_QUADS);
            glVertex2i(250,250);
            glVertex2i(250,200);
            glVertex2i(200,200);
            glVertex2i(200, 250);
    glEnd();

    glColor3f(0.0, 0.0, 1.0);
    glBegin(GL_QUADS);
            glVertex2i(250, 0);
            glVertex2i(250, 50);
            glVertex2i(200, 50);
            glVertex2i(200, 0);
    glEnd();

    glColor3f(1.0, 0.5, 0.5);
    glBegin(GL_QUADS);
            glVertex2i(0, 250);
            glVertex2i(0, 200);
            glVertex2i(50, 200);
            glVertex2i(50, 250);
    glEnd();

    glFlush();

}

/**Função principal
 */
int main(int argc, char ** argv){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(256, 256);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Quadrados");
    glutDisplayFunc(display);
    init();
    glutMainLoop();
	
    return 0;
    
}
