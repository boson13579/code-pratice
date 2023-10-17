#include <bits/stdc++.h>
using namespace std;

vector <int> sticks;
bool vis[20];
bool dfs(int success , int ind , int sum);
int b , sum , ww;
void init();

int main () {
	
	sort(sticks.begin(),sticks.end(),greater<int>());

	if(sum % 4 != 0)
		cout<<"no\n";

	else{
		bool ok = dfs(0,0,0);
		if(ok) cout<<"yes\n";
		else cout<<"no\n";
	}
	return 0;
}

void init(){
	sum = 0;
	sticks.clear();
	memset(vis,false,sizeof(vis));
}

bool dfs(int success , int ind , int tempsum ){
	
	if(success == 3) return true;

	for(int i= ind ; i<sticks.size() ; i++){
		
		if(vis[i]) continue;

		vis[i] = true;
		if(tempsum + sticks[i] == sum/4)
			if(dfs(success+1,0,0))
				return true;
		
		if(tempsum + sticks[i] < sum/4)
			if(dfs(success,i+1,tempsum+sticks[i]))
				return true;
		vis[i] = false;
		
		if(tempsum == 0) return false;
	}
	return false;
}
