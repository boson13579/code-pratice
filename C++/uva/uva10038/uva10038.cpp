#include <iostream>
#include <algorithm>
using namespace std;

int n,a[3000],c[3000],b;
int main () {
	while(cin>>n){
		int ans=1;
		cin>>a[0];
		for(int i=1 ; i<n ; i++){
			cin>>a[i];
			if(a[i-1]-a[i]>=0)
				b=a[i-1]-a[i];
			else
				b=a[i]-a[i-1];
			if( (b>=n) || (b<1) || (c[b]==1)){
				ans=0;
			}
			c[b]+=1;
		}
		if(ans)
			cout<<"Jolly"<<"\n";
		else
			cout<<"Not jolly"<<"\n";
 		for(int i=0 ; i<3000 ; i++){
 			c[i]=0;
		 }
	}
	return 0;
}


