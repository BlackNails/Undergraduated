#include <GL/glut.h>

void myInit(){
  
}
int main(int argc, char** argv) {
  
glutInit(&argc, argv); 
glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
glutInitWindowSize(400, 300); 
glutInitWindowPosition(0, 0); 
glutCreateWindow(argv[0]); 
myInit(); 
glutMainLoop(); 

return 0; 

}

