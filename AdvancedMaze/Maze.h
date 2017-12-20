#ifndef MAZE_H
#define MAZE_H
#include <stdlib.h>
#include <GL/glut.h>
#include "RanGen.h"
/*
 * In this headfile, I used bit to store connection information, not bytes,
 * so you can see there's no such specific structure
 * For each bit, I use '1' to represent wall, etc.
 * I combine the different dimention into the same data pattern: just a byte,
 * They just use different bit (4 in 2D & 6 in 3D)
 * commit: bullshit. 2017.dec.19
 **/

const static int D[6]={1,2,4,8,16,32};
#define TRACKER 0x00000040
/** Global Variable Section **/
static char mode=DIM2;
//size
static int s_x;
static int s_y;
static int s_z;
//current position
static int cp_x;
static int cp_y;
static int cp_z;
//map
int *mapA;
int *map;
//settings
static char sw_tracker;//switch
/** Utility Function Section **/
int* mazeSeek(int x,int y,int z)
{
  return map + (x*s_x + y)*s_y + s_z;
}

/** Function Section **/
void mazeInit(int x,int y,int z)
{
  mapA = malloc(sizeof(int)*x*z*y);
  map = malloc(sizeof(char)*x*y*z);
  {
    int count=x*y*z;
    while(count--)
    {
      mapA[count]=count;
      map[count]=-1;
    }
  }
  free(mapA);
}
void mazeDest()
{
  free(map);
}
void mazeHelper();
/** Graphic Function **/
void mazeGDraw();
void mazeGInit();
void mazeGFlush();
/** Control **/
void mazeCGetC();
#include "Maze.c"
#endif
