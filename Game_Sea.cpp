#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <windows.h>
#include <cstring>
#include <conio.h>
using namespace std;

int x = 9;
int y = 9;
int e = 0;
int ship = 0;
int user = 0;
int esc = 0;

struct Field
{
	char map[17][19] = {
".....ИГРОК--1.....",
"..................",
"....12345678910...",
"...+----------+...",
"..А|          |...",
"..Б|          |...",
"..В|          |...",
"..Г|          |...",
"..Д|          |...",
"..Е|          |...",
"..Ж|          |...",
"..З|          |...",
"..И|          |...",
"..К|          |...",
"...+----------+...",
"..................",
"..................",
	};
}mapfield1, mapfield2, mapfield3, mapfield4;

void OkrasLogoSea(char map[][55]);
void CursorVisible();
void printStuff(int x, int y);
void ConsoleWindow();
void OkrasMenu(string vibor, int color);
void funcBeckShip(char map[][19], int button1, int a, int b);
void LogoSea();
void fViborSea(int count);

void OkrasField(char map[][19], int color1, int color2, int color3, int color4, int color5, int color6, int x);
void OkrasAutorAndInstr(char map[][70], int color, int str);
void movementOnTheField();
void changFont();
void menuBeckShip(string ship);
void moveField(char map[][19], int but);
void mapAutor();
void mapInstr();
void drawingShips(char map[][19], int but);
void eliminationSticking(char map[][19]);
void winn(int numWin);
void outlineAroundShipInsaid(char map2[][19], int ship, int numShip);
void outlineAroundShip(char map1[][19], char map2[][19], int ship);

int main(){
	ConsoleWindow();
menuGameAgain:

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	CursorVisible();
	changFont();

	int viborSea = 0;
	int buttonSea1 = 0;
	int buttonSea2 = 0;

	LogoSea();

	do
	{
		if (buttonSea2 == 80 || viborSea == 0){
			if (viborSea < 4 && viborSea != 0){
				++viborSea;
			}
			else{
				viborSea = 1;
			}

			fViborSea(viborSea); // Покраска выбранного меню
			buttonSea1 = _getch(); // считывание нажатия клавиши

			if (buttonSea1 == 13){
				printStuff(0, 12);
				break;
			}
			else if (buttonSea1 == 27){
				system("cls");
				x = 21;
				y = 9;
				ship = 0;
				user = 0;
				esc = 0;
				goto menuGameAgain;
			}
			else if (buttonSea1 != 224){
				viborSea = 0;
				printStuff(0, 12);
				continue;
			}

			buttonSea2 = _getch(); // считывание нажатия клавиши

			if (buttonSea2 == 77 || buttonSea2 == 75){
				viborSea = 0;
				printStuff(0, 12);
				continue;
			}
			printStuff(0, 12);
		}
		else if (buttonSea2 == 72){
			if (viborSea <= 4 && viborSea > 1){
				--viborSea;
			}
			else{
				viborSea = 4;
			}

			fViborSea(viborSea); // Покраска выбранного меню
			buttonSea1 = _getch(); // считывание нажатия клавиши

			if (buttonSea1 == 13){
				printStuff(0, 12);
				break;
			}
			else if (buttonSea1 == 27){
				system("cls");
				x = 21;
				y = 9;
				ship = 0;
				user = 0;
				esc = 0;
				goto menuGameAgain;
			}
			else if (buttonSea1 != 224){
				viborSea = 0;
				printStuff(0, 12);
				continue;
			}

			buttonSea2 = _getch(); // считывание нажатия клавиши

			if (buttonSea2 == 77 || buttonSea2 == 75){
				viborSea = 0;
				printStuff(0, 12);
				continue;
			}
			printStuff(0, 12);
		}
	} while (true);

	system("cls");

	if (viborSea == 1) { // Выбор меню играть
		while (true){
			if (esc == 1) { // ESC	
				x = 9;
				y = 9;
				ship = 0;
				user = 0;
				esc = 0;
				goto menuGameAgain;
			}

			printStuff(0, 0);
			LogoSea();

			if (ship == 12) { // Включение расстановки второго игрока			
				x = 48;
				y = 9;
				ship = 0;
				user = 1;
				system("cls");
			}

			if (user == 0 && ship != 13){
				OkrasField(mapfield1.map, 6, 9, 6, 0, 0, 10, 13); //  color1  - '.', color2 - остальное, color3 - 127, color4 - 4, color5 - X, color6 - @, int x - положение курсора
				OkrasField(mapfield2.map, 6, 9, 6, 0, 0, 10, 39); //  color1  - '.', color2 - остальное, color3 - 127, color4 - 4, color5 - X, color6 - @, int x - положение курсора
				if (ship != 11 && ship != 13){
					menuBeckShip("\tИГРОК 1");
					printStuff(0, 31);
				}
			}
			else if (user == 1 && ship != 13){
				OkrasField(mapfield1.map, 6, 9, 0, 0, 0, 10, 13); //  color1  - '.', color2 - остальное, color3 - 127, color4 - 4, color5 - X, color6 - @, int x - положение курсора
				OkrasField(mapfield2.map, 6, 9, 0, 6, 0, 10, 39); //  color1  - '.', color2 - остальное, color3 - 127, color4 - 4, color5 - X, color6 - @, int x - положение курсора
				if (ship != 11 && ship != 13){
					menuBeckShip("\tИГРОК 2");
					printStuff(0, 31);
				}
			}

			int but = 0;

			if (_kbhit()){
				but = _getch();
			}
			if (user == 0 && ship != 11 && ship != 12){
				moveField(mapfield1.map, but);  // передвижение по полю
				drawingShips(mapfield1.map, but); // отрисовка кораблей
			}
			if (user == 1 && ship != 11 && ship != 12){
				moveField(mapfield2.map, but);  // передвижение по полю
				drawingShips(mapfield2.map, but); // отрисовка кораблей	
			}
			if (ship == 11 || ship == 12){
				printStuff(0, 0);
				LogoSea(); // отрисовка логотипа

				string selectionEnd_1;

				if (user == 0){
					selectionEnd_1 = "\t\t1 - скрыть корабли и сменить игрока";
				}
				else if (user == 1){
					selectionEnd_1 = "\t\t1 - скрыть корабли и перейти к стрельбе";
				}

				string selectionEnd_2 = "\t\tBackspace - стереть поле";
				string selectionEnd_3 = "\t\tEsc - для выхода в главное меню";

				printStuff(0, 31);
				OkrasMenu(selectionEnd_1, 6); cout << endl; cout << endl;
				OkrasMenu(selectionEnd_2, 6); cout << endl; cout << endl;
				OkrasMenu(selectionEnd_3, 6); cout << endl; cout << endl;

				if (but == 49) { // очистка поля и переход к стрельбе			
					if (user == 0){
						eliminationSticking(mapfield1.map); // устранение залипания курсора
						ship = 12;
					}
					else if (user == 1){
						ship = 13; // переход к стрельбе 
						eliminationSticking(mapfield2.map); // устранение залипания курсора
						//user = 0;mapfield4.map
						system("cls");
					}
				}
				else if (but == 8) { // стирание облости рисования короблей		
					if (user == 0){
						for (int i = 4; i < 14; i++){
							for (int j = 4; j < 14; j++){
								mapfield1.map[i][j] = ' ';
							}
						}
					}
					else if (user == 1){
						for (int i = 2; i < 12; i++){
							for (int j = 42; j < 52; j++){
								mapfield2.map[i][j] = ' ';
							}
						}
					}

					system("cls");
					ship = 0;
				}
			}

			if (but == 27) { // ЕSC		
				esc = 1;
			}

			string walk1 = "\t\t\t    Ход игрока 1.";
			string walk2 = "\t\t\t    Ход игрока 2.";
			string shot = "\t\t    Чтобы выстрелить нажмите пробел";

			int hit_user1 = 0;
			int hit_user2 = 0;
			int numWin = 0;

			while (ship == 13){ // стрельба		
				printStuff(0, 0);

				int but = 0;

				LogoSea();

				OkrasField(mapfield3.map, 6, 9, 0, 0, 12, 10, 13); //  color1-'.', color2-остальное, color3-127, color4-4, color5-X, color6-@, int x-положение курсора
				OkrasField(mapfield4.map, 6, 9, 0, 0, 12, 10, 39); //  color1-'.', color2-остальное, color3-127, color4-4, color5-X, color6-@, int x-положение курсора

				if (_kbhit()){
					but = _getch();
				}

				if (user == 1 || user == 3) { // Ход первого игрока
					user = 3;

					printStuff(0, 31);
					OkrasMenu(walk1, 12);  cout << endl; cout << endl;
					OkrasMenu(shot, 6); // cout << endl;
					moveField(mapfield4.map, but);  // передвижение по полю

					if (but == 32){
						if (mapfield2.map[y][x] == ' '){
							mapfield4.map[y][x] = '*';

							user = 4;

							int z = 0;

							for (int i = 3; i < 15; i++){
								for (int j = 3; j < 15; j++){
									if (mapfield3.map[i][j] == ' '){
										z = 1;
										x = j;
										y = i;
										mapfield3.map[i][j] = ' ';
										break;
									}
								}
								if (z == 1){
									e = 0; // Устранение переноса звездочки на соседнее поле
									break;
								}
							}
						}
						else if (mapfield2.map[y][x] == 4){
							mapfield4.map[y][x] = 88;

							if (mapfield4.map[y][x] == 88){
								outlineAroundShip(mapfield2.map, mapfield4.map, 4);
							}

							int z = 0;

							for (int i = 3; i < 15; i++){
								for (int j = 3; j < 15; j++){
									if (mapfield4.map[i][j] == ' '){
										z = 1;
										x = j;
										y = i;
										break;
									}
								}
								if (z == 1){
									e = 0;
									break;
								}
							}

							hit_user1++;
							user = 3;
						}
					}
					if (but == 27) { // ЕSC					
						for (int i = 4; i < 14; i++){
							for (int j = 4; j < 14; j++){
								mapfield1.map[i][j] = ' ';
								mapfield3.map[i][j] = ' ';
							}
						}
						for (int i = 2; i < 12; i++){
							for (int j = 42; j < 52; j++){
								mapfield2.map[i][j] = ' ';
								mapfield4.map[i][j] = ' ';
							}
						}
						system("cls");
						esc = 1;
						break;
					}
				}
				else if (user == 4) { // Ход второго игрока				
					printStuff(0, 31);
					OkrasMenu(walk2, 12); cout << endl; cout << endl;
					OkrasMenu(shot, 6);  // cout << endl;

					moveField(mapfield3.map, but);  // передвижение по полю

					if (but == 32){
						if (mapfield1.map[y][x] == ' '){
							mapfield3.map[y][x] = '*';

							user = 3;

							int z = 0;

							for (int i = 1; i < 15; i++){
								for (int j = 41; j < 53; j++){
									if (mapfield4.map[i][j] == ' '){
										z = 1;
										x = j;
										y = i;
										break;
									}
								}
								if (z == 1){
									e = 0; // Устранение переноса звездочки на соседнее поле
									break;
								}
							}
						} 
						else if (mapfield1.map[y][x] == 127){
							mapfield3.map[y][x] = 88;

							if (mapfield3.map[y][x] == 88){
								outlineAroundShip(mapfield1.map, mapfield3.map, 127);
							}

							int z = 0;

							for (int i = 3; i < 15; i++){
								for (int j = 3; j < 15; j++){
									if (mapfield3.map[i][j] == ' '){
										z = 1;
										x = j;
										y = i;
										break;
									}
								}
								if (z == 1){
									e = 0;
									break;
								}
							}

							hit_user2++;
							user = 4;
						}
					}
					if (but == 27) { // ЕSC
						for (int i = 4; i < 14; i++){
							for (int j = 4; j < 14; j++){
								mapfield1.map[i][j] = ' ';
								mapfield3.map[i][j] = ' ';
							}
						}
						for (int i = 2; i < 12; i++){
							for (int j = 42; j < 52; j++){
								mapfield2.map[i][j] = ' ';
								mapfield4.map[i][j] = ' ';
							}
						}
						system("cls");
						esc = 1;
						break;
					}
				}
				if (hit_user1 == 20){
					system("cls");
					numWin = 1;
					winn(numWin);
					break;
				}
				else if (hit_user2 == 20){
					system("cls");
					numWin = 2;
					winn(numWin);
					break;
				}
			}
			if (esc == 1) { // ЕSC			
				for (int i = 4; i < 14; i++){
					for (int j = 4; j < 14; j++){
						mapfield1.map[i][j] = ' ';
					}
				}
				for (int i = 2; i < 12; i++){
					for (int j = 42; j < 52; j++){
						mapfield2.map[i][j] = ' ';
					}
				}
				system("cls");
			}
		}
	}
	else if (viborSea == 2){
	do{
		system("cls");
		LogoSea();
		mapInstr();

		int butt = _getch();

		if (butt == 27){
			esc = 1;			
		}
	} while (esc == 0);

	if (esc == 1){
		system("cls");
		x = 9;
		y = 9;
		ship = 0;
		user = 0;
		esc = 0;
		goto menuGameAgain;
		}
	}
	else if (viborSea == 3){
		system("cls");
		int butt;

		LogoSea();

		do{
			mapAutor();

			if (_kbhit()){
				butt = _getch();
				if (butt == 27){
					break;
				}
			}
		} while (true);

		system("cls");
		x = 9;
		y = 9;
		ship = 0;
		user = 0;
		esc = 0;
		goto menuGameAgain;
	}

	system("pause>nul");
}
void OkrasField(char map[][19], int color1, int color2, int color3, int color4, int color5, int color6, int x){ // Цвет игрового поля
	HANDLE consoleOutput;
	consoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);

	for (int i = 0; i < 17; i++) { //печать поля
		printStuff(x, i + 12);

		for (int j = 0; j < 19; j++){
			if (map[i][j] == '.'){				
				SetConsoleTextAttribute(consoleOutput, color1); //Перед строкой для выделения текста цветом 
					cout << map[i][j];		
				SetConsoleTextAttribute(consoleOutput, 15); //Возвращаем назад цвет
			}
			else if (map[i][j] == 127){
				SetConsoleTextAttribute(consoleOutput, color3); //Перед строкой для выделения текста цветом
					cout << map[i][j];
				SetConsoleTextAttribute(consoleOutput, 15); //Возвращаем назад цвет
			}
			else if (map[i][j] == 4){
				SetConsoleTextAttribute(consoleOutput, color4); //Перед строкой для выделения текста цветом
					cout << map[i][j];
				SetConsoleTextAttribute(consoleOutput, 15); //Возвращаем назад цвет
			}
			else if (map[i][j] == 88){
				SetConsoleTextAttribute(consoleOutput, color5); //Перед строкой для выделения текста цветом
					cout << map[i][j];
				SetConsoleTextAttribute(consoleOutput, 15); //Возвращаем назад цвет
			}
			else if (map[i][j] == 64){
				SetConsoleTextAttribute(consoleOutput, color6); //Перед строкой для выделения текста цветом
					cout << map[i][j];
				SetConsoleTextAttribute(consoleOutput, 15); //Возвращаем назад цвет
			}
			else{
				SetConsoleTextAttribute(consoleOutput, color2); //Перед строкой для выделения текста цветом
					cout << map[i][j];
				SetConsoleTextAttribute(consoleOutput, 15); //Возвращаем назад цвет
			}
		}
		cout << endl;
	}
	mapfield2.map[0][12] = '2'; // замена на экземпляре поля номер игрока
	mapfield4.map[0][12] = '2'; // замена на экземпляре поля номер игрока
}
void menuBeckShip(string ship){ // Меню установки кораблей
	printStuff(0, 31);

	string installationMenu = "\t\t\t УСТАНОВИТЕ КОРАБЛИ";
	string horizontally = "\t\t1 - установка по горизонтали 'слева на право'";
	string vertically = "\t\t2 - установка по вертикали 'cнизу вверх'";
	string erase = "\t\tBackspace - стереть поле";
	string exit = "\t\tEsc - для выхода в главное меню";

	OkrasMenu(installationMenu, 6); cout << endl; cout << endl;
	OkrasMenu(ship, 9); cout << endl; cout << endl;
	OkrasMenu(horizontally, 6); cout << endl; cout << endl;
	OkrasMenu(vertically, 6); cout << endl; cout << endl;
	OkrasMenu(erase, 6); cout << endl; cout << endl;
	OkrasMenu(exit, 6); cout << endl; cout << endl;
}
void OkrasLogoSea(char map[][55]){// цвет логотипа
	HANDLE consoleOutput;
	consoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);

	for (int i = 0; i < 12; i++){
		if (i % 2 == 0){
			SetConsoleTextAttribute(consoleOutput, 6); //Перед строкой для выделения текста цветом 
				cout << "\t" << map[i] << endl;
			SetConsoleTextAttribute(consoleOutput, 15); //Возвращаем назад цвет
		}
		else{
			SetConsoleTextAttribute(consoleOutput, 9); //Перед строкой для выделения текста цветом
				cout << "\t" << map[i] << endl;
			SetConsoleTextAttribute(consoleOutput, 15); //Возвращаем назад цвет
		}
	}
}
void funcBeckShip(char map[][19], int button1, int a, int b){ // Функция расстановки кораблей
	char a1;
	int pr = 0;

	if (user == 0) {
		a1 = 127;
	}
	else if (user == 1) {
		a1 = 4;
	}

	int count = 0; // счетчик выполнений если 4х палубный это 10, если 3х - 8 и т.д.

	if (button1 == 50) { // если корабль ставить вертикально	
		for (int i = 0; i < b; i++) { // 4х b = 6; 3х b= 5; 2х b= 4; 1на b= 3;		
			if (map[(y + 1) - i][x + 1] != a1 && map[(y + 1) - i][x - 1] != a1){
				count++;
			}
		}
		if (map[y + 1][x] != a1 && map[y - (b - 2)][x] != a1){
			count++;
		}
		for (int i = 1; i <= (b - 3); i++){
			if (map[y - i][x] != '-'){
				count++;
			}
		}
		if (count == a) { // если все условия выполнения верны		
			for (int i = 0; i < (b - 2); i++){
				map[y - i][x] = a1;
			}

			count = 0;
			pr = 1;
		}
		else if (count != a){
			if (map[y][x] == '@'){
				map[y][x] = ' ';
			}
			else if (map[y][x] == '9'){
				map[y][x] = a1;
			}
			count = 0;
		}
		if (user == 0){
			int z = 0;

			for (int i = 3; i < 15; i++){
				for (int j = 3; j < 15; j++){
					if (map[i][j] == ' '){
						int z = 1;
						x = j;
						y = i;
						break;
					}
				}
				if (z == 1){
					break;
				}
			}
		}
		if (user == 1){
			int z = 0;

			for (int i = 2; i < 12; i++){
				for (int j = 41; j < 53; j++){
					if (map[i][j] == ' '){
						int z = 1;
						x = j;
						y = i;
						break;
					}
				}
				if (z == 1){
					break;
				}
			}
		}
		if (pr == 1){
			++ship;
			printStuff(0, 0);
		}
	}
	else if (button1 == 49) { // если корабль ставить горизонтально	
		for (int i = 0; i < b; i++) { // 4х b = 6; 3х = 5; 2х = 4; 1на = 3;	
			if (map[y + 1][(x - 1) + i] != a1 && map[y - 1][(x - 1) + i] != a1){
				count++;
			}
		}
		if (map[y][x - 1] != a1 && map[y][x + (b - 2)] != a1){
			count++;
		}
		for (int i = 1; i <= (b - 3); i++){
			if (map[y][x + i] != '|'){
				count++;
			}
		}
		if (count == a){
			for (int i = 0; i < (b - 2); i++){
				map[y][x + i] = a1;
			}
			count = 0;
			pr = 1;
		}
		else if (count != a){
			if (map[y][x] == '@'){
				map[y][x] = ' ';
			}
			else if (map[y][x] == '9'){
				map[y][x] = a1;
			}
			count = 0;
		}
		if (user == 0){
			int z = 0;

			for (int i = 3; i < 15; i++){
				for (int j = 3; j < 15; j++){
					if (map[i][j] == ' '){
						int z = 1;
						x = j;
						y = i;
						break;
					}
				}
				if (z == 1){
					break;
				}
			}
		}
		if (user == 1){
			int z = 0;

			for (int i = 3; i < 15; i++){
				for (int j = 41; j < 53; j++){
					if (map[i][j] == ' '){
						int z = 1;
						x = j;
						y = i;
						break;
					}
				}
				if (z == 1){
					break;
				}
			}
		}
		if (pr == 1){
			++ship;
			//system("cls");
			printStuff(0, 0);
		}
	}
	if (button1 == 8){
		if (user == 0){
			for (int i = 4; i < 14; i++){
				for (int j = 4; j < 14; j++){
					map[i][j] = ' ';
				}
			}
		}
		else if (user == 1){
			for (int i = 2; i < 12; i++){
				for (int j = 42; j < 52; j++){
					map[i][j] = ' ';
				}
			}
		}
		ship = 0;
	}
	if (button1 == 27){
		for (int i = 4; i < 14; i++){
			for (int j = 4; j < 14; j++){
				mapfield1.map[i][j] = ' ';
			}
		}
		for (int i = 2; i < 12; i++){
			for (int j = 42; j < 52; j++){
				mapfield2.map[i][j] = ' ';
			}
		}
		system("cls");
		esc = 1;
	}
}
void LogoSea(){ // Логотип морского боя
	char mapLogo[55][55] = {
		"   888  88888   88     8888888888888888888888888888888",
		"  8     8      8  8    88<><><><><><><><><><><><><><88",
		"   888  8888  8    8   8888888888888888888888888888888",
		"      8 8     888888 ",
		"888888  8888  8    8 ",
		"                   888      88  88888 88888 8    88888",
		"                   8  8    8  8   8     8   8    8",
		"888888888888888888 8 88   8    8  8     8   8    8888 ",
		"88<><><><><><><>88 8  88  888888  8     8   8    8",
		"888888888888888888 88888  8    8  8     8   8888 8888",
	};
	OkrasLogoSea(mapLogo);
}
void fViborSea(int count){ // Передвижение по меню Морской бой
	string oneVibor = " 1. ИГРАТЬ ";
	string twoVibor = " 2. ОПИСАНИЕ ";
	string threeVibor = " 3. АВТОРЫ ";
	string fourVibor = " 4. ВЫХОД ";

	int a1 = 9;
	int a2 = 9;
	int a3 = 9;
	int a4 = 9;

	if (count == 1)
		a1 = 6;
	else if (count == 2)
		a2 = 6;
	else if (count == 3)
		a3 = 6;
	else if (count == 4)
		a4 = 6;

	cout << endl; cout << endl;
	cout << "\t\t\t\t"; OkrasMenu(oneVibor, a1); cout << endl; cout << endl;
	cout << "\t\t\t\t"; OkrasMenu(twoVibor, a2); cout << endl; cout << endl;
	cout << "\t\t\t\t"; OkrasMenu(threeVibor, a3); cout << endl; cout << endl;
	cout << "\t\t\t\t"; OkrasMenu(fourVibor, a4); cout << endl; cout << endl;
}
void moveField(char map[][19], int but){ //передвижение по полю
	char a, b, c;
	c = 42; // *
	b = 64; // @

	//cout << "y = " << y << endl; // Координаты y
	//cout << "x = " << x << endl; // Координаты x

	if (user == 0){
		a = 127;
	}
	else if (user == 1){
		a = 4;
	}
	else if (user == 3 || user == 4){
		a = 88; // X
	}
	if (but == 80) { // движение вниз
		if (map[y + 1][x] == a && e == 1) { // []	
			map[y][x] = a;
			y++;
			map[y][x] = b;
		}
		else if (map[y + 1][x] == ' ' && e == 1) { // []		
			map[y][x] = a;
			y++;
			map[y][x] = b;
			e = 0;
		}
		else if (map[y + 1][x] == c && e == 1) { // *		
			map[y][x] = a;
			y++;
			map[y][x] = b;
			e = 2;
		}
		else if (map[y + 1][x] == a && e == 0) { // []		
			map[y][x] = ' ';
			y++;
			map[y][x] = b;
			e = 1;
		}
		else if (map[y + 1][x] == ' ' && e == 0){
			map[y][x] = ' ';
			y++;
			map[y][x] = b;
		}
		else if (map[y + 1][x] == c && e == 0) { // *	
			map[y][x] = ' ';
			y++;
			map[y][x] = b;
			e = 2;
		}
		else if (map[y + 1][x] == c && e == 2) { // *		
			map[y][x] = c;
			y++;
			map[y][x] = b;
		}
		else if (map[y + 1][x] == ' ' && e == 2) { // *		
			map[y][x] = c;
			y++;
			map[y][x] = b;
			e = 0;
		}
		else if (map[y + 1][x] == a && e == 2) { // *		
			map[y][x] = c;
			y++;
			map[y][x] = b;
			e = 1;
		}
	}
	else if (but == 72){
		if (map[y - 1][x] == a && e == 1) { // []		
			map[y][x] = a;
			y--;
			map[y][x] = b;
		}
		else if (map[y - 1][x] == ' ' && e == 1) { // []		
			map[y][x] = a;
			y--;
			map[y][x] = b;
			e = 0;
		}
		else if (map[y - 1][x] == c && e == 1) { // *	
			map[y][x] = a;
			y--;
			map[y][x] = b;
			e = 2;
		}
		else if (map[y - 1][x] == a && e == 0) { // []		
			map[y][x] = ' ';
			y--;
			map[y][x] = b;
			e = 1;
		}
		else if (map[y - 1][x] == ' ' && e == 0){
			map[y][x] = ' ';
			y--;
			map[y][x] = b;
		}
		else if (map[y - 1][x] == c && e == 0) { // *		
			map[y][x] = ' ';
			y--;
			map[y][x] = b;
			e = 2;
		}
		else if (map[y - 1][x] == c && e == 2) { // *		
			map[y][x] = c;
			y--;
			map[y][x] = b;
		}
		else if (map[y - 1][x] == ' ' && e == 2) { // *	
			map[y][x] = c;
			y--;
			map[y][x] = b;
			e = 0;
		}
		else if (map[y - 1][x] == a && e == 2) { // *		
			map[y][x] = c;
			y--;
			map[y][x] = b;
			e = 1;
		}
	}
	else if (but == 77){
		if (map[y][x + 1] == a && e == 1) { // []		
			map[y][x] = a;
			x++;
			map[y][x] = b;
		}
		else if (map[y][x + 1] == ' ' && e == 1) { // []		
			map[y][x] = a;
			x++;
			map[y][x] = b;
			e = 0;
		}
		else if (map[y][x + 1] == c && e == 1) { // *	
			map[y][x] = a;
			x++;
			map[y][x] = b;
			e = 2;
		}
		else if (map[y][x + 1] == a && e == 0) { // []	
			map[y][x] = ' ';
			x++;
			map[y][x] = b;
			e = 1;
		}
		else if (map[y][x + 1] == ' ' && e == 0){
			map[y][x] = ' ';
			x++;
			map[y][x] = b;
		}
		else if (map[y][x + 1] == c && e == 0) { // *		
			map[y][x] = ' ';
			x++;
			map[y][x] = b;
			e = 2;
		}
		else if (map[y][x + 1] == c && e == 2) { // *	
			map[y][x] = c;
			x++;
			map[y][x] = b;
		}
		else if (map[y][x + 1] == ' ' && e == 2) { // *		
			map[y][x] = c;
			x++;
			map[y][x] = b;
			e = 0;
		}
		else if (map[y][x + 1] == a && e == 2) { // *		
			map[y][x] = c;
			x++;
			map[y][x] = b;
			e = 1;
		}
	}
	else if (but == 75){
		if (map[y][x - 1] == a && e == 1) { // []		
			map[y][x] = a;
			x--;
			map[y][x] = b;
		}
		else if (map[y][x - 1] == ' ' && e == 1) { // []		
			map[y][x] = a;
			x--;
			map[y][x] = b;
			e = 0;
		}
		else if (map[y][x - 1] == c && e == 1) { // *		
			map[y][x] = a;
			x--;
			map[y][x] = b;
			e = 2;
		}
		else if (map[y][x - 1] == a && e == 0) { // []		
			map[y][x] = ' ';
			x--;
			map[y][x] = b;
			e = 1;
		}
		else if (map[y][x - 1] == ' ' && e == 0) {		
			map[y][x] = ' ';
			x--;
			map[y][x] = b;
		}
		else if (map[y][x - 1] == c && e == 0) { // *		
			map[y][x] = ' ';
			x--;
			map[y][x] = b;
			e = 2;
		}
		else if (map[y][x - 1] == c && e == 2) { // *		
			map[y][x] = c;
			x--;
			map[y][x] = b;
		}
		else if (map[y][x - 1] == ' ' && e == 2) { // *		
			map[y][x] = c;
			x--;
			map[y][x] = b;
			e = 0;
		}
		else if (map[y][x - 1] == a && e == 2) { // *		
			map[y][x] = c;
			x--;
			map[y][x] = b;
			e = 1;
		}
	}
}
void mapAutor(){// Функция отображения автора
	char map[70][70] = {
"	&& && &&&   &&  & &&   & &&   &&  & && &&  & ",
"	&&&  &&  &  &&& &  && & && &  &&  &    &&& & ",
"	&&  &&    & && &&   && &&   & &&&&& && && && ",
"	&&&  &&  &  &&  &   && &&&&&& &&  & && &&  & ",
"	&& && &&&   &&  &   && &    & &&  & && &&  & ",
"",
"	       &&    & && &&&&  &&   &&   && &&   &",
"	       &&    &     &&  && &  &&       && &",
"	        &&  &  &&  && &&   & &&   &&   &&",
"	         &&&   &&  && &&&&&& &&   &&   &&",
"	          &    &&  && &    & &&&& &&   &&",
	};
	printStuff(0, 15);
	OkrasAutorAndInstr(map, 12, 11);
	printStuff(0, 15);
	OkrasAutorAndInstr(map, 6, 11);
	printStuff(0, 15);
	OkrasAutorAndInstr(map, 14, 11);
	printStuff(0, 15);
	OkrasAutorAndInstr(map, 10, 11);
	printStuff(0, 15);
	OkrasAutorAndInstr(map, 11, 11);
	printStuff(0, 15);
	OkrasAutorAndInstr(map, 9, 11);
	printStuff(0, 15);
	OkrasAutorAndInstr(map, 13, 11);
	printStuff(0, 15);
}
void mapInstr(){// Функция меню описания
	char map[35][70]
	{
	"                                     ПРАВИЛА ИГРЫ",
	"        ",
	"          Играют двое игроков.",
	"        ",
	"        Правила морского боя говорят, что должно быть:",
	"        ",
	"          4 корабля по одной клеточке (однопалубный),",
	"        ",
	"          3 корабля по 2 клеточки(двухпалубный),",
	"        ",
	"          2 корабля по 3 клеточки(трехпалубный)",
	"        ",
	"          1 корабль — четырёхпалубный.",
	"        ",
	"        Корабли располагаются на игровом поле таким образом,",
	"        ",
	"          чтобы между ними всегда был зазор в одну клеточку.",
	"        ",
	"        Корабли могут касаться краёв поля и занимать углы.",
	"        ",
	"        Когда корабли расставлены, игроки по очереди",
	"        ",
	"          производят «выстрелы», выбирая область в поле.",
	"        ",
	"        Если выстрел пришёлся в не занятую кораблём область ",
	"        ",
	"          противника то право хода переходит к сопернику.",
	"        ",
	"        Если выстрел пришёлся в область, где находится корабль,",
	"        ",
	"          стрелявший игрок получает право на ещё один выстрел.",
	};
	printStuff(0, 12);
	OkrasAutorAndInstr(map, 6, 31);
}
void OkrasAutorAndInstr(char map[][70], int color, int str){// Окрашивание пункта Автор
	HANDLE consoleOutput;
	consoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);

	for (int i = 0; i < str; i++){
		for (int j = 0; j < 70; j++){
			SetConsoleTextAttribute(consoleOutput, color); //Перед строкой для выделения текста цветом
				cout << map[i][j];
			SetConsoleTextAttribute(consoleOutput, 15); //Возвращаем назад цвет
		}
		cout << endl;
	}
}
void drawingShips(char map[][19], int but){// Отрисовка кораблей
	string sea4 = "\t\tПоставте  четырехпалубный корабль";
	string sea3 = "\t\tПоставте  трехпалубный корабль   ";
	string sea2 = "\t\tПоставте  двухпалубный корабль   ";
	string sea1 = "\t\tПоставте  однопалубный корабль   ";
	
	if (ship == 0 && map[y][x] == '@') {
		menuBeckShip(sea4); // меню установки корабля
		funcBeckShip(map, but, 10, 6); // Функция расстановки кораблей
	}
	else if (ship == 1 || ship == 2 && map[y][x] == '@') {
		menuBeckShip(sea3); // меню установки корабля
		funcBeckShip(map, but, 8, 5); // Функция расстановки кораблей
	}
	else if (ship == 3 || ship == 4 || ship == 5 && map[y][x] == '@'){
		menuBeckShip(sea2); // меню установки корабля
		funcBeckShip(map, but, 6, 4); // Функция расстановки кораблей
	}
	else if (ship == 6 || ship == 7 || ship == 8 || ship == 9 && map[y][x] == '@'){
		menuBeckShip(sea1); // меню установки корабля
		funcBeckShip(map, but, 4, 3); // Функция расстановки кораблей
	}	
	else if (ship == 10){
		system("cls"); // очистка экрана
		ship = 11;
	}
}
void outlineAroundShip(char map1[][19], char map2[][19], int ship){ // Отрисовка вокруг убитого корабля
	int numShip = 0;

	if (map2[y + 1][x] == 88 && map2[y - 1][x] == 88 && map1[y + 2][x] != ship && map1[y - 2][x] != ship){
		y++;
		outlineAroundShipInsaid(map2, 3, 2);
	}
	else if (map2[y + 1][x] == 88 && map2[y + 2][x] == 88 && map2[y - 1][x] == 88 ){
		y += 2;
		outlineAroundShipInsaid(map2, 4, 2);
	}
	else if (map2[y - 1][x] == 88 && map2[y - 2][x] == 88 && map2[y + 1][x] == 88){
		y -= 2;
		outlineAroundShipInsaid(map2, 4, 1);
	}
	if (map2[y][x + 1] == 88 && map2[y][x - 1] == 88 && map1[y][x + 2] != ship && map1[y][x - 2] != ship){
		x++;
		outlineAroundShipInsaid(map2, 3, 4);
	}
	else if (map2[y][x + 1] == 88 && map2[y][x + 2] == 88 && map2[y][x - 1] == 88 ){
		x += 2;
		outlineAroundShipInsaid(map2, 4, 4);
	}
	else if (map2[y][x - 2] == 88 && map2[y][x + 1] == 88 && map2[y][x - 1] == 88){
		x -= 2;
		outlineAroundShipInsaid(map2, 4, 3);
	}
	if (map1[y + 1][x] != ship && map1[y - 1][x] != ship
		&& map1[y][x + 1] != ship && map1[y][x - 1] != ship){
		numShip = 1;
		outlineAroundShipInsaid(map2, 1, 1); // Функция обрисовки однопалубного
	}
	else if (map2[y + 1][x] == 88){
		numShip = 1;

		if (map1[y + 2][x] != ship && map1[y - 1][x] != ship){
			outlineAroundShipInsaid(map2, 2, 1); // Функция обрисовки двухпалубного
		}
		else if (map2[y + 2][x] == 88){
			if (map1[y + 3][x] != ship && map1[y - 1][x] != ship){
				outlineAroundShipInsaid(map2, 3, 1); // Функция обрисовки трехпалубного
			}
			else if (map2[y + 3][x] == 88){
				outlineAroundShipInsaid(map2, 4, 1); // Функция обрисовки четырехпалубного
			}
		}
	}
	else if (map2[y - 1][x] == 88){
		numShip = 2;

		if (map1[y - 2][x] != ship && map1[y + 1][x] != ship){
			outlineAroundShipInsaid(map2, 2, 2); // Функция обрисовки двухпалубного
		}
		else if (map2[y - 2][x] == 88){
			if (map1[y - 3][x] != ship && map1[y + 1][x] != ship){
				outlineAroundShipInsaid(map2, 3, 2); // Функция обрисовки трехпалубного
			}
			else if (map2[y - 3][x] == 88){
				outlineAroundShipInsaid(map2, 4, 2); // Функция обрисовки четырехпалубного
			}
		}
	}
	else if (map2[y][x + 1] == 88){
		numShip = 3;

		if (map1[y][x + 2] != ship && map1[y][x - 1] != ship){
			outlineAroundShipInsaid(map2, 2, 3); // Функция обрисовки двухпалубного
		}
		else if (map2[y][x + 2] == 88){
			if (map1[y][x + 3] != ship && map1[y][x - 1] != ship){
				outlineAroundShipInsaid(map2, 3, 3); // Функция обрисовки трехпалубного

				if (map2[y + 1][x] == 88 && map2[y - 1][x] == 88 && map2[y + 2][x] != ship && map2[y - 2][x] == ship){
					outlineAroundShipInsaid(map2, 3, 1); // Функция обрисовки трехпалубного
				}
			}
			else if (map2[y][x + 3] == 88){
				outlineAroundShipInsaid(map2, 4, 3); // Функция обрисовки четырехпалубного
			}
		}
	}
	else if (map2[y][x - 1] == 88){
		numShip = 4;

		if (map1[y][x - 2] != ship && map1[y][x + 1] != ship){
			outlineAroundShipInsaid(map2, 2, 4); // Функция обрисовки двухпалубного
		}
		else if (map2[y][x - 2] == 88){
			if (map1[y][x - 3] != ship && map1[y][x + 1] != ship){
				outlineAroundShipInsaid(map2, 3, 4); // Функция обрисовки трехпалубного

				if (map2[y + 1][x] == 88 && map2[y - 1][x] == 88 && map2[y + 2][x] != ship && map2[y - 2][x] == ship){
					outlineAroundShipInsaid(map2, 3, 1); // Функция обрисовки трехпалубного
				}
			}
			else if (map2[y][x - 3] == 88){
				outlineAroundShipInsaid(map2, 4, 4); // Функция обрисовки четырехпалубного
			}
		}
	}
}
void outlineAroundShipInsaid(char map[][19], int ship, int numShip){// Отрисовка вокруг убитого корабля внутреняя функция
	if (numShip == 1){
		for (int i = 0; i < ship; i++){
			if (map[y + i][x + 1] == ' ') { // Отрисовка вокруг коробля с правой стороны			
				map[y + i][x + 1] = '*';
			}
			if (map[y + i][x - 1] == ' ') { // Отрисовка коробля с левой стороны			
				map[y + i][x - 1] = '*';
			}
		}
		if (map[y - 1][x] == ' ') { // Отрисовка коробля сверху
			map[y - 1][x] = '*';
		}
		if (map[y - 1][x + 1] == ' ') { // Отрисовка коробля сверху cправа
			map[y - 1][x + 1] = '*';
		}
		if (map[y - 1][x - 1] == ' ') { // Отрисовка коробля сверху слева
			map[y - 1][x - 1] = '*';
		}
		if (map[y + ship][x] == ' ') { // Отрисовка коробля снизу	
			map[y + ship][x] = '*';
		}
		if (map[y + ship][x + 1] == ' ') { // Отрисовка коробля снизу	
			map[y + ship][x + 1] = '*';
		}
		if (map[y + ship][x - 1] == ' ') { // Отрисовка коробля снизу		
			map[y + ship][x - 1] = '*';
		}
	}
	else if (numShip == 2){
		for (int i = 0; i < ship; i++){
			if (map[y - i][x + 1] == ' ') { // Отрисовка вокруг коробля с правой стороны			
				map[y - i][x + 1] = '*';
			}
			if (map[y - i][x - 1] == ' ') { // Отрисовка коробля с левой стороны			
				map[y - i][x - 1] = '*';
			}
		}
		if (map[y + 1][x] == ' ') { // Отрисовка коробля снизу	
			map[y + 1][x] = '*';
		}
		if (map[y + 1][x + 1] == ' ') { // Отрисовка коробля снизу	
			map[y + 1][x + 1] = '*';
		}
		if (map[y + 1][x - 1] == ' ') { // Отрисовка коробля снизу		
			map[y + 1][x - 1] = '*';
		}
		if (map[y - ship][x] == ' ') { // Отрисовка коробля сверху	
			map[y - ship][x] = '*';
		}
		if (map[y - ship][x + 1] == ' ') { // Отрисовка коробля сверху		
			map[y - ship][x + 1] = '*';
		}
		if (map[y - ship][x - 1] == ' ') { // Отрисовка коробля сверху		
			map[y - ship][x - 1] = '*';
		}
	}
	else if (numShip == 3){
		for (int i = 0; i < ship; i++){
			if (map[y + 1][x + i] == ' ') {  // Отрисовка коробля снизу			
				map[y + 1][x + i] = '*';
			}
			if (map[y - 1][x + i] == ' ') { // Отрисовка коробля сверху			
				map[y - 1][x + i] = '*';
			}
		}
		if (map[y][x - 1] == ' ') { // Отрисовка коробля слева		
			map[y][x - 1] = '*';
		}
		if (map[y + 1][x - 1] == ' ') { // Отрисовка коробля слева		
			map[y + 1][x - 1] = '*';
		}
		if (map[y - 1][x - 1] == ' ') { // Отрисовка коробля слева	
			map[y - 1][x - 1] = '*';
		}
		if (map[y][x + ship] == ' ') { // Отрисовка коробля справа	
			map[y][x + ship] = '*';
		}
		if (map[y + 1][x + ship] == ' ') { // Отрисовка коробля справа		
			map[y + 1][x + ship] = '*';
		}
		if (map[y - 1][x + ship] == ' ') { // Отрисовка коробля справа	
			map[y - 1][x + ship] = '*';
		}
	}
	else if (numShip == 4){
		for (int i = 0; i < ship; i++){
			if (map[y + 1][x - i] == ' ') {  // Отрисовка коробля снизу			
				map[y + 1][x - i] = '*';
			}
			if (map[y - 1][x - i] == ' ') { // Отрисовка коробля сверху			
				map[y - 1][x - i] = '*';
			}
		}
		if (map[y][x + 1] == ' ') { // Отрисовка коробля справа	
			map[y][x + 1] = '*';
		}
		if (map[y + 1][x + 1] == ' ') { // Отрисовка коробля справа	
			map[y + 1][x + 1] = '*';
		}
		if (map[y - 1][x + 1] == ' ') { // Отрисовка коробля справа	
			map[y - 1][x + 1] = '*';
		}
		if (map[y][x - ship] == ' ') { // Отрисовка коробля слева	
			map[y][x - ship] = '*';
		}
		if (map[y + 1][x - ship] == ' ') { // Отрисовка коробля слева		
			map[y + 1][x - ship] = '*';
		}
		if (map[y - 1][x - ship] == ' ') { // Отрисовка коробля слева		
			map[y - 1][x - ship] = '*';
		}
	}
}
void winn(int numWin){ // Победа
	do{
		printStuff(0, 0);
		LogoSea();

		HANDLE consoleOutput;
		consoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);

		SetConsoleTextAttribute(consoleOutput, 12); //Перед строкой для выделения текста цветом

		cout << endl; cout << endl; cout << endl;
		cout << "\t\t\t\t ИГРОК " << numWin << " ВЫГРАЛ!!!";
		cout << endl; cout << endl;
		cout << "\t\t\t Нажмите Esc для выхода в меню";

		SetConsoleTextAttribute(consoleOutput, 15); //Возвращаем назад цвет

		int buttonWalk = _getch();

		if (buttonWalk == 27){
			esc = 1;
		}
	} while (esc == 0);
}
void eliminationSticking(char map[][19]){// устранение залипания курсора
	if (map[y][x] == '@') { 	
		map[y][x] = ' ';
	}
}
void CursorVisible(){// Скрыть видимость курсора
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);	// Получение дескриптора устройства стандартного вывода
	CONSOLE_CURSOR_INFO structCursorInfo;
	GetConsoleCursorInfo(hConsole, &structCursorInfo);
	structCursorInfo.bVisible = FALSE;
	SetConsoleCursorInfo(hConsole, &structCursorInfo);
}
void ConsoleWindow(){ // Размер окна консоли и его отображение
	HWND window_header = GetConsoleWindow();
	SetWindowPos(window_header, HWND_TOP, 200, 100, 800, 1000, NULL);
}
void printStuff(int x, int y)// Обновление экрана{
	// Sleep(95);
	HANDLE hd = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD cd;
	cd.X = x;
	cd.Y = y;
	SetConsoleCursorPosition(hd, cd);
}
void changFont(){ // Смена шрифта  + размер шрифта
	CONSOLE_FONT_INFOEX cfi;
	cfi.cbSize = sizeof(cfi);
	cfi.nFont = 0;
	cfi.dwFontSize.X = 16;                   // Width of each character in the font
	cfi.dwFontSize.Y = 16;                  // Height
	cfi.FontFamily = FF_DONTCARE;
	cfi.FontWeight = FW_NORMAL;
	std::wcscpy(cfi.FaceName, L"Lucida Console"); // Choose your font
	SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &cfi);
}
void OkrasMenu(string vibor, int color){  // Окрашивание меню
	HANDLE consoleOutput;
	consoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);

	SetConsoleTextAttribute(consoleOutput, color); //Перед строкой для выделения текста цветом
		cout << vibor;
	SetConsoleTextAttribute(consoleOutput, 15); //Возвращаем назад цвет
}
