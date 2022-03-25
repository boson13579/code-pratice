#include <bits/stdc++.h>
using namespace std;


int short_distance_matrix[505][505];
vector <int> fire_spot;

int times , num_of_fire , num_of_spot;


void disinit(); //self = 0 , others = INFINTY
void calshortdis(); // key point floyd algorithm  spfa (?


int main () {
	//freopen("test.in", "r", stdin);
	//freopen("test.out","w", stdout);
	ios::sync_with_stdio(0), cin.tie(0);

	cin>>times;
	while(times--){

		cin>>num_of_fire>>num_of_spot;

		fire_spot.clear();

		for(int i=0 ,temp; i<num_of_fire ; i++){
			cin>>temp;
			fire_spot.emplace_back(temp);
		}

		cin.ignore();
		string temp;
		disinit();

		while (getline(cin,temp) && temp != ""){
			stringstream ss(temp);
			int spot1 , spot2 , far;
			ss >> spot1 >> spot2 >> far;
			short_distance_matrix[spot1][spot2] = far;
			short_distance_matrix[spot2][spot1] = far;

		}
		
		calshortdis();
	
		//枚舉 all spot to fire 
		int ans_len = 2147483640 , maxshort , ans;
		for(int i=1 ; i <= num_of_spot ; i++){	//枚舉誰變fire
			maxshort = 0;
			for(int t=1 ; t<=num_of_spot ; t++){	//枚舉spot
				int to_fire = short_distance_matrix[t][i];
				for(auto f:fire_spot)	//cal min dis to all fire spot 
					to_fire = min(to_fire,short_distance_matrix[t][f]);
				maxshort = max(maxshort,to_fire);
			}
			if(ans_len > maxshort){
				ans_len = maxshort;
				ans = i;
			}
		}  
		
		cout<<ans<<"\n";
		if(times)
			cout<<"\n";
		
	}

	return 0;
}

void disinit(){

	for(int i=1 ; i<=num_of_spot ; i++ ){
		for(int t=1 ; t<=num_of_spot ; t++){
			if(i==t)
				short_distance_matrix[i][t] = 0;
			else
				short_distance_matrix[i][t] = 999999999;
		}
	}

}

void calshortdis(){

	for(int i=1 ; i<=num_of_spot ;i++){
			for(int t=1 ; t<=num_of_spot ; t++){
				for(int e=1 ; e<=num_of_spot ; e++){
					short_distance_matrix[t][e] = min( short_distance_matrix[t][e] , short_distance_matrix[t][i]+short_distance_matrix[i][e] );
				}
			}
		}

}
