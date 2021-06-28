#include <GL/glut.h>
#include <stdlib.h>
#include <stdio.h>

void init(void);
void display(void);
void keyboard(unsigned char key, int x, int y);

int main(){
glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
glutInitWindowSize(150,150);
glutInitWindowPosition(100,100);
glutCreateWindow("Desenhe uma linha");
glutDisplayFunc(display);
glutKeyboardFunc(keyboard);
glutMainLoop();
return 0;
}

void init(void){
    glClearColor(1.0,1.0,1.0,1.0);
    glOrtho(0,256,0,256,-1,1);
}

void display(void){
    int i;
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(0.0,0.0,0.0);
    glBegin(GL_LINES);
    glVertex2i(20,100);

    glEnd();
    glFlush();
}

void keyboard(unsigned char key, int x, int y){
    switch (key){
        case 27:
        exit(0);
        break;
    }
}