#include "Menu.h"
#include "Maze.h"
#define BEGINNER_SCALE 30
#define BEGINNER_SQUARE 30
#define MODERATE_SCALE 16
#define MODERATE_SQUARE 60
#define EXCITED_SCALE 8
#define EXCITED_HEIGHT 100
#define EXCITED_WIDTH 160
/*Version & Feature
1.0 *The menu which could just Call Game Start,Quit game.
    *The maze game,could quit,static size(50*50).
*/
int main(void)
{
    srand((unsigned)time(NULL));
    char c;
    c=(char)Menu();
    while(c!='m')
    {
        switch(c)
        {
            case 'q':StartGame(BEGINNER_SQUARE,BEGINNER_SQUARE,BEGINNER_SCALE);break;
            case 'w':StartGame(MODERATE_SQUARE,MODERATE_SQUARE,MODERATE_SCALE);break;
            case 'e':StartGame(EXCITED_HEIGHT,EXCITED_WIDTH,EXCITED_SCALE);break;
        }
        c=(char)Menu();
    }
    return 0;
}
