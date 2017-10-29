/**
 * @file Q6QuadradoColor.c
 * @brief Esse código desenha numa janela com fundo branco, de dimensões 256x256 pixels, 4 quadrados com as mesmas dimensões mas cores distintas. Implemente um temporizador para os valores de RGB mudarem com o tempo para os quadrados, produzindo uma pequena animação.
 * @author George Araújo - george.ifrn@gmail.com
 * @since 23/09/2016
 */
#include <GL/glut.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int refreshMills = 100;/**< Variável que define o intervalor de tempo que as cores mudaram*/
float colorR = 1.0,/** < Valor calculado da cor vermelha*/ 
colorG = 1.0, /** < Valor calculado da cor Verde*/ 
colorB = 1.0;/** < Valor calculado da cor azul*/ 

/**Função inicializa as propriedades de rendering
 */
void init(){
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glOrtho(0.0, 256.0, 0.0, 256.0, -2.0, 2.0);
}

/**Função callBack Timer controla a atualização da janela
 */
void timer(int value){
    srand(time(NULL)); 
    colorR = ((float)(random())/(float)(RAND_MAX));
    colorG = ((float)(random())/(float)(RAND_MAX));
    colorB = ((float)(random())/(float)(RAND_MAX));
    glutPostRedisplay();
    glutTimerFunc(refreshMills, timer, 0);
}

/**Função callBack display desenha as primitivas na tela
 */
void display(){
    glClear(GL_COLOR_BUFFER_BIT);
	
    glColor3f(colorR, 0.0, colorB);
    glBegin(GL_QUADS);
            glVertex2i(0, 0);
            glVertex2i(0, 50);
            glVertex2i(50, 50);
            glVertex2i(50, 0);
    glEnd();

    glColor3f(colorR, colorG, 0.0);
    glBegin(GL_QUADS);
            glVertex2i(250,250);
            glVertex2i(250,200);
            glVertex2i(200,200);
            glVertex2i(200, 250);
    glEnd();

    glColor3f(0.0, colorG, colorB);
    glBegin(GL_QUADS);
            glVertex2i(250, 0);
            glVertex2i(250, 50);
            glVertex2i(200, 50);
            glVertex2i(200, 0);
    glEnd();

    glColor3f(colorR, colorG, colorB);
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
int main(int argc, char** argv){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(256, 256);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Quadrado colorido");
    glutDisplayFunc(display);
    glutTimerFunc(0, timer, 0); 
    init();

    glutMainLoop();
    return 0;
}
