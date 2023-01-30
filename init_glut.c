#include "header.h"

void initRendering()
{
	glEnable(GL_DEPTH_TEST);
}

void handleResize(int width,int heigth)
{
	glViewport(0, 0, window_width, window_height+100);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, window_width, window_height, 0);
    glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void Display()
{
	glClearColor(0.0f,0.0f,0.0f,0.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    draw_map();                                                         //Display map (and elements on the map)
    handle_kill_ennemy(bullet, ennemies);                               //Handle impact between starship (player) bullets and ennemies
    handle_star_ship_collision_with_asteroid(starship, asteroid);       //Handle collision between starship and asteroid
    update_level_player();                                              //update of player level depending score
    game_over_check();                                                  //Use to generate score after a game
    
    glFlush();
}

void my_mouse(int btn, int state, int x, int y){               
    /*if(btn == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
        printf("V %d.0 %d.0 0.0\n", x, y);*/
    
    if(btn == GLUT_LEFT_BUTTON && state == GLUT_DOWN){
        if(located_in_main_menu()){
            if(x > 425 && x < 745 && y > 165 && y < 240){
                go_to_game();
                cursor_menu = 1;
            }
            else if(x > 425 && x < 745 && y > 280 && y < 355){
                go_to_mode_menu();
                cursor_menu = 2;
            }
            else if(x > 425 && x < 745 && y > 390 && y < 455){
                go_to_rules_menu();
                cursor_menu = 3;
            }
            else if(x > 425 && x < 745 && y > 500 && y < 575){
                got_to_score_menu();
                cursor_menu = 4;
            }
            else if(x > 425 && x < 745 && y > 610 && y < 685){
                exit(0);
            }
        }
        else if(located_in_mode_menu()){
            if(x > 215 && x < 550 && y > 480 && y < 560)
                switch_pixel_mode();
            else if(x > 215 && x < 550 && y > 480 && y < 560)
                switch_pixel_mode();
            else if(x > 86 && x < 700 && y > 640 && y < 690)
                go_to_main_menu();
        }
        else if(located_in_pause_menu()){
            if(x > 30 && x < 350 && y > 575 && y < 650)
                go_to_game();
            else if(x > 435 && x < 750 && y > 575 && y < 650)
                go_to_main_menu();
        }
        else if(located_in_score_menu()){
            if(x > 215 && x < 565 && y > 570 && y < 640)
                go_to_main_menu();
        }
        else if(located_in_rules_menu()){
            if(x > 220 && x < 575 && y > 635 && y < 710)
                go_to_main_menu();
        }
        else if(located_in_game_over_menu()){
            if(x > 35 && x < 365 && y > 605 && y < 680){
                go_to_main_menu();
                init_a_new_game();
            }
            else if(x > 410 && x < 750 && y > 605 && y < 680){
                exit(0);
            }
        }
    }
}

void process_keys(unsigned char key, int x, int y){

    switch (key)
        {
            case 'z':{ //moving up !
                if(located_in_the_game())
                    moving_starship_up();
                else{
                    switch_cursor(key);
                }
                break;
            }
            case 's':{ //moving down !
                if(located_in_the_game()){
                    moving_starship_down();
                }
                else{
                    switch_cursor(key);
                }
                break;
            }
            case 'q':{ //moving left !
                if(!do_pause){
                    moving_starship_left();
                }
                else{
                    switch_cursor(key);
                }
                break;
            }
            case 'd':{ //moving right !
                if(!do_pause){
                    moving_starship_right();
                }
                else{
                    switch_cursor(key);
                }
                break;
            }
            case ' ':{ //fire !!!
                if(located_in_the_game()){
                    bullet = add_bullet();
                    starship->bullets_fired++;
                }
                break;
            }
            case 'p':{
                if(located_in_the_game()){              //if we're playing and we wanna pause
                    do_pause = true;
                }
                else if(located_in_pause_menu()){       //if we're in the pause menu and we wanna resume the game
                    do_pause = false;
                }
                break;
            }
            case 'm':{
                if(located_in_pause_menu()){            //if we're in "pause" menu and go back to "main" menu
                    go_to_main_menu();
                }
                else if(located_in_mode_menu()){        //if we're in "mode" menu and go back to "main" menu
                   go_to_main_menu();
                }
                break;
            }
            case 'x':{
                if(located_in_pause_menu()){          //In the "pause" menu to swith to "pixel" mode
                    switch_pixel_mode();
                }
                break;
            }
            case 13:{
                if(located_in_main_menu() && cursor_menu == 1){         //if we're in the "main" menu and we wanna play
                    go_to_game();
                }
                else if(located_in_main_menu() && cursor_menu == 2){    //if we're in the "main" menu and go to "mode" menu
                    go_to_mode_menu();
                }
                else if(located_in_main_menu() && cursor_menu == 3){    //if we're in the "main" menu and go to "mode" menu
                    go_to_rules_menu();
                }
                else if(located_in_main_menu() && cursor_menu == 4){    //if we're in the "main" menu and go to "score" menu
                    got_to_score_menu();
                }
                else if(located_in_main_menu() && cursor_menu == 5){    //if we're in the "main" menu and "quit" the game
                    exit(0);
                }
                else if(located_in_mode_menu() && cursor_menu == 1){    //if w're in the "mode" menu and swich to pixel mode
                    switch_pixel_mode();
                }
                else if(located_in_mode_menu() && cursor_menu == 2){
                    switch_pixel_mode();
                }
                else if(located_in_pause_menu() && cursor_menu == 1){
                    go_to_game();
                }
                else if(located_in_pause_menu() && cursor_menu == 2){
                    go_to_main_menu();
                }
                else if(located_in_score_menu())
                    go_to_main_menu();

                else if(located_in_rules_menu())
                    go_to_main_menu();

                else if(located_in_game_over_menu()){
                    if(cursor_menu == 1){
                        go_to_main_menu();
                        init_a_new_game();
                    }
                    else if(cursor_menu == 2){
                        exit(0);
                    }
                }
                break;
            }
            case 27:{
                if(located_in_main_menu())
                    exit(0);
                break;
            }
            default :
                break;
        }
        map[starship->coordinates.y][starship->coordinates.x] = 'X';
}

//=============FUNCTION FOR THE TIMING OF MOVING ELEMENTS=========================

void timing_update(void){
    glutTimerFunc(ennemies_speed, update_ennemies, 0);
	glutTimerFunc(weapons_starship_speed, update_weapons_moving, 0);
    glutTimerFunc(respaw_speed, update_respaw, 0);
    glutTimerFunc(asteroid_speed, update_asteroid_moving, 0);
    glutTimerFunc(asteroid_respaw, new_asteroid, 0);
}

void update_ennemies(int value){
    if(!do_pause){
        moving_enemies(ennemies);
    }
    glutPostRedisplay();
    glutTimerFunc(ennemies_speed, update_ennemies, 0);
}

void update_respaw(int value){
    if(!do_pause){
        ennemies = add_ennemy(0);
    }
    glutPostRedisplay();
    glutTimerFunc(respaw_speed, update_respaw, 0);
}

void update_weapons_moving(int value){
    if(!do_pause){
        moving_bullet(bullet);
        //Ennemies weapons to add
    }
    glutPostRedisplay();
    glutTimerFunc(weapons_starship_speed, update_weapons_moving, 0);
}

void update_asteroid_moving(int value){
    if(!do_pause){
        moving_asteroid(asteroid);
    }
    glutPostRedisplay();
    glutTimerFunc(asteroid_speed, update_asteroid_moving, 0);
}

void new_asteroid(int value){
    srand(time(NULL));
    if(!do_pause){
        if(asteroid_side == 0){
            asteroid = add_asteroid(5 + rand()%15, 2);
            asteroid_side = 1;
        }
        else if(asteroid_side == 1){
            asteroid = add_asteroid(25 + rand()%35, 2);
            asteroid_side = 0;
        }
    }
    glutPostRedisplay();
    glutTimerFunc(asteroid_respaw, new_asteroid, 0);
}

//===========================================================================

void update_level_player(void){
    if(starship->ennmies_killed > 3 && starship->ennmies_killed <= 6){
        starship->level = 2;
        respaw_speed = 2550;
        ennemies_speed = 170;
        asteroid_speed = 1000;
        asteroid_respaw = 8000;
    }
    else if(starship->ennmies_killed > 6 && starship->ennmies_killed <= 10){
        starship->level = 3;
        respaw_speed = 2200;
        ennemies_speed = 130;
        asteroid_speed = 850;
        asteroid_respaw = 6500;
    }
    else if(starship->ennmies_killed > 10 && starship->ennmies_killed <= 15){
        starship->level = 4;
        respaw_speed = 1870;
        ennemies_speed = 100;
        asteroid_speed = 700;
        asteroid_respaw = 5000;
    }
    else if(starship->ennmies_killed > 15 && starship->ennmies_killed <= 25){
        starship->level = 5;
        respaw_speed = 1600;
        ennemies_speed = 70;
        asteroid_speed = 600;
        asteroid_respaw = 4000;
    }
    else if(starship->ennmies_killed > 25){
        starship->level = 6;
        respaw_speed = 1360;
        ennemies_speed = 40;
        asteroid_speed = 500;
        asteroid_respaw = 3000;
    }
}

void game_over_check(void){
    if(starship->life > 0)
        return;
    else{
        game_over = true;
        do_pause = true;

        float killed = starship->ennmies_killed;
        float fired = starship->bullets_fired;
        float score = starship->score;

        score_multiplicator = (killed)/(fired);
        
        if(score_multiplicator >= 0.95)
            score_multiplicator = 2.00;
        else if(score_multiplicator >= 0.90 && score_multiplicator < 0.95)
            score_multiplicator = 1.90;
        else if(score_multiplicator >= 0.8 && score_multiplicator < 0.9)
            score_multiplicator = 1.80;
        else if(score_multiplicator >= 0.7 && score_multiplicator < 0.8)
            score_multiplicator = 1.70;
        else if(score_multiplicator >= 0.6 && score_multiplicator < 0.7)
            score_multiplicator = 1.60;
        else if(score_multiplicator >= 0.5 && score_multiplicator < 0.6)
            score_multiplicator = 1.50;
        else if(score_multiplicator >= 0.4 && score_multiplicator < 0.5)
            score_multiplicator = 1.40;
        else if(score_multiplicator >= 0.3 && score_multiplicator < 0.4)
            score_multiplicator = 1.30;
        else if(score_multiplicator >= 0.2 && score_multiplicator < 0.3)
            score_multiplicator = 1.20; 
        else if(score_multiplicator >= 0.1 && score_multiplicator < 0.2)
            score_multiplicator = 1.10;
        else if(score_multiplicator < 0.1)
            score_multiplicator = 1.00;
        
        final_score = score*score_multiplicator;
    }
}

//=============FUNCTION TO KNOW ON WHICH SCREEN WE'RE LOCATED & NAVIGATE ======================

bool located_in_main_menu(void){
    if(do_pause && !game_over && show_menu && !menu_mode && !menu_score && !menu_rules)
        return true;
    else{
        return false;
    }
}

bool located_in_mode_menu(void){
    if(do_pause && !game_over && !show_menu && menu_mode && !menu_score && !menu_rules)
        return true;
    else{
        return false;
    }
}

bool located_in_score_menu(void){
    if(do_pause && !game_over && !show_menu && !menu_mode && menu_score && !menu_rules)
        return true;
    else{
        return false;
    }
}

bool located_in_pause_menu(void){
    if(do_pause && !game_over && !show_menu && !menu_mode && !menu_score && !menu_rules)
        return true;
    else{
        return false;
    }
}

bool located_in_the_game(void){
    if(!do_pause && !game_over && !show_menu && !menu_mode && !menu_score && !menu_rules)
        return true;
    else{
        return false;
    }
}

bool located_in_rules_menu(void){
    if(do_pause && !game_over && !show_menu && !menu_mode && !menu_score && menu_rules)
        return true;
    else{
        return false;
    }
}

bool located_in_game_over_menu(void){
    if(do_pause && game_over && !show_menu && !menu_mode && !menu_score && !menu_rules)
        return true;
    else{
        return false;
    }    
}

void go_to_main_menu(void){
    do_pause = true;
    game_over = false;
    show_menu = true;
    menu_mode = false;
    menu_score = false;
    menu_rules = false;
}

void go_to_game(void){
    do_pause = false;
    game_over = false;
    show_menu = false;
    menu_mode = false;
    menu_score = false;
    menu_rules = false;
}

void go_to_mode_menu(void){
    do_pause = true;
    game_over = false;
    show_menu = false;
    menu_mode = true;
    menu_score = false;
    menu_rules = false;
}

void go_to_rules_menu(void){
    do_pause = true;
    game_over = false;
    show_menu = false;
    menu_mode = false;
    menu_score = false;
    menu_rules = true;
}

void got_to_score_menu(void){
    do_pause = true;
    game_over = false;
    show_menu = false;
    menu_mode = false;
    menu_score = true;
    menu_rules = false;
}

void switch_pixel_mode(void){
    if(pixel_mode)
        pixel_mode = 0;
    else{
        pixel_mode = 1;
    }
}

void switch_cursor(unsigned char key){
    switch (key)
    {
        case 'z':{
            if(located_in_main_menu()){
                if(cursor_menu >= 2)
                    cursor_menu--;
            }
            break;
        }
        case 's':{
            if(located_in_main_menu()){
                if(cursor_menu <= 4)
                    cursor_menu++;
            }
            break;
        }
        case 'q':{
            if(located_in_pause_menu() || located_in_game_over_menu()){
                if(cursor_menu == 2)
                    cursor_menu = 1;
            }
            break;
        }
        case 'd':{
            if(located_in_pause_menu() || located_in_game_over_menu()){
                if(cursor_menu == 1)
                    cursor_menu = 2;
            }
            break;
        }
        default:
            break;
    }
}

//============ FCT TO INITIATE A NEW GAME ===========================================

void init_a_new_game(void){
    //We free memory for elements
    ennemies = free_list_ennemies(ennemies);
	bullet = free_bullet_list(bullet);
	asteroid = free_list_asteroids(asteroid);
	free(starship);
	free(map);
	free(score_table);

    //We reinitiziale map dimension at 0 to avoid wrong dimension during initialization
    mX = 0;
    mY = 0;

    //We call game init function
    initializing_game();
}