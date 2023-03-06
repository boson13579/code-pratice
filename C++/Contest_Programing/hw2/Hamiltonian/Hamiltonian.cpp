#include <bits/stdc++.h>
using namespace std;

int maze[105][105];
int dis[105][105];

vector<pair<int, int>> candy;
pair<int, int> start, end;

void bfs(pair<int,int> a);

int main() {
	ios::sync_with_stdio(0), cin.tie(0);

	int testcase;
	cin >> testcase;
	while (testcase--) {
		int n, m;
		cin >> n >> m;
		
		char temp;
		for (int i = 0; i < n; i++) {
			for (int t = 0; t < m;t++) {
				cin >> temp;
				maze[i][t] = (temp == '#' ? 0 : 1);
				if (temp == 'T') start = { i,t };
				if (temp == 'W') end = { i,t };
				if (temp = 'C') candy.emplace_back(i, t);
			}
		}

		vector<pair<int,int>> path[candy.size()+2];
		bfs(start); 
		for(int i=0 ; i<candy.size() ; i++){
			
			path[0].emplace_back(dis[candy[i].first][candy[i].second],i+1);
			
		}
		path[0].emplace_back()
	}



	return 0;
}

void bfs(pair<int,int> a){

}