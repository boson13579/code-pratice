/*
Assignment 14
Name: 陳柏燊
Student Number: 110502529
Course 2021-CE1003-A
*/
#include <bits/stdc++.h>
using namespace std;

string a;

int main () {
	//freopen("test.in", "r", stdin);
	//freopen("test.out","w", stdout);
	//ios::sync_with_stdio(0), cin.tie(0);
	while(cin>>a and a!="-1"){
		if(a == "0"){
			cout<<"2\n";
			continue;
		}
		int by = 0;
		for(char i:a)
			by = max(int(i),by);
		if(by >= 97 and by <= 122)
			by -=61;
		else if(by >= 65 and by <= 90)
			by -=55;
		else if(by >= 48 and by <= 57)
			by -=48;
		bool ok = false;
		reverse(a.begin(),a.end());
		for(int t=by+1 ; t<=62 ; t++){
			long long int ans = 0;
			int pow = 1;
			for(char i:a){
				int num = int(i);
				if(num >= 97 and num <=122)
					ans += (num-61)*pow;
				else if(num >=65 and num<=90)
					ans += (num-55)*pow;
				else if(num >=48 and num<=57)
					ans += (num-48)*pow;
				pow *= t;
			}
			if(ans%(t-1)==0){
				ok = true;
				cout<<t<<"\n";
			}
			if(ok)
				break;
		}
		if(!ok)
			cout<<"such number is impossible!\n";		
	}

	return 0;
}

