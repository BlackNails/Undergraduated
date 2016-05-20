#include <GL/glut.h>
#include <math.h>
#define PI 3.141592
int width = 500 , height = 500;
/*Posiciones iniciales*/
float posX = 250 , posY = 250 , posZ = 0;
float r = 20,moveUnit = 5; 
int bandera = 1; 

/*Dibuja la cara del personaje con triangulos*/
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

/*Dibuja el cuerpo*/    
void cuerpo(){

    //cuerpo
    glLineWidth(5);
    glBegin(GL_LINES);
    glVertex2f(posX,posY);
    glVertex2f(posX,posY - 2.5*r);
    glEnd();
    //brazos
    glLineWidth(5);
    glBegin(GL_LINES);
    glVertex2f(posX - r , posY - 1.5*r);
    glVertex2f(posX + r , posY - 1.5*r);
    glEnd();
    //piernas
    glLineWidth(5);
    glBegin(GL_LINES);
    glVertex2f(posX - r , posY - 3*r );
    glVertex2f(posX , posY - 2.5*r);
    glEnd();
    glLineWidth(5);
    glBegin(GL_LINES);
    glVertex2f(posX + r , posY - 3*r );
    glVertex2f(posX , posY - 2.5*r);
    glEnd();

}

void eventosteclado(int key, int x, int y) {
    switch (key) {
    case GLUT_KEY_RIGHT:
        bandera = 1;
        if(posX < width - r)
            posX += moveUnit;
        break;
    case GLUT_KEY_LEFT:
        bandera = 0;
        if(posX > r)
            posX -= moveUnit;
        break;
    case GLUT_KEY_UP:
        bandera = 2;
        if(posY < height - r)
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
    glClearColor(1.0, 1.0, 1.0, 0.0);

    glMatrixMode(GL_PROJECTION);
    glMatrixMode(GL_MODELVIEW);
    
    gluOrtho2D(0.0, width, 0.0, height);
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

    glTranslatef(-posX,-posY,posZ);

    /*Se dibuja la cara*/
    cara();
    glPopMatrix();

    /*Para que no se salga del mapa cuando llega al limite del ancho*/
    if(bandera == 2 && posX == height - r || bandera == 3){
        glPushMatrix();
        glTranslatef(posX,posY,posZ);
        glRotatef(270,0.0,0.0,1.0);
        glTranslatef(-posX,-posY,posZ);
        cuerpo();
        glPopMatrix();
    }
    /*Limite izquierdo*/
    if(bandera == 3 && posX == r || bandera == 2){
        glPushMatrix();
        glTranslatef(posX,posY,posZ);
        glRotatef(90,0.0,0.0,1.0);
        glTranslatef(-posX,-posY,posZ);
        cuerpo();
        glPopMatrix();
    }
    if(bandera == 1 || bandera == 0 )
        cuerpo();


    glPopMatrix();

    

    glutSwapBuffers();

    glFlush();


}

int main(int argc, char ** argv)
{
    glutInit(&argc, argv);
    
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    
    glutInitWindowPosition(0,0);
    
    glutInitWindowSize(500, 500);
    
    glutCreateWindow("Dibuja un Paisaje ");
    
    init();
    
    glutDisplayFunc(display);
    glutSpecialFunc(eventosteclado);

    glutMainLoop();
} 
