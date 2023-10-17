#include <bits/stdc++.h>
using namespace std;
int task , n , arr[1010];
int main () {
	ios::sync_with_stdio(0), cin.tie(0);
	cin>>task;
	while(task--){
		cin>>n;
		for(int i=0 ; i<n ; i++) cin>>arr[i];
		int count = 1;
		for(int i=1 , sum = 1; i<n-1 ; i++)
			if(sum+arr[i]<arr[i+1]){
				sum +=arr[i];
				count++;
			}
		cout<<count+1<<"\n";
	}
	return 0;
}

