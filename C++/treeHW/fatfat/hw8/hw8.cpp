#include <bits/stdc++.h>
using namespace std;

int times = 0;
const int DIMENSION = 3;
const int eachline = (1+DIMENSION*DIMENSION)*(DIMENSION*DIMENSION)/(2*DIMENSION);
struct sGame {
	int x, y;
	int board[DIMENSION][DIMENSION];
};

sGame Initialize();
sGame TryTrySee(sGame game);
sGame NextCell(sGame game);
bool OK(const sGame &game);
sGame PrevCell (sGame game);
void Output(sGame game);

int main()
{	
	struct sGame game;
	bool done = false;
	game = Initialize();
	do {
		game = TryTrySee(game);
		if (OK(game)) game = NextCell(game);
		else game = PrevCell(game);
		done = (game.y == DIMENSION) || (game.y < 0);
	} while (!done);
	Output(game);
	return 0;
}

sGame Initialize(){
	sGame ans;
	ans.x = 0;
	ans.y = 0;
	memset(ans.board , 0 , sizeof(ans.board));
	return ans;
}

sGame NextCell(sGame game){
	//1.
	game.x++;
	//2.
	if(game.x == DIMENSION){
		game.x = 0;
		game.y++;
	}
	//return
	return game;
}

sGame TryTrySee(sGame game){

	//4.
	while(1){
		//1.
		game.board[game.x][game.y]++;
		//2.
		if(OK(game)) return game;
		//3.
		if(game.board[game.x][game.y] >= DIMENSION*DIMENSION) return game;

	}
}

sGame PrevCell (sGame game){
	//1.
	game.board[game.x][game.y] = 0;
	//2.
	game.x--;
	//3.
	if(game.x < 0){
		game.x = DIMENSION-1;
		game.y--;
	}
	//return
	return game;
	
}
void Output(sGame game){
	for(int i=0 ; i<DIMENSION  ; i++){
		for(int t=0 ; t<DIMENSION ; t++)
			cout<<game.board[i][t]<<" ";
		cout<<"\n";
	}
}

bool OK(const sGame &game){
	
	//1.
	for(int i=0 ; i<DIMENSION ; i++){
		for(int t=0 ; t<DIMENSION ; t++){
			if(game.board[game.x][game.y] == game.board[i][t])
				if(i == game.x and t == game.y)
					continue;
				else
					return false;
		}
	}
	//2.
	int ysum = 0;
	for(int i=0  ; i<DIMENSION ; i++)
		ysum += game.board[game.x][i];
	if(game.y == DIMENSION-1 and ysum != eachline)
		return false;
	if(game.y < DIMENSION-1 and ysum >= eachline)
		return false;
	//3.
	int xsum = 0;
	for(int i=0 ; i<DIMENSION ; i++)
		xsum +=game.board[i][game.y];
	if(game.x == DIMENSION-1 and xsum != eachline)
		return false;
	if(game.x < DIMENSION-1 and xsum >= eachline)
		return false;
	//4.
	if(game.x == game.y){
		
		int lsysum = 0;
		for(int i=0 ; i<DIMENSION ; i++)
			lsysum += game.board[i][i];
		if(game.x == DIMENSION-1 and lsysum != eachline)
			return false;
		if(game.x < DIMENSION-1 and lsysum >= eachline)
			return false;

	}
	//4.
	if(game.x + game.y == DIMENSION-1){
		int rsysum = 0;
		for(int i = 0 ; i<DIMENSION ; i++)
			rsysum += game.board[i][DIMENSION-1-i];
		if(game.y == DIMENSION-1 and rsysum != eachline)
			return false;
		if(game.y <DIMENSION-1 and rsysum >= eachline)
			return false;
	}
	return true;

}