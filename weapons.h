#ifndef __WAEPONS_H__
#define __WAEPONS_H__

// Starship weapons
typedef struct List_bullet
{
    Coordinates coordinates;                            //Used to locate bullets on map following their coordinates                      
    int bullet_nbr;
    struct List_bullet *next;                           //Pointer to next bullet fired
    
}List_bullet, Bullet;

List_bullet *bullet;                                    //Declaration of a pointer to first element of chained list of bullets

List_bullet *create_empty_bullet_list(void);            //Create one empty bullet list (chained list)
int is_empty_bullet_list(List_bullet *li);              //Check if list of bullet is empty
Bullet *create_bullet(void);                            //Function handles the creation of parameters of a new bullet => Return a new element in bullet list
int list_bullet_lenght(List_bullet *li);                //return the number of element (bullet) ongoing
List_bullet *add_bullet(void);                          //Function adding a new bullet in the list when it's called
void print_bullet_list(List_bullet *li);                //function printing the bullet list in the console (not used in glut)
void moving_bullet(List_bullet *bullet);                //Function that handles the moving of bullet on the map
List_bullet *free_bullet(int position);                 //Just a function that will free memory of an element in the bullet chained list (identify by its position => parameter)
                                                        //It returns the bullet list updated (pointer on first element)
List_bullet *free_bullet_list(List_bullet *li);         //Free the complete chained list of bullets

void handle_kill_ennemy(List_bullet *bullet, List_ennemies *ennemies);  //We take in argument, chained list of bullets and chained list of ennemies
                                                                        //This function handles the impact between bullets and ennemies

#endif