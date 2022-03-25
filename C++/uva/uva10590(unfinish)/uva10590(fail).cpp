#include <bits/stdc++.h>
using namespace std;

long long int sum=7 , sum_even=0 , sum_odd=1 , sum_even_now=0 , sum_odd_now=1 ;
vector<long long int> DP;
int main () {
	ios::sync_with_stdio(0), cin.tie(0);
	int a, max_a=3;
	DP.push_back(1);DP.push_back(1);DP.push_back(2);DP.push_back(3);
	while(cin>>a){
		if(a<=max_a){
			cout<<DP[a]<<"\n";
			continue;
		}
		for(int i = max_a+1 ;i<=a ; i++){
			if(i%2==0){
				sum_even_now += DP[i - 4] + DP[i-3];
				sum_even += sum_even_now;
				DP.push_back(sum - sum_even);
				cout << i << ' ' << sum << ' ' << sum_even << ' ' << *(DP.end() - 1)<< '\n';
			}
			else{
				sum_odd_now += DP[i-4] + DP[i-3];
				sum_odd += sum_odd_now;
				DP.push_back(sum - sum_odd);
				cout << i << ' ' << sum << ' ' << sum_odd << ' ' << *(DP.end() - 1) <<'\n';
			}	
		sum += *(DP.end() - 1);
		}

		cout<<DP[a]<<"\n";
		max_a = a;
	}

	return 0;
}

