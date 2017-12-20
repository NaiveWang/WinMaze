/** Utility Function Section **/
int* mazeSeek3(int x,int y,int z)
{
  return s_x*x+s_y*y+z+maze;
}
int* mazeSeek2(int x,int y)
{
  return s_x*x+y+maze;
}
/** Function Section **/
void mazeInit2(int x,int y)
{
  int c0=x*y,c1;//counter
  int *connection=malloc(x*y*sizeof(int));
  maze=malloc(x*y*sizeof(int));
  s_x=x;
  s_y=y;
  while(c0--)
  {
    *(connection+c0)=c0;
    *(maze+c0)=0x0000000F;
  }
  for(c0=x;c0--;)for(c1=y;c1--;)
  {///for each node
    int c2=4,c3;
    char con[4]={0};
    //1.find adjacent legal node, get the random value.
    if(c0==0 || *(s_x*c0+c1+connection)==*(s_x*(c0-1)+c1+connection)) {c2--;con[0]=1;}
    if(c0==x-1 || *(s_x*c0+c1+connection)==*(s_x*(c0+1)+c1+connection)) {c2--;con[1]=1;}
    if(c1==0 || *(s_x*c0+c1+connection)==*(s_x*c0+c1-1+connection)) {c2--;con[2]=1;}
    if(c1==y-1 || *(s_x*c0+c1+connection)==*(s_x*c0+c1+1+connection)) {c2--;con[3]=1;}
    c2=ranGen(c2);
    //2.set the current node value & nodes with same value to the new value.
    for(c3=0;;c3++)
    {
      if(!con[c3]) continue;
      if(!c2) break;
      c2--;
    }
    //3.set the maze connection value.
    *(maze+c0*x+c1)^=D[c3];
    switch(c3)
    {
      case 0:c2=*(s_x*(c0-1)+c1+connection);*(maze+(c0-1)*x+c1)^=D[c3];break;
      case 1:c2=*(s_x*(c0+1)+c1+connection);*(maze+(c0+1)*x+c1)^=D[c3];break;
      case 2:c2=*(s_x*c0+c1-1+connection);*(maze+c0*x+c1-1)^=D[c3];break;
      case 3:c2=*(s_x*c0+c1+1+connection);*(maze+c0*x+c1+1)^=D[c3];break;
    }
    int *cp0=connection+c0*x+c1;
    int *cp1=connection+x*y;
    c3=*(s_x*c0+c1+connection);
    while(cp0<cp1)
    {
      if(*cp0==c3) *cp0==c2;
      cp0++;
    }
  }
  //free(connection);
}
//void mazeInit3(int,int,int);
//void mazeHelper();
/** Graphic Function **/
//void mazeGDraw();
void mazeGInit()
{
  glViewport(0,0,s_x,s_y);

  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();

  gluOrtho2D(0.0,s_x,0.0,s_y);
  glMatrixMode(GL_MODELVIEW);
}
void mazeGFlush()
{
  static int x,y;
  static int *aux;
  aux=maze;
  glClearColor(0,0,0,0);
  glClear(GL_COLOR_BUFFER_BIT);
  glColor3ub(255,255,255);
  glBegin(GL_QUADS);
  glVertex2i(x,y);
  glVertex2i(x+1,y);
  glVertex2i(x+1,y+1);
  glVertex2i(x,y+1);
  glEnd();
  for(x=0;x<s_y;x++)for(y=0;y<s_y;y++)
  {
    if((*aux)^D[0])
    {
      glBegin(GL_QUADS);
      glVertex2f(x,y);
      glVertex2f(x+0.1,y);
      glVertex2f(x+0.1,y+1);
      glVertex2f(x,y+1);
      glEnd();
    }
    if((*aux)^D[1])
    {
      glBegin(GL_QUADS);
      glVertex2f(x+1,y);
      glVertex2f(x+1.1,y);
      glVertex2f(x+1.1,y+1);
      glVertex2f(x+1,y);
      glEnd();
    }
    if((*aux)^D[2])
    {
      glBegin(GL_QUADS);
      glVertex2f(x,y);
      glVertex2f(x,y+0.1);
      glVertex2f(x+1,y+0.1);
      glVertex2f(x+1,y);
      glEnd();
    }
    if((*aux)^D[3])
    {
      glBegin(GL_QUADS);
      glVertex2f(x,y+1);
      glVertex2f(x,y+1.1);
      glVertex2f(x+1,y+1.1);
      glVertex2f(x+1,y+1);
      glEnd();
    }
    aux++;
  }
  glFlush();
}
/** Control **/
//void mazeCGetC();
