#ifndef __ENNEMIES_H__
#define __ENNEMIES_H__


//ennemies
typedef struct Ennemy{
    int bullets_fired;              //nbr of bullet fired
    Coordinates coordinates;        //Coordinates on the map
    int life;                       //Nbr of life of the ennemy
    int nbr_steps_to_do;            //correspond at nbr of steps before change direction
    int nbr_steps_done;             //correspond at nbr of steps done for change direction
    int state;                      //in witch direction ennemy will move next : 1 = left 2 = right
    struct Ennemies *next;          //Pointer to next ennemy in the list
    
}List_ennemies, Ennemy;

List_ennemies *ennemies;            //Create the first pointer to beginning of the ennemies chained list

Ennemy *create_empty_ennemy_list(void);                         // Create an empty ennemies chained list
int is_empty_ennemy_list(List_ennemies *ennemies);              // Check if ennemies list empty (return 1 = True, return 0 = False)
List_ennemies *create_ennemy(void);                             // Function that set up parameters of an ennemy (life, state, coordinates, etc ...)
List_ennemies *add_ennemy(int nbr);                             //function who add an ennemy into chained list when it's called | return pointeur to the first element of the list
int list_ennemies_lenght(List_ennemies *li);                    //function returning the number of ennemies ongoing

void moving_enemies(List_ennemies *ennemies);                   //function that handles the moving of ennemies during the game

void print_list_ennemies(List_ennemies *ennemies);              //Function showing list of ennemies into console
Ennemy *free_ennemy(int position);                              //Function used to release element in the memory (identified by its position in the list) | return pointers of the first element in the list
List_ennemies *free_list_ennemies(List_ennemies *ennemies);     //Function to release (free) all chained list of ennemies
int list_ennemies_lenght(List_ennemies *li);                    //return the number of elements of ennemies chained list

#endif