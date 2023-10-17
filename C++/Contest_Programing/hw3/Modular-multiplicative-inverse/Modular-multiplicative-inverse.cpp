#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0), cin.tie(0);

	int n = 10;
	int arr[10][10];

	memset(arr, 0, sizeof(arr));

	for (int i = 0; i < n; i++)
		for (int t = 0; t < n; t++)
			if (i == 0 or t == 0)
				arr[i][t] = 1;
			else
				arr[i][t] += arr[i - 1][t] + arr[i][t - 1];

	for (int i = 0; i < n; i++) {
		for (int t = 0; t < n; t++)
			cout << setw(6) << arr[i][t];
		cout << "\n\n";
	}

	return 0;
}