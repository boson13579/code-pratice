#include <bits/stdc++.h>
using namespace std;

int main () {
	int n;
	ios::sync_with_stdio(0), cin.tie(0);
	int arr[n];
	srand(time(NULL));
	for(int i=0 ; i<n ; i++){
		arr[i] = (rand()%201)-100;
		cout<<arr[i]<<" ";
	}
	cout<<"\n";

	//-----
	int ans=0,fr=0,mfr=0,en=0;
	for(int i=0 ,c=0; i<n ; i++){
		if(c>0){
			c = c + arr[i];
		}
		else{
			c = arr[i];
			fr = i;
		}
		if(ans<c){
			mfr = fr;
			en = i;
			ans = c;
		}
	}
	//-----

	cout<<mfr<<" "<<en<<" "<<ans<<"\n";
	cout<<"\n";
	return 0;
}

