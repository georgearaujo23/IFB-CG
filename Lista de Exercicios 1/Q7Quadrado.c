/**
 * @file Q7Quadrado.c
 * @brief Esse código desenha numa janela com fundo branco, de dimensões 256x256 pixels, um quadrado vermelho, com vértice superior esquerdo de coordenadas (x, y)= (30, 226) e vértice inferior direito de coordenadas (x, y) = (226, 30). Quando a tecla a for pressionada, o quadrado deverá ficar com a cor azul. Quando a tecla v for pressionada, o quadrado deverá voltar à cor vermelha.
 * @author George Araújo - george.ifrn@gmail.com
 * @since 25/09/2016
 */

#include <GL/glut.h>

float CorR = 1.0, /**< Variável guarda o valor da cor vermelha das primitivas*/
CorB = 0.0; /**< Variável guarda o valor da cor azul das primitivas*/

/**Função inicializa propriedades de rendering
 */
void init(){
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glOrtho(0.0, 256.0, 0.0, 256.0, -2.0, 2.0);
}

/**Função callBack display desenha as primitivas na tela
 */
void display(){
    glClear(GL_COLOR_BUFFER_BIT);
    
    glColor3f(CorR, 0.0, CorB);
    
    glBegin(GL_QUADS);
        glVertex2i(30, 226);
        glVertex2i(30, 30);
        glVertex2i(226, 30);
        glVertex2i(226,226);
    glEnd();
    
    glFlush();
    
}

/**Função callBack keyboard gerencia as entradas do teclado
 */
void keyboard(unsigned char key, int x, int y){
    
    switch(key){
        case 'a':
            CorB = 1.0;
            CorR = 0.0;
        break;
        case 'A':
            CorB = 1.0;
            CorR = 0.0;
        break;
        case 'v':
            CorB = 0.0;
            CorR = 1.0;
        break;
        case 'V':
            CorB = 0.0;
            CorR = 1.0;
        break;
    }
    
    glutPostRedisplay();
}

/**Função principal
 */
int main(int argc, char ** argv){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(256, 256);
    glutInitWindowPosition(150, 75);
    glutCreateWindow("Q7 Quadrado");
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    init();
    glutMainLoop();
    
    return 0;
}