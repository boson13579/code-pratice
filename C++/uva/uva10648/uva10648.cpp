#include <bits/stdc++.h>
using namespace std;

int arr[10010];
int DP[10010];
int main(){
	// freopen("test.in", "r", stdin);
	// freopen("test.out","w", stdout);
	ios::sync_with_stdio(0), cin.tie(0);

	int a;
	while (cin >> a and a != 0)
	{
		int maxsubarr = -2147483640;
		for (int i = 0; i < a; i++)
			cin>>arr[i];

		DP[0] = max(arr[0],0);

		for(int i=1 ; i<a ; i++){
			DP[i] = max(DP[i-1],0) + arr[i]; 
			maxsubarr = max(maxsubarr,DP[i]);
		}

		if(maxsubarr>0)
			cout<<"The maximum winning streak is "<<maxsubarr<<".\n";
		else
			cout<<"Losing streak.\n";
	}

	return 0;
}
