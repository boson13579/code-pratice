#include <bits/stdc++.h>
using namespace std;

int a , b , c; 
int ansarr[5001];
vector <pair<int , int>> edge[5001];
bool vis[5001];
void dijkstra(int start);
int main () {
	//freopen("test.in", "r", stdin);
	//freopen("test.out","w", stdout);
	//ios::sync_with_stdio(0), cin.tie(0);
	memset(ansarr , -1 , sizeof(ansarr));
	cin>>a>>b>>c;
	for(int i=0 , t1 , t2 , t3; i<a-1  ; i++){
		cin>>t1>>t2>>t3;
		edge[t1].emplace_back(t2,t3);
		edge[t2].emplace_back(t1,t3);
	}

	dijkstra(b);
	int ans = 0;
	for(int i=1 ;i<=a ; i++){
		if(ansarr[i] >= c)
			ans++;
	}
	cout<<ans<<"\n";


	return 0;
}

void dijkstra(int start){
	
	multiset <pair<int ,int>> q;
	//to dis
	for(auto i:edge[start]){
		ansarr[i.first] = i.second;
		q.emplace(i.first,i.second);
	}
		
	while(!q.empty()){
		//for(auto i:q)
		//	cout<<i.first<<" "<<i.second<<"\n";
		int now = (*q.begin()).first;
		q.erase(q.begin());
		if(vis[now]) continue;

		vis[now] = true;

		for(auto i:edge[now]){
			if(i.second <= ansarr[now]){
				ansarr[i.first] = i.second;
			}
			else{
				ansarr[i.first] = ansarr[now];
			}
			q.emplace(i.first,ansarr[i.first]);
		}
	}
}