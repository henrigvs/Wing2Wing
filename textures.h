#ifndef _TEXTURES_H_
#define _TEXTURES_H_

//Functions for creation of textures of the main menu
void tex_main_menu_play(void);                                                                       
void tex_main_menu_mode(void);
void tex_main_menu_rules(void);
void tex_main_menu_score(void);
void tex_main_menu_quit(void);

//Function for the creation of textures of sub-menu
void tex_main_sub_menu_mode_ON(void);
void tex_main_sub_menu_mode_OFF(void);
void tex_main_sub_menu_score(void);
void tex_main_sub_menu_rules(void);
void tex_sub_menu_game_over_retry(void);
void tex_sub_menu_game_over_quit(void);

//Function for creation of textures of the pause menu
void tex_pause_MENU_OFF(void);
void tex_pause_MENU_ON(void);
void tex_pause_RESUME_OFF(void);
void tex_pause_RESUME_ON(void);

//Functions for creation of textures of asteroids
void tex_asteroid_1(int j, int i);                          //Function displying asteroid (type 1) in glut window | takes coordinates as arg
void tex_asteroid_2(int j, int i);                          //Function displying asteroid (type 2) in glut window | takes coordinates as arg
void tex_asteroid_3(int j, int i);                          //Function displying asteroid (type 3) in glut window | takes coordinates as arg

//Functions for creation of textures of starship and ennemies
void tex_starship(int j, int i);                            //Function displaying player in the glut window | takes coordinates as arg
void tex_enemmies(int j, int i);                            //Function displaying ennemies in the glut window | takes coordinates as arg

//Function for creation of the background
void draw_star_bg(float size, float x, float y);            //Function that creates the little stars on the background
void Display_bg(void);                                      //Function displaying background

//Functions for creation of textures of waepons
void tex_starship_bullets(int j, int i);                    //Function displaying starship (player) bullet in glut window | takes coordinates as arg
void tex_ennemies_bullets(int j, int i);                    //Function displaying ennemies (player) red lasers in glut window | takes coordinates as arg              


#endif