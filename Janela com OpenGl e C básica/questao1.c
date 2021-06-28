#include <stdlib.h>
#include <stdio.h>
#include <GL/glut.h>

void inicio(void);
void teclas();
void desenha(void);

double rotate_y = 0;
double rotate_x = 0;

int main(int argc, char** argv){
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_DEPTH | GLUT_SINGLE | GLUT_RGBA);
    glutInitWindowPosition(100,100);
    glutInitWindowSize(648,480);
    glutCreateWindow("OpenGl");

    inicio();

    glutDisplayFunc(desenha);
    glutSpecialFunc(teclas);

    glutMainLoop();

}

void inicio(){
    glClearColor(0,0,0,0);

}

void desenha(void){
    
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    
    // Reinicializar transformações
    glLoadIdentity();

    // Rotacionar quando o usuário mudar as variáveis rotate_x e rotate_y
    glRotatef( rotate_x, 1.0, 0.0, 0.0 );
    glRotatef( rotate_y, 0.0, 1.0, 0.0 );
    
    glBegin(GL_POINT);
    glColor3f( 1.0, 0.0, 0.0 );     glVertex3f(  1, -1, -1 ); 
    glEnd();

    glFlush();
    glutSwapBuffers();

    /*glBegin(GL_TRIANGLES);
        //triangulo de cabeça para baixo vermelho
        glColor3f(1.0,0.0,0.0);
        glVertex2f(0.5,0.5);
        glVertex2f(-0.5,0.5);
        glVertex2f(0.0,-0.5);

    glEnd();
    */
    //glFlush();
}

void teclas( int key, int x, int y ) {

    // Seta para direita - aumenta a rotação em 5 graus
    if (key == GLUT_KEY_RIGHT)
        rotate_y += 5;
    
    //  Seta para esquerda - diminui a rotação em 5 graus
    else if (key == GLUT_KEY_LEFT)
        rotate_y -= 5;

    else if (key == GLUT_KEY_UP)
        rotate_x += 5;

    else if (key == GLUT_KEY_DOWN)
        rotate_x -= 5;
  
    // Requisitar atualização da tela
    glutPostRedisplay();

}