#include <bits/stdc++.h>
using namespace std;

int a , maxl = -1 , minl = 3000 , plus , len;
string guess , check , str[300][2] , tmp;
vector<string> ans;
char trash;

int main () {
	ios::sync_with_stdio(0), cin.tie(0);
	cin>>a;
	while(a--){
		cin>>trash;
		while(cin>>tmp&&tmp!="\n"){
			len = tmp.size();
			if(str[len][0]=="")
				str[len][0] = tmp;
			else
				str[len][1] = tmp;
			if(len>maxl) maxl = len;
			if(len<minl) minl = len;
		}
		for()

	}



	return 0;
}

