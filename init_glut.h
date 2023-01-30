#ifndef __INIT_GLUT__H
#define __INIT_GLUT__H

//Protoypes of function init.c
void initRendering();
void handleResize(int width,int heigth);
void changeSize(int width, int height);
void Display();
void process_keys(unsigned char key, int x, int y);     //Function handles keyboard actions
void timing_update(void);                               //Global Function handle timing (next functions)
void update_ennemies(int value);                        //Function timer handles the moving frequency of enemies
void update_weapons_moving(int value);                  //Function timer handles the moving frequency bullets of starship
void update_weapons_ennemies(int value);                //Function timer handles the moving frequency bullets of ennemies
void update_respaw(int value);                          //Function timer handles the respaw frequency of ennemies
void update_asteroid_moving(int value);                 //Function timer handles the moving frequency of asteroids
void new_asteroid(int value);                           //Function timer handles the respaw frequency of asteroids

void update_level_player(void);                         //Function that update level in function of score
void game_over_check(void);                             //Function (constant refresh) to check if game-over
void my_mouse(int btn, int state, int x, int y);        //Function used to calcul coordinates during development and handles mouse actions

// FUNCTION TO KNOW ON WHICH SCREEN WE'RE LOCATED
bool located_in_main_menu(void);                        //Functions used to locate on wich menu's (screen) we're
bool located_in_mode_menu(void);
bool located_in_rules_menu(void);
bool located_in_score_menu(void);
bool located_in_pause_menu(void);
bool located_in_the_game(void);
bool located_in_game_over_menu(void);

void go_to_main_menu(void);                             //Functions used to navigate between menu's (screen)
void go_to_game(void);
void go_to_mode_menu(void);
void got_to_score_menu(void);

void switch_pixel_mode(void);                           //Function used to switch between PIXEL MODE & NORMAL MODE
void switch_cursor(unsigned char key);                  //Function used to switch cursor in menu's

void init_a_new_game(void);                             //Function used to create a new game after a game over

#endif