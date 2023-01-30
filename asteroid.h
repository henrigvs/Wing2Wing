#ifndef __ASTEROID_H__
#define __ASTEROID_H__

// Asteroid
typedef struct List_asteroid                                    //Defining the structure of an asteroid
{
    Coordinates coordinates;
    int type; //type 1, 2 ou 3
    struct List_asteroid *next;                                 //Pointer to the next asteroid in the chained list
    
}List_asteroid, Asteroid;

List_asteroid *asteroid;                                        //First pointer at beginning of the chained list of asteroids
int asteroid_side;                                              //0 = left | 1 = right (use the reappear alternatively on left or right side of board)



List_asteroid *create_empty_asteroid_list(void);                //Create one empty asteroid list (chained list)
int is_empty_asteroid_list(List_asteroid *li);                  //Check if list of asteroid is empty
Asteroid *create_asteroid(int x, int y);                        //Function handles the creation of parameters of a new asteroid => Return a new element the asteroid list
List_asteroid *add_asteroid(int x, int y);                      //Add an asteroid in the chained list when it's called
void initialize_asteroid(void);                                 //Initialize 4 first asteroids at beginning of the game

void moving_asteroid(List_asteroid *li);                        //Handle the moving on asteroid during the game (scrolling)

void print_asteroid_list(List_asteroid *li);                    //Print asteroid list into console
int list_asteroid_lenght(List_asteroid *asteroid);              //return the number of asteroids ongoing (in the list)
Asteroid *free_asteroid(int position);                          //free an asteroid in the list when it disappears (argument is the position in the list)
List_asteroid *free_list_asteroids(List_asteroid *asteroid);    //free all the list of asteroid

void handle_star_ship_collision_with_asteroid(Starship *starship, List_asteroid *asteroid); //handle collision between starship and asteroid (reset position of starship and decrease the lives counter)

#endif