#include <bits/stdc++.h>
using namespace std;

int factorsum(int a){
	map<int,int> factor;
	int divide = 2;
	while(a!=1){
		if(a%divide==0){
			if(factor.find(divide)==factor.end())
				factor.insert(make_pair(divide,1));
			else
				factor[divide] = factor[divide]+1;
			a/=divide;
			continue;
		}
		divide++;	
	}
	int sum=1;
	for(auto i:factor){
		int onefactorsum = 0;
		for(int t=0 ; t<=i.second ; t++){
			onefactorsum += pow(i.first,t);
		}
		sum *= onefactorsum;
	}	
		
	return sum;
}


int main () {
	//freopen("test.in", "r", stdin);
	//freopen("test.out","w", stdout);
	ios::sync_with_stdio(0), cin.tie(0);

	int a,cases=1;
	while(cin>>a and a!=0){
		bool find = false;
		int ans;
		for(int i=a ; i>0 and !find; i--){
			if(factorsum(i)==a){
				find = true;
				ans = i; 
			}
		}
		if(find){
			cout<<"Case "<<cases++<<": "<<ans<<"\n";
		}
		else{
			cout<<"Case "<<cases++<<": -1\n";
		}
	}


	return 0;
}

