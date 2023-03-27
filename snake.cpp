// ***************************************************
// Projekt:      
// Copyright:    
// Author:      	Landry Rutalindwa
// Datum:        	11.03.2023
// Programmname: 	Snake
// ***************************************************

#include <iostream>
#include <conio.h>
#include <windows.h>

using namespace std;

bool gameOver;
const int height = 20;
const int width = 20;

int x,y,FruitX,FruitY,score,speed,gamemode=5;

int tailX[100], tailY[100], ntail;

enum eDirection {STOP=0, UP, DOWN, LEFT, RIGHT};
eDirection dir;

void Setup();
void Draw();
void Input();
void Logic();
void Start();

int main()

{
	Setup();
	Start();
	system("PAUSE");
	while(!gameOver){
						Draw();
						Input();
						Logic();
						Sleep(speed);
					}
	
	return 0;
}


void Start()
{
	while(gamemode>4){
	cout << "Willkommen zum Klassischen 'Snake'" << endl;
	cout << "-------------------------------------------" << endl;
	cout << "Waehle zwisch viel Stufen:" << endl << endl;
	cout << "1. Einfach" << endl;
	cout << "2. Normal" << endl;
	cout << "3. Hart" << endl;
	cout << "4. Experte" << endl << endl;
	cout << "Eingabe: ";
	cin >> gamemode;
		
		if (gamemode == 1){
			speed = 100;
		}else if(gamemode == 2){
			speed = 60;
		}else if(gamemode == 3){
			speed = 30;
		}else if(gamemode == 4){
			speed = 10;
		}else{
			cout << endl << "Fahlsche Eingabe, Bitte nochmal." << endl << endl;
			system ("PAUSE");
			system ("CLS");
	}
	}
}


void Setup()
{
	gameOver = false;
	dir = STOP;
	x = width/2;
	y = height/2;
	FruitX = rand() % width;
	FruitY = rand() % height;
	ntail++;	
}

	
void Draw()
{
	system("CLS");

	for(int i=0;i<width;i++){
		cout << "#";
	}cout << endl;
	
	for(int i=0;i<height;i++){
		for(int j=0;j<width;j++){
			if(j==0 || j==width-1){
				cout << "#";
			}else if (i==y && j==x){
				cout << "O";
			}else if(i==FruitY && j==FruitX){
				cout << "F";
			}else{
				bool print = false;
					for(int k=0;k<ntail;k++){
						if(i==tailY[k] && j==tailX[k]){
							cout << "o";
							print = true;
					}
				} if(!print){cout << " ";}
				}
		}cout << endl;
	}
	
	for(int i=0;i<width;i++){
		cout << "#";
	}cout << endl;
	cout << endl << "Punkte: " << score << endl;
}


void Input()
{
	if(_kbhit()){
		switch(_getch()){
			
			case 'w':	dir=UP;
						break;
						
			case 's':	dir=DOWN;
						break;
						
			case 'a':	dir=LEFT;
						break;
						
			case 'd':	dir=RIGHT;
						break;	
						
			default :	break;											
		}
	}
	
	if(x<0 || x>width || y<0 || y>height){
		gameOver = true;
	}
		
	for(int i=0;i<ntail;i++){
		if(x==tailX[i] && y==tailY[i]){
			gameOver = true;
		}
	}

	if(x==FruitX && y==FruitY){
		score += 10;
		FruitX = rand() % width;
		FruitY = rand() % height;
		ntail++;
	}
}


void Logic()
{
	int prevX = tailX[0];
	int prevY = tailY[0];
	tailX[0]=x;
	tailY[0]=y;
	int prev2X, prev2Y;
	
	for(int i=0;i<ntail;i++){
		prev2X = tailX[i];
		prev2Y = tailY[i];
		tailX[i] = prevX;
		tailY[i] = prevY;
		prevX = prev2X;
		prevY = prev2Y;
	}
		
	switch(dir){
		
		case UP :		y--;
						break;
					
		case DOWN :		y++;
						break;
					
		case LEFT :		x--;
						break;
					
		case RIGHT :	x++;
						break;
						
		default:		break;
	}
}


