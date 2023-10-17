#include <bits/stdc++.h>
using namespace std;

int cases;
string trash,temp = "QQ";
vector <pair<double,double>> dots;
vector <pair<double,double>> O;

void solve();

int main () {
	//freopen("test.in", "r", stdin);
	//freopen("test.out","w", stdout);
	ios::sync_with_stdio(0), cin.tie(0);
	
	cin>>cases;cin.ignore();
	getline(cin,trash);
	while(cases--){

		if(!bool(cases)){
			double firnum , secnum;
			while(cin>>firnum>>secnum)
				dots.emplace_back(firnum,secnum);
		}
		else
			while(1){
				getline(cin,temp);
				if(temp == "")
					break;
				stringstream ss(temp);
				string firnum , secnum;
				ss >> firnum >> secnum;
				dots.emplace_back(atof(firnum.c_str()),atof(secnum.c_str()));
			}

		solve();
		dots.clear();
		temp = "QQ";
		O.clear();
	}



	return 0;
}

void solve(){

	for(int i=0 ; i<dots.size()-1 ; i++){
		for(int t=i+1; t<dots.size() ; t++){
			pair<double , double> mid = make_pair((dots[i].first+dots[t].first)/2.0,(dots[i].second+dots[t].second)/2.0);
			//if(sqrt((dots[i].first-mid.first)*(dots[i].first-mid.first)+(dots[i].second-mid.second)*(dots[i].second-mid.second)) > 5)
			//	continue;
			pair <double , double> fa = make_pair(-(dots[i].second-dots[t].second),dots[i].first-dots[t].first);
			double fadis = sqrt(fa.first*fa.first + fa.second*fa.second);
			double dis = sqrt(6.25-(dots[i].first-mid.first)*(dots[i].first-mid.first)-(dots[i].second-mid.second)*(dots[i].second-mid.second));
			double fanum = dis/fadis;
			//if(!(mid.first+fa.first*fanum > 50 || mid.first+fa.first*fanum<0 || mid.second+fa.second*fanum > 50 || mid.second+fa.second*fanum<0))
			O.emplace_back(mid.first+fa.first*fanum , mid.second+fa.second*fanum);
			//if(!(mid.first-fa.first*fanum > 50 || mid.first-fa.first*fanum<0 || mid.second-fa.second*fanum > 50 || mid.second-fa.second*fanum<0))
			O.emplace_back(mid.first-fa.first*fanum , mid.second-fa.second*fanum);
		}
	}

	int ans = 1;
	for(auto i:O){
		int tempans = 0;
		for(auto t:dots)
			if((i.first-t.first)*(i.first-t.first)+(i.second-t.second)*(i.second-t.second) <= 6.25)
				tempans++;
		ans = max(ans,tempans);
	}

	if(!cases)
		cout<<ans<<"\n";
	else
		cout<<ans<<"\n\n";
}