#include <bits/stdc++.h>
using namespace std;

vector <int> nums;
bool vis[20];
bool dfs(int times , int ind , int sum);
int b , sum;
void init();

int main () {
	//freopen("test.in", "r", stdin);
	//freopen("test.out","w", stdout);
	//ios::sync_with_stdio(0), cin.tie(0);

	int a;cin>>a;
	while(a--){
		cin>>b;
		init();
		for(int i=0 , temp ; i<b ; i++){
			cin>>temp;
			sum += temp;
			nums.emplace_back(temp);
		}
		
		//sort(nums.begin(),nums.end(),greater<int>());

		if(sum % 4 != 0 or *(nums.end()-1) > sum/4){
			cout<<"no\n";
			continue;
		}
		bool ok = dfs(0,0,0);
		if(ok)
			cout<<"yes\n";
		else
			cout<<"no\n";

	}

	return 0;
}

void init(){
	sum = 0;
	nums.clear();
	memset(vis,false,sizeof(vis));
}

bool dfs(int times , int ind , int tempsum ){
	
	if(times == 3) return true;

	for(int i= ind ; i<b ; i++){
		
		if(vis[i]) continue;

		vis[i] = true;

		if(tempsum + nums[i] == sum/4)
			if(dfs(times+1,0,0))
				return true;
		
		if(tempsum + nums[i] < sum/4)
			if(dfs(times,i+1,tempsum+nums[i]))
				return true;

		vis[i] = false;
		
		if(tempsum == 0)
			return false;
	}
	return false;
}
