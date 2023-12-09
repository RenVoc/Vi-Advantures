/*

	����������� ����������� ��������� �� SDK - �������� gb.h, ������ - font.h

*/

#include <gb/gb.h>
#include <gb/font.h>
#include <stdio.h>
#include "res/mapSprites/simplebackground.c"
#include "res/mapSprites/simplebackgroundmap.c"
#include "res/mapSprites/windowmap.c"
#include "GameCharacter.c"
#include "res/characters.c"

INT16 playerlocation[2]; // stores two INT16 x and y position of player
BYTE jumping;
INT8 gravity = -2;
INT16 currentspeedY;
INT16 floorYposition = 139;

GameCharacter cat;
GameCharacter enemy;
UBYTE spritesize = 8;

void movegamecharacter(GameCharacter* character, UINT8 x, UINT8 y) {
	move_sprite(character->spritids[0], x, y);
	move_sprite(character->spritids[1], x, y + spritesize);
	move_sprite(character->spritids[2], x + spritesize, y);
	move_sprite(character->spritids[3], x + spritesize, y + spritesize);
}

void setupcat() {
	cat.x = 80;
	cat.y = 130;
	cat.width = 16;
	cat.height = 16;

	set_sprite_tile(0, 0);
	cat.spritids[0] = 0;
	set_sprite_tile(2, 2);
	cat.spritids[2] = 2;
	set_sprite_tile(1, 1);
	cat.spritids[1] = 1;
	set_sprite_tile(3, 3);
	cat.spritids[3] = 3;

	movegamecharacter(&cat, cat.x, cat.y);
}

void setupenemy() {
	enemy.x = 20;
	enemy.y = 130;
	enemy.width = 16;
	enemy.height = 16;

	set_sprite_tile(4, 4);
	enemy.spritids[0] = 4;
	set_sprite_tile(5, 5);
	enemy.spritids[1] = 5;
	set_sprite_tile(6, 6);
	enemy.spritids[2] = 6;
	set_sprite_tile(7, 7);
	enemy.spritids[3] = 7;

	movegamecharacter(&enemy, enemy.x, enemy.y);
}

/*
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
		movegamecharacter(&cat, cat.x, cat.y);
	}
	else {
		movegamecharacter(&cat, cat.x, cat.y);
	}
}*/

void performantdelay(UINT8 numloops) {
	UINT8 i;
	for (i = 0; i < numloops; i++) {
		wait_vbl_done();
	}
}

UBYTE checkcollisions(GameCharacter* one, GameCharacter* two) {
	return (one->x >= two->x && one->x <= two->x + two->width) && (one->y >= two->y && one->y <= two->y + two->height) || (two->x >= one->x && two->x <= one->x + one->width) && (two->y >= one->y && two->y <= one->y + one->height);
}


void main() {

	set_sprite_data(0, 8, characters);

	//NR52_REG = 0x80;
	//NR50_REG = 0x77;
	//NR51_REG = 0xFF;
	
	//font_t min_font; // ������ ���������� ������� ������ �����
	//font_init(); // �������������� �����
	//min_font = font_load(font_min); // ���������� � ���������� ���� �� ������� � ������� ����, �������� 36 ������
	//font_set(min_font); // ������������� ����� � �������� ����� �������� ���������� � ��������� � ����� ������ 

	//set_bkg_data(37, 7, backgroundtiles);
	//set_bkg_tiles(0, 0, 40, 18, backgroundmap);

	//set_win_tiles(0, 0, 16, 1, windowmap); // ������������� ����������, ���-�� �������� � ������� � �����, ������� ����� ������� �� ������ windowmap
	//move_win(7, 100); // ���������� ��� ���� ������ ����  
	
	//playerlocation[0] = 10;
	//playerlocation[1] = floorYposition;
	//jumping = 0;

	//move_sprite(0, playerlocation[0], playerlocation[1]);

	setupcat();
	setupenemy(); 
	// SHOW_BKG;  
	// SHOW_WIN;
	SHOW_SPRITES;
	DISPLAY_ON; 

	while (!checkcollisions(&cat, &enemy)) {
		if (joypad() & J_LEFT) {
			cat.x -= 2;
			movegamecharacter(&cat, cat.x, cat.y);
		}
		if (joypad() & J_RIGHT) {
			cat.x += 2;
			movegamecharacter(&cat, cat.x, cat.y);
		}
		if (joypad() & J_UP) {
			cat.y -= 2;
			movegamecharacter(&cat, cat.x, cat.y);
		}
		if (joypad() & J_DOWN) {
			cat.y += 2;
			movegamecharacter(&cat, cat.x, cat.y);
		}

		enemy.x -= 5;
		if (enemy.x <= 0) {
			enemy.x = 160;
			enemy.y = cat.y; 
		}
		movegamecharacter(&enemy, enemy.x, enemy.y); 

		performantdelay(5);
	}

	printf("\n \n \n \n == Happy New Year \n \n \n My Sweety Vi :3 ==");
}