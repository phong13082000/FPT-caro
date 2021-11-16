#include<iostream>
using namespace std;
// Cho phep nguoi dung nhap cac buoc di chuyen bang dong lenh
// Hien thi trang thai hien tai cua board
// Kiem tra tinh trang win va bao cao ket qua
// Tiep tuc cho den khi 2 nguoi choi thang ( chua lam dieu kien hoa )
// Chua tao bot, chua tao chuc nang xem lai, chua luu thong tin nguoi choi
void checkWin(char a[23][45]){
	for(int i=0; i<23; i++){
		for(int j=0; j<45; j++)
		{	//doc
			if(a[i][j]==a[i+2][j] && a[i+2][j]==a[i+4][j] && a[i+4][j]==a[i+6][j] && a[i+6][j]==a[i+8][j] &&  a[i+8][j]=='X'){
				cout << "Player 1 win !" << endl;
				break;
			}else if(a[i][j]==a[i+2][j] && a[i+2][j]==a[i+4][j] && a[i+4][j]==a[i+6][j] && a[i+6][j]==a[i+8][j] && a[i+8][j]=='O'){
				cout << "Player 2 win !" << endl;
				break;
			//ngang		
			}else if(a[i][j]==a[i][j+4] && a[i][j+4]==a[i][j+8] && a[i][j+8]==a[i][j+12] && a[i][j+12]==a[i][j+16] && a[i][j+16]=='X'){
				cout << "Player 1 win !" << endl;
				break;
			}else if(a[i][j]==a[i][j+4] && a[i][j+4]==a[i][j+8] && a[i][j+8]==a[i][j+12] && a[i][j+12]==a[i][j+16] && a[i][j+16]=='O'){
				cout << "Player 2 win !" << endl;
				break;
			}
			//cheo
			else if(a[i][j]==a[i+2][j+4] && a[i+2][j+4]==a[i+4][j+8] && a[i+4][j+8]==a[i+6][j+12] && a[i+6][j+12]==a[i+8][j+16] && a[i+8][j+16]=='X'){
				cout << "Player 1 win !" << endl;
				break;
			}else if(a[i][j]==a[i+2][j+4] && a[i+2][j+4]==a[i+4][j+8] && a[i+4][j+8]==a[i+6][j+12] && a[i+6][j+12]==a[i+8][j+16] && a[i+8][j+16]=='O'){
				cout << "Player 2 win !" << endl;
				break;
			}
		}
	}
}

void BanCo(char a[23][45], int x=0, int y=0)
{
	for(int i=0; i<23; i++)
	{
		for(int j=0; j<45; j++)
		{
			a[i][j] = ' ';
		}
	}
	for(int i=1; i<2; i++)
	{
		for(int j=6; j<43; j++)
		{
			a[i][j] = '0'+x;
			j += 3;
			x ++;
		}
	}
	for(int i=3; i<22; i++)
	{
		for(int j=2; j<3; j++)
		{
			a[i][j] = '0'+y;
		}
		i += 1;
		y ++;
	}
	for(int i=2; i<23; i++)
	{
		for(int j=4; j<45; j++)
		{
			a[i][j] = '|';
			j += 3;
		}
	}
	for(int i=2; i<23; i++)
	{
		for(int j=4; j<45; j++)
		{
			if(j%4!=0) a[i][j] = '-';
		}
		i += 1;
	}
	for(int i=0; i<23; i++)
	{
		for(int j=0; j<45; j++)
		{
			cout << a[i][j];
		}
		cout << endl;
	}
}
void player1(char a[23][45],int m,int n)
{
	cout << "Player 1's turn: " << endl;
	cout << "Row: ";
	cin >> n;
	cout << "Colomn: ";
	cin >> m;
	system("cls");
	for(int i=0; i<23; i++){
		for(int j=0; j<45; j++){
			a[n*2+3][m*4+6] = 'X';
			cout << a[i][j];
		}
		cout << endl;
	}
	
}
void player2(char a[23][45],int m,int n)
{
	cout << "Player 2's turn: " << endl;
	cout << "Row: ";
	cin >> n;
	cout << "Colomn: ";
	cin >> m;
	system("cls");
	for(int i=0; i<23; i++){
		for(int j=0; j<45; j++){
			a[n*2+3][m*4+6] = 'O';
			cout << a[i][j];
		}
		cout << endl;
	}
}
int main(){
	char a[23][45];
	int m,n,c,r;
	int x=0;
	int y=0;
	BanCo(a,x,y);
	while(1){
	player1(a,m,n);
	checkWin(a);
	player2(a,m,n);
	checkWin(a);
}
}
