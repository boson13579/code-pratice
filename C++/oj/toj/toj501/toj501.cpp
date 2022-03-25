#include <bits/stdc++.h>
using namespace std;

int a , arr[200010] , ans=0;

int main () {
	ios::sync_with_stdio(0), cin.tie(0);
	cin>>a;
	for(int i=1 ; i<=a ; i++){
		cin>>arr[i];
		arr[a+i]=arr[i];
	}
	for(int i=0 , cur=0 ; i<=a*2 ; i++){
		cur+=1;
		cur=min(cur,arr[i]);
		ans=max(ans,cur);
	}
	cout<<min(ans,a)<<"\n";

	return 0;
}

