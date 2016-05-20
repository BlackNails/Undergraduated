#include <GL/glut.h>
#include <math.h>
#define PI 3.141592

float posX = 250 , posY = 250 , posZ = 0;
float r = 20,moveUnit = 5; 
int bandera  = 1; 
/*Dibuja la cara del personaje*/
void cara(){

    glColor3f(0.5,0.5,0.5);
    int i;
    float angulo,angulo2;

        for(i = 0 ; i < 170 ; i++){
            glBegin(GL_TRIANGLES);
            glVertex2f(posX,posY);
            angulo = (10 + 2*i)*2*1.0*PI/360;
            angulo2 = (10 + 2*(i+1))*2*PI/360;
            glVertex2f(posX + r*cos(angulo),posY + r*sin(angulo));
            glVertex2f(posX + r*cos(angulo2),posY+r*sin(angulo2));
            glEnd();
        
        }    

}

void eventosteclado(int key, int x, int y) {
    switch (key) {
    case GLUT_KEY_RIGHT:
        bandera = 1;
        if(posX < 480)
            posX += moveUnit;
        break;
    case GLUT_KEY_LEFT:
        bandera = 0;
        if(posX > 20)
            posX -= moveUnit;
        break;
    case GLUT_KEY_UP:
        bandera = 2;
        if(posY < 480)
            posY += moveUnit;
        break;
    case GLUT_KEY_DOWN:
        bandera = 3;
        if(posY > r)
        posY -= moveUnit;
        break;
    default:
        break;
    }
glutPostRedisplay();
}
void init()
{
    glClearColor(0.7843, 0.7843, 1, 0.0);
    glMatrixMode(GL_PROJECTION);
    glMatrixMode(GL_MODELVIEW);

    gluOrtho2D(0.0, 500, 0.0, 500);
}

void display()
{
    int i;
    
    glClear(GL_COLOR_BUFFER_BIT);    
    glColor3f(0.5,0.5,0.5);
    glPushMatrix();
    glTranslatef(posX,posY,posZ);

    if(bandera == 0)
        glRotatef(180,0.0,0.0,1.0);
    if(bandera == 2)
        glRotatef(90,0.0,0.0,1.0);
    if(bandera == 3)
        glRotatef(270,0.0,0.0,1.0);

    /*Regresa*/
    glTranslatef(-posX,-posY,posZ);
    /*Se dibuja la cara*/
    cara();
    glPopMatrix();

    glFlush();
}

int main(int argc, char ** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowPosition(0,0);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Pacman");
    init();
    glutDisplayFunc(display);
    glutSpecialFunc(eventosteclado);
    glutMainLoop();
} 
