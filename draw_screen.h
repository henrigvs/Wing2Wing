#ifndef _DRAW_MAP_H_
#define _DRAW_MAP_H_

#include "load_map.h"
                                        
                       

void renderBitmapString(float x, float y, float z, void *font, char *string);   //String rendering
void display_text(char *string, int x, int y, int z);                           //String displaying => Arguments : String + coordinates

void Display_main_menu(void);                                                   //Function displaying main menu
void Display_score_menu(void);                                                  //Function displaying score menu
void Display_pause_menu(void);                                                  //Function displaying pause menu
void Display_game_over_menu(void);                                              //Function displaying game over menu
void Display_life_and_score(void);                                              //Function displaying information in the bottom of game board (lifes and score)
void Display_game_play(void);                                                   //Global function displaying all elements during the game

void draw_map(void);                                                            //Function that displays all elements


#endif
