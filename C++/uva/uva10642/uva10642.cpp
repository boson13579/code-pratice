#include <bits/stdc++.h>
using namespace std;



int main () {
	//freopen("test.in", "r", stdin);
	//freopen("test.out","w", stdout);
	ios::sync_with_stdio(0), cin.tie(0);

	int a;
	cin>>a;
	int b = 1;
	while(a--){

		int f1,f2,e1,e2;
		cin>>f1>>f2>>e1>>e2;

		int f = f1+f2;
		int e = e1+e2;

		int ans = (((e+1)*e)/2+e1)-(((f+1)*f)/2+f1);
	
		cout<<"Case "<<b<<": "<<ans<<"\n";
		b++;
	}



	return 0;
}

