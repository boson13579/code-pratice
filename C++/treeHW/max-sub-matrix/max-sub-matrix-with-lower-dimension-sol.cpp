#include <bits/stdc++.h>
using namespace std;

int arr[10000][10000];

int fx,fy,ex,ey,tfx=0,tex;

int maxsubarrray(int *a , int n){
	int c=0,ans=0;//tfx,tex
	for(int i=0 ,ttfx; i<n ; i++){
		if(c>0){
			c += a[i];
		}
		else{
			c = a[i]; // c = 0 + a[i]
			ttfx = i;
		}	  
	if(ans<c){
		tfx = ttfx;
		ans = c;
		tex = i;
	}
	}
	return ans;
}

int maxsubmatrix(int m , int n){
	int ans=INT_MIN,sum[m],tfy,tey;
	for(int i=0 ; i<n ; i++){
		for(int t=i ; t<n ; t++){
			for(int o=0 ; o<m ; o++){
				if(t==i)
					sum[o]=0;
				sum[o] += arr[o][t];
			}
		int temp = maxsubarrray(sum,m);
		if(ans<temp){
			ans = temp;
			fy = i;
			ey = t;
			fx = tfx;
			ex = tex;
		}
		}	
	}
	return ans;
}

int main () {
	//ios::sync_with_stdio(0), cin.tie(0);
	int m,n,ran;
	cout<<"please in put matrix size : \n";
	cout<<"hight : ";cin>>m;
	cout<<"wide : ";cin>>n;
	cout<<"Random or input(1 is random , 0 is input) ";cin>>ran;
	if(bool(ran)){
		srand(time(NULL));
		for(int i=0 ; i<m ; i++){
			for(int t=0 ; t<n ; t++){
				arr[i][t] = rand()-16383;
			}
		}
		cout<<"random-matrix :\n";
		for(int i=0;i<m;i++){
			for(int t=0 ; t<n ; t++){
				cout<<arr[i][t]<<" ";
			}
			cout<<"\n";
		}
	}
	else{
		for(int i=0 ; i<m ; i++)
			for(int t=0 ; t<n ; t++)
				cin>>arr[i][t];
	}
	int ans = maxsubmatrix(m,n);
	cout<<"max-sub-matrix : \n";
	for(int i=fx ; i<=ex ; i++){
		for(int t=fy ; t<=ey ; t++){
			cout<<arr[i][t]<<" ";
		}
		cout<<"\n";
	}
	
	cout<<"max sub-matrix-sum : "<<ans<<"\n";

	return 0;
}

