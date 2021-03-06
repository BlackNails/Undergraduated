#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>

#include <time.h>
#include <stdlib.h>

#include <stdio.h>

//using namespace std;

int angle = 1;

static void Timer(int value){
    angle += 0.1;
    glutPostRedisplay();
    // 100 milliseconds
    glutTimerFunc(100, Timer, 0);
}


void init(){
    glClearColor(1.0,1.0,1.0,1.0);
}

void display(){
    glClear(GL_COLOR_BUFFER_BIT);

    glRotatef(angle, 0.0, 1.0, 0.0);
    glRotatef(angle, 0.0, 0.0, 01.0);

    glColor3f(0.9,0.9,0.1);
    glutSolidTeapot(0.5);

    glFlush();

}


int main(int argc, char *argv[]){


    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
    glutInitWindowSize(400,300);
    glutInitWindowPosition(200,100);
    glutCreateWindow("Simulation App");

    init();
    glutDisplayFunc(display);

    Timer(0);

    glutMainLoop();



    return 0;
}
