#include "header.h"
#include "string.h"

Starship *create_starship(void){
    starship = malloc(sizeof(Starship));


    char *new_name;                           
    printf("Introduce your name : ");
    scanf("%s", &starship->name);

    starship->score = 0.0;                                          //Initiate  the score at 0
    starship->life = 3;                                             //          the number of lives
    starship->level = 1;                                            //          the level
    starship->bullets_fired = 0;                                    //          the number of   bullets fired
    starship->ennmies_killed = 0;                                   //                          ennemies killed

    starship->coordinates.x = mX / 2;                               //Set up the X position on center of the map
    starship->coordinates.y = mY-2;                                 //Set up the Y position at the bottom of the map

    map[starship->coordinates.y][starship->coordinates.x] = 'X';    //Make appear the starship on the map

    return starship;
}

void moving_starship_left(void){
    if(starship->coordinates.x > 1){
        map[starship->coordinates.y][starship->coordinates.x] = '.';
        starship->coordinates.x--;
        }
    map[starship->coordinates.y][starship->coordinates.x] = 'X';
}

void moving_starship_right(void){
    if(starship->coordinates.x < mX-3){
        map[starship->coordinates.y][starship->coordinates.x] = '.';
        starship->coordinates.x++;
        }
    map[starship->coordinates.y][starship->coordinates.x] = 'X';
}

void moving_starship_up(void){
    if(starship->coordinates.y > 1){
        map[starship->coordinates.y][starship->coordinates.x] = '.';
        starship->coordinates.y--;
    }
    map[starship->coordinates.y][starship->coordinates.x] = 'X';
}

void moving_starship_down(void){
    if(starship->coordinates.y < mY-2){
        map[starship->coordinates.y][starship->coordinates.x] = '.';
        starship->coordinates.y++;
    }
    map[starship->coordinates.y][starship->coordinates.x] = 'X';
}

void save_score(char *string, Starship *starship){
    if(score_saved){
        return;
    }
    else{
        FILE *f;
        f = fopen(string, "a");
        if(f == NULL){
            printf("Problem to write scores data file !\n");
            exit(0);
        }
        else{
            fprintf(f, "%s %.0f\n", &starship->name, starship->score);
        }
        score_saved = true;
        fclose(f);
    }
}

int sizeof_score_table_file(char *string){
    int size = 0;
    char name[16];
    int score;
    FILE *f;
    f = fopen(string, "r");
    if(f == NULL){
        printf("Score data file is empty\n");
        return 0;
    }
    else{
        fscanf(f, "%s%d", name, &score);
        while(!feof(f)){
            fscanf(f, "%s%d", name, &score);
            size++;
        }
    }
    fclose(f);
    return size;
}

void import_score_table(char *string){
    int size = sizeof_score_table_file(string);
    
    FILE *f;
    f = fopen(string, "r");
    if(f == NULL){
        printf("Score data file is empty\n");
        exit(0);
    }
    else{
        score_table = malloc((size+1)*sizeof(Score_table));
        for(int i = 0; i<size;i++){
            fscanf(f, "%s %d" ,score_table[i].name, &score_table[i].score);
        }
    }
    fclose(f);

    for(int i = 0; i<size; i++){
        for(int j = 0; j<size; j++){
            if(score_table[j].score < score_table[j+1].score){
                Score_table temp = score_table[j];
                score_table[j] = score_table[j+1];
                score_table[j+1] = temp;
            }
        }
    }
}