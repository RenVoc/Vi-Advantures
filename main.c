/*

	Подключение необходимых библиотек из SDK - основная gb.h, шрифты - font.h

*/

#include <gb/gb.h>
#include <gb/font.h>
#include <stdio.h>
#include "res/playerSprites/Melkiy.c"
#include "res/playerSprites/melkiy-big.c"
#include "res/mapSprites/simplebackground.c"
#include "res/mapSprites/simplebackgroundmap.c"
#include "res/mapSprites/windowmap.c"

INT16 playerlocation[2]; // stores two INT16 x and y position of player
BYTE jumping;
INT8 gravity = -2;
INT16 currentspeedY;
INT16 floorYposition = 139;


void performantdelay(UINT8 numloops) {
	UINT8 i;
	for (i = 0; i < numloops; i++) {
		wait_vbl_done();
	}
}

INT8 wouldhitsurface(INT16 projectedYPosition) {
	if (projectedYPosition >= floorYposition) {

		return floorYposition;
	}
	return -1;
}

void jump(UINT8 spriteid, UINT16 spritelocation[2]) {
	INT8 possiblesurfaceY;

	if (jumping == 0) {
		jumping = 1;
		currentspeedY = 10;
	}

	// work out current speed - effect of gravities accelleration down
	currentspeedY = currentspeedY + gravity;

	spritelocation[1] = spritelocation[1] - currentspeedY;

	possiblesurfaceY = wouldhitsurface(spritelocation[1]);

	if (possiblesurfaceY != -1) {
		jumping = 0;
		move_sprite(spriteid, spritelocation[0], possiblesurfaceY);
	}
	else {
		move_sprite(spriteid, spritelocation[0], spritelocation[1]);
	}
}

void main(){

	//NR52_REG = 0x80;
	//NR50_REG = 0x77;
	//NR51_REG = 0xFF;

	//font_t min_font; // задаем переменную которая хранит шрифт
	//font_init(); // инициализируем шрифт
	//min_font = font_load(font_min); // подгружаем в переменную один из шрифтов в массиве либы, занимает 36 тайлов
	//font_set(min_font); // устанавливаем шрифт в значение нашей изменной переменной и загружаем в видео память

	//set_bkg_data(37, 7, backgroundtiles);
	//set_bkg_tiles(0, 0, 40, 18, backgroundmap);

	//set_win_tiles(0, 0, 16, 1, windowmap); // устанавливаем координаты, кол-во символов в надписи и строк, которые будут браться из нашего windowmap
	//move_win(7, 120); // перемещаем под слой нашего фона

	set_sprite_data(1, 2, Cat);
	set_sprite_tile(0, 0);            /* defines the tiles numbers */

	playerlocation[0] = 10;
	playerlocation[1] = floorYposition;
	jumping = 0;

	move_sprite(0, playerlocation[0], playerlocation[1]);

	// SHOW_BKG;  
	// SHOW_WIN;
	SHOW_SPRITES;
	DISPLAY_ON; 

	while (1) {
		// scroll_bkg(1, 0); // прокрутка фона с небольшой задержкой
		if ((joypad() & J_A) || jumping == 1) {
			jump(0, playerlocation);
		}
		if (joypad() & J_LEFT) {
			playerlocation[0] = playerlocation[0] - 2;
			move_sprite(0, playerlocation[0], playerlocation[1]);
		}
		if (joypad() & J_RIGHT) {
			playerlocation[0] = playerlocation[0] + 2;
			move_sprite(0, playerlocation[0], playerlocation[1]);
		}
		performantdelay(5);
	}
}