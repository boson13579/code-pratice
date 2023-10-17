#include <bits/stdc++.h>
using namespace std;

struct poly{

	vector<long long> co;

	poly operator*(poly a){
		poly ans;
		for(int i=0 ; i<this->co.size() ; i++){
			for(int t=0 ; t<a.co.size() ; t++){
				if(ans.co.size()<i+t+1){
					ans.co.emplace_back(this->co[i]*a.co[t]);
				}
				else{
					ans.co[i+t] += this->co[i]*a.co[t];
				}
			}
		}
		return ans;
	}
};

int main () {
	// freopen("test.in", "r", stdin);
	// freopen("test.out","w", stdout);
	ios::sync_with_stdio(0), cin.tie(0);


	int a;
	while(cin>>a){
		vector<poly> all;
		poly ans;
		ans.co.emplace_back(1);
		for(int i=0 ; i<a ; i++){
			poly temp;
			int tempint;
			cin>>tempint;
			temp.co.emplace_back(-tempint);
			temp.co.emplace_back(1);
			ans = ans * temp;
		}
		for(int i=ans.co.size()-1 ; i>=0 ; i--){
			if(ans.co[i]==0 and i!=0)
				continue;
			if(ans.co[i]>=0 and i!=ans.co.size()-1)
				cout<<"+ ";
			if(ans.co[i]<0 and i!=ans.co.size()-1)
				cout<<"- ";
			
				
			if(i>1){
				if(abs(ans.co[i])==1)
					cout<<"x^"<<i<<" ";
				else
					cout<<abs(ans.co[i])<<"x^"<<i<<" ";
			}
			if(i==1){
				if(abs(ans.co[i])==1)
					cout<<"x"<<" ";	
				else
					cout<<abs(ans.co[i])<<"x"<<" ";
			}
			if(i==0){
				cout<<abs(ans.co[i])<<" = 0\n";
			}
		}
	}


	return 0;
}

