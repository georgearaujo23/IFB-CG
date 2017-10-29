/**
 * @brief Este primeiro trabalho de Computação Gráfica consiste em desenvolver um programa
que implemente as Transformações Geométricas 2D vistas em sala de aula.
 * @file trabalho1.c
 * @author George Araújo - george.ifrn@gmail.com
 * @since 12/10/2016
 */

#include <GL/glut.h>

int comando = 0 /**<< Define qual comando deve ser executado com as teclas direcionais. (1. Translação | 2. Rotação | 3. Escala)*/;
GLint transX = 0, /**<< Define o tamanho da translação no eixo X*/
transY = 0, /**<< Define o tamanho da translação no eixo Y*/
anguloZ, /**<< Define o ângulo de rotação no eixo Z*/
anguloY = 0; /**<< Define o ângulo de rotação no eixo Y (espelhamento)*/
GLfloat zoom = 1.0, /**<< Define a escala do objeto*/
h =100.0, /**<< Define a altura inicial do polígono*/
l = 120.0; /**<< Define a lagura inicial do polígono*/

/**Função inicializa as propriedades de rendering do OpenGL
 */
void init()
{
    glClearColor(0.5, 0.5, 0.5, 1.0);
    gluOrtho2D(-300, 300, -300, 300);
}

/**Função callback para tratamento de entrada pelas teclas especiais do teclado.
 * 
 */
void tecladoEventoTeclasEspeciais (int tecla, int x, int y)  
{
    switch (tecla)
    {
        case GLUT_KEY_LEFT:
            if(comando == 1)
            {
                transX -= 2;

            }
            break;
        case GLUT_KEY_RIGHT:
            if(comando == 1)
            {
                transX += 2;

            }
            break;
        case GLUT_KEY_UP:	
            if(comando == 1)
            {
                transY += 2;
                
            }else if (comando == 2)
            {
                anguloZ += 3;
            }else if(comando == 3)
            {
                zoom += 0.1;
            }

            break;
        case GLUT_KEY_DOWN:	
            if(comando == 1)
            {
                transY -= 2;
                
            }else if (comando == 2)
            {
                anguloZ -= 3;
            }else if(comando == 3)
            {
                zoom -= 0.1;
            }

            break;
    }
	
    glutPostRedisplay();
}

/**Função callback para tratamento de entrada pelo teclado.
 * O usuário deve teclar uma das seguintes teclas para definir o comando que será executado (selecionar o tipo de transformação).
 * (T - Translação | R - Rotação | S - Escala | M - Espelhar objeto | I - Retornar o objeto para a configuração inicial)
 */
void tecladoEventoTeclas(unsigned char key, int x, int y)
{
    switch(key)
    {
        case 't':
            comando = 1;
            break;
        case 'T':
            comando = 1;
            break;
        case 'r':
            comando = 2;
            break;
        case 'R':
            comando = 2;
            break;
        case 's':
            comando = 3;
            break;
        case 'S':
            comando = 3;
            break;
        case 'm':
            if(anguloY == 0)
            {
                anguloY = 180;
            }else{
                anguloY = 0;
            }
            
            break;
        case 'M':
            if(anguloY == 0)
            {
                anguloY = 180;
            }else{
                anguloY = 0;
            }
            break;
        case 'i':
            transX = 0;
            transY = 0;
            anguloZ = 0;
            anguloY = 0;
            zoom = 1.0;
            break;
        case 'I':
            transX = 0;
            transY = 0;
            anguloZ = 0;
            anguloY = 0;
            zoom = 1.0;
            break;
    }
    
    glutPostRedisplay();
    
}

/**Função callback que desenha as primitivas do OpenGL
 */    
void desenha(){
    
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(1.0, 0.0, 0.0);
    glBegin(GL_LINES);
        glVertex2i(-300, 0);
        glVertex2i(300, 0);
    glEnd();
    
    glBegin(GL_LINES);
        glVertex2i(9, -300);
        glVertex2i(0, 300);
    glEnd();
    
    
    glColor3f(1.0, 1.0, 0.0);
    
    glPushMatrix();
        
        glTranslatef(transX, transY, 0);
        
        glTranslatef(l/2, (h/2), 0);
            
            glScalef(zoom, zoom, zoom);
            glRotatef(anguloZ, 0, 0, 1);    
            glRotatef(anguloY, 0, 1, 0);
        
        glTranslatef(-( (l/2)), -((h/2)), 0);
        
        
        
        glBegin(GL_POLYGON);
            
            glVertex2f(60.0f,0.0f); 
            
            glColor3f(0.0, 0.0, 1.0);
            glVertex2f(0.0f,0.0f); 
            glColor3f(0.0, 0.0, 1.0);
            glVertex2f(0.0f,100.0f);
            glVertex2f(20.0f,100.0f);
            glVertex2f(20.0f,60.0f);
            glColor3f(1.0, 1.0, 0.0);
            
            glVertex2f(40.0f,60.0f);
            glVertex2f(60.0f,100.0f);
            glVertex2f(80.0f,60.0f);
            
            glColor3f(1.0, 0.0, 0.0);
            glVertex2f(100.0f,60.0f);
            glVertex2f(100.0f,100.0f);
            glVertex2f(120.0f,100.0f);
            glVertex2f(120.0f,0.0f);
            glColor3f(1.0, 1.0, 0.0);
            
        glEnd();
        
    glPopMatrix();
    
    glutSwapBuffers();

}

/**Função principal
 */
int main(int argc, char** argv){
    
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(600, 600);
    glutInitWindowPosition(300, 150);
    glutCreateWindow("Trabalho 1");
    
    init();
    glutDisplayFunc(desenha);
    glutKeyboardFunc(tecladoEventoTeclas);
    glutSpecialFunc(tecladoEventoTeclasEspeciais);
    
    glutMainLoop();
    
    return 1;
}
