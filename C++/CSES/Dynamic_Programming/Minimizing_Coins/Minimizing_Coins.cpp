#include <bits/stdc++.h>
using namespace std;

int DP[1000010];

vector<int> coin;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int n, sum, temp;
    cin >> n >> sum;

    for (int i = 0; i <= sum; i++) DP[i] = 2147483640;

    for (int i = 0; i < n; i++) {
        cin >> temp;
        coin.emplace_back(temp);
        DP[temp] = 1;
    }
	for(auto i:coin){
		for(int t=1 ; t+i<=sum ; t++){
			DP[t+i] = min(DP[t+i],DP[t]+1);
		}
	}

    cout << (DP[sum] == 2147483640 ? -1 : DP[sum]) << "\n";

    return 0;
}
