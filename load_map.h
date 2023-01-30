#ifndef _LOADMAP_H_
#define _LOADMAP_H_

#include <stdbool.h>

#define Square_size 20.0
char **map;                             //Declaration of a 2D array to stock the map
int mX;                                 //Variable to store X Dimension of the map
int mY;                                 //Variable to store Y Dimension of the map

void map_dimension(void);               //This function make the calcuation of map dimension and modify value of variable hereover
void load_map(void);                    //This function load map into an 2D array declared hereover
void show_map(void);                    //Show map in the console (for development)

#endif