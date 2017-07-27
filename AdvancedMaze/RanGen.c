void ranInit()
{
  srand((unsigned)time(NULL));
}
int ranGen(int n)
{
  if(n>0)
  {
    register int sh=n,count=0;
    int ret;
    //get the bind
    while(sh)
    {
      count++;
      //printf("%d ", sh);
      sh>>=1;
    }
    //printf("aaaaaaaa %d\n",count);
    sh=1;
    while(--count)
    {
      sh<<=1;
      sh|=1;
    }
    //printf("%x\n",sh);
    do{
      ret=rand()&sh;
      //printf("#%d#",ret);
    }while(ret>=n);
    return ret;
  }
  return 0;

}
