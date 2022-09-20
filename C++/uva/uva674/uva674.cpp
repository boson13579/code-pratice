#include <bits/stdc++.h>
using namespace std;

long long int DP[8000];

int main() {
    //freopen("test.in", "r", stdin);
    //freopen("test.out", "w", stdout);
    ios::sync_with_stdio(0), cin.tie(0);
	memset(DP,0,sizeof(DP));
	DP[0] = 1;
    for(int i=0 ; i<7500 ; i++){
		DP[i+1] += DP[i];
	}
	for(int i=0 ; i<7500 ; i++){
		DP[i+5] += DP[i];
	}
	for(int i=0 ; i<7500 ; i++){
		DP[i+10] += DP[i];
	}
	for(int i=0 ; i<7500 ; i++){
		DP[i+25] += DP[i];
	}
	for(int i=0 ; i<7500 ; i++){
		DP[i+50] += DP[i];
	}

    int a;
    while (cin >> a) {
        cout << DP[a] << "\n";
    }
    return 0;
}
