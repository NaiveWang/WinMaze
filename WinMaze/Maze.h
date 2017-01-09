#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <graphics.h>
#define DIRECTION 4
#define DEBUG_WIDTH 10
#define NORTH 1
#define SORTH 2
#define WEST 4
#define EAST 8
#define ALL_1 -1
#define ARREY_INDEX(BASE,LENGTH,Y,X) ((BASE)+((LENGTH)*(Y)+(X)))
#define RAN_COLOR WHITE//EGERGB(Ran(0xFF),Ran(0xFF),Ran(0xFF))
typedef struct Maze_Node
{
    char wall[DIRECTION];//up,down,left,right:0123
}MazeNode;
int Ran(int mod)
{
    if(mod)
        return rand()%mod;
    else
        return rand();
}
//Debug section.
/*void Debug_0(int width,int height,const int *base)
{
    FILE *fp;
    int counter = 1;
    fp = fopen("Debug_0.txt","w");
    for(;counter<=width*height;counter++)
    {
        fprintf(fp,"%2d ",*(base+counter-1));
        if(counter%width==0) fprintf(fp,"\n");
    }
    fclose(fp);
    system("pause");
}
void Debug_1(int value)
{
    FILE *fp;
    fp = fopen("Debug_1.txt","a");
    fprintf(fp,"%d\n",value);
    fclose(fp);
    system("pause");
}*/
//Display Section
void NodeDisp(int x,int y,int width,MazeNode mn)
{
    register int ox=x+width-1,oy=y+width-1;
    putpixel(x,y,RAN_COLOR);
    putpixel(ox,y,RAN_COLOR);
    putpixel(x,oy,RAN_COLOR);
    putpixel(ox,oy,RAN_COLOR);
    if(mn.wall[0]) {setcolor(RAN_COLOR);line(x,y,ox,y);}
    if(mn.wall[1]) {setcolor(RAN_COLOR);line(x,oy,ox,oy);}
    if(mn.wall[2]) {setcolor(RAN_COLOR);line(x,y,x,oy);}
    if(mn.wall[3]) {setcolor(RAN_COLOR);line(ox,y,ox,oy);}
}
void ToadDisp(int x,int y,int width)
{
    setfillcolor(RAN_COLOR);
    bar(x+1,y+1,x+width-2,y+width-2);
}
void MazeDisp(int col,int row,int wid,int x,int y,MazeNode *base)
{
    register int rcol=0,rrow;
    cleardevice();
    for(;rcol<col;rcol++)
        for(rrow=0;rrow<row;rrow++)
    {
        NodeDisp(rrow*wid,rcol*wid,wid,*base);
        base++;
    }
    ToadDisp(x*wid,y*wid,wid);
}
void InitGraph(int width,int height,int scale)
{
    initgraph(width*scale,height*scale);
}
//Initialize section
void SetCFlagToZ(const int *height,const int *width,char *const base)
{
    register int ofst = (*height) * (*width);
    while(ofst--) *(base+ofst) = 0;
}
void SetNodeConnect(const int *p,const int *n,const int *height,const int *width,int *const base)
//p for previous,n for new
{
    register int tail = (*height)*(*width),ofst = *p;
    for(;ofst<tail;ofst++)
    {
        if(*(base+ofst)==*p) *(base+ofst) = *n;
    }
}
int JudgeIfCouldConnect(const int *curr,const int *height,const int *width,const int *const Fbase,char *const FCbase)
//"curr" is the pointer to the current value.
//+1S, did it in 2016/10/13.
{
    const int scale = (*height)*(*width);
    int ofst = *curr;
    register int x,y,counter=0;
    for(;ofst < scale;ofst++)
    {
        if(*(Fbase+ofst)==*curr)
        {
            y = ofst/(*width);
            x = ofst%(*width);
            if(y>0&&*ARREY_INDEX(Fbase,*width,y-1,x)!=*curr) {counter++;*ARREY_INDEX(FCbase,*width,y-1,x)+=SORTH;}
            if(y<(*height-1)&&*ARREY_INDEX(Fbase,*width,y+1,x)!=*curr) {counter++;*ARREY_INDEX(FCbase,*width,y+1,x)+=NORTH;}
            if(x>0&&*ARREY_INDEX(Fbase,*width,y,x-1)!=*curr) {counter++;*ARREY_INDEX(FCbase,*width,y,x-1)+=EAST;}
            if(x<(*width-1)&&*ARREY_INDEX(Fbase,*width,y,x+1)!=*curr) {counter++;*ARREY_INDEX(FCbase,*width,y,x+1)+=WEST;}
        }
    }
    return counter;
}
void WallBuilder(const int *height,const int *width,int *base)
{
    register int iteration_counter = sizeof(MazeNode)*(*height)*(*width)/4;
    while(iteration_counter--)
    {
        *base = (int)ALL_1;
        base++;
    }
}
void WallCrusher(const int *height,const int *width,const int *previous,int seed,int *const FCbase,char *const FlagBase,MazeNode *const maze)
{
    int ofst=0;
    char Ftemp,dir=0;
    seed++;
    while(seed)
    {
        Ftemp=*(FlagBase+ofst);
        if(Ftemp)
        {
            if(Ftemp & EAST) {dir=EAST;*(FlagBase+ofst)-=EAST;seed--;continue;}
            if(Ftemp & WEST) {dir=WEST;*(FlagBase+ofst)-=WEST;seed--;continue;}
            if(Ftemp & SORTH) {dir=SORTH;*(FlagBase+ofst)-=SORTH;seed--;continue;}
            if(Ftemp & NORTH) {dir=NORTH;*(FlagBase+ofst)-=NORTH;seed--;continue;}
        }
        else ofst++;
    }
    {
        register int x=ofst%(*width),y=ofst/(*width);
        SetNodeConnect(previous,(FCbase+ofst),height,width,FCbase);
        switch (dir)
        {
            case NORTH: (maze+ofst)->wall[0]=0;ARREY_INDEX(maze,*width,y-1,x)->wall[1]=0;break;
            case SORTH: (maze+ofst)->wall[1]=0;ARREY_INDEX(maze,*width,y+1,x)->wall[0]=0;break;
            case WEST: (maze+ofst)->wall[2]=0;ARREY_INDEX(maze,*width,y,x-1)->wall[3]=0;break;
            case EAST: (maze+ofst)->wall[3]=0;ARREY_INDEX(maze,*width,y,x+1)->wall[2]=0;break;
            case 0   : return;
        }
    }
}
void MazeInitializer(const int *height,const int *width,MazeNode *mp)
{
    char flagC[*height][*width];
    int counter=(*height)*(*width);
    int flag[*height][*width];
    int seedn;
    WallBuilder(height,width,(int*)mp);
    while(counter--)
    {
        *((int*)flag+counter) = counter;
    }
    counter=(*height)*(*width);
    //InitGraph(*width,*height,20);
    while(--counter)
    {
        SetCFlagToZ(height,width,*flagC);
        seedn = JudgeIfCouldConnect(&counter,height,width,*flag,*flagC);
        WallCrusher(height,width,&counter,Ran(seedn),*flag,*flagC,mp);
        //MazeDisp(*height,*width,20,0,0,mp);
        //Debug_0(*width,*height,*flag);
        //Debug_1(counter);
        //system("pause");
    }
}
//Input & Control Section
int KeyTrigger()
{
    if(kbmsg()) return  getch();
        else return 0;
}
//Operating yeah , this is the fuckin' important one.
int StartGame(int height,int row,int scale)
{
    int x=0,y=0;
    MazeNode mp[height*row];
    //system("pause");
    InitGraph(row,height,scale);
    A:MazeInitializer(&height,&row,mp);
    MazeDisp(height,row,scale,x,y,mp);
    for(;;)
    {
        switch(KeyTrigger())
        {
            case 'w': if((mp+y*row+x)->wall[0]) break; else {y--; MazeDisp(height,row,scale,x,y,mp);break;}
            case 's': if((mp+y*row+x)->wall[1]) break; else {y++; MazeDisp(height,row,scale,x,y,mp);break;}
            case 'a': if((mp+y*row+x)->wall[2]) break; else {x--; MazeDisp(height,row,scale,x,y,mp);break;}
            case 'd': if((mp+y*row+x)->wall[3]) break; else {x++; MazeDisp(height,row,scale,x,y,mp);break;}
            case 'q': free(mp); return 0;
        };
        Sleep(20);
        if(x==row-1&&y==0) {break;}
    }
    closegraph();
    return 0;
}
