#include <GL/glut.h>
#include <math.h>
#define PI 3.141592
int height = 600 , width = 800;

/*Funcion circulo para el sol y las llantas del carro
dibuja con triangulos*/
void circulo(int r , int posX , int posY){
    int i;

    float angulo,angulo2;

    for(i = 0 ; i < 180 ; i++){
      glBegin(GL_TRIANGLES);
      glVertex2f(posX,posY);
      angulo = (10 + 2*i)*2*1.0*PI/360;
      angulo2 = (10 + 2*(i+1))*2*PI/360;
      glVertex2f(posX + r*cos(angulo),posY + r*sin(angulo));
      glVertex2f(posX + r*cos(angulo2),posY+r*sin(angulo2));
      glEnd();
    }
}

/*Dibuja los postes con las helices*/
void helices(float x1 , float y1 , float y2){
  int i;
  /*primero dibuja el palo*/
  glColor3f(1.0,1.0,1.0);
  glLineWidth(5);
  glBegin(GL_LINES);
  glVertex2f(x1,y1);
  glVertex2f(x1,y2);
  glEnd();

  /*aqui dibuja las helices rotandolas*/
  for(i = 0 ; i <= 2 ; i++){
    glPushMatrix();
    glTranslatef(x1,y2,0);
    glRotatef(120*i,0.0,0.0,1.0);
    glTranslatef(-x1,-y2,0);
    glColor3f(1.0,0.0,0.2);
    glBegin(GL_POLYGON);
    glVertex2f(x1,y2);
    glVertex2f(x1-width/32,y2+10);
    glVertex2f(x1 - width/16,y2);
    glVertex2f(x1 - width/32,y2 - 10);
    glEnd();

    glPopMatrix();
  }

}


void carro(){
  int i;
  /*LLantas*/
  glColor3f(0.0,0.0,0.0);
  circulo(height/32,7*width/16,3*height/16);
  glColor3f(1.0,1.0,1.0);
  circulo((height/32)-height/128,7*width/16,3*height/16);

  glColor3f(0.0,0.0,0.0);
  circulo(height/32,9*width/16,3*height/16);
  glColor3f(1.0,1.0,1.0);
  circulo((height/32)-height/128,9*width/16,3*height/16);
/*lineas*/
  for(i = 1 ; i <= 18 ; i++){
    glPushMatrix();
    glTranslatef(7*width/16,3*height/16,0);
    glRotatef(20*i,0.0,0.0,1.0);
    glTranslatef(-7*width/16,-3*height/16,0);
    glColor3f(0.0,0.0,0.0);
    glLineWidth(1);
    glBegin(GL_LINES);
    glVertex2f(7*width/16,7*height/32);
    glVertex2f(7*width/16,5*height/32);
    glEnd();

    glPopMatrix();
//  }
//  for(i = 1 ; i <= 18 ; i++){
    glPushMatrix();
    glTranslatef(9*width/16,3*height/16,0);
    glRotatef(20*i,0.0,0.0,1.0);
    glTranslatef(-9*width/16,-3*height/16,0);
    glColor3f(0.0,0.0,0.0);
    glLineWidth(1);
    glBegin(GL_LINES);
    glVertex2f(9*width/16,7*height/32);
    glVertex2f(9*width/16,5*height/32);
    glEnd();

    glPopMatrix();
  }
  /*Cuerpo*/
  glColor3f(1.0,0.0,0.0);
  glBegin(GL_POLYGON);
  glVertex2f(3*width/8,3*height/16);
  glVertex2f(5*width/8,3*height/16);
  glVertex2f(5*width/8,5*height/16);
  glVertex2f(3*width/8,5*height/16);
  glEnd();

}

void init(){
    glClearColor(0.75, 0.75, 0.75, 0.0);

    glMatrixMode(GL_PROJECTION);
    glMatrixMode(GL_MODELVIEW);

    gluOrtho2D(0.0, width, 0.0, height);
}

void display(){

  int i;
  float angulo;

  glClear(GL_COLOR_BUFFER_BIT);

  /*Primero dibujo el piso*/

  glColor3f(0.22,0.49,0.01);
  glBegin(GL_POLYGON);
  glVertex2i(0,width/8);
  glVertex2i(0,0);
  glVertex2i(width,0);
  glVertex2i(width,height/8);
  glEnd();

  /*Dibujo la pista*/
  glColor3f(0.27,0.32,0.24);
  glBegin(GL_POLYGON);
  glVertex2i(0,height/4);
  glVertex2i(0,height/8);
  glVertex2i(width,height/8);
  glVertex2i(width,height /4);
  glEnd();

  /*Los cerros*/
  glColor3f(0.22,0.49,0.01);
  glBegin(GL_POLYGON);
  glVertex2i(0,height/4);
  glVertex2i(width,height/4);
  glVertex2i(width,5*height/16);
  glVertex2i(width*7/8,3*height/8);
  glVertex2i(width*3/4,5*height/16);
  glVertex2i(width/3,5*height/8);
  glVertex2i(width/3,height/4);
  glEnd();

  glColor3f(0.22,0.49,0.01);
  glBegin(GL_POLYGON);
  glVertex2i(0,height/4);
  glVertex2i(0,height*3/8);
  glVertex2i(width/8,height/2);
  glVertex2i(width/4,height/4);
  glEnd();


  /*Las lineas de la pista*/

  glColor3f(1.0,1.0,1.0);
  glBegin(GL_POLYGON);
  glVertex2i(0,3*height/16);
  glVertex2i(width,3*height/16);
  glVertex2i(width,13*height/64);
  glVertex2i(0,13*height/64);
  glEnd();

  /*Lineas del sol*/

  for(i = 0 ; i < 18 ; i++){
  //  angulo =
    glColor3f(1.0,1.0,0.0);
    glLineWidth(3);
    glBegin(GL_LINES);
    glVertex2f(3*width/4,4*height/5);
    glVertex2f( (3*width/4) + (width*cos(20*2*PI*i/360)/8),(4*height/5)
    + (width*sin(20*2*PI*i/360)/8));
    glEnd();
  }

  /* EL sol*/
  glColor3f(1.0,0.0,0.0);
  circulo(width/16,3*width/4,4*height/5);
  glColor3f(1.0,1.0,0.0);
  circulo(15*width/256,3*width/4,4*height/5);

  /*Las helices*/
  helices(width/16,3*height/8,3*height/4);
  helices(3*width/10,height/2,3*height/4);
  helices(width/2,5*height/16,3*height/4);
/*dibuja el carro*/
  carro();

  glutSwapBuffers();
  glFlush();
}

int main(int argc, char ** argv){

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowPosition(0,0);
    glutInitWindowSize(width, height);

    glutCreateWindow("Dibuja un Paisaje ");
    init();

    glutDisplayFunc(display);

    glutMainLoop();
}
