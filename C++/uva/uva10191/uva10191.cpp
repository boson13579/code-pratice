#include <bits/stdc++.h>
using namespace std;

int a;
string temp;
bool iswork[2000];
int snpti , stti , cal;

void outputstrti(int a){
	cout<<a/60;
	cout<<":";
	int b = a%60;
	for(int i=(to_string(b).size()) ; i<2 ; i++)
		cout<<"0";
	cout<<b<<" "; 
}

void outputhr(int a){
	int b = a/60;
	if(b)
		cout<<b<<" hours and ";
	cout<<a%60<<" minutes.";
}
int main () {
	//freopen("test.in", "r", stdin);
	//freopen("test.out","w", stdout);
	ios::sync_with_stdio(0), cin.tie(0);

	while(cin>>a){

		cin.ignore();
		memset(iswork , false , sizeof(iswork));
		snpti = 0;
		iswork[1081] = true;
		
		for(int i=0 ; i<a ; i++){
			getline(cin,temp);
			string sth = temp.substr(0,2);
			string sm = temp.substr(3,2);
			string fh = temp.substr(6,2);
			string fm = temp.substr(9,2);
			 
			int st = 60*(stoi(sth)) + stoi(sm);
			int ft = 60*(stoi(fh)) + stoi(fm);
			
			for(int t = st ; t<=ft ; t++ )
				iswork[t] = true;
		}
		int temptime , tempstrti;

		bool findtime = !iswork[600];
		if(findtime)
			tempstrti = 600;

		for(int i=601 ; i<=1081 ; i++){
			
			//if(findtime and !iswork[i])
			//	contiue;
			
			if(findtime and iswork[i]){
				temptime = i-tempstrti;
				if(i==1081)
					temptime--;
				if(temptime > snpti){
					snpti = temptime;
					stti = tempstrti;
				}
				findtime = false;
			}

			//if(!findtime and iswork[i])
			//	continue;
			
			if(!findtime and !iswork[i]){
				tempstrti = i-1;
				findtime = true;
			}
				
		}
		cout<<"Day #"<<++cal<<": the longest nap starts at ";
		outputstrti(stti);
		cout<<"and will last for ";
		outputhr(snpti);
		cout<<"\n";

		//cout<<"\n\n";
		//for(int i=600 ; i<=1080 ; i+=5)
		//	cout<<iswork[i];

	}

	return 0;
}

