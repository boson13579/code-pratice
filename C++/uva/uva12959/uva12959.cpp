#include <bits/stdc++.h>
using namespace std;

int score[550];

int main () {
	//freopen("test.in", "r", stdin);
	//freopen("test.out","w", stdout);
	ios::sync_with_stdio(0), cin.tie(0);

	int a,b;
	while(cin>>a>>b and !(a==0 and b==0)){
		memset(score,0,sizeof(score));
		for(int i=0 ; i<b ; i++){
			for(int t=0 ; t<a ; t++){
				int temp;
				cin>>temp;
				score[t] += temp;
			}
		}
		int ans;
		int maxScore = -1;
		for(int i=0 ; i<a ; i++){
			if(score[i]>=maxScore){
				maxScore = score[i];
				ans = i;
			}
		}
		cout<<ans+1<<"\n";
	}


	return 0;
}

