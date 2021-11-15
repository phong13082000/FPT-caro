#include<iostream>
#include<conio.h>
#include <windows.h>
using namespace std;
void gotoxy(char& a[][], int x, int y)
{	
	a[x][y]='X';
	cout <<	a[x][y];
}
int main(){
	char a[23][45];
	int m,n,c,r;
	int x=0;
	int y=0;
	for(int i=0; i<23; i++){
		for(int j=0; j<45; j++){
			a[i][j] = ' ';
		}
	}
	for(int i=1; i<2; i++){
		for(int j=6; j<43; j++){
			a[i][j] = '0'+x;
			j += 3;
			x ++;
		}
	}
	for(int i=3; i<22; i++){
		for(int j=2; j<3; j++){
			a[i][j] = '0'+y;
		}
		i += 1;
		y ++;
	}
	for(int i=2; i<23; i++){
		for(int j=4; j<45; j++){
			a[i][j] = '|';
			j += 3;
		}
	}
	for(int i=2; i<23; i++){
		for(int j=4; j<45; j++){
			if(j%4!=0) a[i][j] = '-';
		}
		i += 1;
	}
	for(int i=0; i<23; i++){
		for(int j=0; j<45; j++){
			cout << a[i][j];
		}
		cout << endl;
	}
	cout << "Player 1's turn: " << endl;
	cout << "Column: ";
	cin >> m;
	cout << "Row: ";
	cin >> n;
	c = m*4+6;
	r = n*2+3;
	gotoxy(a[23][45],r,c);
	getch();
	
}
