#include <bits/stdc++.h>
using namespace std;

int times = 1;
map <int , vector<int>> adj_list;
map <int , int> in_degree; 
map <int , bool> vis;
int gone = 0;
bool ans = true;

void input(int a , int b);
void init();
void DFS(int a);

int main () {
	//freopen("test.out" , "w" , stdout);
	ios::sync_with_stdio(0), cin.tie(0);
	int a,b;
	while(cin>>a>>b and a>=0 and b>=0){
		
		if(a!=0 or b!=0){
			input(a,b);
			continue;
		}

		if(adj_list.size() == 0){
			cout<<"Case "<<times++<<" is a tree.\n";
			continue;
		}

		int root;
		bool findroot = false;
		for(auto i:in_degree)
			if(i.second==0){
				root = i.first;
				findroot = true;	
			}
				
		if(!findroot){
			cout<<"Case "<<times++<<" is not a tree.\n";
			init();
			continue;

		}
			DFS(root);

		if(gone != adj_list.size())
			ans = false;

		if(ans)
			cout<<"Case "<<times++<<" is a tree.\n";
		else
			cout<<"Case "<<times++<<" is not a tree.\n";

		init();

	}

	return 0;
}

void input(int a , int b){

	if(adj_list.find(a) == adj_list.end()){
		vector <int> temp;
		adj_list[a] = temp;
	}

	if(adj_list.find(b) == adj_list.end()){
		vector <int> temp;
		adj_list[b] = temp;
	}
	adj_list[a].emplace_back(b);

	if(in_degree.find(a) == in_degree.end())
		in_degree[a] = 0;
	if(in_degree.find(b) == in_degree.end())
		in_degree[b] = 0;
	in_degree[b]++;

	if(vis.find(a) == vis.end())
		vis[a] = false;
	if(vis.find(b) == vis.end())
		vis[b] = false;
}

void DFS(int a){

	gone++;
	if(vis[a]){
		ans = false;
		return;
	}
	for(auto i:adj_list[a])
		DFS(i);	
}

void init(){
	adj_list.clear();
	in_degree.clear();
	vis.clear();
	gone = 0;
	ans = true;
}