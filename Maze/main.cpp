#include<iostream>

#include<stdlib.h>

using namespace std;



char map[20][40] = {
"#######################################",
"#O X XXXXX XX #",
"# X XX XXXX XXX#",
"# XXXXXXXXXXXXX XXXXXXXX XX #",
"# XX XXX XXXXX #",
"# XXXX XXX XXXX X XX X #",
"# X XXXX XX X X XX X #",
"#P XX X X XX X X XX X X #",
"# XX X X XX X XX X X #",
"# XX X XX X XXXXXXX X #",
"# X XXXXX XXXXXX #",
"#X X X X X XXXXX X #",
"#X X XXX X X XXXXX X X #",
"#X X X X XXXX X X #",
"# X XX X XXXX X XX X X #",
"# XXXXXX X X X XX #",
"# X X XXXX X XXXX#",
"# XXXXXXXX X X X F#",
"#######################################"

};

int x = 1, y = 1;
bool game_running = true;

int main()
{

while(game_running == true)
{
system("cls");
for(int display = 0; display < 20; display++)
{
cout<<map[display]<<endl;
}

if(GetAsyncKeyState(VK_DOWN))
{
int y2 = y + 1;
if(map[y2][x] == ' ')
{
map[y][x] = ' ';
y++;
map[y2][x] = 'O';
}
}

if(GetAsyncKeyState(VK_UP))
{
int y2 = y - 1;
if(map[y2][x] == ' ')
{
map[y][x] = ' ';
y--;
map[y2][x] = 'O';
}
}

if(GetAsyncKeyState(VK_RIGHT))
{
int x2 = x + 1;
if(map[y][x2] == ' ')
{
map[y][x] = ' ';
x++;
map[y][x] = 'O';
}
}

if(GetAsyncKeyState(VK_LEFT))
{
int x2 = x - 1;
if(map[y][x2] == ' ')
{
map[y][x] = ' ';
x--;
map[y][x] = 'O';
}
}

if(GetAsyncKeyState(VK_ESCAPE))
{
game_running = false;
}

}
system("pause>nul");
cout<<"GAME OVER"<<endl;

return 0;
}
