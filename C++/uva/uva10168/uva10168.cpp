#include <bits/stdc++.h>
using namespace std;

bool isprime[10000005];

void init(){
	for(int i=2 ; i<10000000 ; i++){
		if(isprime[i]){
			for(int j=i*2 ; j<10000000 ; j += i){
				isprime[j]=false;
			}
		}
	}
}

void find2prime(int n){
	for(int i=2;i<n;i++){
		if(isprime[i]&&isprime[n-i]){
			cout<<i<<" "<<n-i<<"\n";
			break;
		}
	}
}

int main () {
	ios::sync_with_stdio(0), cin.tie(0);
	int a;
	memset(isprime,true,sizeof(isprime));
	isprime[0]=false;
	isprime[1]=false;
	init();
	while(cin>>a){
		if(a<8){
			cout<<"Impossible.\n";
		}
		else{
			if(a%2==0){
				cout<<"2 2 ";
				find2prime(a-4);
			}
			else{
				cout<<"2 3 ";
				find2prime(a-5);
			}
		}
	}
	return 0;
}

