#include <GL/glut.h> // GLUT (also loads gl.h and glu.h)
void myReshape(int w, int h) { // window is reshaped
glViewport (0, 0, w, h); // update the viewport
glMatrixMode(GL_PROJECTION); // update projection
glLoadIdentity();
gluOrtho2D(0.0, 1.0, 0.0, 1.0); // map unit square to viewport
glMatrixMode(GL_MODELVIEW);
glutPostRedisplay(); // request redisplay
}
void myDisplay(void) { // (re)display callback
glClearColor(0.5, 0.5, 0.5, 1.0); // background is gray
glClear(GL_COLOR_BUFFER_BIT); // clear the window
glColor3f(1.0, 0.0, 0.0); // set color to red
glBegin(GL_POLYGON); // draw the diamond
glVertex2f(0.90, 0.50);
glVertex2f(0.50, 0.90);
glVertex2f(0.10, 0.50);
glVertex2f(0.50, 0.10);
glEnd();
glColor3f(0.0, 0.0, 1.0); // set color to blue
glRectf(0.25, 0.25, 0.75, 0.75); // draw the rectangle
glutSwapBuffers(); // swap buffers
}
int main(int argc, char** argv) { // main program
glutInit(&argc, argv); // OpenGL initializations
glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);// double buffering and RGB
glutInitWindowSize(400, 400); // create a 400x400 window
glutInitWindowPosition(0, 0); // ...in the upper left
glutCreateWindow(argv[0]); // create the window
glutDisplayFunc(myDisplay); // setup callbacks
glutReshapeFunc(myReshape);
glutMainLoop(); // start it running
return 0; // ANSI C expects this
}
