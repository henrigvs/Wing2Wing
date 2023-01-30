#include "header.h"

void renderBitmapString(float x, float y, float z, void *font, char *string) {
	char *c;
	glRasterPos3f(x, y, z);
	for (c=string; *c != '\0'; c++) {
		glutBitmapCharacter(font, *c);
	}
}

void display_text(char *string, int x, int y, int z) {
	glColor3f(1.0f,1.0f,1.0f);
	glMatrixMode(GL_PROJECTION);
	glPushMatrix();
	glLoadIdentity();
	gluOrtho2D(0, window_width, window_height, 0);
	glMatrixMode(GL_MODELVIEW);

	glPushMatrix();
	glLoadIdentity();
	renderBitmapString(x, y, z, GLUT_BITMAP_HELVETICA_18, string);
	glPopMatrix();
	
	glMatrixMode(GL_PROJECTION);
	glPopMatrix();
	glMatrixMode(GL_MODELVIEW);
}

void Display_main_menu(void){

	if(cursor_menu == 1){			//Depending the value of cursor, displaying the right screen
		tex_main_menu_play();
	}
	else if(cursor_menu == 2){
		tex_main_menu_mode();
	}
	else if(cursor_menu == 3){
		tex_main_menu_rules();
	}
	else if(cursor_menu == 4){
		tex_main_menu_score();
	}
	else if(cursor_menu == 5){
		tex_main_menu_quit();
	}
	display_text("Up = Press Z  |  Down = Press S", 250, window_height-6, 0);
}

void Display_score_menu(void){
	tex_main_sub_menu_score();

	int y = 290;
	int size = sizeof_score_table_file(score_table_file);
	int name_to_show;

	if(size<11)
		name_to_show = sizeof_score_table_file(score_table_file);
	else{
		name_to_show = 10;
	}

	for(int i = 0; i<name_to_show; i++){
		char score[16];
		sprintf(score, "%d", score_table[i].score);
		display_text(score_table[i].name, window_width-500, y, 0);
		display_text(score, window_width-330, y, 0);
		y = y+30;
	}
}

void Display_pause_menu(void){
	if(pixel_mode && cursor_menu == 1){
		tex_pause_RESUME_ON();
	}
	else if(pixel_mode && cursor_menu == 2){
		tex_pause_MENU_ON();
	}
	else if(!pixel_mode && cursor_menu == 1){
		tex_pause_RESUME_OFF();
	}
	else if(!pixel_mode && cursor_menu == 2){
		tex_pause_MENU_OFF();
	}
}

void Display_game_over_menu(void){
	if(cursor_menu == 1){
		tex_sub_menu_game_over_retry();
	}
	else if(cursor_menu == 2){
		tex_sub_menu_game_over_quit();
	}
	save_score(score_table_file, starship);		//Call function to save the score

	int y_position = 300;
	display_text("SCORE : ", window_width-435, y_position, 0);
	char score_char[10];
	sprintf(score_char, "%.0f", starship->score);
	display_text(score_char, window_width-355, y_position, 0);

	display_text("PRECISION MULTIPLICATOR : x ", window_width-555, y_position+30, 0);
	sprintf(score_char, "%.2f", score_multiplicator);
	display_text(score_char, window_width-270, y_position+30, 0);

	display_text("FINAL SCORE : ", window_width-480, y_position+60, 0);
	sprintf(score_char, "%.0f", final_score);
	display_text(score_char, window_width-345, y_position+60, 0);


	if(starship->score <= 500)
		display_text("YOU CAN DO BETTER :-(", window_width-500, y_position+110, 0);
	else if(starship->score > 500 && starship->score <= 1000)
		display_text("NOT BAD ...", window_width-440, y_position+110, 0);
	else if(starship->score > 1000 && starship->score <= 1500)
		display_text("GOOD JOB :-)", window_width-460, y_position+110, 0);
	else if(starship->score > 1500 && starship->score <= 2000)
		display_text("DAMN YOU'RE A STRIKER !!!", window_width-500, y_position+110, 0);
}

void Display_life_and_score(void){
	//Display score
	display_text("SCORE : ", 5, window_height-5, 0);
	char score_char[10];
	sprintf(score_char, "%.0f", starship->score);
	display_text(score_char, 85, window_height-5, 0);

	//Display life
	display_text("LIVES : ", 150, window_height-5, 0);
	char lives_char[2];
	sprintf(lives_char, "%d", starship->life);
	display_text(lives_char, 220, window_height-5, 0);

	//Display Level
	display_text("LEVEL : ", 260, window_height-5, 0);
	char level_char[10];
	sprintf(level_char, "%d", starship->level);
	display_text(level_char, 330, window_height-5, 0);

	//Dislay pause
	display_text("PAUSE & COMMAND = P", 550, window_height-5, 0);
}

void Display_game_play(void){
	Display_bg(); 								//Display backgroud of game screen
	Display_life_and_score();					//Display information on the bottom of game screen

	for (int j = 0; j < mX; ++j)				//Display characters and asteroids
	{	
		for (int i = 0; i < mY; ++i)
		{	
			if (map[j][i]  == 'X') 
			{
				tex_starship(j, i);
			}

			if (map[j][i]  == '@') 
			{
				tex_enemmies(j, i);
			}

			if (map[j][i]  == '|') 
			{
				tex_starship_bullets(j, i);
			}

			if (map[j][i] == 'o')
			{
				tex_ennemies_bullets(j, i);
			}

			if (map[j][i]  == '1') 
			{
				tex_asteroid_1(j, i);
			}

			if (map[j][i]  == '2') 
			{
				tex_asteroid_2(j, i);
			}

			if (map[j][i]  == '3') 
			{
				tex_asteroid_3(j, i);
			}
		}
	}
}

void draw_map(void)
{
	if(located_in_the_game())			//If we are playing => Display the gameplay function
		Display_game_play();

	if(located_in_main_menu())			//If we are in the main menu => Display main menu
		Display_main_menu();

	if(located_in_pause_menu())			//If we are in the pause => Display pause menu
		Display_pause_menu();

	if(located_in_game_over_menu()) 	//If game is over => Display game over menu
		Display_game_over_menu();
	
	if(located_in_mode_menu())			//If we are in mode menu => Display mode menu
		if(!pixel_mode)
			tex_main_sub_menu_mode_ON();
		else if(pixel_mode)
			tex_main_sub_menu_mode_OFF();

	if(located_in_score_menu())			//If we are in score menu => Display score menu
		Display_score_menu();

	if(located_in_rules_menu())			//If we are in rules menu => Display rules menu
		tex_main_sub_menu_rules();
}
