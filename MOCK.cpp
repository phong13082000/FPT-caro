#include<iostream>
#include <windows.h>
using namespace std;
// Cho phep nguoi dung nhap cac buoc di chuyen bang dong lenh
// Hien thi trang thai hien tai cua board
// Kiem tra tinh trang win va bao cao ket qua
// Tiep tuc cho den khi 2 nguoi choi thang va hoa
// Da co chuc nang replay
// Chua tao bot, chua luu thong tin nguoi choi
int checkWin(char a[23][45])
{
	for(int i=0; i<10; i++){
		for(int j=0; j<10; j++){
			if(a[i*2+3][j*4+6]==a[i*2+3+2][j*4+6] && a[i*2+3+2][j*4+6]==a[i*2+3+4][j*4+6] && a[i*2+3+4][j*4+6]==a[i*2+3+6][j*4+6] && a[i*2+3+6][j*4+6]=='X')
			{
				return 1;
				break;
			}else if(a[i*2+3][j*4+6]==a[i*2+3+2][j*4+6] && a[i*2+3+2][j*4+6]==a[i*2+3+4][j*4+6] && a[i*2+3+4][j*4+6]==a[i*2+3+6][j*4+6] && a[i*2+3+6][j*4+6]=='O')
			{
				return 2;
				break;	
			}else if(a[i*2+3][j*4+6]==a[i*2+3][j*4+6+4] && a[i*2+3][j*4+6+4]==a[i*2+3][j*4+6+8] && a[i*2+3][j*4+6+8]==a[i*2+3][j*4+6+12] && a[i*2+3][j*4+6+12]=='X')
			{
				return 1;
				break;
			}else if(a[i*2+3][j*4+6]==a[i*2+3][j*4+6+4] && a[i*2+3][j*4+6+4]==a[i*2+3][j*4+6+8] && a[i*2+3][j*4+6+8]==a[i*2+3][j*4+6+12] && a[i*2+3][j*4+6+12]=='O')
			{
				return 2;
				break;
			}else if(a[i*2+3][j*4+6]==a[i*2+3+2][j*4+6+4] && a[i*2+3+2][j*4+6+4]==a[i*2+3+4][j*4+6+8] && a[i*2+3+4][j*4+6+8]==a[i*2+3+6][j*4+6+12] && a[i*2+3+6][j*4+6+12]=='X')
			{
				return 1;
				break;
			}else if(a[i*2+3][j*4+6]==a[i*2+3+2][j*4+6+4] && a[i*2+3+2][j*4+6+4]==a[i*2+3+4][j*4+6+8] && a[i*2+3+4][j*4+6+8]==a[i*2+3+6][j*4+6+12] && a[i*2+3+6][j*4+6+12]=='O')
			{
				return 2;
				break;
			}else if(a[i*2+3][j*4+6]==a[i*2+3+2][j*4+6-4] && a[i*2+3+2][j*4+6-4]==a[i*2+3+4][j*4+6-8] && a[i*2+3+4][j*4+6-8]==a[i*2+3+6][j*4+6-12] && a[i*2+3+6][j*4+6-12]=='X')
			{
				return 1;
				break;
			}else if(a[i*2+3][j*4+6]==a[i*2+3+2][j*4+6-4] && a[i*2+3+2][j*4+6-4]==a[i*2+3+4][j*4+6-8] && a[i*2+3+4][j*4+6-8]==a[i*2+3+6][j*4+6-12] && a[i*2+3+6][j*4+6-12]=='O')
			{
				return 2;
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


int minimax(char a[23][45], int depth, bool isMaximizing )
{
	if(checkWin(a)==2) return 10- depth;
	if(checkWin(a)==1) return -10+ depth;
	if(Full(a)) return 0;
	
	if(isMaximizing)
	{
		int bestScore=-100000;	
		for(int i=0; i<10; i++)
		{
			for(int j=0; j<10; j++)
			{
				if ((a[i*2+3][j*4+6]=='X') || (a[i*2+3][j*4+6]=='O'));
				{
					a[i*2+3][j*4+6]='O';
					int r = minimax(a,depth +1 ,false);
					a[i*2+3][j*4+6]=' ';
					if(r>bestScore)
					{
						bestScore=r;
					}
				}
			}
		}
		return bestScore;
	}else
	{
		int bestScore=100000;	
		for(int i=0; i<10; i++)
		{
			for(int j=0; j<10; j++)
			{
				if ((a[i*2+3][j*4+6]=='X') || (a[i*2+3][j*4+6]=='O'));
				{
					a[i*2+3][j*4+6]='O';
					int r = minimax(a,depth +1 ,true);
					a[i*2+3][j*4+6]=' ';
					if(r<bestScore)
					{
						bestScore=r;
					}
				}
			}
		}
		return bestScore;
	}
	
}
void bot(char a[23][45],int m, int n, int row2[50],int col2[50],int count2)
{
	cout << "Bot's turn: " << endl;
	int bestScore=100000;
	for(int i=0; i<10; i++)
	{
		for(int j=0; j<10; j++)
		{
			if ((a[i*2+3][j*4+6]!='X') || (a[i*2+3][j*4+6]!='O'))
			{
				a[i*2+3][j*4+6]='O';
				int r = minimax(a,0,true);
				a[i*2+3][j*4+6]=' ';
				if(r<bestScore)
				{
					bestScore=r;
					n=i;
					m=j;
				}
			}
		}
	}
	a[n*2+3][m*4+6]='O';	
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
	char a[23][45];
	int row1[50],row2[50],col1[50],col2[50];
	int win1=0,win2=0,draw=0;
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
	    		cout << "=> Player 1 = X, Player 2 = O" << endl;
	    		board(a,x,y);
	    		count1=0;
	    		count2=0;
		    	while(1){
                	player1(a,m,n,row1,col1,count1);
                	count1++;
                	if(checkWin(a)==1)
					{
                		cout << "Player 1 win !" << endl;
                		break;
	    			}
                	player2(a,m,n,row2,col2,count2);
                	count2++;
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
        	    	case 3:
        	    		board(a,x,y);
	    				count1=0;
	    				count2=0;
        	    		while(1)
						{
		                	player1(a,m,n,row1,col1,count1);
		                	count1++;
		                	if(checkWin(a)==1)
							{
		                		cout << "Player 1 win !" << endl;
		                		break;
			    			}
		                	bot(a,m,n,row2,col2,count2);
		                	board(a,x,y);
		                	count2++;
		                	if(checkWin(a)==2)
							{
		                		cout << "Bot win !" << endl;
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
    				win1++;
				}
				else if(checkWin(a)==2)
				{
					win2++;
				}
				else
				{
					draw++;
				}
				cout<<"---------------Player 1's information---------------"<<endl;
				cout<<"Player 1's number of wins: "<<win1<<endl;
				cout<<"Player 1's number of losses: "<<win2<<endl;
				cout<<"Player 1's number of draws: "<<draw<<endl;
				cout<<"---------------Player 2's information---------------"<<endl;
				cout<<"Player 2's number of wins: "<<win2<<endl;
				cout<<"Player 2's number of losses: "<<win1<<endl;
				cout<<"Player 2's number of draws: "<<draw<<endl;
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
ofstream Player ("Player.txt");
Player<<"Player's information";
Player<<"---------------Player 1's information---------------"<<endl;
Player<<"Player 1's number of wins: "<<win1<<endl;
Player<<"Player 1's number of losses: "<<win2<<endl;
Player<<"Player 1's number of draws: "<<draw<<endl;
Player<<"---------------Player 2's information---------------"<<endl;
Player<<"Player 2's number of wins: "<<win2<<endl;
Player<<"Player 2's number of losses: "<<win1<<endl;
Player<<"Player 2's number of draws: "<<draw<<endl;
Player.close();
return 0;
}
