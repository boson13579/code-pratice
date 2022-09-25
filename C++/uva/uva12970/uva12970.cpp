#include <bits/stdc++.h>
using namespace std;

unsigned long long int gcd(long long int a,long long int b){
	while(a!=0){
		if(a<b)
			swap(a,b);
		a = a%b;	
	}
	return b;
}


int main() {
    // freopen("test.in", "r", stdin);
    // freopen("test.out","w", stdout);
    ios::sync_with_stdio(0), cin.tie(0);

    int cases = 1;

    unsigned long long int v1, v2, d1, d2;

    pair<unsigned long long int,unsigned long long int>avg;

    while (cin >> v1 >> d1 >> v2 >> d2 and  !(v1 == 0 and v2 == 0 and d1 == 0 and d2 == 0)) {
        unsigned long long int et1 = d1*v2;
		unsigned long long int et2 = d2*v1;



		if(et1<et2)
			cout<<"Case #"<<cases++<<": You owe me a beer!\n";
		else
			cout<<"Case #"<<cases++<<": No beer for the captain.\n";

		avg.second = (v1*v2)*2;
		avg.first = et1+et2;
		
		if(avg.first%avg.second==0)
			cout<<"Avg. arrival time: "<<avg.first/avg.second<<"\n";
		else{
			unsigned long long int divide = gcd(avg.first,avg.second);
			cout<<"Avg. arrival time: "<<avg.first/divide<<"/"<<avg.second/divide<<"\n";
		}	
		
    }

    return 0;
}


