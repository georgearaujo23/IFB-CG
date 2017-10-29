/**
 * @file Q8Selecao.c
 * @brief Esse código, utilizando o programa preenchimento.c (dado em sala de aula) como referência, desenha numa janela com fundo branco, de dimensões 256x256 pixels, quatro polígonos com as mesmas coordenadas dos polígonos do programa de referência. Todos os polígonos devem estar inicialmente preenchidos de amarelo e com bordas pretas. Quando o usuário clicar com o botão esquerdo do mouse dentro de um dos polígonos, a cor de preechimento deste polígono deverá mudar para uma cor aleatória. Quando a tecla b for pressionada, o programa passará a mudar as cores das bordas e não mais dos fundos dos polígonos. Quando a tecla f for pressionada, o programa passará a mudar as cores dos fundos dos polígonos e não mais das bordas.
 * @author George Araújo - george.ifrn@gmail.com
 * @since 25/09/2016
 */
#include <GL/glut.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

GLfloat r1 = 1.0 , /**< Cor vermelha do poligono 1 */ 
        g1 = 1.0 , /**< Cor verde do poligono 1*/
        b1 = 0.0, /**< Cor azul do poligono 1*/ 
        r2 = 1.0 , /**< Cor vermelha do poligono 2*/ 
        g2 = 1.0 , /**< Cor verde do poligono 2*/ 
        b2 = 0.0, /**< Cor azul do poligono 2*/ 
        r3 = 1.0 , /**< Cor vermelha do poligono 3*/ 
        g3 = 1.0 , /**< Cor verde do poligono 3*/ 
        b3 = 0.0, /**< Cor azul do poligono 3*/ 
        r4 = 1.0 , /**< Cor vermelha do poligono 4*/ 
        g4 = 1.0 , /**< Cor verde do poligono 4*/ 
        b4 = 0.0, /**< Cor azul do poligono 4*/ 
        rb1 = 0.0 , /**< Cor vermelha da bordado poligono 1*/ 
        gb1 = 0.0 , /**< Cor verde da bordado poligono 1*/ 
        bb1 = 0.0, /**< Cor azul da bordado poligono 1*/ 
        rb2 = 0.0 , /**< Cor vermelha da borda do poligono 2*/ 
        gb2 = 0.0 , /**< Cor verde da bordado poligono 2*/ 
        bb2 = 0.0, /**< Cor azul da bordado poligono 2*/ 
        rb3 = 0.0 , /**< Cor vermelha da borda do poligono 3*/ 
        gb3 = 0.0 , /**< Cor verde da bordado poligono 3*/ 
        bb3 = 0.0, /**< Cor azul da bordado poligono 3*/ 
        rb4 = 0.0 , /**< Cor vermelha da borda do poligono 4*/ 
        gb4 = 0.0 , /**< Cor verde da bordado poligono 4*/ 
        bb4 = 0.0; /**< Cor azul da bordado poligono 4*/ 
GLint mudaBorda = 0; /**< define se a cor mudada é da borda ou do fundo*/ 

/**Função inicializa propriedades de rendering
 */
void init(){ 
    glClearColor(1.0, 1.0, 1.0, 1.0);
    gluOrtho2D(0.0, 256.0, 0.0, 256.0);
}

/**Função callBack keyboard trata entrada do telcado
 */
void keyboard(unsigned char key, int x, int y){
    switch(key){
        case 'F':
            mudaBorda = 0;
        break;
        case 'f':
            mudaBorda = 0;
        break;
        case 'b':
            mudaBorda = 1;
        break;
        case 'B':
            mudaBorda = 1;
        break;
    }
}

/**Função callBack onClickMouse trata entrada dos botões do mouse
 */
void onClickMouse(int button, int state, int x, int y){
    switch(button){
        case GLUT_LEFT_BUTTON:
            
            srand(time(NULL));
            
            if (mudaBorda == 0){
                //p1
                if (state == GLUT_DOWN && x >= 30 && x <= 113 && y >= 30 && y <= 113){
                    r1 = ((float) random() / (float)(RAND_MAX));
                    g1 = ((float) random() / (float)(RAND_MAX));
                    b1 = ((float) random() / (float)(RAND_MAX));
                    
                }else 
                    //p2
                    if(state == GLUT_DOWN && x >= 143 && x <= 226 && y >= 30 && y <= 113){
                        r2 = ((float) random() / (float)(RAND_MAX));
                        g2 = ((float) random() / (float)(RAND_MAX));
                        b2 = ((float) random() / (float)(RAND_MAX));
                }else 
                    //p3
                    if (state == GLUT_DOWN && x >= 30 && x <= 113 && y >= 143 && y <= 226){
                        r3 = ((float) random() / (float)(RAND_MAX));
                        g3 = ((float) random() / (float)(RAND_MAX));
                        b3 = ((float) random() / (float)(RAND_MAX));
                }else 
                    //p4
                    if (state == GLUT_DOWN &&  x >= 143 && x <= 226 && y >= 143 && y <= 226){
                        r4 = ((float) random() / (float)(RAND_MAX));
                        g4 = ((float) random() / (float)(RAND_MAX));
                        b4 = ((float) random() / (float)(RAND_MAX));
                }
            }else{
                //p1
                if (state == GLUT_DOWN && x >= 30 && x <= 113 && y >= 30 && y <= 113){
                    rb1 = ((float) random() / (float)(RAND_MAX));
                    gb1 = ((float) random() / (float)(RAND_MAX));
                    bb1 = ((float) random() / (float)(RAND_MAX));
                    
                }else 
                    //p2
                    if(state == GLUT_DOWN && x >= 143 && x <= 226 && y >= 30 && y <= 113){
                        rb2 = ((float) random() / (float)(RAND_MAX));
                        gb2 = ((float) random() / (float)(RAND_MAX));
                        bb2 = ((float) random() / (float)(RAND_MAX));
                }else 
                    //p3
                    if (state == GLUT_DOWN && x >= 30 && x <= 113 && y >= 143 && y <= 226){
                        rb3 = ((float) random() / (float)(RAND_MAX));
                        gb3 = ((float) random() / (float)(RAND_MAX));
                        bb3 = ((float) random() / (float)(RAND_MAX));
                }else 
                    //p4
                    if (state == GLUT_DOWN &&  x >= 143 && x <= 226 && y >= 143 && y <= 226){
                        rb4 = ((float) random() / (float)(RAND_MAX));
                        gb4 = ((float) random() / (float)(RAND_MAX));
                        bb4 = ((float) random() / (float)(RAND_MAX));
                }
                    
            }
            
        break;
    }
    
    glutPostRedisplay();
    
}

/**Função desenha os polígonos a partir das coordenadas máximas e mínimas
 */
void desenhaPoligono(int minX, int maxX, int minY, int maxY){
    glBegin(GL_POLYGON);
        glVertex2i(minX,maxY);  
        glVertex2i(maxX,maxY);
        glVertex2i(maxX,minY); 
        glVertex2i(minX,minY); 
    glEnd();
}

/**Função desenha as bordas a partir das coordenadas máximas e mínimas
 */
void desenhaBorda(int minX, int maxX, int minY, int maxY){
    glBegin(GL_LINE_LOOP);
        glVertex2i(minX,maxY);  
        glVertex2i(maxX,maxY);
        glVertex2i(maxX,minY); 
        glVertex2i(minX,minY);
    glEnd();
}

/**Função callBack display desenha as pritivas openGL
 */
void display(){
    glClear(GL_COLOR_BUFFER_BIT);
                    
    glColor3f(r1, g1, b1);
    //p1
    desenhaPoligono(30, 113, 143, 226);

    glColor3f(r2, g2, b2);
    //p2
    desenhaPoligono(143, 226, 143, 226);

    glColor3f(r3, g3, b3);
    //p3
    desenhaPoligono(30, 113, 30, 113);

    glColor3f(r4, g4, b4);
    //p4
    desenhaPoligono(143, 226, 30, 113);
    
    glLineWidth(3.0);
    glColor3f(rb1, gb1, bb1);
    //b1
    desenhaBorda(30, 113, 143, 226);

    glColor3f(rb2, gb2, bb2);
    //b2
    desenhaBorda(143, 226, 143, 226);

    glColor3f(rb3, gb3, bb3);
    //b3
    desenhaBorda(30, 113, 30, 113);

    glColor3f(rb4, gb4, bb4);
    //b4
    desenhaBorda(143, 226, 30, 113);
    
    glFlush();
    
}


/**Função principal
 */
int main(int argc, char ** argv){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(256, 256);
    glutInitWindowPosition(150, 75);
    glutCreateWindow("Q8 - Seleção");
    glutDisplayFunc(display);
    glutMouseFunc(onClickMouse);
    glutKeyboardFunc(keyboard);
    init();
    
    glutMainLoop();
    
    return 0;
}