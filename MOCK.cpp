#include<iostream>
#include <fstream>
#include <windows.h>
using namespace std;
// Cho phep nguoi dung nhap cac buoc di chuyen bang dong lenh
// Hien thi trang thai hien tai cua board
// Kiem tra tinh trang win va bao cao ket qua
// Tiep tuc cho den khi 2 nguoi choi thang va hoa
// Da co chuc nang replay

class Player
{
public:
	string name;
	int win=0,lose=0,draw=0;

	Player()
	{
		
	}
	
	void Input()
	{
		cout<<"Name: ";
		cin>>this->name;
	}
	
	void Output()
	{
		cout<<"------------Player's Information------------"<<endl;
		cout<<"Name: "<<name<<endl;
		cout<<"Wins: "<<win<<endl;
		cout<<"Losses: "<<lose<<endl;
		cout<<"Draws: "<<draw<<endl;
	}
	
	string getName()
	{
		return name;
	}
	
	int getWin()
	{
		return win;
	}
	
	int getLose()
	{
		return lose;
	}
	
	int getDraw()
	{
		return draw;
	}
};

void writeinfile(Player p)
{
	ofstream player;
	player.open("Player.txt",ios::out|ios::app);
	player<<"---------------Player's information---------------"<<endl;
	player<<"Name: "<<p.getName()<<endl;
	player<<"Wins: "<<p.getWin()<<endl;
	player<<"Losses: "<<p.getLose()<<endl;
	player<<"Draws: "<<p.getDraw()<<endl;
}

void showAllRecords()
{
    ifstream readFile;
    readFile.open("Player.txt");
    char charsInLine[1024];
    cout<<"----------Player's records---------- "<<endl;
    while(!readFile.eof()){
        readFile.getline(charsInLine,1024);
        cout<<charsInLine<<endl;
    }
    readFile.close();
}

int checkWin(char a[23][45])
{
	for(int i=0; i<10; i++){
		for(int j=0; j<10; j++){
			if(a[i*2+3][j*4+6]==a[i*2+3+2][j*4+6] && a[i*2+3+2][j*4+6]==a[i*2+3+4][j*4+6] && a[i*2+3+4][j*4+6]==a[i*2+3+6][j*4+6] && a[i*2+3+6][j*4+6]=='X')
			{
				return 10;
				break;
			}else if(a[i*2+3][j*4+6]==a[i*2+3+2][j*4+6] && a[i*2+3+2][j*4+6]==a[i*2+3+4][j*4+6] && a[i*2+3+4][j*4+6]==a[i*2+3+6][j*4+6] && a[i*2+3+6][j*4+6]=='O')
			{
				return -10;
				break;	
			}else if(a[i*2+3][j*4+6]==a[i*2+3][j*4+6+4] && a[i*2+3][j*4+6+4]==a[i*2+3][j*4+6+8] && a[i*2+3][j*4+6+8]==a[i*2+3][j*4+6+12] && a[i*2+3][j*4+6+12]=='X')
			{
				return 10;
				break;
			}else if(a[i*2+3][j*4+6]==a[i*2+3][j*4+6+4] && a[i*2+3][j*4+6+4]==a[i*2+3][j*4+6+8] && a[i*2+3][j*4+6+8]==a[i*2+3][j*4+6+12] && a[i*2+3][j*4+6+12]=='O')
			{
				return -10;
				break;
			}else if(a[i*2+3][j*4+6]==a[i*2+3+2][j*4+6+4] && a[i*2+3+2][j*4+6+4]==a[i*2+3+4][j*4+6+8] && a[i*2+3+4][j*4+6+8]==a[i*2+3+6][j*4+6+12] && a[i*2+3+6][j*4+6+12]=='X')
			{
				return 10;
				break;
			}else if(a[i*2+3][j*4+6]==a[i*2+3+2][j*4+6+4] && a[i*2+3+2][j*4+6+4]==a[i*2+3+4][j*4+6+8] && a[i*2+3+4][j*4+6+8]==a[i*2+3+6][j*4+6+12] && a[i*2+3+6][j*4+6+12]=='O')
			{
				return -10;
				break;
			}else if(a[i*2+3][j*4+6]==a[i*2+3+2][j*4+6-4] && a[i*2+3+2][j*4+6-4]==a[i*2+3+4][j*4+6-8] && a[i*2+3+4][j*4+6-8]==a[i*2+3+6][j*4+6-12] && a[i*2+3+6][j*4+6-12]=='X')
			{
				return 10;
				break;
			}else if(a[i*2+3][j*4+6]==a[i*2+3+2][j*4+6-4] && a[i*2+3+2][j*4+6-4]==a[i*2+3+4][j*4+6-8] && a[i*2+3+4][j*4+6-8]==a[i*2+3+6][j*4+6-12] && a[i*2+3+6][j*4+6-12]=='O')
			{
				return -10;
				break;
			}
		}
	}
}
bool Full(char a[23][45])
{
	int dem=0;
	for(int i=0; i<10; i++)
	{
		for(int j=0; j<10; j++)
		{
			if ((a[i*2+3][j*4+6]=='X') || (a[i*2+3][j*4+6]=='O'))
			dem++;
		}
	}
	if(dem==100)
	{
		return true;
	}else
	{
		return false;
	}
}
void board(char a[23][45], int x=0, int y=0)
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
void player1(char a[23][45],int m,int n,int row1[50],int col1[50],int count1)
{
	cout << "Player 1's turn: " << endl;
	cout << "Row: ";
	cin >> n;
	cout << "Column: ";
	cin >> m;
	while(m<0 || n<0 || a[n*2+3][m*4+6]=='X' || a[n*2+3][m*4+6]=='O' || m>9 || n>9)
	{
		//kiem tra o nhap co hop le hay khong
		cout<<"Re-enter !"<<endl;
		cout << "Row: ";
		cin >> n;
		cout << "Column: ";
		cin >> m;
	}
	system("cls");
	row1[count1]=n*2+3;
	col1[count1]=m*4+6;
	a[n*2+3][m*4+6] = 'X';
	for(int i=0; i<23; i++)
	{
		for(int j=0; j<45; j++)
		{
			cout << a[i][j];
		}
		cout << endl;
	}
}
void player2(char a[23][45],int m,int n,int row2[50],int col2[50],int count2)
{
	cout << "Player 2's turn: " << endl;
	cout << "Row: ";
	cin >> n;
	cout << "Column: ";
	cin >> m;
	while(m<0 || n<0 || a[n*2+3][m*4+6]=='X' || a[n*2+3][m*4+6]=='O' || m>9 || n>9)
	{
		//kiem tra o nhap co hop le hay khong
		cout<<"Re-enter !"<<endl;
		cout << "Row: ";
		cin >> n;
		cout << "Column: ";
		cin >> m;
	}
	system("cls");
	row2[count2]=n*2+3;
	col2[count2]=m*4+6;
	a[n*2+3][m*4+6] = 'O';
	for(int i=0; i<23; i++)
	{
		for(int j=0; j<45; j++)
		{
			cout << a[i][j];
		}
		cout << endl;
	}
}
struct Move
{
    int rw, cl;
};

bool isMovesLeft(char a[23][45])
{
    for (int i = 0; i<10; i++){
    	for (int j = 0; j<10; j++){
    		if (a[i*2+3][j*4+6]==' '){
    			return true;
			}else{
				return false;
			}
		}
	}
}

int evaluate(char a[23][45],bool Max)
{
    int vx = 0;// tinh diem van dau theo x
    int vo = 0;// tinh diem van dau theo o
	for(int i=0; i<10; i++){
		for(int j=0; j<10; j++){
			if(a[i*2+3][j*4+6]==a[i*2+3+2][j*4+6] && a[i*2+3+2][j*4+6]==a[i*2+3+4][j*4+6] && a[i*2+3+4][j*4+6]==a[i*2+3+6][j*4+6]) // Doc
			{
				if(a[i*2+3][j*4+6]=='X'){
					if(10 > abs(vx)){
						vx=1000;
					}
				}else if(a[i*2+3][j*4+6]=='O'){
					if(10 > abs(vo)){
						vo=-1000;
					}
				}	
			}else if(a[i*2+3][j*4+6]==a[i*2+3][j*4+6+4] && a[i*2+3][j*4+6+4]==a[i*2+3][j*4+6+8] && a[i*2+3][j*4+6+8]==a[i*2+3][j*4+6+12]) // Ngang
			{
				if(a[i*2+3][j*4+6]=='X'){
					if(10 > abs(vx)){
						vx=1000;
					}
				}else if(a[i*2+3][j*4+6]=='O'){
					if(10 > abs(vo)){
						vo=-1000;
					}
				}
			}else if(a[i*2+3][j*4+6]==a[i*2+3+2][j*4+6+4] && a[i*2+3+2][j*4+6+4]==a[i*2+3+4][j*4+6+8] && a[i*2+3+4][j*4+6+8]==a[i*2+3+6][j*4+6+12]) // Cheo
			{
				if(a[i*2+3][j*4+6]=='X'){
					if(10 > abs(vx)){
						vx=1000;
					}
				}else if(a[i*2+3][j*4+6]=='O'){
					if(10 > abs(vo)){
						vo=-1000;
					}
				}
			}else if(a[i*2+3][j*4+6]==a[i*2+3+2][j*4+6-4] && a[i*2+3+2][j*4+6-4]==a[i*2+3+4][j*4+6-8] && a[i*2+3+4][j*4+6-8]==a[i*2+3+6][j*4+6-12])
			{
				if(a[i*2+3][j*4+6]=='X'){
					if(10 > abs(vx)){
						vx=1000;
					}
				}else if(a[i*2+3][j*4+6]=='O'){
					if(10 > abs(vo)){
						vo=-1000;
					}
				}
				// 3 lien 1 chan
			}else if(a[i*2+3][j*4+6]==a[i*2+3+2][j*4+6] && a[i*2+3+2][j*4+6]==a[i*2+3+4][j*4+6] && a[i*2+3+6][j*4+6]!=' ' || a[i*2+3][j*4+6]==a[i*2+3+2][j*4+6] && a[i*2+3+2][j*4+6]==a[i*2+3+4][j*4+6] && a[i*2+3-2][j*4+6]!=' ') // Doc
			{
				if(a[i*2+3][j*4+6]=='X'){
					if(6 > abs(vx)){
						vx=7;
					}
				}else if(a[i*2+3][j*4+6]=='O'){
					if(6 > abs(vo)){
						vo=-7;
					}
				}
			}else if(a[i*2+3][j*4+6]==a[i*2+3][j*4+6+4] && a[i*2+3][j*4+6+4]==a[i*2+3][j*4+6+8] && a[i*2+3][j*4+6+12]!=' ' || a[i*2+3][j*4+6]==a[i*2+3][j*4+6+4] && a[i*2+3][j*4+6+4]==a[i*2+3][j*4+6+8] && a[i*2+3][j*4+6-4]!=' ') // Ngang
			{
				if(a[i*2+3][j*4+6]=='X'){
					if(6 > abs(vx)){
						vx=7;
					}
				}else if(a[i*2+3][j*4+6]=='O'){
					if(6 > abs(vo)){
						vo=-7;
					}
				}
			}else if(a[i*2+3][j*4+6]==a[i*2+3+2][j*4+6+4] && a[i*2+3+2][j*4+6+4]==a[i*2+3+4][j*4+6+8] && a[i*2+3+6][j*4+6+12]!=' ' || a[i*2+3][j*4+6]==a[i*2+3+2][j*4+6+4] && a[i*2+3+2][j*4+6+4]==a[i*2+3+4][j*4+6+8] && a[i*2+3-2][j*4+6-4]!=' ') // Cheo
			{
				if(a[i*2+3][j*4+6]=='X'){
					if(6 > abs(vx)){
						vx=7;
					}
				}else if(a[i*2+3][j*4+6]=='O'){
					if(6 > abs(vo)){
						vo=-7;
					}
				}
			}else if(a[i*2+3][j*4+6]==a[i*2+3+2][j*4+6-4] && a[i*2+3+2][j*4+6-4]==a[i*2+3+4][j*4+6-8] && a[i*2+3+6][j*4+6-12]!=' ' || a[i*2+3][j*4+6]==a[i*2+3+2][j*4+6-4] && a[i*2+3+2][j*4+6-4]==a[i*2+3+4][j*4+6-8] && a[i*2+3-2][j*4+6+4]!=' ')
			{
				if(a[i*2+3][j*4+6]=='X'){
					if(6 > abs(vx)){
						vx=7;
					}
				}else if(a[i*2+3][j*4+6]=='O'){
					if(6 > abs(vo)){
						vo=-7;
					}
				}
				// 3 lien 2 ho
			}else if(a[i*2+3][j*4+6]==a[i*2+3+2][j*4+6] && a[i*2+3+2][j*4+6]==a[i*2+3+4][j*4+6] && a[i*2+3+6][j*4+6]==' ' && a[i*2+3-2][j*4+6]==' ') // Doc
			{
				if(a[i*2+3][j*4+6]=='X'){
					if(8 > abs(vx)){
						vx=8;
					}
				}else if(a[i*2+3][j*4+6]=='O'){
					if(8 > abs(vo)){
						vo=-8;
					}
				}
			}else if(a[i*2+3][j*4+6]==a[i*2+3][j*4+6+4] && a[i*2+3][j*4+6+4]==a[i*2+3][j*4+6+8] && a[i*2+3][j*4+6+12]==' ' && a[i*2+3][j*4+6-4]==' ') // Ngang
			{
				if(a[i*2+3][j*4+6]=='X'){
					if(8 > abs(vx)){
						vx=8;
					}
				}else if(a[i*2+3][j*4+6]=='O'){
					if(8 > abs(vo)){
						vo=-8;
					}
				}
			}else if(a[i*2+3][j*4+6]==a[i*2+3+2][j*4+6+4] && a[i*2+3+2][j*4+6+4]==a[i*2+3+4][j*4+6+8] && a[i*2+3+6][j*4+6+12]==' ' && a[i*2+3-2][j*4+6-4]==' ') // Cheo
			{
				if(a[i*2+3][j*4+6]=='X'){
					if(8 > abs(vx)){
						vx=8;
					}
				}else if(a[i*2+3][j*4+6]=='O'){
					if(8 > abs(vo)){
						vo=-8;
					}
				}
			}else if(a[i*2+3][j*4+6]==a[i*2+3+2][j*4+6-4] && a[i*2+3+2][j*4+6-4]==a[i*2+3+4][j*4+6-8] && a[i*2+3+6][j*4+6-12]!=' ' && a[i*2+3-2][j*4+6+4]==' ')
			{
				if(a[i*2+3][j*4+6]=='O'){
					if(8 > abs(vo)){
						vo=-8;
					}
				}else if(a[i*2+3][j*4+6]=='X'){
					if(8 > abs(vx)){
						vx=8;
					}
				}
				// 2 lien 2 ho
			}else if(a[i*2+3][j*4+6]==a[i*2+3+2][j*4+6] && a[i*2+3+4][j*4+6]==' ' && a[i*2+3-2][j*4+6]==' ') // Doc
			{
				if(a[i*2+3][j*4+6]=='O'){
					if(4 > abs(vo)){
						vo=-4;
					}
				}else if(a[i*2+3][j*4+6]=='X'){
					if(4 > abs(vx)){
						vx=4;
					}
				}
			}else if(a[i*2+3][j*4+6]==a[i*2+3][j*4+6+4] && a[i*2+3][j*4+6+8]==' ' && a[i*2+3][j*4+6-4]==' ') // Ngang
			{
				if(a[i*2+3][j*4+6]=='O'){
					if(4 > abs(vo)){
						vo=-4;
					}
				}else if(a[i*2+3][j*4+6]=='X'){
					if(4 > abs(vx)){
						vx=4;
					}
				}
			}else if(a[i*2+3][j*4+6]==a[i*2+3+2][j*4+6+4] && a[i*2+3+4][j*4+6+8]==' ' && a[i*2+3-2][j*4+6-4]==' ') // Cheo
			{
				if(a[i*2+3][j*4+6]=='O'){
					if(4 > abs(vo)){
						vo=-4;
					}
				}else if(a[i*2+3][j*4+6]=='X'){
					if(4 > abs(vx)){
						vx=4;
					}
				} 
			}else if(a[i*2+3][j*4+6]==a[i*2+3+2][j*4+6-4] && a[i*2+3+4][j*4+6-8]==' ' && a[i*2+3-2][j*4+6+4]==' ')
			{
				if(a[i*2+3][j*4+6]=='O'){
					if(4 > abs(vo)){
						vo=-4;
					}
				}else if(a[i*2+3][j*4+6]=='X'){
					if(4 > abs(vx)){
						vx=4;
					}
				}
				// 2 lien 1 chan
			}else if(a[i*2+3][j*4+6]==a[i*2+3+2][j*4+6] && a[i*2+3+4][j*4+6]!=' ' || a[i*2+3][j*4+6]==a[i*2+3+2][j*4+6] && a[i*2+3-2][j*4+6]!=' ') // Doc
			{
				if(a[i*2+3][j*4+6]=='O'){
					if(2 > abs(vo)){
						vo=-3;
					}
				}else if(a[i*2+3][j*4+6]=='X'){
					if(2 > abs(vx)){
						vx=3;
					}
				}
			}else if(a[i*2+3][j*4+6]==a[i*2+3][j*4+6+4] && a[i*2+3][j*4+6+8]!=' ' || a[i*2+3][j*4+6]==a[i*2+3][j*4+6+4] && a[i*2+3][j*4+6-4]!=' ') // Ngang
			{
				if(a[i*2+3][j*4+6]=='O'){
					if(2 > abs(vo)){
						vo=-3;
					}
				}else if(a[i*2+3][j*4+6]=='X'){
					if(2 > abs(vx)){
						vx=3;
					}
				}
			}else if(a[i*2+3][j*4+6]==a[i*2+3+2][j*4+6+4] && a[i*2+3+4][j*4+6+8]!=' ' || a[i*2+3][j*4+6]==a[i*2+3+2][j*4+6+4] && a[i*2+3-2][j*4+6-4]!=' ') // Cheo
			{
				if(a[i*2+3][j*4+6]=='O'){
					if(2 > abs(vo)){
						vo=-3;
					}
				}else if(a[i*2+3][j*4+6]=='X'){
					if(2 > abs(vx)){
						vx=3;
					}
				}
			}else if(a[i*2+3][j*4+6]==a[i*2+3+2][j*4+6-4] && a[i*2+3+4][j*4+6-8]!=' ' || a[i*2+3][j*4+6]==a[i*2+3+2][j*4+6-4] && a[i*2+3-2][j*4+6+4]==' ')
			{
				if(a[i*2+3][j*4+6]=='O'){
					if(2 > abs(vo)){
						vo=-3;
					}
				}else if(a[i*2+3][j*4+6]=='X'){
					if(2 > abs(vx)){
						vx=3;
					}
				}
				// con lai
			}else
			{
				if(a[i*2+3][j*4+6]=='O'){
					if(2 > abs(vo)){
						vo=0;
					}
				}else if(a[i*2+3][j*4+6]=='X'){
					if(2 > abs(vx)){
						vx=0;
					}
				}
			}
		}
	}
    if(abs(vx)==abs(vo))
    {
        if(Max == true) return vx;
        if(Max == false) return vo;
    }
    else if(abs(vx)>abs(vo))
    {
        return vx;
    }
    else if (abs(vx)<abs(vo))
    {
        return vo;
    }
    return 0;
}
int minimax(char a[23][45], int alpha, int beta, int depth, bool isMax)
{
    int score = evaluate(a,isMax);
    if (score == 1000)
        return score;
    if (score == -1000)
        return score;
    if (isMovesLeft(a)==false)
        return 0;
    if (score == 8 || score == 7){
        if(depth == 1) return score;
    } 
    if (depth == 3) return score;
     if (isMax)
    {
        int best = -10000000;
        for (int i = 0; i<10; i++)
        {
            for (int j = 0; j<10; j++)
            {
                if (a[i*2+3][j*4+6]==' ')
                {
                    a[i*2+3][j*4+6] = 'X';

                    int value = minimax(a, alpha, beta, depth+1, !isMax);

                    a[i*2+3][j*4+6] = ' ';
                    best = max(value, best);
                    alpha = max(alpha, best);
                    if (beta <= alpha){
                    	break;
					}
                }
            }
        }
        return best;
    }
 
    else
    {
        int best = 10000000;
 
        for (int i = 0; i<10; i++)
        {
            for (int j = 0; j<10; j++)
            {

                if (a[i*2+3][j*4+6]==' ')
                {
                    a[i*2+3][j*4+6] = 'O';
 
                    int value = minimax(a, alpha, beta, depth+1, !isMax);
 
                    a[i*2+3][j*4+6] = ' ';
                    best = min(value, best);
                    alpha = min(alpha, best);
                    if (beta <= alpha){
                    	break;
					}
                }
            }
        }
        return best;
    }
}

Move findBestMove(char a[23][45])
{
    int bestVal = -10000000;
    Move bestMove;
    bestMove.rw = -1;
    bestMove.cl = -1;
    int alpha = -10000000;
    int beta = 10000000;
 
    // Traverse all cells, evaluate minimax function for
    // all empty cells. And return the cell with optimal
    // value.
    for (int i = 0; i<10; i++)
    {
        for (int j = 0; j<10; j++)
        {
            // Check if cell is empty
            if (a[i*2+3][j*4+6]==' ')
            {
                // Make the move
                a[i*2+3][j*4+6] = 'X';
 
                // compute evaluation function for this
                // move.
                int moveVal = minimax(a, alpha, beta, 0, false);
 
                // Undo the move
                a[i*2+3][j*4+6] = ' ';
 
                // If the value of the current move is
                // more than the best value, then update
                // best/
                if (moveVal > bestVal)
                {
                    bestMove.rw = i*2+3;
                    bestMove.cl = j*4+6;
                    bestVal = moveVal;
                }
            }
        }
    }
    cout << "The value of the best Move is : " << bestVal << endl;
    return bestMove;
}


void bot(char a[23][45],int row1[50],int col1[50],int count1){
	cout << "BOT's turn: " << endl;
	Move bestMove = findBestMove(a);
	row1[count1]=bestMove.rw;
	col1[count1]=bestMove.cl;
	system("cls");
	for(int i=0; i<23; i++)
	{
		for(int j=0; j<45; j++)
		{
			a[bestMove.rw][bestMove.cl] = 'X';
			cout << a[i][j];
		}
		cout << endl;
	}
}
void replay(char a[23][45],int row1[50],int col1[50],int count1,int row2[50],int col2[50],int count2)
{
	int c1=0;
	int c2=0;
	while(c1<count1 || c2<count2)
	{
		system("cls");
		a[row1[c1]][col1[c1]]='X';
		for(int i=0; i<23; i++){
    		for(int j=0; j<45; j++)
			{
    	    	cout << a[i][j];
			}
			cout << endl;
		}
		c1++;
		Sleep(1000);
		if(checkWin(a)==1)
		{
            cout << "Player 1 win !" << endl;
            break;
	    }
		system("cls");	
		a[row2[c2]][col2[c2]]='O';
		for(int i=0; i<23; i++)
		{
    		for(int j=0; j<45; j++)
			{
    	    	cout << a[i][j];
			}
			cout << endl;
		}
		c2++;
		Sleep(1000);
	    if(checkWin(a)==2)
		{
           	cout << "Player 2 win !" << endl;
            break;
    	}
    	if(Full(a))
		{
    		cout <<"Draw!" <<endl;
    		break;
		}
	}
}
int main(){
	Player p1,p2;
	char a[23][45];
	int row1[50],row2[50],col1[50],col2[50];
	int count1,count2;
	int m,n,number;
	char kt;
	int x=0;
	int y=0;
	do{
		system("cls");
    	cout << "*-------MAIN MENU-------*" << endl;
    	cout << "1.Play with Other Player" << endl;
    	cout << "2.Play with Bot" << endl;
    	cout << "3.Replay" << endl;
    	cout << "4.Player Information" << endl;
    	cout << "5.Guide" << endl;
    	cout << "6.Exit" << endl;
    	cout << "Press number to choice: ";
    	cin >> number;
	    switch(number)
		{
	    	case 1:
			p1.Input();
			p2.Input();
	    		cout << "=> Player 1 = X, Player 2 = O" << endl;
	    		board(a,x,y);
	    		count1=0;
	    		count2=0;
		    	while(1){
                	player1(a,m,n,row1,col1,count1);
                	count1++;
                	if(checkWin(a)==10)
					{
                		cout << "Player 1 win !" << endl;
                		break;
	    			}
                	player2(a,m,n,row2,col2,count2);
                	count2++;
                	if(checkWin(a)==-10)
					{
                		cout << "Player 2 win !" << endl;
                		break;
    				}
    				if(Full(a))
					{
    					cout <<"Draw!" <<endl;
    					break;
					}
                }
    			break;
    		
    		case 3:
    			if(count1==0)
				{
					board(a,x,y);
					cout<< "You haven't played yet! " <<endl;
					break;
				}else
				{
					board(a,x,y);
					Sleep(1000);
    				replay(a,row1,col1,count1,row2,col2,count2);
	    			break;	
				}
				
			case 5:
				cout<< "Players take turns entering point coordinates (Row,Column)" <<endl;
				cout<< "Do not enter the coordinates entered! Otherwise you will have to re-entered"<<endl;
				cout<< "Winning condition: when a player has 4 moves in a row horizontally, vertically or diagonally, he wins" <<endl;
				break;
				
    		case 2:
    			cout << endl << "*-------Play with BOT-------*" << endl;
            	cout << "1.Easy Mode" << endl;
            	cout << "2.Normal Mode" << endl;
            	cout << "3.Hard Mode" << endl;
            	cout << "4.Back to MAIN MENU" << endl;
            	cout << "Press number to choice: ";
            	cin >> number;
        	    switch(number)
				{
        	    	case 4:
        	    		break;
        	    	case 1:
        	    		cout << "=>  BOT = X,Player 2 = O" << endl;
	    	        	board(a,x,y);
	    	        	count1=0;
	    	        	count2=0;
        	    		while(1){
                        
	    		         	bot(a,row1,col1,count1);
                          	count1++;
                         	if(checkWin(a)==10)
			         		{
                	        	cout << "BOT win !" << endl;
                	          	break;
    			         	}
    			         	player2(a,m,n,row2,col2,count2);
		                	count2++;
		                	if(checkWin(a)==-10)
							{
		                		cout << "Player 2 win !" << endl;
		                		break;
		    				}
    			        	if(Full(a))
				        	{
    				        	cout <<"Draw!" <<endl;
    				        	break;
				        	}
						}
				}
		
			case 4:
    			if(checkWin(a)==1)
				{
    				p1.win++;
    				p2.lose++;
				}
				else if(checkWin(a)==2)
				{
					p2.win++;
					p1.lose++;
				}
				else
				{
					p1.draw++;
					p2.draw++;
				}
				p1.Output();
				p2.Output();
				break;
    		
			case 6:
			    break;
		    	
			default:
			   	cout <<"Number to choice is false! Choose again: "<<endl;
			    Sleep(1000);
			    continue;
	    	
    	}
    	if(number==6)
		{
    		cout << "EXIT ? (Y/N): ";    
    		cin >> kt;
    		if(kt=='Y' || kt=='y') break;
		}else
		{
			cout << "CONTINUE ? (Y/N): ";    
    		cin >> kt;
    		if(kt=='Y' || kt=='y') 
    		{
    			continue;
			}else if(kt=='N' || kt=='n')
			{
				break;
			}
		}
    	
    }while(1);
    writeinfile(p1);
    writeinfile(p2);
    return 0;
}
