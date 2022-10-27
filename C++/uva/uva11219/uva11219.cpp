#include <bits/stdc++.h>
using namespace std;



int main () {
	//freopen("test.in", "r", stdin);
	//freopen("test.out","w", stdout);
	ios::sync_with_stdio(0), cin.tie(0);

	int a;
	cin>>a;
	int task =1;
	while(a--){
		cout<<"Case #"<<task++<<": ";
		string nows,birs;
		cin>>nows>>birs;
		string nowd,nowm,nowy,bird,birm,biry;
		int inowd,inowm,inowy,ibird,ibirm,ibiry;
		nowd = nows.substr(0,2);
		nowm = nows.substr(3,2);
		nowy = nows.substr(6,4);
		bird = birs.substr(0,2);
		birm = birs.substr(3,2);
		biry = birs.substr(6,4);
		inowd = stoi(nowd);
		inowm = stoi(nowm);
		inowy = stoi(nowy);
		ibird = stoi(bird);
		ibirm = stoi(birm);
		ibiry = stoi(biry);

		string addnow = nowy + nowm + nowd;
		string addbir = biry + birm + bird;
		int iaddnow = stoi(addnow);
		int iaddbir = stoi(addbir);
		if(addnow == addbir){
			cout<<"0\n";
			continue;
		}
		if(iaddbir > iaddnow){
			cout<<"Invalid birth date\n";
			continue;
		}
		int age = inowy - ibiry;
		if(inowm == ibirm and ibird > inowd)
			age--;
		if(ibirm > inowm )
			age--;
		if(age>130){
			cout<<"Check birth date\n";
			continue;
		}
		cout<<age<<"\n";
		
			
	}



	return 0;
}

