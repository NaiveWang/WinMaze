#include <graphics.h>
#define COLUMN 200
#define ROW 500
int Menu()
{
    int c;
    cleardevice();
    initgraph(ROW,COLUMN);
    outtextxy(120,60,"苟利国家生死以，岂因祸福避趋之。");
    outtextxy(120,80,"蛤说，爱走迷宫的少年，运气不会太差。");
    outtextxy(120,100,"按q初级  按w中级 按e可赛艇（多的走不出）");
    //outtextxy(130,100,"按E可赛艇，（开始游戏）");
    outtextxy(120,120,"注意：由于此随机算法存在漏洞，故终点设在右上角。");
    outtextxy(165,140,"按M安轨（退出）");
    c=getch();
    closegraph();
    return c;
}
