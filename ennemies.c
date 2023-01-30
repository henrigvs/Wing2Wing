#include "header.h"

List_ennemies *create_empty_ennemy_list(void){
    return NULL;
}

int is_empty_ennemy_list(List_ennemies *ennemies){
    return ennemies == NULL;
}

Ennemy *create_ennemy(void){
    List_ennemies *ennemy = malloc(sizeof(Ennemy));
    if(!ennemy)
        return NULL;
 
    srand(time(NULL));
    int x, y, state, step_to_do;
    do{
            x = 2 + rand()%mX-3;
            y = 1;
            state = 1 + rand()%20;
            step_to_do = 1+rand()%30;
    } while(map[y][x] != '.');

    ennemy->bullets_fired = 0;
    ennemy->life = 3;                       // used to set lifes number of ennemy
    ennemy->coordinates.x = x;              // used to set x coord of ennemy
    ennemy->coordinates.y = y;              // used to set y coord of ennemy
    ennemy->nbr_steps_to_do = step_to_do;   // used to set of much step must be done before change direction (right or left)
    ennemy->nbr_steps_done = 0;             // used to count how much step are done before change direction (right or left)
    ennemy->state = state;                  // used to determine if ennemy will go to right or left (even number => left | odd number => right)
    ennemy->next = NULL;                    // used to initiate pointer to NULL
    map[y][x] = '@';                        // used to make appear the ennemy on map

    return ennemy;
}

List_ennemies *add_ennemy(int nbr){
    Ennemy *new_ennemy = create_ennemy();
    Ennemy *current = ennemies;
    Ennemy *previous = ennemies;
    if(is_empty_ennemy_list(ennemies)){
        return new_ennemy;
    }
    
    if(nbr == 0){
        new_ennemy->next = ennemies;
        return new_ennemy;
    }

    for(int i = 0; i<nbr; i++){
        previous = current;
        current = current->next;
    }
    previous->next = new_ennemy;
    new_ennemy->next = current;
    return ennemies;
}

void print_list_ennemies(List_ennemies *ennemies){
    if(is_empty_ennemy_list(ennemies))
        printf("Ennemies list is empty!\n");

    while(!is_empty_ennemy_list(ennemies))
    {
        printf("[%d]", ennemies->bullets_fired);
        printf("[%d]", ennemies-> life);
        printf("[%d]", ennemies-> state);
        printf("[%d]", ennemies->coordinates.x);
        printf("[%d]", ennemies->coordinates.y);
        printf("[%d]", ennemies->nbr_steps_to_do);
        printf("[%d]", ennemies->nbr_steps_done);
        ennemies = ennemies->next;
        printf("\n");
    }
    printf("\n");
}

void moving_enemies(List_ennemies *ennemies){

    srand(time(NULL));
    int ennemy_position = 0;                                                //Used as a marker for positioning in the chained list of ennemies

    while(!is_empty_ennemy_list(ennemies)){                                 //Browse the chained list of ennemies

        if(map[ennemies->coordinates.y+1][ennemies->coordinates.x] == '#'){ //test the low border of map represented by a #
            map[ennemies->coordinates.y][ennemies->coordinates.x] = '.';    //If ennemy touch border, it disappears and memory element is released
            free_ennemy(ennemy_position);
            return;                                                         //to break function to avoid beug if two ennemies touch border in same time
        }

        
        
        else if(ennemies->nbr_steps_done < ennemies->nbr_steps_to_do){      //First of all ! test if it remains step to do before change direction (right/left)      

            if(map[ennemies->coordinates.y+2][ennemies->coordinates.x] == '1' || map[ennemies->coordinates.y+2][ennemies->coordinates.x] == '2' ||
            map[ennemies->coordinates.y+2][ennemies->coordinates.x] == '3'){    //test if there is no border or asteroid in front of (to esquive)
                if(ennemies->state%2 == 0){
                    map[ennemies->coordinates.y][ennemies->coordinates.x] = '.';
                    ennemies->coordinates.x--;                               
                    ennemies->coordinates.x--;
                    map[ennemies->coordinates.y][ennemies->coordinates.x] = '@';
                }
                else{
                    map[ennemies->coordinates.y][ennemies->coordinates.x] = '.';
                    ennemies->coordinates.x--;
                    ennemies->coordinates.x--;
                    map[ennemies->coordinates.y][ennemies->coordinates.x] = '@';
                }
            }            
            else{
                map[ennemies->coordinates.y][ennemies->coordinates.x] = '.';    //Move forward step by step
                ennemies->coordinates.y++;
                map[ennemies->coordinates.y][ennemies->coordinates.x] = '@';
            }
            ennemies->nbr_steps_done++;
        }

       
        else{                                           //If it doesn't remain step to do => one step right or left (if step to do = step done)

            ennemies->nbr_steps_to_do = 1 + rand()%30;  //Reset step to do (random number between 1-30) 
            ennemies->nbr_steps_done = 0;               //reset step done at 0
            
            if(ennemies->state%2 == 0){                 //if state of the ennemy is even

                //Test if there is a map border or asteroid near the ennemy (if yes => must change state to switch direction)
                if(map[ennemies->coordinates.y][ennemies->coordinates.x-1] == '#' || map[ennemies->coordinates.y][ennemies->coordinates.x+1] == '1'
                || map[ennemies->coordinates.y][ennemies->coordinates.x-1] == '2' || map[ennemies->coordinates.y][ennemies->coordinates.x-1] == '3'){
                    while(ennemies->state%2 == 0){
                        ennemies->state = 1 + rand()%20;
                    }
                }
                //If there is no border or asteroid near ennemy => go one step lower on the map
                else{
                    map[ennemies->coordinates.y][ennemies->coordinates.x] = '.';
                    ennemies->coordinates.x--;
                    map[ennemies->coordinates.y][ennemies->coordinates.x] = '@';
                    ennemies->state = 1 + rand()%20;
                }
            }

            else if(ennemies->state%2 == 1){            //if state of the ennemy is odd

                //Test if there is a map border or asteroid near the ennemy (if yes => must change state to switch direction)
                if(map[ennemies->coordinates.y][ennemies->coordinates.x+1] == '#' || map[ennemies->coordinates.y][ennemies->coordinates.x+1] == '5' 
                || map[ennemies->coordinates.y][ennemies->coordinates.x-1] == '5'){
                    while(ennemies->state%2 == 1){
                        ennemies->state = 1 + rand()%20;
                    }
                }
                //If there is no border or asteroid near ennemy => go one step lower on the map
                else{
                    map[ennemies->coordinates.y][ennemies->coordinates.x] = '.';
                    ennemies->coordinates.x++;
                    map[ennemies->coordinates.y][ennemies->coordinates.x] = '@';
                    ennemies->state = 1 + rand()%20;
                }
            }
        }
        ennemy_position++; //increase position before to go to next element in ennemy chained list
        ennemies = ennemies->next; // Go to next element in the chained list
    }  
}

Ennemy *free_ennemy(int position){
    Ennemy *previous = ennemies;
    Ennemy *current = ennemies;
    if(is_empty_ennemy_list(ennemies))
        return NULL;
    
    else if(position == 0){
        ennemies = ennemies->next;
        free(current);
        return ennemies;
    }
    for(int i = 0; i<position; i++){
        previous = current;
        current = current->next;
    }
    previous->next = current->next;
    free(current);
    return ennemies;
}

List_ennemies *free_list_ennemies(List_ennemies *ennemies){
    Ennemy *tmp;
    if(is_empty_ennemy_list(ennemies))
        return NULL;

    while (!is_empty_ennemy_list(ennemies))
    {
        tmp = ennemies->next;
        free(ennemies);
        ennemies = tmp;
    }
    return ennemies;
}

int list_ennemies_lenght(List_ennemies *li){
    int nbr_elements = 0;
    while(!is_empty_ennemy_list(li)){
        nbr_elements++;
        li = li->next;
    }
    return nbr_elements;
}
