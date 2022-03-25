#include <bits/stdc++.h>
using namespace std;

long long int a[200010] , b , tmp , tmp1;

int main () {
	ios::sync_with_stdio(0), cin.tie(0);
	a[0] = 0;
	cin>>b;
	for(int i=1 ; i<=b ;i++){
		cin>>tmp;
		a[i] = a[i-1]+tmp;
	}
	cin>>b;
	for(int i=0 ; i<b ; i++){
		cin>>tmp>>tmp1;
		cout<<a[tmp1]-a[tmp-1]<<"\n";
	}

	return 0;
}

