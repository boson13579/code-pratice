#include<iostream>
#include<vector>
#include<string>
#include <bits/stdc++.h>
using namespace std;

int mostnum(vector<string>& sentences)
{
    int maxi = 0;
    for(auto i:sentences)
    	maxi = max(maxi ,int(count(i.begin() , i.end() , ' ')));
	return maxi+1;
}


int main()
{
    freopen("test.in" , "r" , stdin);
    string temp;
    int a=1;
    int b = 0;
    while(cin>>b){
        cin.ignore();
        for(int i=0 ; i<b ; i++){
            getline(cin,temp);
            if(a==15)
                cout<<temp<<"\n";
        }
        a++;
    }
}