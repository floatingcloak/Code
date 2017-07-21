#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <time.h>
#include <cstring>
#include <conio.h>
#include <iostream>
#include <windows.h>

using namespace std;

#define KEY_DOWN(VK_NONAME) ((GetAsyncKeyState(VK_NONAME) & 0x8000) ? 1:0)

int RoleX = 20,RoleY = 10;
int DirX[9] = {0,-1,1,1,-1,0,2,0,-2};
int DirY[9] = {0,-1,-1,1,1,-1,0,1,0};


inline void H(){
	CONSOLE_CURSOR_INFO cursor = {1, 0}; 
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor);
}

inline void Go(int x,int y){
	HANDLE hOut=GetStdHandle(STD_OUTPUT_HANDLE);
	COORD c={x, y};SetConsoleCursorPosition(hOut,c);
}

inline int GetDir(){
	POINT p;GetCursorPos(&p);
	HWND hWnd = GetForegroundWindow(); 
	// cout<<hWnd<<endl;
	LPRECT r3;GetWindowRect(hWnd,r3);
	// cout<<p.x<<' '<<p.y<<endl;
	// cout<<(r3 -> right)<<' '<<(r3 -> top)<<endl;
	int NowX = p.x - (r3 -> left),NowY = p.y - (r3 -> top);
	int Pre1X = RoleX * 7 + 10,Pre1Y = RoleY * 14 + 30;
	int Pre2X = (RoleX + 1) * 7 + 10,Pre2Y = RoleY * 14 + 30;
	int Pre3X = RoleX * 7 + 10,Pre3Y = (RoleY + 1) * 14 + 30;
	int Pre4X = (RoleX + 1) * 7 + 10,Pre4Y = (RoleY + 1) * 14 + 30;
	if(NowX <= Pre1X && NowY <= Pre1Y)return 1;
	else if(NowX >= Pre2X && NowY <= Pre2Y)return 2;
	else if(NowX >= Pre4X && NowY >= Pre4Y)return 3;
	else if(NowX <= Pre3X && NowY >= Pre3Y)return 4;
	else if(NowY >= Pre1Y && NowY <= Pre3Y && NowX <= Pre1X)return 8;
	else if(NowY >= Pre1Y && NowY <= Pre3Y && NowX >= Pre2X)return 6;
	else if(NowX >= Pre1X && NowX <= Pre2X && NowY <= Pre1Y)return 5;
	else return 7;
}

inline void ChangeDir(int k,int l){
	Go(RoleX + DirX[l],RoleY + DirY[l]);
	if(l == 8 || l == 6)printf("  ");
	else printf(" ");
	Go(RoleX + DirX[k],RoleY + DirY[k]);
	switch (k) {
		case 1:printf("\\");break;
		case 2:printf("/");break;
		case 3:printf("\\");break;
		case 4:printf("/");break;
		case 5:printf("|");break;
		case 6:printf("--");break;
		case 7:printf("|");break;
		case 8:printf("--");break;
	}
}

inline void PrintRole(){
	Go(RoleX,RoleY);printf("#");
}

int main(){
	int NowDir = 0,LastDir = 0,Px = RoleX,Py = RoleY;char ch;
	GetDir();
	PrintRole();
	while(true){
		if(Px != RoleX || Py != RoleY){
			PrintRole();
		}
		Go(RoleX,RoleY);
		
		
		if(NowDir != LastDir)ChangeDir(NowDir,LastDir);
		LastDir = NowDir;
		if(kbhit() && (ch=getch())){
	   	    if(ch == 'w')RoleY--;
	   	    if(ch == 'a')RoleX--;
	   	    if(ch == 's')RoleY++;
	   	    if(ch == 'd')RoleX++;
       }
	}
}
