#include <bits/stdc++.h>
using namespace std;

const int MOD = 10000;

string a;

struct bigint{

	//declare
	vector<int> arr;
	int len;

	//init
	bigint(){
		arr.emplace_back(0);
		len = 1;
	}

	bigint(string v){
		cout<<"hi";
	}
	
};

int solve();

int main () {
	//freopen("test.in", "r", stdin);
	//freopen("test.out","w", stdout);
	//ios::sync_with_stdio(0), cin.tie(0);

	cin>>a;
	cout<<solve(a)<<"\n";


	return 0;
}

int solve(string target){
	return 5;
}