/**
* @file priElipse.c
* @brief Esse código desenha uma elipse a partir de primitivas do OpenGL.
* 
* @author George Araújo - george.ifrn@gmail.com .
* @since 10/09/2016
*/

#include <GL/glut.h>
#include <iostream>
#include <math.h>

float raiox = 100.0 /**< Coordenada X do Raio da elipse*/,
raioy = 50.0 /**< Coordenada Y do Raio da circulo*/, 
origemX = 300.0 /**< Coordenada X do centro da elipse*/,  
origemY = 300.0 /**< Coordenada Y do centro da elipse*/, 
px = 0.0 /**< Coordenada X da primitiva que será desenhada*/,  
py = 0.0 /**< Coordenada Y da primitiva que será desenhada*/;

/**Função inicializa propriedades do rendering.
 *
 */
void init(void){
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glOrtho(0.0, 600.0, 0.0, 600.0, -2.0, 2.0);
}

/**Função callback display que desenha as primitivas na tela.
 */
void display(){
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 1.0, 0.0);
    
    glBegin(GL_LINE_STRIP);
        
        for(float i = 0.0; i<10.0; i+=0.01){
            px = cos(i) * raiox + origemX;
            py = sin(i) * raioy + origemY;
            glVertex2f(px, py);
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
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Elipse");
    glutDisplayFunc(display);
    init();
    glutMainLoop();
    
    return 0;
}