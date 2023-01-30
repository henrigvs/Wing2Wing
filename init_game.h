#ifndef __INITGAME_H__
#define __INITGAME_H__

typedef struct Coordinates          //Defining the structure of coordinates => X and Y axes
{
    int x;
    int y;
} Coordinates;

//Starship
void initializing_game(void);       //Function called to initialize element of the game (starship, ennemies, empty bullet list, speed, cursor menu, score multiplicator)






#endif