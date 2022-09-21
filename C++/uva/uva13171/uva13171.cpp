#include <bits/stdc++.h>
using namespace std;



int main () {
	//freopen("test.in", "r", stdin);
	//freopen("test.out","w", stdout);
	ios::sync_with_stdio(0), cin.tie(0);

	int t;
	cin>>t;
	while(t--){
		int m,y,c;
		string qq;
		cin>>m>>y>>c>>qq;

		for(auto i:qq){
			if(i=='M')
				m--;
			if(i=='Y')
				y--;
			if(i=='C')
				c--;
			if(i=='R'){
				m--;
				y--;
			}
			if(i=='B'){
				m--;
				y--;
				c--;
			}
			if(i=='G'){
				y--;
				c--;
			}
			if(i=='V'){
				m--;
				c--;
			}
		}
        if (m >= 0 and y >= 0 and c >= 0)
            cout << "YES " << m << " " << y << " " << c << "\n";
		
		else
			cout<<"NO\n";
		 
	}
	return 0;
}

