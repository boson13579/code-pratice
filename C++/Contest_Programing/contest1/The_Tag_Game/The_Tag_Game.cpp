#include <bits/stdc++.h>
using namespace std;

int sdis[200005], edis[200005];

vector<int> path[200005];

void bfs(int x, int* arr);

int main() {
	ios::sync_with_stdio(0), cin.tie(0);

	int n, x;
	cin >> n >> x;

	for (int i = 0, a, b; i < n - 1; i++) {
		cin >> a >> b;
		path[a].emplace_back(b);
		path[b].emplace_back(a);
	}

	sdis[1] = 1;
	edis[x] = 1;
	bfs(1,sdis);
	bfs(x,edis);

	int ans = 0;
	for(int i=1 ; i<=n ; i++){
		if(sdis[i] > edis[i])
			ans = max(ans, sdis[i]*2-2);
	}
	cout<<ans<<"\n";
	return 0;
}

void bfs(int x, int* arr){

	queue<int> q;
	q.emplace(x);

	while(!q.empty()){
		
		int now = q.front();
		q.pop();

		for(int i:path[now]){
			if(!arr[i]){
				arr[i] = arr[now] + 1;
				q.emplace(i);
			} 
			
		}	
	}
}

