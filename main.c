/*

    Подключение необходимых библиотек из SDK - основная gb.h, шрифты - font.h

*/

#include <gb/gb.h>
#include <gb/font.h>
#include <stdio.h>
#include "res/playerSprites/SmilerSprites.c"
#include "res/mapSprites/simplebackground.c"
#include "res/mapSprites/simplebackgroundmap.c"
#include "res/mapSprites/windowmap.c"

void main(){
    font_t min_font; // задаем переменную которая хранит шрифт
    font_init(); // инициализируем шрифт
    min_font = font_load(font_min); // подгружаем в переменную один из шрифтов в массиве либы, занимает 36 тайлов
    font_set(min_font); // устанавливаем шрифт в значение нашей изменной переменной и загружаем в видео память

    set_bkg_data(37, 7, backgroundtiles);
    set_bkg_tiles(0, 0, 40, 18, backgroundmap);

    set_win_tiles(0, 0, 16, 1, windowmap); // устанавливаем координаты, кол-во символов в надписи и строк, которые будут браться из нашего windowmap
    move_win(7, 120); // перемещаем под слой нашего фона

    SHOW_BKG;  
    SHOW_WIN;
    DISPLAY_ON;

    while (1) {
        scroll_bkg(1, 0); // прокрутка фона с небольшой задержкой
        delay(100);
    }
}