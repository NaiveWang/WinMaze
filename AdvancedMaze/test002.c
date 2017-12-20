#include "Maze.h"
int main(int argc,char **argv)
{
  mazeInit2(3,3);

  glutInit(&argc,argv);
  glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
  glutInitWindowSize(500,500);
  glutInitWindowPosition(0,0);
  glutCreateWindow("AM test002");
  glutReshapeFunc(mazeGInit);
  glutDisplayFunc(mazeGFlush);
  //glutMouseFunc(&SetDot);
  glutIdleFunc(mazeGFlush);
  glutMainLoop();
  return 0;
}
