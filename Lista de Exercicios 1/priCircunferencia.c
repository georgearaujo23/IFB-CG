/**
* @file priCircunferencia.c
* @brief Esse código desenha uma circunferência a partir de primitivas do OpenGL.
* 
* @author George Araújo - george.ifrn@gmail.com .
* @since 10/09/2016
*/

#include <GL/glut.h>
#include <iostream>
#include <math.h>

float raio = 40.0 /**< Raio da cincunferência*/, 
origemx = 300.0 /**< Coordenada X do centro da Circunferencia*/, 
origemy = 300.0 /**< Coordenada Y do centro da Circunferencia*/, 
pontox = 0.0 /**< Coordenada X da primitiva que será desenhada*/, 
pontoy = 0.0 /**< Coordenada Y da primitiva que será desenhada*/;

/**Função inicializa propriedades do rendering.
 *
 */
void init(){
    glClearColor(0.0, 0.0, 0.0, 1.0);
    glOrtho(0, 600, 0, 600, 2, -2);
}

/**Função callback display que desenha a primitiva na tela.
 */
void display(){
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.0, 0.0, 1.0);
    glBegin(GL_LINE_STRIP);
        for(float i = 0.0; i<10.0; i+=0.01){
            pontox = cos(i)*raio + origemx;
            pontoy = sin(i)*raio + origemy;
            glVertex2f(pontox, pontoy);
        }
    glEnd();
    glFlush();
} 

/**Função principal.
 * 
 */
int main(int argc, char** argv){
    
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(600, 600);
    glutInitWindowPosition(50,50);
    glutCreateWindow("Circunferencia");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    
    return 0;
}