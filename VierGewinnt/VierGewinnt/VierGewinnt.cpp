//Vier Gewinnt

//Benötigte Librarys

#include "stdafx.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <windows.h>

using namespace std;

//Benötigte Funktionen

void game_human (int playground[]);		//Steuert Ablauf pvp
void draw (int playground[]);			//"Malt" Spielfeld
void winplayer1 (int& a, int playground[]);	//Siegbedingungen für Spieler
void winplayer2 (int& a, int playground[]);	//Siegbedingungen für Computer
void clear (int playground[], int j);		//Leert das Array
void move1 (int& a, int playground[]);	//Steuert die Bewegung der Spielsteine
void move2 (int& a, int playground[]);	//Steuert die Bewegung der Spielsteine
void menu ();					//Auswahl des Spieltyps


int main( int argc, char* argv[]) {
	
	cout << "\n---Vier Gewinnt---\n\n";	//Start des Programs

	menu ();				//Funktion "Menu" wird aufgerufen

	system("PAUSE");
	return 0;
}


void menu () {					//Hier wird der Spieltyp gewählt
	
	char e;
	int r = 0;
	int *numArray = new int [72]; //Pointer auf Array

	while (r == 0) {

start2:
		clear (numArray, 0);
		
		game_human (numArray);

		clear (numArray, 0);			//Funktion "clear" leert das numArray

		cout << "\nDo you want to play again? ([y] yes [n] no) ";
input:
		cin >> e;

	cout << "\n[" << e << "]\n\n";

		if (e == 'y')  {
			goto start2;

		} else if (e == 'n') {
			cout << "Good bye!\n\n";
			r = 1;}

		else {cout << "\nInvalid input! Please try again: "; //Catch exception
			goto input;
		}
	}

	delete [] numArray;				//Löscht das numArray
}


void clear (int playground[], int j) {
	for (j = 0; j < 72; j++)
		playground[j] = 0;
}

void move1 (int& a, int playground[]) {

	if (a == 10) {
		while (playground[a] < 1) {
		playground[a - 9] = 0;
		playground[a] = 1;
		draw(playground);
		a += 9;
			Sleep(200);
		}
	}

	else if (a == 11) {
		while (playground[a] < 1) {
		playground[a - 9] = 0;
		playground[a] = 1;
		draw(playground);
		a += 9;
			Sleep(200);
		}
	}

	else if (a == 12) {
		while (playground[a] < 1) {
		playground[a - 9] = 0;
		playground[a] = 1;
		draw(playground);
		a += 9;
			Sleep(200);
		}
	}

	else if (a == 13) {
		while (playground[a] < 1) {
		playground[a - 9] = 0;
		playground[a] = 1;
		draw(playground);
		a += 9;
			Sleep(200);
		}
	}

	else if (a == 14) {
		while (playground[a] < 1) {
		playground[a - 9] = 0;
		playground[a] = 1;
		draw(playground);
		a += 9;
			Sleep(200);
		}
	}

	else if (a == 15) {
		while (playground[a] < 1) {
		playground[a - 9] = 0;
		playground[a] = 1;
		draw(playground);
		a += 9;
			Sleep(200);
		}
	}

	else if (a == 16) {
		while (playground[a] < 1) {
		playground[a - 9] = 0;
		playground[a] = 1;
		draw(playground);
		a += 9;
			Sleep(200);
		}
	}
}

void move2 (int& a, int playground[]) {

	if (a == 10) {
		while (playground[a] < 1) {
		playground[a - 9] = 0;
		playground[a] = 2;
		draw(playground);
		a += 9;
			Sleep(200);
		}
	}

	else if (a == 11) {
		while (playground[a] < 1) {
		playground[a - 9] = 0;
		playground[a] = 2;
		draw(playground);
		a += 9;
			Sleep(200);
		}
	}

	else if (a == 12) {
		while (playground[a] < 1) {
		playground[a - 9] = 0;
		playground[a] = 2;
		draw(playground);
		a += 9;
			Sleep(200);
		}
	}

	else if (a == 13) {
		while (playground[a] < 1) {
		playground[a - 9] = 0;
		playground[a] = 2;
		draw(playground);
		a += 9;
			Sleep(200);
		}
	}

	else if (a == 14) {
		while (playground[a] < 1) {
		playground[a - 9] = 0;
		playground[a] = 2;
		draw(playground);
		a += 9;
			Sleep(200);
		}
	}

	else if (a == 15) {
		while (playground[a] < 1) {
		playground[a - 9] = 0;
		playground[a] = 2;
		draw(playground);
		a += 9;
			Sleep(200);
		}
	}

	else if (a == 16) {
		while (playground[a] < 1) {
		playground[a - 9] = 0;
		playground[a] = 2;
		draw(playground);
		a += 9;
			Sleep(200);
		}
	}
}




void draw (int playground[])				//"Malt" das Spielfeld
{

	cout << " " << " a" << " b" << " c" << " d" << " e" << " f" << " g" << endl;

	for (int i = 0; i < 62; i++) {
	playground[i] = 5;
		i += 8;
	}

	for (int i = 8; i < 71; i++) {
	playground[i] = 5;
		i += 8;
	}

	for (int i = 0; i < 9; i++) {
		playground[i] = 5;
	}

	for (int i = 62; i < 72; i++) {
		playground[i] = 5;
	}

	for (int i = 0; i < 72; i++) {
		cout << playground[i] << " ";
		if (i == 8 || i == 17 || i == 26 || i == 35 || i == 44 || i == 53 || i == 62 || i == 71)
			cout << endl;
		}

	cout << endl;
}


void winplayer1 (int& a, int playground[]) {
	for (int i = 10; i < 62; i++) {

	if (playground[i] == 1) {

		if (playground[i - 1] == 1) {
				if (playground[i - 2] == 1) {
					if (playground[i - 3] == 1) {
						a = 1; }}}

		else if (playground[i + 1] == 1) {
				if (playground[i + 2] == 1) {
					if (playground[i + 3] == 1) {
						a = 1; }}}

		else if (playground[i + 9] == 1) {
				if (playground[i + 18] == 1) {
					if (playground[i + 27] == 1) {
						a = 1; }}}

		else if (playground[i - 9] == 1) {
				if (playground[i - 18] == 1) {
					if (playground[i - 27] == 1) {
						a = 1; }}}

		else if (playground[i + 10] == 1) {
				if (playground[i + 20] == 1) {
					if (playground[i + 30] == 1) {
						a = 1; }}}

		else if (playground[i - 10] == 1) {
				if (playground[i - 20] == 1) {
					if (playground[i - 30] == 1) {
						a = 1; }}}

		else if (playground[i + 8] == 1) {
				if (playground[i + 16] == 1) {
					if (playground[i + 24] == 1) {
						a = 1; }}}

		else if (playground[i - 8] == 1) {
				if (playground[i - 16] == 1) {
					if (playground[i - 24] == 1) {
						a = 1; }}}
		}
	}

	if (a == 1) { cout << "\nPlayer one wins!\n"; }
} 


void winplayer2 (int& a, int playground[]) {
	for (int i = 10; i < 62; i++) {

	if (playground[i] == 2) {

		if (playground[i - 1] == 2) {
				if (playground[i - 2] == 2) {
					if (playground[i - 3] == 2) {
						a = 1; }}}

		else if (playground[i + 1] == 2) {
				if (playground[i + 2] == 2) {
					if (playground[i + 3] == 2) {
						a = 1; }}}

		else if (playground[i + 9] == 2) {
				if (playground[i + 18] == 2) {
					if (playground[i + 27] == 2) {
						a = 1; }}}

		else if (playground[i - 9] == 2) {
				if (playground[i - 18] == 2) {
					if (playground[i - 27] == 2) {
						a = 1; }}}

		else if (playground[i + 10] == 2) {
				if (playground[i + 20] == 2) {
					if (playground[i + 30] == 2) {
						a = 1; }}}

		else if (playground[i - 10] == 2) {
				if (playground[i - 20] == 2) {
					if (playground[i - 30] == 2) {
						a = 1; }}}

		else if (playground[i + 8] == 2) {
				if (playground[i + 16] == 2) {
					if (playground[i + 24] == 2) {
						a = 1; }}}

		else if (playground[i - 8] == 2) {
				if (playground[i - 16] == 2) {
					if (playground[i - 24] == 2) {
						a = 1; }}}
		}
	}

	if (a == 1) { cout << "\nPlayer two wins!\n"; }
} 

void game_human (int playground[]) {

	int x = 0, y = 0, i = 0;
	char j , k;

	cout << "Player 1 (1)  -  Player 2 (2)" << endl;
	cout << "\nPress ""q"" for menu" << endl << endl;

	draw(playground);

	while (x == 0) {

		cout << "\nPlayer 1! Please enter your choice (a - g) ... ";

start1:
		cin >> j;

		cout << "\n[" << j << "]\n";

		if (j == 'q') {
			x = 1;
			goto end;
		}

		else if (j == 'a')
			i = 10;
		else if (j == 'b')
			i = 11;
		else if (j == 'c')
			i = 12;
		else if (j == 'd')
			i = 13;
		else if (j == 'e')
			i = 14;
		else if (j == 'f')
			i = 15;
		else if (j == 'g')
			i = 16;

		else {cout << "\nInvalid input! Please try again: "; //Catch exception
			goto start1;
		}

		move1 (i, playground);

		winplayer1 (x, playground);

		if (x != 0)
			goto end;
		
		cout << "\nPlayer 2! Please enter your choice (a - g) ... ";		

start2:

		cin >> k;

		cout << "\n[" << k << "]\n";

		if (k == 'q') {
			x = 1;
			goto end;
		}

		else if (k == 'a')
			i = 10;
		else if (k == 'b')
			i = 11;
		else if (k == 'c')
			i = 12;
		else if (k == 'd')
			i = 13;
		else if (k == 'e')
			i = 14;
		else if (k == 'f')
			i = 15;
		else if (k == 'g')
			i = 16;

		else {cout << "\nInvalid input! Please try again: "; //Catch exception
			goto start2;
		}

		move2 (i, playground);

		winplayer2 (x, playground);	
	}

	end:;
}
