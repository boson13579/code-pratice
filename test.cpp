#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> a(vector<vector<int>> *matrix){
	vector<vector<int>> temp = *matrix;
	temp[1][1] = 1;
	return temp;
}


int factorsum(int a){
	map<int,int> factor;
	int divide = 2;
	while(a!=1){
		if(a%divide==0){
			if(factor.find(divide)==factor.end())
				factor.insert(make_pair(divide,1));
			else
				factor[divide] = factor[divide]+1;
			a/=divide;
			continue;
		}
		divide++;	
	}
	int sum=1;
	for(auto i:factor){
		cout<<i.first<<" "<<i.second<<"\n";
		sum*=((i.first*(((i.second*i.second+i.second)/2)+1)));
	}
		
	return sum;
}
int main () {
	//freopen("test.in", "r", stdin);
	//freopen("test.out","w", stdout);
	ios::sync_with_stdio(0), cin.tie(0);

	cout<<factorsum(5)<<"\n";
	// vector<vector<int>> qq;
	// for(int i=0 ; i<2 ; i++){
	// 	vector<int> temp;
	// 	for(int t=0 ; t<2 ; t++){
	// 		int tempint;
	// 		cin>>tempint;
	// 		temp.emplace_back(tempint);
	// 	}
	// 	qq.emplace_back(temp);
	// }
	// qq=a(&qq);
	// for(auto i:qq){
	// 	for(auto t:i){
	// 		cout<<t<<" ";
	// 	}
	// 	cout<<"\n";
	// }


	return 0;
}

