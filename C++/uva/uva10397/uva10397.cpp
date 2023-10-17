#include <bits/stdc++.h>
using namespace std;

struct mypair{
	double distance;
	int from;
	int to;
};
bool cmp(mypair a , mypair b){
	if(a.distance != b.distance)
		return a.distance < b.distance;
}
struct xandy{
	int x;
	int y;
};

vector <int> ancestor; //record group like disjoint set(? maybe call it group will be better
vector <xandy> coordinates;
vector <mypair> edges;

double ans = 0;

void init(int a);
void caledge();
void solve(int n);

int main () {
	ios::sync_with_stdio(0), cin.tie(0);
	int n,b;
	while(cin>>n){

		init(n);
		for(int i=0 ; i<n ; i++){
			xandy temp;
			cin>>temp.x>>temp.y;
			coordinates.emplace_back(temp);
		}
		caledge();
		cin>>b;
		for(int i=0,temp1,temp2 ; i<b ; i++){
			cin>>temp1>>temp2;
			int temp3 = ancestor[temp1];
			for(int t=0 ; t<ancestor.size() ; t++)
				if(ancestor[t] == temp3)
					ancestor[t] = ancestor[temp2];

		}
		solve((n-1)-b);
		cout<<fixed<<setprecision(2)<<ans<<"\n";
	}
	return 0;
}

void init(int a){
	ans = 0;
	edges.clear();
	ancestor.clear();
	coordinates.clear();
	for(int i=0 ; i<=a ; i++)
		ancestor.emplace_back(i);

}

void caledge(){
	for(auto i=0 ; i<coordinates.size()-1 ; i++ ){
		for(int t=i+1 ; t<coordinates.size() ; t++){
			mypair temp;
			temp.distance = sqrt(pow(coordinates[i].x-coordinates[t].x,2)+pow(coordinates[i].y-coordinates[t].y,2));
			temp.from = i+1;
			temp.to = t+1;
			edges.emplace_back(temp);
		}
	}
}

void solve(int n){
	sort(edges.begin(),edges.end(),cmp);
	for(int i=0 ; i<edges.size() ; i++){

		if(ancestor[edges[i].from] == ancestor[edges[i].to])
			continue;
		ans += edges[i].distance;

		int temp = ancestor[edges[i].from];
		for(int t=0 ; t<ancestor.size() ; t++)
			if(ancestor[t] == temp)
				ancestor[t] = ancestor[edges[i].to];		
	}
}