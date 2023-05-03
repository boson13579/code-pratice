#include<bits/stdc++.h>
using namespace std;

int table[1005][1005];

bool cmp(array<int, 4> a, array<int, 4> b) {
    if (a[0] != b[0])
        return a[0] < b[0];
    else
        return a[1] < b[1];
}

int main() {

    // init combination
    for (int i = 0; i < 1002; i++) {
        table[0][i] = 1;
        table[i][0] = 1;
    }
    for (int i = 1; i < 1002; i++) {
        for (int t = 1; t < 1002; t++) {
            table[i][t] += table[i - 1][t];
            table[i][t] += table[i][t - 1];
            table[i][t] %= 2552;
        }
    }

    int W, H, K;
    cin >> W >> H >> K;

    while (K--) {
        int numBlock;
        cin >> numBlock;

        vector<vector<int>> dp(W + 1, vector<int>(H + 1, 0));
        vector<array<int, 4>> block(numBlock);

        for (int i = 0; i < numBlock; i++) {
            cin >> block[i][0] >> block[i][1] >> block[i][2] >> block[i][3];
        }
        block.push_back({ W, H, W, H });

        sort(block.begin(), block.end(), cmp);

        //block[i][0] block[i][1] means ith block start 
        //block[i][2] block[i][3] means ith block end

        for (int i = 0; i <= numBlock; i++) {
            dp[block[i][0]][block[i][1]] = table[block[i][0]][block[i][1]];
            for (int t = 0; t < i; t++) {
                if (block[t][2] > block[i][0] or block[t][3] > block[i][1]) continue;;
                dp[block[i][0]][block[i][1]] -= dp[block[t][0]][block[t][1]] * table[block[i][0] - block[t][2]][block[i][1] - block[t][3]];
                if (dp[block[i][0]][block[i][1]] < 0) dp[block[i][0]][block[i][1]] += (-(dp[block[i][0]][block[i][1]] / 2552) + 1) * 2552;
            }
        }

        cout << dp[W][H] << "\n";
    }

    return 0;
}