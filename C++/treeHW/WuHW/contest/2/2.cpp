#include <bits/stdc++.h>
using namespace std;

const int MOD = 1000000000;//base on 10^9

struct bignumber{

	//declear
	bool positive;
	int len;
	int arr[100];

	//init
	bignumber(){
		positive = true;
		len = 0;
		memset(arr,0,sizeof(arr));
	}

	//string to bignumber
	bignumber(string a){
		
		//process sign
		if(a[0] == '-'){
			positive = false;
			a = a.substr(1,a.size()); 
		}
		else
			positive = true;

		//process number
		int i = 0;
		while(a.size()>0 and a!="0"){

			if(a.size() > 9){
				arr[i] = stoi(a.substr(a.size()-9,a.size()));
				a = a.substr(0,a.size()-9);
			}
			else{
				arr[i] = stoi(a);
				len = i;
				a = "";
			}
			i++;
		}
		
	}
	
};

//declear operator
bignumber operator+(const bignumber &a , const bignumber &b);
bignumber operator-(const bignumber &a , const bignumber &b);
bool operator >= (const bignumber &a , const bignumber &b);

//declear function
void print(bignumber a);

int main () {
	//freopen("test.in", "r", stdin);
	//freopen("test.out","w", stdout);
	//ios::sync_with_stdio(0), cin.tie(0);

	string a , b , sign;
		
	cout<<"Please input the first number : ";cin>>a;
	bignumber firnum = a;

	cout<<"Please input the second bumber : ";cin>>b;
	bignumber secnum = b;

	cout<<"add or subtract ?\nPlease input the sign ( + or - ) : ";cin>>sign;

	if(sign == "+")
		print(firnum + secnum);
	else if(sign == "-")
		print(firnum - secnum);

	cout<<"\n\nThanks for using the program\n";

	return 0;
}

bignumber operator + (const bignumber &a , const bignumber &b){

	bignumber ans;

	//print(a);
	//cout<<b.positive<<b.arr[0]<<"\n";
	//print(b);

	if( (a.positive and b.positive) or (!a.positive and !b.positive) ){
		int tempans = 0; 
		int reminder = 0;
		for(int i=0 ;  reminder !=0 or i<=a.len or i<=b.len ; i++){
			tempans = 0;
			if(a.len >= i)
				tempans += a.arr[i];
			if(b.len >= i)
				tempans += b.arr[i];
			tempans += reminder;
			ans.arr[i] = tempans%MOD;
			reminder = tempans/MOD;
			ans.len = i; 
		}

		if(!a.positive and !b.positive)
			ans.positive = false;
		
		return ans;
	}

	if(a.positive and !b.positive){
		bignumber c = b;
		c.positive = true;
		return a-c; 
	}
	else{
		bignumber c = a;
		c.positive = true;
		return b-c;
	}

}

bignumber operator-(const bignumber &a , const bignumber &b){
	bignumber ans;
	if(a.positive and b.positive){
		if(a>=b){
			bool lend = false;
			for(int i=0 ; i<=a.len or lend; i++){
				ans.arr[i] = a.arr[i];
				if(i<=b.len)
					ans.arr[i] -= b.arr[i];
				if(lend){
					ans.arr[i] -=1;
					lend = false;
				}
				if(ans.arr[i]<0){
					lend = true;
					ans.arr[i] += 1000000000;
				}
			}
		}
		else{
			ans = b-a;
			ans.positive = false;	
		}

		//find ans.len
		for(int i=a.len ; i>=0 ; i--){
			if(ans.arr[i] > 0){
				ans.len = i;
				break;
			}
		}
		return ans;
	}
	if(a.positive and !b.positive){
		bignumber c = b;
		c.positive = true;
		return a+c; 
	}
	if(!a.positive and b.positive){
		bignumber c = b; 
		c.positive = false;
		return a+c;
	}
	if(!a.positive and !b.positive){
		bignumber c = b;
		c.positive = true;
		return c + a; 
	}

}

void print(bignumber a){
	cout<<"\nAnswer : ";
	if(!a.positive)
		cout<<"-";
	if(a.len == 0){
		cout<<a.arr[0];
		return;
	}
	for(int i=a.len ; i>=0 ; i--){
		if(i != a.len)
			for(int t=to_string(a.arr[i]).size() ; t<9 ; t++)
				cout<<'0';
		cout<<a.arr[i];
	}		
}

bool operator >= (const bignumber &a , const bignumber &b){
	if(a.len>b.len)
			return true;
		else if(a.len<b.len)
			return false;
		for(int i=a.len ; i>=0 ; i--){
			if(a.arr[i]>b.arr[i])
				return true;
			else if(a.arr[i] < b.arr[i])
				return false;
		}
		return true;
}