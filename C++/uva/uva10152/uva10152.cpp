#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main () {
	ios_base::sync_with_stdio(0);
    cin.tie(0);
	int a , b;
	cin>>a;
	while(a--){
		cin>>b;
		string trash;
		getline(cin,trash);
		string c[b] , d[b];
		for(int i=0 ; i<b ; i++){
			getline(cin,c[i]);
		}
		for(int i=0 ; i<b ; i++){
			getline(cin,d[i]);
		}
		int in = b-1 , on = b-1 , count = -1 ;
		
		for(int i= b-1 ; i>= 0 ; i--){
			if(d[on]==c[in]){
				on--;
				in--;
			}
			else{
				in --;
				count ++;
			}
		}
		for( count ; count>=0 ; count--){
			cout<<d[count]<<"\n";
		}
		cout<<"\n";
	}
	return 0;
}
