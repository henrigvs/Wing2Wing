#include "header.h"

void initializing_game(void){

    //Initialize speed of elements (for timer fct in init.c)
    
    respaw_speed = 3000;
    ennemies_speed = 200;
    weapons_starship_speed = 100;
    asteroid_speed = 1200;
    asteroid_respaw = 10000;

    score_multiplicator = 1;
    cursor_menu = 1;

    score_saved = false;
    menu_mode = false;
    do_pause = true;
	show_menu = true;
	pixel_mode = false;
	game_over = false;
    menu_score = false;
    menu_rules = false;

    import_score_table(score_table_file);
    map_dimension();
    load_map();
    create_starship();

	printf("Loading...\n");

    ennemies = add_ennemy(0);
    initialize_asteroid();
}




