#include <bits/stdc++.h>
using namespace std;

long long int ans[1000][4];

long long int solve(int a , int b)
{
	if(ans[a][b]!=0)
		return ans[a][b];
	else{
		if(a>=3)
			ans[a][b]=solve(a-1,1)+solve(a-2,2)+solve(a-3,3);
		else if(a==2)
			ans[a][b]=solve(a-1,1)+solve(a-2,2);
		else if(a==1)
			ans[a][b]=solve(a-1,1);
		if(b==1)
			ans[a][b]*=2;
		return ans[a][b];
	}
}
int main()
{
	//freopen("test.in", "r", stdin);
	//freopen("test.out","w", stdout);
	ios::sync_with_stdio(0), cin.tie(0);

	// init
	ans[0][1]=2;
	ans[0][2]=1;
	ans[0][3]=1;
	int a;
	while (cin >> a)
	{
		cout<<solve(a,0)<<"\n";
	}

	return 0;
}
