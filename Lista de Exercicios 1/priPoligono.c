/**
* @file priPoligono.c
* @brief Esse código desenha uma primitiva do tipo polígono usando OpenGL e GLUT
* 
* @author George Araújo - george.ifrn@gmail.com .
* @since 10/09/2016
*/

#include <GL/glut.h>
#include <iostream>

/**Função inicializa propriedades do rendering.
 *
 */
void init(){
    
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glOrtho(0, 500, 0, 500, 2, -2);
    
}

/**Função callback display que desenha a primitiva na tela.
 */
void display(){
    
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 0.0, 0.0);
    glBegin(GL_POLYGON);
        glVertex2i(20, 30);
        glVertex2i(100, 30);
        glVertex2i(100,110);
        glVertex2i(60, 160);
        glVertex2i(20,110);
    glEnd();
    glFlush();
    
}

/**Função principal.
 * 
 */
int main(int argc, char** argv){
    
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500,500);
    glutInitWindowPosition(50,50);
    glutCreateWindow("Lista 1 - 1.a Poligono");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    
}