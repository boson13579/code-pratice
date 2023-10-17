#include <bits/stdc++.h>
#define ll long long
using namespace std;

int arr[10000][10000];
int maxans = INT_MIN;
int mfx,mfy,mex,mey;

ll fun(int fx , int fy , int ex , int ey){
	if(ex<fx or ey<fy)
		return INT_MIN;
	ll ans=0;
	for(int i=fx ; i<=ex ; i++){
		for(int t=fy ; t<=ey ; t++){
			ans += arr[i][t];
		}
	}
	return ans;
}

int main () {
	srand(time(NULL));
	int n;cin>>n;
	for(int i=0 ; i<n ; i++){
		for(int t=0 ; t<n ; t++){
			arr[i][t] = rand()%201+(-100);
		}
	}
	for(int i=0 ; i<n ; i++){
		for(int t=0 ; t<n ; t++){
			cout<<arr[i][t]<<" ";
		}
		cout<<"\n";
	}
	for(int i=0 ; i<n ; i++){
		for(int t=0 ; t<n ; t++){
			for(int q=i ; q<n ; q++){
				for(int w=t ; w<n ; w++){
					ll qq = fun(i,t,q,w);
					if(maxans<qq){
						maxans = qq;
						mfx = i;
						mfy = t;
						mex = q;
						mey = w;
					}

				}
			}
		}
	}
	for(int i=mfx ; i<=mex ; i++){
		for(int t=mfy ; t<=mey ; t++){
			cout<<arr[i][t]<<" ";
		}
		cout<<"\n";
	}
	cout<<"\n";
	cout<<maxans;

	return 0;
}

