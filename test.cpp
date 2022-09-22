#include <bits/stdc++.h>
using namespace std;

map <int,vector<pair<int,int>> , greater<int>> qq;

int main () {
	//freopen("test.in", "r", stdin);
	//freopen("test.out","w", stdout);
	ios::sync_with_stdio(0), cin.tie(0);

	vector<pair<int,int>> temp;
	temp.emplace_back(0,1);
	qq.insert(make_pair(50,temp));
	temp.clear();
	temp.emplace_back(make_pair(1,0));
	qq.insert(make_pair(51,temp));
	temp.clear();
	qq[50].emplace_back(make_pair(2,-1));

	for(auto i=qq.begin() ; i!=qq.end() ; i++){
		cout<<"| ";
		int nowCol = 0;
		for(auto t:(*i).second){
			for(int a=nowCol ; a<t.first ; a++){
				cout<<" ";
			}
			if(t.second==1)
				cout<<"/";
			else if(t.second==0)
				cout<<"_";
			else if(t.second==-1)
				cout<<"\\";
		}
		cout<<"\n";
	}
	cout<<"+";
	for(int i=0 ; i<3 ; i++)
		cout<<"-";

	return 0;
}

