# Vi Advantures
<strong>Приключения Ви</strong> - это игра для ретро-консоли <strong>Game Boy / Game Boy Color</strong> разрабатываемая под движком оригинального Game Boy с использованием SDK - [GameBoy Development Kit](https://sourceforge.net/projects/gbdk/files/gbdk-win32/2.95-3/) на языке <strong>C</strong> и <strong>Ассемблере</strong>.

## Процесс разработки
<strong>Требуется установить:</strong>
- [Microsoft Visual Studio](https://visualstudio.microsoft.com/ru/downloads/);
- Пакет [поддержки языков C/C++](https://marketplace.visualstudio.com/items?itemName=ms-vscode.cpptools);
- [Microsoft SDK](https://developer.microsoft.com/ru-ru/windows/downloads/windows-sdk/) под вашу операционную систему;
- Изображения (тайлы) рисуются с помощью утилиты [Gameboy Tile Designer](https://www.devrs.com/gb/hmgd/gbtd.html) и экспортируются в необходимый код для Ассемблера в директории res;
- В качестве эмулятора и дебаггера используется утилита [BGB](https://bgb.bircd.org/).

Для сборки проекта после изменений в системных файлах запускается батник **.\build.bat** он собирает проект в файл с расширением .gb который открывается и эмулятором и консолью.

В качестве тестовой консоли использую оригинальный **Nintendo Gameboy Advance SP AGS-001**, картридж с поддержкой SD-накопителя на которую закидываю файл с расширением **.gb**

### Связь
- linkedin: [Ivan Olovyannikov](https://www.linkedin.com/in/ivan-olovyannikov-052aa0282/)
- e-mail: [iolovyannikov@yandex.ru](iolovyannikov@yandex.ru)

В ходе работы над проектом, документация будет дорабатываться.
