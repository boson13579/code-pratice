#include <bits/stdc++.h>
using namespace std;



int main () {
	//freopen("test.in", "r", stdin);
	//freopen("test.out","w", stdout);
	ios::sync_with_stdio(0), cin.tie(0);

	int a,b;
	while(cin>>a and a!=0){
		double c = (-1+sqrt(1+4*a*2))/2;
		b = int(c)+1;
		cout<<int(((b+1)*b)/2)-a<<" "<<b<<"\n";
        }

	return 0;
}

