#include <bits/stdc++.h>
using namespace std;

string s;
int arr[1000100];

void mp (string a ){
	arr[0]=-1;
	int p = -1; 
	for(int i = 1 ; i<a.size() ; i++){
		while(p!=-1 && (a[i] != a[p+1]))
			p = arr[p];
		if(a[i] == a[p+1])
			p++;
		arr[i] = p;
	}
}

int main () {
	ios::sync_with_stdio(0), cin.tie(0);
	while(cin>>s&&s!="."){
		mp(s);
		int l = s.size() - 1 - arr[s.size()-1] ;
		if (s.size() % l != 0)
			cout<<"1\n";
		else
			cout<<s.size()/l<<"\n";
	}
	return 0;
}

