#include<iostream>
#include<fstream>
using namespace std;

void print(char a[][10],int b);
bool isvalidturn(char a[][10],int row,int column,int b);
bool iswinner(char a[][10],int b,char ch);
void save(char a[][10],int s,int t);

int main()
{
char board[10][10]={{NULL}};
int s,i,r,c;//size,turn,riw,column
char ch;
cout<<"This is Tic Tac Toe game."<<endl;
cout<<"Press C to continue previous game and N to new game (N / C)"<<endl;
cin>>ch;
if (ch=='c' || ch=='C')
{
ifstream fin;
fin.open("Game.txt");
fin>>s>>i;
for (int a=0;a<s;a++)//size,
{
for (int b=0;b<s;b++)
fin>>board[a][b];
}
fin.close();
cout<<"Game loaded"<<endl;
}
else
{
cout<<"Enter size of the board"<<endl;
cin>>s;
i=0;
}

while (i<s*s)
{
print(board, s);
cout<<"Player X turn (Enter -1 & -1 to save game)"<<endl;
cout<<"Enter the row = ";
cin>>r;
cout<<"Enter the column = ";
cin>>c;

while (isvalidturn(board, r, c, s)==false)//Board,row,column,size
{
cout<<"Wrong turn please input again"<<endl;
cout<<"Enter row = ";
cin>>r;
cout<<"Enter column = ";
cin>>c;
}
if (r==-1 && c==-1)
{
save(board, s, i);
r=0;
c=0;
i=100;
}
			

board[r][c]='x';
if (iswinner(board, s, 'x')==true)
{
cout<<"X is winner"<<endl;
i=100;
}

i++;

if (i<s*s)
{
print(board, s);
cout<<"Player O turn (Enter -1 & -1 to save game)"<<endl;
cout<<"Enter row = ";
cin>>r;
cout<<"Enter column = ";
cin>>c;

while (isvalidturn(board, r, c, s) == false)
{
cout<<"Wrong turn please input again"<<endl;
cout<<"Enter row = ";
cin>>r;
cout<<"Enter column = ";
cin>>c;
}
if(r==-1 && c==-1)
{
save(board, s, i);
r=0;
c=0;
i=100;
}

board[r][c] = 'o';
if (iswinner(board, s, 'o')==true)
{
cout<<"O is winner"<<endl;
i = 100;
}
i++;
}		
}




if (i==s*s)
{
cout<<"The game is a draw"<<endl;
print(board,s);
}
return 0;
}

void print(char a[][10],int b)
{
	system ("cls");
cout<<" ";
for(int i=0;i<b;i++)
cout<<"\t"<<i;
cout<<endl;
for (int i=0;i<b;i++)
{
cout<<i;
for (int j=0;j<b;j++)
{
if(a[i][j]==NULL)
cout<<"\t"<<" ";
else
cout<<"\t"<<a[i][j];
}
cout<<endl;			 
}
}

bool isvalidturn(char a[][10], int row, int column, int b)
{
if(a[row][column]==NULL && row<b && column<b)
return true;
else
return false;
}

bool iswinner(char a[][10],int b,char ch) // Board,Board size,ch turn
{
int counter=0;	
for (int i=0;i<b;i++)
{
for (int j=0;j<b;j++)
{
if (a[i][j]==ch) // row check
counter++;
}
if(counter==b)
return true;
counter=0;
for (int j=0;j<b;j++)
{
if(a[j][i]==ch) // column check
counter++;
}
if(counter==b)
return true;
counter=0;	
}

for(int i=0;i<b;i++)
{
if(a[i][i]==ch)
counter++;
}
if(counter==b)
return true;
counter = 0;
for (int i=0;i<b;i++)
{
if(a[i][b-i-1]==ch)
counter++;
}
if (counter==b)
return true;

return false;
}

void save(char a[][10],int s,int t)//Board , size board,turn
{
ofstream fout;
fout.open("Game.txt");
fout<<s<<" "<<t<<endl;

for (int i=0;i<s;i++)
{
for (int j=0;j<s;j++)
fout<<a[i][j];
fout<<endl;
}
fout.close();
}
