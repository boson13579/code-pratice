#include <bits/stdc++.h>
using namespace std;

vector<int> a[1000010];
int n,k;

int main () {
	ios::sync_with_stdio(0), cin.tie(0);
	cin>>n>>k;
	int c,d;
	for(int i = 0 ; i<k ;i++){
		cin>>c>>d;
		a[c].emplace_back(d);
		a[d].emplace_back(c);
	}
	for(int i=1 ; i<=n ; i++){
		sort(a[i].begin() , a[i].end());
	}
	for(int i=1 ; i<=n ; i++){
		for(int j=0 ; j<a[i].size() ; j++){
			cout<<a[i][j];
			if(j!=a[i].size()-1)
				cout<<" ";
		}
		cout<<"\n";
	}

	return 0;
}

