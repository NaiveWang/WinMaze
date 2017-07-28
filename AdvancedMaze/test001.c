#include <stdio.h>
#include "RanGen.h"
#define PASS(x) printf("PASS:%04d\n",x)
#define TEST 12
int main(void)
{
  int i;
  int ii[TEST]={0};
  PASS(1);
  ranInit();
  PASS(2);
  for(i=0;i<7000000;i++)
  {
    ii[ranGen(TEST)]++;
  }
  for(i=0;i<TEST;i++)
  {
    printf("%d\n",ii[i]);
  }
  printf("\n");
  return 0;
}
