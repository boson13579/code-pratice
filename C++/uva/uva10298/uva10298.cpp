#include <bits/stdc++.h>
using namespace std;

string a;

int main () {
	ios::sync_with_stdio(0), cin.tie(0);
	while(cin>>a){
		if(a==".")
			return 0;
		int ans=1 , l=1 , n=1 , j=0;
		bool ok = false;
		while(1){
			
			bool subok = true;
			
			if(l*(n+1) > a.size()){
				subok = false;
				break;
			}
				
			else {  
				for(int j=0 ; j<l ; j++){
					if(a[0+j]!=a[(l*n)+j])
						subok = false;
				}
			}

			if(subok&&l*(n+1)==(a.size())){
				ok = true;
				break;
			}

			if(subok)
				n += 1;
			else{
				n = 1;
				l = l*n + j + 1 ;
			}

		}

		if(ok)
			ans = n+1;
		cout<<ans<<"\n";

	}
	
	return 0;
}

