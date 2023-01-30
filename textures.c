#include "header.h"

//=================== TEXTURES FOR MAIN MENU ==============================

#include "ressources/images/c_files/main_menu/menu_main_play.c"
#include "ressources/images/c_files/main_menu/menu_main_mode.c"
#include "ressources/images/c_files/main_menu/menu_main_rules.c"
#include "ressources/images/c_files/main_menu/menu_main_score.c"
#include "ressources/images/c_files/main_menu/menu_main_quit.c"

void tex_main_menu_play(void){
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	int tex_main_menu_play;
	glGenTextures(1, &tex_main_menu_play);
	glBindTexture(GL_TEXTURE_2D, tex_main_menu_play);
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
	gluBuild2DMipmaps(GL_TEXTURE_2D, menu_main_play.bytes_per_pixel,
			menu_main_play.width, menu_main_play.height, GL_RGB, GL_UNSIGNED_BYTE,
			menu_main_play.pixel_data);
	glEnable(GL_TEXTURE_2D);

	glBegin(GL_POLYGON);
		glTexCoord2f(0.0, 0.0); 	glVertex2f(0, 90);
		glTexCoord2f(1.0, 0.0);		glVertex2f(window_width, 90);
		glTexCoord2f(1.0, 1.0);		glVertex2f(window_width, window_height);
		glTexCoord2f(0.0, 1.0);		glVertex2f(0, window_height);
	glEnd();
		
	glDisable(GL_TEXTURE_2D);
}

void tex_main_menu_mode(void){
    glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	int tex_main_menu_mode;
	glGenTextures(1, &tex_main_menu_mode);
	glBindTexture(GL_TEXTURE_2D, tex_main_menu_mode);
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
	gluBuild2DMipmaps(GL_TEXTURE_2D, menu_main_mode.bytes_per_pixel,
			menu_main_mode.width, menu_main_mode.height, GL_RGB, GL_UNSIGNED_BYTE,
			menu_main_mode.pixel_data);
	glEnable(GL_TEXTURE_2D);

	glBegin(GL_POLYGON);
		glTexCoord2f(0.0, 0.0); 	glVertex2f(0, 90);
		glTexCoord2f(1.0, 0.0);		glVertex2f(window_width, 90);
		glTexCoord2f(1.0, 1.0);		glVertex2f(window_width, window_height);
		glTexCoord2f(0.0, 1.0);		glVertex2f(0, window_height);
	glEnd();
		
	glDisable(GL_TEXTURE_2D);
}

void tex_main_menu_rules(void){
    glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	int tex_main_menu_rules;
	glGenTextures(1, &tex_main_menu_rules);
	glBindTexture(GL_TEXTURE_2D, tex_main_menu_rules);
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
	gluBuild2DMipmaps(GL_TEXTURE_2D, menu_main_rules.bytes_per_pixel,
			menu_main_rules.width, menu_main_rules.height, GL_RGB, GL_UNSIGNED_BYTE,
			menu_main_rules.pixel_data);
	glEnable(GL_TEXTURE_2D);

	glBegin(GL_POLYGON);
		glTexCoord2f(0.0, 0.0); 	glVertex2f(0, 90);
		glTexCoord2f(1.0, 0.0);		glVertex2f(window_width, 90);
		glTexCoord2f(1.0, 1.0);		glVertex2f(window_width, window_height);
		glTexCoord2f(0.0, 1.0);		glVertex2f(0, window_height);
	glEnd();
		
	glDisable(GL_TEXTURE_2D);
}

void tex_main_menu_score(void){
    glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	int tex_main_menu_score;
	glGenTextures(1, &tex_main_menu_score);
	glBindTexture(GL_TEXTURE_2D, tex_main_menu_score);
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
	gluBuild2DMipmaps(GL_TEXTURE_2D, menu_main_score.bytes_per_pixel,
			menu_main_score.width, menu_main_score.height, GL_RGB, GL_UNSIGNED_BYTE,
			menu_main_score.pixel_data);
	glEnable(GL_TEXTURE_2D);

	glBegin(GL_POLYGON);
		glTexCoord2f(0.0, 0.0); 	glVertex2f(0, 90);
		glTexCoord2f(1.0, 0.0);		glVertex2f(window_width, 90);
		glTexCoord2f(1.0, 1.0);		glVertex2f(window_width, window_height);
		glTexCoord2f(0.0, 1.0);		glVertex2f(0, window_height);
	glEnd();
		
	glDisable(GL_TEXTURE_2D);
}

void tex_main_menu_quit(void){
    glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	int tex_main_menu_quit;
	glGenTextures(1, &tex_main_menu_quit);
	glBindTexture(GL_TEXTURE_2D, tex_main_menu_quit);
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
	gluBuild2DMipmaps(GL_TEXTURE_2D, menu_main_quit.bytes_per_pixel,
			menu_main_quit.width, menu_main_quit.height, GL_RGB, GL_UNSIGNED_BYTE,
			menu_main_quit.pixel_data);
	glEnable(GL_TEXTURE_2D);

	glBegin(GL_POLYGON);
		glTexCoord2f(0.0, 0.0); 	glVertex2f(0, 90);
		glTexCoord2f(1.0, 0.0);		glVertex2f(window_width, 90);
		glTexCoord2f(1.0, 1.0);		glVertex2f(window_width, window_height);
		glTexCoord2f(0.0, 1.0);		glVertex2f(0, window_height);
	glEnd();
		
	glDisable(GL_TEXTURE_2D);
}

//=================== TEXTURES FOR SUB-MENU MENU ==============================
#include "ressources/images/c_files/main_menu/sub-menu/menu_main_mode_ON.c"
#include "ressources/images/c_files/main_menu/sub-menu/menu_main_mode_OFF.c"
#include "ressources/images/c_files/main_menu/sub-menu/menu_main_score.c"
#include "ressources/images/c_files/main_menu/sub-menu/menu_main_rules.c"

void tex_main_sub_menu_mode_ON(void){
    glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	int tex_sub_menu_mode_ON;
	glGenTextures(1, &tex_sub_menu_mode_ON);
	glBindTexture(GL_TEXTURE_2D, tex_sub_menu_mode_ON);
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
	gluBuild2DMipmaps(GL_TEXTURE_2D, menu_main_mode_ON.bytes_per_pixel,
			menu_main_mode_ON.width, menu_main_mode_ON.height, GL_RGB, GL_UNSIGNED_BYTE,
			menu_main_mode_ON.pixel_data);
	glEnable(GL_TEXTURE_2D);

	glBegin(GL_POLYGON);
		glTexCoord2f(0.0, 0.0); 	glVertex2f(0, 90);
		glTexCoord2f(1.0, 0.0);		glVertex2f(window_width, 90);
		glTexCoord2f(1.0, 1.0);		glVertex2f(window_width, window_height);
		glTexCoord2f(0.0, 1.0);		glVertex2f(0, window_height);
	glEnd();
		
	glDisable(GL_TEXTURE_2D);
}

void tex_main_sub_menu_mode_OFF(void){
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	int tex_sub_menu_mode_OFF;
	glGenTextures(1, &tex_sub_menu_mode_OFF);
	glBindTexture(GL_TEXTURE_2D, tex_sub_menu_mode_OFF);
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
	gluBuild2DMipmaps(GL_TEXTURE_2D, menu_main_mode_OFF.bytes_per_pixel,
			menu_main_mode_OFF.width, menu_main_mode_OFF.height, GL_RGB, GL_UNSIGNED_BYTE,
			menu_main_mode_OFF.pixel_data);
	glEnable(GL_TEXTURE_2D);

	glBegin(GL_POLYGON);
		glTexCoord2f(0.0, 0.0); 	glVertex2f(0, 90);
		glTexCoord2f(1.0, 0.0);		glVertex2f(window_width, 90);
		glTexCoord2f(1.0, 1.0);		glVertex2f(window_width, window_height);
		glTexCoord2f(0.0, 1.0);		glVertex2f(0, window_height);
	glEnd();
		
	glDisable(GL_TEXTURE_2D);
}

void tex_main_sub_menu_score(void){
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	int tex_sub_menu_score;
	glGenTextures(1, &tex_sub_menu_score);
	glBindTexture(GL_TEXTURE_2D, tex_sub_menu_score);
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
	gluBuild2DMipmaps(GL_TEXTURE_2D, sub_menu_main_score.bytes_per_pixel,
			sub_menu_main_score.width, sub_menu_main_score.height, GL_RGB, GL_UNSIGNED_BYTE,
			sub_menu_main_score.pixel_data);
	glEnable(GL_TEXTURE_2D);

	glBegin(GL_POLYGON);
		glTexCoord2f(0.0, 0.0); 	glVertex2f(0, 90);
		glTexCoord2f(1.0, 0.0);		glVertex2f(window_width, 90);
		glTexCoord2f(1.0, 1.0);		glVertex2f(window_width, window_height);
		glTexCoord2f(0.0, 1.0);		glVertex2f(0, window_height);
	glEnd();
		
	glDisable(GL_TEXTURE_2D);
}

void tex_main_sub_menu_rules(void){
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	int tex_sub_menu_rules;
	glGenTextures(1, &tex_sub_menu_rules);
	glBindTexture(GL_TEXTURE_2D, tex_sub_menu_rules);
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
	gluBuild2DMipmaps(GL_TEXTURE_2D, sub_menu_main_rules.bytes_per_pixel,
			sub_menu_main_rules.width, sub_menu_main_rules.height, GL_RGB, GL_UNSIGNED_BYTE,
			sub_menu_main_rules.pixel_data);
	glEnable(GL_TEXTURE_2D);

	glBegin(GL_POLYGON);
		glTexCoord2f(0.0, 0.0); 	glVertex2f(0, 90);
		glTexCoord2f(1.0, 0.0);		glVertex2f(window_width, 90);
		glTexCoord2f(1.0, 1.0);		glVertex2f(window_width, window_height);
		glTexCoord2f(0.0, 1.0);		glVertex2f(0, window_height);
	glEnd();
		
	glDisable(GL_TEXTURE_2D);
}

//=================== TEXTURES FOR MENU PAUSE ==============================
#include "ressources/images/c_files/pause_menu/pause_menu_MENU_OFF.c"
#include "ressources/images/c_files/pause_menu/pause_menu_MENU_ON.c"
#include "ressources/images/c_files/pause_menu/pause_menu_RESUME_OFF.c"
#include "ressources/images/c_files/pause_menu/pause_menu_RESUME_ON.c"
#include "ressources/images/c_files/main_menu/sub-menu/game_over_screen_quit.c"
#include "ressources/images/c_files/main_menu/sub-menu/game_over_screen_retry.c"

void tex_pause_MENU_OFF(void){
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	int tex_pause_menu_off;
	glGenTextures(1, &tex_pause_menu_off);
	glBindTexture(GL_TEXTURE_2D, tex_pause_menu_off);
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
	gluBuild2DMipmaps(GL_TEXTURE_2D, pause_menu_MENU_OFF.bytes_per_pixel,
			pause_menu_MENU_OFF.width, pause_menu_MENU_OFF.height, GL_RGB, GL_UNSIGNED_BYTE,
			pause_menu_MENU_OFF.pixel_data);
	glEnable(GL_TEXTURE_2D);

	glBegin(GL_POLYGON);
		glTexCoord2f(0.0, 0.0); 	glVertex2f(0, 90);
		glTexCoord2f(1.0, 0.0);		glVertex2f(window_width, 90);
		glTexCoord2f(1.0, 1.0);		glVertex2f(window_width, window_height);
		glTexCoord2f(0.0, 1.0);		glVertex2f(0, window_height);
	glEnd();
		
	glDisable(GL_TEXTURE_2D);
}

void tex_pause_MENU_ON(void){
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	int tex_pause_menu_on;
	glGenTextures(1, &tex_pause_menu_on);
	glBindTexture(GL_TEXTURE_2D, tex_pause_menu_on);
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
	gluBuild2DMipmaps(GL_TEXTURE_2D, pause_menu_MENU_ON.bytes_per_pixel,
			pause_menu_MENU_ON.width, pause_menu_MENU_ON.height, GL_RGB, GL_UNSIGNED_BYTE,
			pause_menu_MENU_ON.pixel_data);
	glEnable(GL_TEXTURE_2D);

	glBegin(GL_POLYGON);
		glTexCoord2f(0.0, 0.0); 	glVertex2f(0, 90);
		glTexCoord2f(1.0, 0.0);		glVertex2f(window_width, 90);
		glTexCoord2f(1.0, 1.0);		glVertex2f(window_width, window_height);
		glTexCoord2f(0.0, 1.0);		glVertex2f(0, window_height);
	glEnd();
		
	glDisable(GL_TEXTURE_2D);
}

void tex_pause_RESUME_OFF(void){
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	int tex_pause_resume_off;
	glGenTextures(1, &tex_pause_resume_off);
	glBindTexture(GL_TEXTURE_2D, tex_pause_resume_off);
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
	gluBuild2DMipmaps(GL_TEXTURE_2D, pause_menu_RESUME_OFF.bytes_per_pixel,
			pause_menu_RESUME_OFF.width, pause_menu_RESUME_OFF.height, GL_RGB, GL_UNSIGNED_BYTE,
			pause_menu_RESUME_OFF.pixel_data);
	glEnable(GL_TEXTURE_2D);

	glBegin(GL_POLYGON);
		glTexCoord2f(0.0, 0.0); 	glVertex2f(0, 90);
		glTexCoord2f(1.0, 0.0);		glVertex2f(window_width, 90);
		glTexCoord2f(1.0, 1.0);		glVertex2f(window_width, window_height);
		glTexCoord2f(0.0, 1.0);		glVertex2f(0, window_height);
	glEnd();
		
	glDisable(GL_TEXTURE_2D);
}

void tex_pause_RESUME_ON(void){
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	int tex_pause_resume_on;
	glGenTextures(1, &tex_pause_resume_on);
	glBindTexture(GL_TEXTURE_2D, tex_pause_resume_on);
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
	gluBuild2DMipmaps(GL_TEXTURE_2D, pause_menu_RESUME_ON.bytes_per_pixel,
			pause_menu_RESUME_ON.width, pause_menu_RESUME_ON.height, GL_RGB, GL_UNSIGNED_BYTE,
			pause_menu_RESUME_ON.pixel_data);
	glEnable(GL_TEXTURE_2D);

	glBegin(GL_POLYGON);
		glTexCoord2f(0.0, 0.0); 	glVertex2f(0, 90);
		glTexCoord2f(1.0, 0.0);		glVertex2f(window_width, 90);
		glTexCoord2f(1.0, 1.0);		glVertex2f(window_width, window_height);
		glTexCoord2f(0.0, 1.0);		glVertex2f(0, window_height);
	glEnd();
		
	glDisable(GL_TEXTURE_2D);
}

void tex_sub_menu_game_over_retry(void){
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	int tex_game_over_retry;
	glGenTextures(1, &tex_game_over_retry);
	glBindTexture(GL_TEXTURE_2D, tex_game_over_retry);
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
	gluBuild2DMipmaps(GL_TEXTURE_2D, game_over_screen_retry.bytes_per_pixel,
			game_over_screen_retry.width, game_over_screen_retry.height, GL_RGB, GL_UNSIGNED_BYTE,
			game_over_screen_retry.pixel_data);
	glEnable(GL_TEXTURE_2D);

	glBegin(GL_POLYGON);
		glTexCoord2f(0.0, 0.0); 	glVertex2f(0, 90);
		glTexCoord2f(1.0, 0.0);		glVertex2f(window_width, 90);
		glTexCoord2f(1.0, 1.0);		glVertex2f(window_width, window_height);
		glTexCoord2f(0.0, 1.0);		glVertex2f(0, window_height);
	glEnd();
		
	glDisable(GL_TEXTURE_2D);
}

void tex_sub_menu_game_over_quit(void){
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	int tex_game_over_quit;
	glGenTextures(1, &tex_game_over_quit);
	glBindTexture(GL_TEXTURE_2D, tex_game_over_quit);
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
	gluBuild2DMipmaps(GL_TEXTURE_2D, game_over_screen_quit.bytes_per_pixel,
			game_over_screen_quit.width, game_over_screen_quit.height, GL_RGB, GL_UNSIGNED_BYTE,
			game_over_screen_quit.pixel_data);
	glEnable(GL_TEXTURE_2D);

	glBegin(GL_POLYGON);
		glTexCoord2f(0.0, 0.0); 	glVertex2f(0, 90);
		glTexCoord2f(1.0, 0.0);		glVertex2f(window_width, 90);
		glTexCoord2f(1.0, 1.0);		glVertex2f(window_width, window_height);
		glTexCoord2f(0.0, 1.0);		glVertex2f(0, window_height);
	glEnd();
		
	glDisable(GL_TEXTURE_2D);
}

//=================== TEXTURES FOR ASTEROIDS ==============================

#include "ressources/images/c_files/asteroid_1.c"
#include "ressources/images/c_files/asteroid_2.c"
#include "ressources/images/c_files/asteroid_3.c"

void tex_asteroid_1(int j, int i){
	if(pixel_mode){
    	glColor3f(1.0f,1.0f,1.0f);

		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
		glTranslatef(i*Square_size,j*Square_size,0.0f);
		
		glBegin(GL_QUADS);
		glVertex3f(0.0f, 0.0f, 0.0f);
		glVertex3f(Square_size, 0.0f, 0.0f);
		glVertex3f(Square_size,Square_size, 0.0f);
		glVertex3f(0.0f,Square_size, 0.0f);

		glEnd();
	}
	else{	
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();

		int tex_asteroid_1;
		glGenTextures(1, &tex_asteroid_1);
		glBindTexture(GL_TEXTURE_2D, tex_asteroid_1);
		glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
		gluBuild2DMipmaps(GL_TEXTURE_2D, asteroid_1.bytes_per_pixel,
				asteroid_1.width, asteroid_1.height, GL_RGB, GL_UNSIGNED_BYTE,
				asteroid_1.pixel_data);
		glEnable(GL_TEXTURE_2D);

		glTranslatef(i*Square_size,j*Square_size,0.0f);
		glBegin(GL_POLYGON);
			glTexCoord2f(0.0, 0.0); 	glVertex2f(-20.0, -20.0);
			glTexCoord2f(1.0, 0.0);		glVertex2f(20.0, -20.0);
			glTexCoord2f(1.0, 1.0);		glVertex2f(20.0, 20.0);
			glTexCoord2f(0.0, 1.0);		glVertex2f(-20.0, 20.0);
		glEnd();
		glDisable(GL_TEXTURE_2D);
	}
}

void tex_asteroid_2(int j, int i){
	if(pixel_mode){
    	glColor3f(1.0f,1.0f,1.0f);

		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
		glTranslatef(i*Square_size,j*Square_size,0.0f);
		
		glBegin(GL_QUADS);
		glVertex3f(0.0f, 0.0f, 0.0f);
		glVertex3f(Square_size, 0.0f, 0.0f);
		glVertex3f(Square_size,Square_size, 0.0f);
		glVertex3f(0.0f,Square_size, 0.0f);

		glEnd();
	}
	else{
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();

		int tex_asteroid_2;
		glGenTextures(1, &tex_asteroid_2);
		glBindTexture(GL_TEXTURE_2D, tex_asteroid_2);
		glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
		gluBuild2DMipmaps(GL_TEXTURE_2D, asteroid_2.bytes_per_pixel,
				asteroid_2.width, asteroid_2.height, GL_RGB, GL_UNSIGNED_BYTE,
				asteroid_2.pixel_data);
		glEnable(GL_TEXTURE_2D);

		glTranslatef(i*Square_size,j*Square_size,0.0f);
		glBegin(GL_POLYGON);
			glTexCoord2f(0.0, 0.0); 	glVertex2f(-20.0, -20.0);
			glTexCoord2f(1.0, 0.0);		glVertex2f(20.0, -20.0);
			glTexCoord2f(1.0, 1.0);		glVertex2f(20.0, 20.0);
			glTexCoord2f(0.0, 1.0);		glVertex2f(-20.0, 20.0);
		glEnd();
		glDisable(GL_TEXTURE_2D);
	}
}


void tex_asteroid_3(int j, int i){
	if(pixel_mode){
		glColor3f(1.0f,1.0f,1.0f);

		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
		glTranslatef(i*Square_size,j*Square_size,0.0f);
		
		glBegin(GL_QUADS);
		glVertex3f(0.0f, 0.0f, 0.0f);
		glVertex3f(Square_size, 0.0f, 0.0f);
		glVertex3f(Square_size,Square_size, 0.0f);
		glVertex3f(0.0f,Square_size, 0.0f);

		glEnd();
	}
	else{
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();

		int tex_asteroid_3;
		glGenTextures(1, &tex_asteroid_3);
		glBindTexture(GL_TEXTURE_2D, tex_asteroid_3);
		glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
		gluBuild2DMipmaps(GL_TEXTURE_2D, asteroid_3.bytes_per_pixel,
				asteroid_3.width, asteroid_3.height, GL_RGB, GL_UNSIGNED_BYTE,
				asteroid_3.pixel_data);
		glEnable(GL_TEXTURE_2D);

		glTranslatef(i*Square_size,j*Square_size,0.0f);
		glBegin(GL_POLYGON);
			glTexCoord2f(0.0, 0.0); 	glVertex2f(-20.0, -20.0);
			glTexCoord2f(1.0, 0.0);		glVertex2f(20.0, -20.0);
			glTexCoord2f(1.0, 1.0);		glVertex2f(20.0, 20.0);
			glTexCoord2f(0.0, 1.0);		glVertex2f(-20.0, 20.0);
		glEnd();
		glDisable(GL_TEXTURE_2D);
	}
}

//=================== TEXTURES FOR STARSHIP & ENNEMIES ==============================

#include "ressources/images/c_files/spacecraft_small.c"
#include "ressources/images/c_files/spaceship_ennemy_small.c"

void tex_starship(int j, int i){
	if(pixel_mode){

		glColor3f(0.8f,0.2f,0.6f);

		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
		glTranslatef(i*Square_size-18,j*Square_size-20,0.0f);
		glScalef(0.3, 0.3, 0.3);

		glBegin(GL_POLYGON);
		
			glVertex3f(85.0, 15.0, 0.0);
			glVertex3f(29.0, 225.0, 0.0);
			glVertex3f(81.0, 153.0, 0.0);
			glVertex3f(120.0, 153.0, 0.0);
			glVertex3f(175.0, 231.0, 0.0);
			glVertex3f(120.0, 15.0, 0.0);
			glVertex3f(102.0, 62.0, 0.0);

		glEnd();

	}	
	
	else{
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();

		int tex_spaceship;
		glGenTextures(1, &tex_spaceship);
		glBindTexture(GL_TEXTURE_2D, tex_spaceship);
		glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
		gluBuild2DMipmaps(GL_TEXTURE_2D, spacecraft_small.bytes_per_pixel,
				spacecraft_small.width, spacecraft_small.height, GL_RGB, GL_UNSIGNED_BYTE,
				spacecraft_small.pixel_data);
		glEnable(GL_TEXTURE_2D);

		glTranslatef(i*Square_size,j*Square_size+20,0.0f);
		glBegin(GL_POLYGON);
			glTexCoord2f(0.0, 0.0); 	glVertex2f(-25.0, -40.0);
			glTexCoord2f(1.0, 0.0);		glVertex2f(35.0, -40.0);
			glTexCoord2f(1.0, 1.0);		glVertex2f(35.0, 30.0);
			glTexCoord2f(0.0, 1.0);		glVertex2f(-25.0, 30.0);
		glEnd();
		glDisable(GL_TEXTURE_2D);
	}
}

void tex_enemmies(int j, int i){
	if(pixel_mode){
		glColor3f(0.4f,0.7f,0.3f);

		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
		glTranslatef(i*Square_size,j*Square_size,0.0f);
		
		glBegin(GL_QUADS);
		glVertex3f(0.0f, 0.0f, 0.0f);
		glVertex3f(Square_size, 0.0f, 0.0f);
		glVertex3f(Square_size,Square_size, 0.0f);
		glVertex3f(0.0f,Square_size, 0.0f);

		glEnd();
	}	
	else{	
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();

		int tex_spaceship_ennemy;
		glGenTextures(1, &tex_spaceship_ennemy);
		glBindTexture(GL_TEXTURE_2D, tex_spaceship_ennemy);
		glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
		gluBuild2DMipmaps(GL_TEXTURE_2D, spaceship_ennemy_small.bytes_per_pixel,
				spaceship_ennemy_small.width, spaceship_ennemy_small.height, GL_RGB, GL_UNSIGNED_BYTE,
				spaceship_ennemy_small.pixel_data);
		glEnable(GL_TEXTURE_2D);

		glTranslatef(i*Square_size,j*Square_size-5,0.0f);
		glBegin(GL_POLYGON);
			glTexCoord2f(0.0, 0.0); 	glVertex2f(-20.0, -20.0);
			glTexCoord2f(1.0, 0.0);		glVertex2f(20.0, -20.0);
			glTexCoord2f(1.0, 1.0);		glVertex2f(20.0, 20.0);
			glTexCoord2f(0.0, 1.0);		glVertex2f(-20.0, 20.0);
		glEnd();
		glDisable(GL_TEXTURE_2D);
	}
}

//=================== TEXTURE FOR BACKGROUND ==============================

#include "ressources/images/c_files/background_small.c"

void draw_star_bg(float size, float x, float y){
	glColor3f(0.1f,0.1f,0.1f);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glTranslated(x, y, 0.0f);
	glScalef(size, size, size);

	glBegin(GL_TRIANGLE_FAN);

			glVertex3f(1.0f, 4.0f, 0.0f);
			glVertex3f(3.0f, 3.0f, 0.0f);
			glVertex3f(1.0f, 2.0f, 0.0f);
			glVertex3f(0.0f, 0.0f, 0.0f);
			glVertex3f(-1.0f, 2.0f, 0.0f);
			glVertex3f(-3.0f, 3.0f, 0.0f);
			glVertex3f(-1.0f, 4.0f, 0.0f);
			glVertex3f(0.0f,6.0f, 0.0f);		

	glEnd();
}

void Display_bg(void){
		draw_star_bg(5.0, 79.0, 61.0);
		draw_star_bg(4.0, 290.0, 65.0);
		draw_star_bg(3.0, 545.0, 155.0);
		draw_star_bg(5.0, 392.0, 171.0);
		draw_star_bg(2.0, 460.0, 270.0);
		draw_star_bg(6.0, 105.0, 430.0);
		draw_star_bg(3.0, 481.0, 475.0);
		draw_star_bg(4.0, 498.0, 623.0);
		draw_star_bg(2.0, 165.0, 186.0);
		draw_star_bg(5.0, 291.0, 375.0);
		draw_star_bg(7.0, 600.0, 400.0);
		draw_star_bg(6.0, 700.0, 245.0);
		draw_star_bg(2.0, 605.0, 56.0);
		draw_star_bg(3.0, 694.0, 566.0);
		draw_star_bg(4.0, 317.0, 631.0);
		draw_star_bg(5.0, 172.0, 577.0);
		draw_star_bg(4.0, 92.0, 753.0);
		draw_star_bg(2.0, 336.0, 769.0);
		draw_star_bg(5.0, 693.0, 725.0);
}

//=================== TEXTURE FOR WEAPONS (STARSHIP & ENNEMIES) ==============================
#include "ressources/images/c_files/blue_laser.c"
#include "ressources/images/c_files/red_laser.c"

void tex_starship_bullets(int j, int i){
	if(pixel_mode){
		glColor3f(0.0f,0.5f,1.0f);

		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
		glTranslatef(i*Square_size+9,j*Square_size,0.0f);
		
		glBegin(GL_QUADS);
		glVertex3f(0.0f, 0.0f, 0.0f);
		glVertex3f(5, 0.0f, 0.0f);
		glVertex3f(5,5, 0.0f);
		glVertex3f(0.0f,5, 0.0f);

		glEnd();
	}
	
	else{	
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();

		int tex_blue_laser;
		glGenTextures(1, &tex_blue_laser);
		glBindTexture(GL_TEXTURE_2D, tex_blue_laser);
		glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
		gluBuild2DMipmaps(GL_TEXTURE_2D, blue_laser.bytes_per_pixel,
				blue_laser.width, blue_laser.height, GL_RGB, GL_UNSIGNED_BYTE,
				blue_laser.pixel_data);
		glEnable(GL_TEXTURE_2D);

		glTranslatef(i*Square_size+5,j*Square_size,0.0f);
		glBegin(GL_POLYGON);
			glTexCoord2f(0.0, 0.0); 	glVertex2f(-8.0, -8.0);
			glTexCoord2f(1.0, 0.0);		glVertex2f(8.0, -8.0);
			glTexCoord2f(1.0, 1.0);		glVertex2f(8.0, 8.0);
			glTexCoord2f(0.0, 1.0);		glVertex2f(-8.0, 8.0);
		glEnd();
		glDisable(GL_TEXTURE_2D);
	}
}

void tex_ennemies_bullets(int j, int i){
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	int tex_red_laser;
	glGenTextures(1, &tex_red_laser);
	glBindTexture(GL_TEXTURE_2D, tex_red_laser);
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
	gluBuild2DMipmaps(GL_TEXTURE_2D, red_laser.bytes_per_pixel,
			red_laser.width, red_laser.height, GL_RGB, GL_UNSIGNED_BYTE,
			red_laser.pixel_data);
	glEnable(GL_TEXTURE_2D);

	glTranslatef(i*Square_size+5,j*Square_size,0.0f);
	glBegin(GL_POLYGON);
		glTexCoord2f(0.0, 0.0); 	glVertex2f(-8.0, -8.0);
		glTexCoord2f(1.0, 0.0);		glVertex2f(8.0, -8.0);
		glTexCoord2f(1.0, 1.0);		glVertex2f(8.0, 8.0);
		glTexCoord2f(0.0, 1.0);		glVertex2f(-8.0, 8.0);
	glEnd();
	glDisable(GL_TEXTURE_2D);
}