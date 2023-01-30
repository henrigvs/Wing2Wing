#include "header.h"

int main(int argc, char **argv)
{
	initializing_game();

    glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);

	glutInitWindowSize(window_width, window_height);
	glutCreateWindow("Wing2Wing");

	initRendering();


	glutDisplayFunc(Display);
	glutReshapeFunc(handleResize);
	//glutIdleFunc(Display);
	glutKeyboardFunc(process_keys);
	glutMouseFunc(my_mouse);

	timing_update();


	glEnable(GL_DEPTH_TEST);
	glutMainLoop();

// ========= free memory at program closing ========
	ennemies = free_list_ennemies(ennemies);				
	bullet = free_bullet_list(bullet);
	asteroid = free_list_asteroids(asteroid);
	free(starship);
	free(map);
	free(score_table);
//==================================================
	
	return 0;
}
