#include <bits/stdc++.h>
using namespace std;

double rpower(double b , int n){
    
    if(n==0)
        return 1;
    return b*rpower(b,n-1);

}

int main(){
    
    cout<<fixed<<setprecision(1)<<rpower(2.0 , 3)<<"\n";
    system("pause");
    return 0;

}