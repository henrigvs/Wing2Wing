#include "header.h"

List_asteroid *create_empty_asteroid_list(void){
    return NULL;
}

int is_empty_asteroid_list(List_asteroid *asteroid){
    if(asteroid == NULL)
        return 1;
    
    return 0;
}

Asteroid *create_asteroid(int x, int y){
    srand(time(NULL));
    List_asteroid *asteroid = malloc(sizeof(Asteroid));
    if(!asteroid)
        return NULL;

    //Type of asteroid
    asteroid->type = 1 + rand()%3;
    asteroid->coordinates.x = x;    //X positioning
    asteroid->coordinates.y = y;    //Y positioning

    //Show on the map
    char type_asteroid_char[1];
    sprintf(type_asteroid_char, "%i", asteroid->type); //transform int into char to be included in the map (char array)
    map[asteroid->coordinates.y][asteroid->coordinates.x] = type_asteroid_char[0];
    free(type_asteroid_char[1]);

    asteroid->next = NULL;

    return asteroid;
}

List_asteroid *add_asteroid(int x, int y){
    Asteroid *new_asteroid = create_asteroid(x, y);
    if(is_empty_asteroid_list(asteroid)){
        return new_asteroid;
    }    
    else{
        new_asteroid->next = asteroid;
        return new_asteroid;
    }
}

void initialize_asteroid(void){
    create_empty_asteroid_list();
    asteroid_side = 0;

    asteroid = add_asteroid(10,35);
    sleep(1);
    asteroid = add_asteroid(30,25);
    sleep(1);
    asteroid = add_asteroid(15,15);
    sleep(1);
    asteroid = add_asteroid(23,5);
}

void moving_asteroid(List_asteroid *asteroid){
    int asteroid_position = 0;
    while(!is_empty_asteroid_list(asteroid)){
        if(map[asteroid->coordinates.y+1][asteroid->coordinates.x] == '#'){
            map[asteroid->coordinates.y][asteroid->coordinates.x] = '.';
            free_asteroid(asteroid_position);
            asteroid = asteroid->next;
            return;
        }
        else{
            char type_asteroid_char[1];
            sprintf(type_asteroid_char, "%i", asteroid->type);                  //transform int into char to be included in the map (char array)
            map[asteroid->coordinates.y][asteroid->coordinates.x] = '.';
            asteroid->coordinates.y++;
            map[asteroid->coordinates.y][asteroid->coordinates.x] = type_asteroid_char[0];
            asteroid = asteroid->next;

        }
        asteroid_position++;
    }
}

void handle_star_ship_collision_with_asteroid(Starship *starship, List_asteroid *asteroid){
    if(is_empty_asteroid_list(asteroid))
        return;
    else{
        while(!is_empty_asteroid_list(asteroid)){
            if(abs(starship->coordinates.x - asteroid->coordinates.x) < 2 && abs(starship->coordinates.y - asteroid->coordinates.y) < 2){
                starship->life--;
                    map[starship->coordinates.y][starship->coordinates.x] = '.';
                    starship->coordinates.x = mX / 2; //Set up the position on the middle bottom of the map
                    starship->coordinates.y = mY-3;
            }
            asteroid = asteroid->next;
        }
    }
}

void print_asteroid_list(List_asteroid *asteroid){
    if(is_empty_asteroid_list(asteroid)){
        printf("List of asteroid is empty !\n");
        return;
    }
    else{
        printf("Number of asteroid : %d\n\n", list_asteroid_lenght(asteroid));
        while(!is_empty_asteroid_list(asteroid)){
            printf("Coordinate x : %d\n", asteroid->coordinates.x);
            printf("Coordinate Y : %d\n", asteroid->coordinates.y);
            printf("type : %d\n", asteroid->type);
            printf("Next pointeur : %x\n\n", asteroid->next);
            asteroid = asteroid->next;
        }
    }
}

int list_asteroid_lenght(List_asteroid *asteroid){
    int nbr_elements = 0;
    while(!is_empty_asteroid_list(asteroid)){
        nbr_elements++;
        asteroid = asteroid->next;
    }
    return nbr_elements;
}

Asteroid *free_asteroid(int position){
    Asteroid *previous = asteroid;
    Asteroid *current = asteroid;
    if(is_empty_asteroid_list(asteroid))
        return;
    
    else if(position == 0){
        asteroid = asteroid->next;
        free(current);
        return asteroid;
    }
    for(int i = 0; i<position; i++){
        previous = current;
        current = current->next;
    }
    previous->next = current->next;
    free(current);
    return asteroid;
}

List_asteroid *free_list_asteroids(List_asteroid *asteroid){
    Asteroid *tmp;
    if(is_empty_ennemy_list(asteroid))
        return NULL;

    while (!is_empty_ennemy_list(asteroid))
    {
        tmp = asteroid->next;
        free(asteroid);
        asteroid = tmp;
    }
    return asteroid;
}