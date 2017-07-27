#ifndef RANGEN_H
#define RANGEN_H
#include <stdlib.h>
#include <time.h>
//#include <stdio.h>
/*
 * Optimized Random Generator
 * This function could be used in any GCC compilers
 **/
/*
 * This function could generate a random nunmber, with same possibility.
 **/
int ranGen(int);
/*
 * Using time to initilize the random generater.
 **/
void ranInit();

#include "RanGen.c"
#endif
