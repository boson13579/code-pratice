#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

int n ;
string s;

int main () {
	ios::sync_with_stdio(0), cin.tie(0);
	cin>>n>>s;
	int ans = n-1;
	for(int i=n-1 ; i>=0 ; i--){
		bool ok=1;
		for(int j=i , k=n-1 ; j<k ; j++ , k--){
			if(s[j]!=s[k]){
				ok=0;
				break;
			}		
		}
		if(ok)
			ans=i;
	}
	cout<<ans<<"\n";

	return 0;
}


