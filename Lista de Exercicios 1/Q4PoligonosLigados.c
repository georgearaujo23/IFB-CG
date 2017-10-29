/**
 * @file Q4PoligonosLigados.c
 * @brief Esse código desenha um conjunto de polígonos com arestas “ligadas”.
 * 
 * @author George Araújo - george.ifrn@gmail.com
 * @since 12/09/2016
 */

#include <GL/glut.h>
#include <iostream>

/**Função inicializa propriedades do rendering
 */
void init(){
    glClearColor(1.0, 1.0, 1.0, 0.0);
    glOrtho(0.0, 600.0, 0.0, 600.0, -2.0, 2.0);
}

/**Função auxiliar da display, desenha os tijolos 2.5D
 */
void poligonos(float x, float y,float width, float height, float r, float g, float b){
    glColor3f(r,g,b);
    
    glBegin(GL_POLYGON);
        glVertex2f(x, y);
        glVertex2f(x + width, y + (width/2));
        glVertex2f(x + 2*width, y);
        glVertex2f(x + width, y - (width/2));
    glEnd();
    
    glColor3f(r/2,g/2,b/2);
    
    glBegin(GL_POLYGON);
        glVertex2f(x, y);
        glVertex2f(x + width, y - (width/2));
        glVertex2f(x + width, y - (width/2) -height);
        glVertex2f(x, y -height);
    glEnd();
    
    glBegin(GL_POLYGON);
        glVertex2f(x + 2*width, y);
        glVertex2f(x + width, y - (width/2));
        glVertex2f(x + width, y - (width/2) -height);
        glVertex2f(x + 2*width, y -height);
    glEnd();
    
    glColor3f(0.0,0.0,0.0);
    glBegin(GL_LINE_LOOP);
        glVertex2f(x, y);
        glVertex2f(x + width, y + (width/2));
        glVertex2f(x + 2*width, y);
        glVertex2f(x + width, y - (width/2));
    glEnd();
    
}

/**Função callback display desenha as primitividas na tela
 */
void display(){
    glClear(GL_COLOR_BUFFER_BIT);
    
    poligonos(300, 300, 50, 15.0, 0.8, 0.8, 0.8);
    poligonos(250, 275, 50, 15.0, 0.8, 0.8, 0.8);
    poligonos(300, 235, 50, 15.0, 0.2, 0.2, 0.2);
    poligonos(250, 210, 50, 15.0, 0.2, 0.2, 0.2);
    poligonos(200, 250, 50, 15.0, 0.8, 0.8, 0.8);
    poligonos(150, 225, 50, 15.0, 0.8, 0.8, 0.8);
    poligonos(300, 185, 50, 15.0, 0.2, 0.2, 0.2);
    poligonos(200, 200, 50, 15.0, 0.8, 0.8, 0.8);
    poligonos(250, 175, 50, 15.0, 0.8, 0.8, 0.8);
    poligonos(350, 275, 50, 15.0, 0.8, 0.8, 0.8);
    poligonos(400, 250, 50, 15.0, 0.8, 0.8, 0.8);
    poligonos(450, 225, 50, 15.0, 0.8, 0.8, 0.8);
    poligonos(350, 225, 50, 15.0, 0.0, 0.7, 0.9);
    poligonos(400, 200, 50, 15.0, 0.8, 0.8, 0.8);
    poligonos(350, 175, 50, 15.0, 0.8, 0.8, 0.8);
    poligonos(300, 150, 50, 15.0, 0.8, 0.8, 0.8);
    
    
    
    glFlush();
}

/**Função principal
 */
int main(int argc, char ** argv){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(600, 600);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Poligonos ligados");
    glutDisplayFunc(display);
    init();
    
    glutMainLoop();
    
    return 0;
}