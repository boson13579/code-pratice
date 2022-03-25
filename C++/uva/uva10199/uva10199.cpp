#include <bits/stdc++.h>
using namespace std;

unordered_map<string, int> dots;
string inttostr[105];

vector<string> go[105];
int dfn[105],low[105],deep=0;

set<string> ans; 

void init(int n);

void dfs(int cur , int par);

int main () {
	//freopen("test.in","r",stdin);
	//freopen("test.out","w",stdout);
	ios::sync_with_stdio(0), cin.tie(0);
	int times = 0;
	int dots_num;
	while(cin>>dots_num && dots_num != 0){
		times++;
		init(dots_num);
		string temp_str,temp_str2;

		for(int i=0 ; i<dots_num ; i++){
			cin>>temp_str;
			dots[temp_str] = i;
			inttostr[i] = temp_str;
		}

		int roads_num;cin>>roads_num;
		for(int i=0 ; i<roads_num ; i++){
			cin>>temp_str>>temp_str2;
			go[dots[temp_str]].emplace_back(temp_str2);
			go[dots[temp_str2]].emplace_back(temp_str);
		}

		for(int i=0 ; i<dots_num ; i++){
			if(!dfn[i])
				dfs(i,-1);
		}
		if(times != 1)
			cout<<"\n";
		cout<<"City map #"<<times<<": ";
		cout<<ans.size();
		cout<<" camera(s) found\n";
		for(auto i:ans)
			cout<<i<<"\n";
	}


	return 0;
}

void init(int n){
	for(int i=0 ; i<105 ; i++){
		go[i].clear();
		dfn[i] = low[i] = 0;
	}
		
	dots.clear();	
	ans.clear();
	deep = 0;
}

void dfs(int cur , int par){
	int chi = 0;
	dfn[cur] = low[cur] = ++deep;

	for(auto i :go[cur]){
		if(!bool(dfn[dots[i]])){
			chi++;
			dfs(dots[i],cur);
			low[cur] = min(low[cur],low[dots[i]]);

			if((par == -1 and chi>1)or(par != -1 and low[dots[i]]>=dfn[cur]))
				ans.insert(inttostr[cur]);
		}
		else if(dots[i] != par)
			low[cur] = min(low[cur] , dfn[dots[i]]);
	}
}