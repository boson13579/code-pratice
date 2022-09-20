#include <bits/stdc++.h>
using namespace std;

int main() {
    // freopen("test.in", "r", stdin);
    // freopen("test.out","w", stdout);
    ios::sync_with_stdio(0), cin.tie(0);

    int times;
    cin >> times;

    while (times--) {
        int a, b, c;
        cin >> a >> b >> c;
        long long ans = 0;
        long long halfTest = pow(2,a-1);
		vector<int> ansList;
		vector<int> list;
		for(int i=b ; i<=c ; i++){
			list.emplace_back(i);
			ansList.emplace_back(1);
		}
		for(int i=0 ; i<a ; i++){
			for(int t=0 ; t<list.size() ; t++){
				if (list[t]<=halfTest)
					ansList[t]*=2;
				else
					list[t]-=halfTest;
			}
			halfTest /=2;

		}
		for(auto i:ansList)
			ans += i;
        cout << ans << "\n";
    }

    return 0;
}
