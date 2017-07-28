#ifndef MAZE_H
#define MAZE_H
#include <stdlib.h>
/*
 * In this headfile, I used bit to store connection information, not bytes,
 * so you can see there's no such specific structure
 * For each bit, I use '1' to represent wall, etc.
 * I combine the different dimention into the same data pattern: just a byte,
 * They just use different bit (4 in 2D & 6 in 3D)
 **/
/** Global Variable Section **/

#include "maze.c"
#endif
