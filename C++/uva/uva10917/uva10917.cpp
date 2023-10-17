#include <bits/stdc++.h>
using namespace std;

int dis_to_home[1010]; //shortest
int DP[1010]; //ways to home
vector <pair<int,int>> edge[1010]; //(to,dis)

void dijkstra(int start , int n);
void init(int n);
int DFS(int to);

int main () {
	freopen("test.in", "r", stdin);
	freopen("test.out","w", stdout);
	ios::sync_with_stdio(0), cin.tie(0);
	int n,m;
	while(cin>>n and n != 0){
		cin>>m;
		init(n);
		for(int i=0 , a , b , c ; i<m ; i++){
			cin>>a>>b>>c;
			edge[a].emplace_back(make_pair(b,c));
			edge[b].emplace_back(make_pair(a,c));
		}

		dijkstra(2,n);
		cout<<DFS(2)<<"\n";
		
	}
	return 0;
}

void init(int n){
	for(int i=1 ; i<=n ; i++)
		edge[i].clear();
	for(int i=0 ; i<=n ; i++){
		DP[i] = -1;
		dis_to_home[i] = 9999999;
	}
	DP[1] = 1;
}

void dijkstra(int start , int n){

	priority_queue <pair<int,int> , vector<pair<int,int>> , greater<pair<int,int>>> pq; //(dis , form) 
	//priority_queue <pair<int , int>> init less<>
	bool vis[n+10];
	memset(vis,false,sizeof(vis));
	dis_to_home[start] = 0;
	pq.emplace(make_pair(dis_to_home[start],start));

	while(!pq.empty()){
		int now = pq.top().second;pq.pop();
		if(vis[now])
			continue;
		vis[now] = true;
		for(auto i:edge[now]){

			if(dis_to_home[i.first]>dis_to_home[now]+i.second){
				dis_to_home[i.first] = dis_to_home[now] + i.second;
				pq.emplace(dis_to_home[i.first],i.first);
			}

		}
	}
}

int DFS(int to){	//從屁屁走
	if(DP[to] != -1)
		return DP[to];
	int ans=0;
	for(auto i:edge[to]){
		if(dis_to_home[i.first]>dis_to_home[to]){
			ans += DFS(i.first);
		}
	}
	DP[to] = ans;
	return DP[to];
}