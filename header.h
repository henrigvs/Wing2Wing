#ifndef __HEADER_H__
#define __HEADER_H__

#ifdef __APPLE_CC__
#include <OpenGL/OpenGL.h>
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include "unistd.h"

#define window_height 830
#define window_width 780
#include "init_glut.h"
#include "init_game.h"
#include "load_map.h"
#include "draw_screen.h"
#include "ennemies.h"
#include "starship.h"
#include "weapons.h"
#include "weapons_ennemies.h"
#include "asteroid.h"
#include "textures.h"
#define map_file "maps/map.map"                 //Files in wich is the map limit
#define score_table_file "score_table.txt"      //Files in wich the scores are saved

//Declaration of variable of the game
bool do_pause;              // True = game paused | False = game not paused
bool show_menu;             // True = main menu | False = Not main menu
bool pixel_mode;            // True = Pixel mode activated | False = Pixel mode desactivated
bool game_over;             // True = game over | False = game not over (it remains lives)
float score_multiplicator;  // Used to multiply score 
float final_score;          // Used to show final score (multiplied)
int cursor_menu;            // Used to navigate into main menu
bool score_saved;           // Used to check if score has been saved
bool menu_mode;             // TRUE =  "Mode menu" | FALSE = not "Mode menu"
bool menu_score;            // TRUE =  "score menu" | FALSE = not "score menu"
bool menu_rules;            // TRUE =  "Rules menu" | FALSE = not "Rules menu"

int respaw_speed;           //Variables used for speed frequencies
int ennemies_speed;
int weapons_starship_speed;
int asteroid_speed;
int asteroid_respaw;


#endif