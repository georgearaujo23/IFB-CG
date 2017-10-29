/**
 * @file Q2Poligono.c
 * @brief Esse código Desenha um polígono que imita um tijolo isométrico
 * 
 * @author George Araújo - george.ifrn@gmail.com
 * @since 11/09/2016
 */

#include <GL/glut.h>
#include <iostream>

/**Função inicializa as propriedades do rendering
 */
void init(){
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glOrtho(0.0, 400.0, 0.0, 400.0, -2.0, 2.0 );
}

/**Função callback display desenha a primitiva na tela
 */
void display(){
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.0, 1.0, 1.0);
    
    glBegin(GL_POLYGON);
        glVertex2f(50.0, 100.0);
        glVertex2f(100.0, 130.0);
        glVertex2f(150.0, 100.0);
        glVertex2f(100.0, 70.0);
    
    glEnd();
    
    glFlush();
}

/**Função Principal
 */
int main(int argc, char ** argv){
    
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(400, 400);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Tijolo isometrico");
    glutDisplayFunc(display);
    init();
    glutMainLoop();
    
    return 0;
}