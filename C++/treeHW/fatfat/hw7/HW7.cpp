#include <bits/stdc++.h>
using namespace std;

const int dimension = 5;

struct sGame{
    int x,y;
    int board[dimension][dimension];
};

sGame Initialize(){
    sGame temp;
    temp.x = 0;
    temp.y = 0;
    for(int i=0 ; i<dimension ; i++)
        for(int t=0 ; t<dimension ; t++)
            temp.board[i][t] = 0;
    return temp;
}

bool ok(sGame temp){
    for(int i=0 ; i<dimension ; i++){
        for(int t=0 ; t<dimension ; t++){
            if(i == temp.x and t == temp.y)
                continue;
            if(temp.board[i][t] == temp.board[temp.x][temp.y])
                return false;
        }
    }
    return true;
}
sGame TryTrySee(sGame temp){
    temp.board[temp.x][temp.y] += 1;
    while(!ok(temp))
        temp.board[temp.x][temp.y] += 1;
    return temp;
}

sGame NextCell(sGame temp){
    temp.x += 1;
    if(temp.x == dimension){
        temp.x = 0;
        temp.y += 1;
    }
    return temp;
}

void Output(sGame temp){
    for(int i=0 ; i<dimension ; i++){
        for(int t=0 ; t<dimension ; t++){
            cout<<temp.board[i][t]<<" ";
        }
        cout<<"\n";
    }
    return;
}
int main()
{
struct sGame game;
game = Initialize();
do {
game = TryTrySee(game);
game = NextCell(game);
} while (game.y < dimension);
Output(game);
return 0;
}