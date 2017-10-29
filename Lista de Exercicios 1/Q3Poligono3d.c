/**
 * @file Q3Poligono3d.c
 * @brief Esse código desenha um polígono que imita um tijolo isométrico "2.5D"
 * 
 * @author George Araújo - george.ifrn@gmail.com
 * @since 11/09/2016
 */

#include <GL/glut.h>
#include <iostream>

/**Função inicializa propriedades do rendering
 */
void init(){
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glOrtho(0.0, 600.0, 0.0, 600.0, -2.0, 2.0);
}

/**Função callback display desenha das primitivas na tela.
 */
void display(){
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.75, 0.25, 1.0);
    
    glBegin(GL_POLYGON);
        glVertex2f(100.0, 130.0);
        glVertex2f(150.0, 100.0);
        glVertex2f(100.0, 70.0);
        glVertex2f(50.0, 100.0);
    glEnd();
    
    glColor3f(0.25, 0.25, 0.25);
    glBegin(GL_POLYGON);
        glVertex2f(50.0, 100.0);
        glVertex2f(100.0, 70.0);
        glVertex2f(100.0, 50.0);
        glVertex2f(50.0, 80.0);
    glEnd();
    
    glColor3f(0.25, 0.25, 0.25);
    glBegin(GL_POLYGON);
        glVertex2f(100.0, 70.0);
        glVertex2f(100.0, 50.0);
        glVertex2f(150.0, 80.0);
        glVertex2f(150.0, 100.0);
        
    glEnd();
    
    glFlush();
}

/**Função principal
 */
int main(int argc, char ** argv){
    
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(600, 600);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Tijolo isometrico");
    glutDisplayFunc(display);
    init();
    glutMainLoop();
    
    return 0;
}
