#ifndef __STARSHIP_H__
#define __STARSHIP_H__

//Starship structure
typedef struct Starship                     //Defining the structure of a starship
{
    char *name;                             //String of char for name
    Coordinates coordinates;                //Struct of coordinates
    int bullets_fired;                      //Used to count the number of bullets fired
    int hard_waepons;                       //Used to count the number of ammunation fired for secondary waepon (not implemanted)
    float score;                            //Used to count the score
    int life;                               //Used to count the remaining lives
    int level;                              //Used to determine the level
    int ennmies_killed;                     //Used to count the number of ennemies killed
} Starship;

Starship *starship;                         //Declaration of the pointer to starship

Starship *create_starship(void);            //Function that creates starship          
void moving_starship_left(void);            //Functions handle the moving of asteroid
void moving_starship_right(void);
void moving_starship_up(void);
void moving_starship_down(void);


typedef struct Score_table                  //Score table structure
{
    char name[16];
    int score;
} Score_table;

Score_table *score_table;

void save_score(char *string, Starship *starship);  //Function to save the score (at game over)
int sizeof_score_table_file(char *string);          //Function to determine how much score are saved in the score file
void import_score_table(char *string);              //Function to import the score table from score file

#endif