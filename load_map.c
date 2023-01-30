#include "header.h"

void map_dimension(void)
{
    char end_line_char = 0;
    mX = 0;
    mY = 0;

    FILE *f = NULL;
    f = fopen(map_file, "r");                   //open map_file (map.map)
    if(f == NULL)
    {
        printf("MAP file is empty!\n");
        exit(0);
    }

    while(end_line_char != '/')                 //Calculation of columns number
    {
        mX++;
        end_line_char = fgetc(f);
    }
    rewind(f);                                  //back to the beginning of map_file

    while(end_line_char != EOF)                 //Calculation of lines number
    {
        end_line_char = fgetc(f);
        if(end_line_char == '/')
        {
            mY++;
        }
    }
    rewind(f);                                  //back to the beginning of map_file
}

void load_map(void)
{

    FILE *f = NULL;
    f = fopen(map_file, "r");                   
    if(f == NULL)
    {
        printf("MAP file is empty!\n");
        exit(0);
    }

    map = malloc(mY * sizeof(char*));           //Memory allocation (malloc) for lines numbers
    if(map == NULL)
    {
        printf("Memory allocation failed");
        exit(1);
    }

    //Transfert MAP into a 2D array
    int i, j;
    for(i=0; i < mY; i++)
    { 
        map[i] = malloc(mX * sizeof(char*));    //memory alloc for columns numbers
        for(j=0; j < mX; j++)
        {
            map[i][j] = fgetc(f);               //browse char by char all characters in the map file
        }
        fgetc(f);
    }

    fclose(f);
    printf("\n");
}

void show_map(void){
    for(int i = 0; i < mY; i++)
    {
        for(int j = 0; j < mX-1; j++)
        {
            printf("%c", map[i][j]);
        }
        printf("\n");
    }
}