/*
	solve : just a normal DFS

	create by 110502529
*/
#include <bits/stdc++.h>
using namespace std;

vector<pair<int , int>> edge[5001]; // <to , relation>
int relation[5001]; //relation to Vk
bool vis[5001]; //record check or not
int a,b,c; 

void DFS(int start);

int main () {

	cin>>a>>b>>c;

	//input edge
	for(int i=1 , t1 , t2 , t3; i<a  ; i++){
		cin>>t1>>t2>>t3;
		edge[t1].emplace_back(t2,t3);
		edge[t2].emplace_back(t1,t3);
	}

	for(auto i:edge[b]){
		relation[i.first] = i.second;
		vis[i.first] = true;
		DFS(i.first);
	}

	int ans = 0;

	for(int i=1 ;i<=a ; i++){
		if(relation[i] >= c and i!= b)
			ans++;
	}

	cout<<ans<<"\n";
	return 0;
}

void DFS (int start){
	for(auto i:edge[start]){
		if(vis[i.first]) continue;
		if(relation[start] < i.second) relation[i.first] = relation[start];
		else relation[i.first] = i.second;
		vis[i.first] = true;
		DFS(i.first);
	}
}