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
 **/
#define DIM3 0x000000FF
#define DIM2 0x00000000
const static int D[6]={1,2,4,8,16,32};
#define TRACKER 0x00000040
/** Global Variable Section **/
static char mode=DIM2;
//size
static int s_x;
static int s_y;
static int s_z;
static int *maze;
//current position
static int cp_x;
static int cp_y;
static int cp_z;
//settings
static char sw_tracker;//switch
/** Utility Function Section **/
int* mazeSeek3(int,int,int);
int* mazeSeek2(int,int);
/** Function Section **/
void mazeInit2(int,int);
void mazeInit3(int,int,int);
void mazeHelper();
/** Graphic Function **/
void mazeGDraw();
void mazeGInit();
void mazeGFlush();
/** Control **/
void mazeCGetC();
#include "Maze.c"
#endif
