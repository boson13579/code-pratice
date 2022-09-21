#include <bits/stdc++.h>
using namespace std;



int main () {
	//freopen("test.in", "r", stdin);
	//freopen("test.out","w", stdout);
	ios::sync_with_stdio(0), cin.tie(0);

	vector<int> a;
	int cases;
	cin>>cases;
	while(cases--){
		int n;
		cin>>n;
		a.clear();
		int temp;
		cin>>temp;
		a.emplace_back(temp);
		int q=0;
		for(int i=0 ; i<n-1 ; i++){
			cin>>temp;
			for(auto t:a){
				if(temp>=t)
					q++;
			}
			a.emplace_back(temp);
		}
		cout<<q<<"\n";
			
	
	}

	return 0;
}

