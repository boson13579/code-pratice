#include <bits/stdc++.h>
using namespace std;
/*
 
DP[i][j] = x的前i位中z的前j位組合數
if x[i] = z[i]
	DP[i][j] = DP[i-1][j] + DP[i-1][j-1]
else
	DP[i][j] = DP[i-1][j]
 
*/
const int MOD = 1000000000;
 
struct bignumber{
	int len;
	int arr[25];

	//init
	bignumber(){
		len = 1;
		//memset(arr,0,sizeof(arr));
	}
 
	// int to bignumber beasuse this only set "1" XD
	bignumber(int n){
		len = 1;
		arr[0] = n;
	}
 
};
 
bignumber operator + (const bignumber &a , const bignumber &b){
 
	bignumber ans;
	int i=0 , carry = 0;
	for(i=0 ; i < a.len or i < b.len or carry > 0 ; i++ ){
		if(i<a.len)
			carry += a.arr[i];
		if(i<b.len)
			carry += b.arr[i];
		ans.arr[i] = carry%MOD;
		carry /= MOD;
	}
	ans.len = i;
	return ans;
} 
 
bignumber DP[10000][105];
string x , z ;
int main () {
	//freopen("test.in", "r", stdin);
	//freopen("test.out","w", stdout);
	ios::sync_with_stdio(0), cin.tie(0);
	int n;cin>>n;
	while(n--){
		cin>>x;
		cin>>z;
		int long1 = x.size();
		int long2 = z.size();

		for(int i=0 ; i<=x.size() ; i++)
			DP[i][0] = 1;

		for(int j=1 ; j<z.size() ; j++){
			DP[0][j] = 0;

		//solve at here
		for(int i=1 ; i<=long1 ; i++){
			for(int j=1 ; j<=long2 and j<=i ; j++){
				if(x[i-1]==z[j-1])
					DP[i][j] = DP[i-1][j] + DP[i-1][j-1];
				else
					DP[i][j] = DP[i-1][j];
			}
		}
 
		//print answer
		for(int i=DP[long1][long2].len-1 ; i>=0 ; i--){
			if(DP[long1][long2].len-1 == 0 and DP[long1][long2].arr[i] == 0){
				cout<<"0";
				break;
			}
			if(i != DP[long1][long2].len-1 and DP[long1][long2].arr[i] == 0){
				cout<<"000000000";
			}
			else if(i != DP[long1][long2].len-1){
				for(int t = to_string(DP[long1][long2].arr[i]).size() ; t<9 ; t++)
					cout<<"0";
			}	
			cout<<DP[long1][long2].arr[i];
		}
 
		cout<<"\n";
	}
	return 0;
}