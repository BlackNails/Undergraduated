/*Simple Template for OpenGL*/
/*Usual parameters used*/

#include <GL/glut.h>

#define width  800
#define height 600
int move_unit = 5;
int posX = width/2 , posY = height/2;

/*Some initial Parameters*/
void init(){

    glClearColor(1.0, 1.0, 1.0, 0.0); // white background
    glMatrixMode(GL_PROJECTION); // projection matrix
    glMatrixMode(GL_MODELVIEW);
    gluOrtho2D(0.0, width, 0.0, height);

}

void display(){
  /*All the drawing goes here*/
  glClear(GL_COLOR_BUFFER_BIT);// // clear the window

  //end
  glutSwapBuffers(); // make it all visible
}

void keyboardEvents(int key, int x, int y){

  switch(key){
    case GLUT_KEY_RIGHT:
      posX+=move_unit;
      break;

    case GLUT_KEY_LEFT:
      posX-=move_unit;
      break;

    case GLUT_KEY_UP:
      posY+=move_unit;
      break;

    case GLUT_KEY_DOWN:
      posY-=move_unit;
      break;

    default:
      break;
  }

  glutPostRedisplay();

}

int main(int argc, char ** argv){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);

    glutInitWindowPosition(0,0); // window position
    glutInitWindowSize(width, height); // window size

    glutCreateWindow(" Window Title ");

    init();

    glutDisplayFunc(display);
    glutSpecialFunc(keyboardEvents); // keyboard events

    glutMainLoop();
}
