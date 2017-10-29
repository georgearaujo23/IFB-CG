/**
 * @file priArcoPreenchido.c
 * @brief Esse código desenha um arco, com as extremidades ligadas e preenchido, a partir de primitivas OpenGL
 * 
 * @author George Araújo - george.ifrn@gmail.com
 * @since 11/09/2016
 */



#include <GL/glut.h>
#include <iostream>
#include <math.h>

float raio = 100.0, /**< Raio do arco*/
origemx = 300.0, /**< Coordenada X do centro do arco*/
origemy = 300.0, /**< Coordenada Y do centro do arco*/
px = 0.0, /**< Coordenada X da primitiva*/
py = 0.0; /**< Coordenada Y da primitiva*/

/**Função inicializa as propriedades do rendering
 */
void init(){
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glOrtho(0.0, 600.0, 0.0, 600.0, -2.0, 2.0);
}

/**Função callback display desenha as primitivas na tela
 */
void display(){
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 0.0, 1.0);
    
    glBegin(GL_LINE_STRIP);
        for(float i = 0.0; i<=1.25; i+=0.01){
            px = cos(i) * raio + origemx;
            py = sin(i) * raio + origemy;
            glVertex2f(px, py);
            px = cos(2.5 -i) * raio + origemx;
            py = sin(2.5 -i) * raio + origemy;
            glVertex2f(px, py);
            
        }
    glEnd();
    
    glFlush();
}

/**Função principal
 */
int main(int argc, char** argv){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(600, 600);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Arco preenchido");
    glutDisplayFunc(display);
    init();
    
    glutMainLoop();
}