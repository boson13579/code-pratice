#include <bits/stdc++.h>
using namespace std;

int DP[1000005];

int fibo(int n) {

	if(DP[n]!=0)
		return DP[n];
	
	DP[n] = fibo(n-1)+fibo(n-2);
    return DP[n];
}

int main() {


    // freopen("test.in", "r", stdin);
    // freopen("test.out","w", stdout);
    // ios::sync_with_stdio(0), cin.tie(0);
	int n;
	DP[0] = 1;
	DP[1] = 1;
    while (cin >> n) cout << fibo(n);

    return 0;
}
