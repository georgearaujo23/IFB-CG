/**
* @file priCirculo.c
* @brief Esse código desenha um circulo a partir de primitivas do OpenGL.
* 
* @author George Araújo - george.ifrn@gmail.com .
* @since 10/09/2016
*/


#include <GL/glut.h>
#include <iostream>
#include <math.h>

float raio = 100.0 /**< Raio da circulo*/, 
origemX = 300.0 /**< Coordenada X do centro da circulo*/, 
origemY = 300.0 /**< Coordenada Y do centro da circulo*/, 
px = 0.0 /**< Coordenada X da primitiva que será desenhada*/, 
py = 0.0 /**< Coordenada Y da primitiva que será desenhada*/;

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
    glColor3f(0.0, 1.0, 0.0);
    glBegin(GL_LINE_STRIP);
        for(float i =0.0; i<10.0; i+=0.01){
            px= cos(i) * raio + origemX;
            py= sin(i) * raio + origemY;
            glVertex2f(px, py);
            glVertex2f(origemX, origemY);
        }
    glEnd();
    glFlush();
}

/**Função principal.
 * 
 */
int  main(int argc, char ** argv){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(600, 600);
    glutInitWindowPosition(100,100);
    glutCreateWindow("circulo");
    glutDisplayFunc(display);
    init();
    glutMainLoop();
    
    return 0;
}