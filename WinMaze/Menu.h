#include <graphics.h>
#define COLUMN 200
#define ROW 500
int Menu()
{
    int c;
    cleardevice();
    initgraph(ROW,COLUMN);
    outtextxy(120,60,"�������������ԣ������������֮��");
    outtextxy(120,80,"��˵�������Թ������꣬��������̫�");
    outtextxy(120,100,"��q����  ��w�м� ��e����ͧ������߲�����");
    //outtextxy(130,100,"��E����ͧ������ʼ��Ϸ��");
    outtextxy(120,120,"ע�⣺���ڴ�����㷨����©�������յ��������Ͻǡ�");
    outtextxy(165,140,"��M���죨�˳���");
    c=getch();
    closegraph();
    return c;
}
