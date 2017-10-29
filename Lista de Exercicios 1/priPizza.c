/**
 * @file priPizza.c
 * @brief Esse código desenha uma fatia de pizza a partir de primitivas do OpenGL.
 * 
 * @author George Araújo - george.ifrn@gmail.com
 * @since 11/09/2016
 */

#include <GL/glut.h>
#include <iostream>
#include <math.h>

float raio = 100.0, /**< Raio da pizza*/
origemx = 300.0, /**< Coordenada X do centro da pizza*/
origemy = 300.0, /**< Coordenada Y do centro da pizza*/
px = 0.0, /**< Coordenada X da primitiva*/
py = 0.0; /**< Coordenada Y da primitiva*/

/**Função inicializa as propriedades do rendering
 */
void init(){
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glOrtho(0.0, 600.0, 0.0, 600.0, -2.0, 2.0);
}

/** Função callback display desenha aas primitivas na tela
 */
void display(){
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 1.0, 1.0);
    
    glBegin(GL_LINE_STRIP);
        for(float i = 0.0; i<1.0; i+=0.01){
            px = cos(i) * raio + origemx;
            py = sin(i) * raio + origemy;
            glVertex2f(px, py);
            glVertex2f(origemx, origemy);
        }
        
    glEnd();
    
    glFlush();
}

/**Função Principal
 */
int main(int argc, char** argv){
    
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(600, 600);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Fatia de pizza");
    glutDisplayFunc(display);
    init();
    
    glutMainLoop();
    
    return 0;
}