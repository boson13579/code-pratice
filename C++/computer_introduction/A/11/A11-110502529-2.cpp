/*
Assignment 11-2
Name: 陳柏燊
Student Number: 110502529
Course 2021-CE1003-A
*/
#include <bits/stdc++.h>
using namespace std;

string a;
int from , len = 0 ;
bool ismid;

int mid(int cur);
int lef(int cur);

int main () {
	//freopen("test.in", "r", stdin);
	//freopen("test.out","w", stdout);
	//ios::sync_with_stdio(0), cin.tie(0);
	
	while(cin>>a and a != "-1"){

		len = 0;

		//solve
		for(int i=0; i<a.size()-1 ; i++){
			int temp = 0;
			bool tim = true;
			if(i>0 && a[i-1] == a[i+1])
				temp = mid(i);
			if(a[i] == a[i+1])
				if(temp < lef(i)){
					temp = lef(i);
					tim = false;
				}
			if(len < temp){
				from = i;
				len = temp;
				ismid = tim;
			}
		}

		//print answer
		if(len == 0)
			cout<<"Palindrome not existed!\n\n";
		else{
			cout<<"Palindrome:";
			int i = from - len/2;
			if(!ismid)
				i += 1;
			for( i ; i<=(from + len/2) ; i++){
				cout<<a[i];
			}
			cout<<"\nLength:"<<len<<"\n\n";
		}
	}
	
	return 0;
}

int mid(int cur){
	int ans = 3; 
	int wide = 2;
	while( cur+wide < a.size() and cur-wide>=0 ){
		if(a[cur+wide] != a[cur-wide])
			break;
		ans += 2;
		wide += 1;
	}
	return ans;
}
int lef(int cur){
	int ans = 2;
	int wide = 1;
	while(cur-wide >=0 and cur+1+wide < a.size()){
		if(a[cur-wide] != a[cur+1+wide])
			break;
		ans += 2;
		wide += 1;
	}
	return ans;
}
