#include "header.h"

List_bullet *create_empty_bullet_list(void){
    return NULL;
}

int is_empty_bullet_list(List_bullet *li){
    if(li == NULL)
        return 1;
    
    return 0;
}

Bullet *create_bullet(void){
    List_bullet *bullet = malloc(sizeof(Bullet));
    if(!bullet)
        return NULL;

    bullet->coordinates.x = starship->coordinates.x;            //initiate position at the same position than starship on X axis
    bullet->coordinates.y = starship->coordinates.y-1;          //initiate position at the position Y-1 (one position higher) of starship
    map[bullet->coordinates.y][bullet->coordinates.x] = '|';    //identify the bullet on the map
    bullet->next = NULL;

    return bullet;
}

int list_bullet_lenght(List_bullet *li){
    int nbr_elements = 0;
    while(!is_empty_bullet_list(li)){
        nbr_elements++;
        li = li->next;
    }
    return nbr_elements;
}

List_bullet *add_bullet(void){
    Bullet *new_bullet = create_bullet();                       //Call the fonction create_bullet to set initial parameters
    Bullet *current = bullet;
    Bullet *previous = bullet;
    if(is_empty_bullet_list(bullet))
        return new_bullet;                                      //If it's the first bullet, we just return the created bullet
    
    else{
        new_bullet->next = bullet;
        return new_bullet;                                      //If it's not the first bullet, we add the bullet created in the front of chained list of bullet
    }
}

void print_bullet_list(List_bullet *li){
    if(is_empty_bullet_list(li))
        printf("Bullet list is empty!\n");

    while(!is_empty_bullet_list(li))
    {
        printf("[%d]", li->coordinates.x);
        printf("[%d]", li->coordinates.y);
        printf("[%d]", li->next);
        li = li->next;
        printf("\n");
    }
    printf("\n");
}

void moving_bullet(List_bullet *bullet){
    if(is_empty_bullet_list(bullet)){
        return;
    }
    int position_bullet_in_the_list = 0;                        //use as a marker in the bullet chained list 
                                                                //because it's not necessary the first bullet in the list that will target ennemy

    int bullet_qty = list_bullet_lenght(bullet);
    for(int i = 0; i<bullet_qty; i++){                          //Browse all elements in the list one by one.
        
        
        if(map[bullet->coordinates.y - 1][bullet->coordinates.x] == '#' || map[bullet->coordinates.y - 2][bullet->coordinates.x] == '1' ||  //If bullet position is near a border or an asteroid (type 1, 2 or 3), we call the function hit_border to free memory
        map[bullet->coordinates.y - 2][bullet->coordinates.x] == '2' || map[bullet->coordinates.y - 2][bullet->coordinates.x] == '3')
        {
            map[bullet->coordinates.y][bullet->coordinates.x] = '.';
            free_bullet(position_bullet_in_the_list);
            return;
        }
        else{
            bullet->coordinates.y--;                            //Move bullet step by step to the high border of the map
            map[bullet->coordinates.y][bullet->coordinates.x] = '|';
            map[bullet->coordinates.y+1][bullet->coordinates.x] = '.';
        }
        bullet = bullet->next;
        position_bullet_in_the_list++;
    }
}

List_bullet *free_bullet(int position){
    Bullet *previous = bullet;
    Bullet *current = bullet;
    if(is_empty_bullet_list(bullet))
        return NULL;                  

    else if(position == 0){                                      //If the element to release is the first (just to move pointer to 2nd and free 1st)
        bullet = bullet->next;
        free(current);
        return bullet;                 
    }
    for(int i = 0; i<position; i++){
        previous = current;
        current = current->next;                                //If it's not the first => browse the list and positioning the pointeur to concerned element (position)
    }
    previous->next = current->next;     //chain previous and next element
    free(current);                      //release concerned element
    return bullet;
}

List_bullet *free_bullet_list(List_bullet *li){
    Bullet *tmp;
    if(is_empty_bullet_list(li))
        return NULL;

    while (!is_empty_bullet_list(li))
    {
        tmp = li->next;
        free(li);
        li = tmp;
    }
    return li;
}

//===========================================================================================================

void handle_kill_ennemy(List_bullet *bullet, List_ennemies *ennemies){
    if((is_empty_ennemy_list(ennemies)) || (is_empty_bullet_list(bullet))){
        return;
    }
    
    int ennemy_position = 0; //used as marker of the position of concerned ennemy in chained list
    int bullet_position = 0; //idem but for bullets list

    List_ennemies *first_cell_list_ennemies = ennemies;                 //We save the pointer of first element of chained list of ennemies

    while(!is_empty_bullet_list(bullet)){                               //Browse the bullets list (just once)
        while(!is_empty_ennemy_list(ennemies)){                         //Browse the ennemies list (as much as there are elements in bullet list)

            if((abs(ennemies->coordinates.y - bullet->coordinates.y) < 2) && (abs(ennemies->coordinates.x - bullet->coordinates.x)) < 2){
                map[ennemies->coordinates.y][ennemies->coordinates.x] = '.';
                map[bullet->coordinates.y][bullet->coordinates.x] = '.';
                free_bullet(bullet_position);
                free_ennemy(ennemy_position);
                starship->score = starship->score+100.00;
                starship->ennmies_killed++;
            }
            ennemy_position++;
            ennemies = ennemies->next;
        }
        bullet_position++;
        bullet = bullet->next;                                          //Go to next element in bullet list

        ennemies = first_cell_list_ennemies;                            //repositioning the pointeur to the beginning of ennemies list after each pass in second loop "while"
        ennemy_position = 0;                                            //reset the identifier of ennemy after each pass in second loop "while"
    }
}