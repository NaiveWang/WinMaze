#include <stdio.h>
#include "RanGen.h"
#define PASS(x) printf("PASS:%04d\n",x)
int main(void)
{
  int i;
  int ii[5]={0};
  PASS(1);
  ranInit();
  PASS(2);
  for(i=0;i<6000000;i++)
  {
    ii[ranGen(5)]++;
  }
  for(i=0;i<5;i++)
  {
    printf("%d\n",ii[i]);
  }
  printf("\n");
  return 0;
}
