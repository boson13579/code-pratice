#include <iostream>
#include <cmath>
using namespace std;

double f(double a){
    return 3*pow(a,3)+2*a-1;
}

int main(){
    
    cout<<"f(-3.2) = "<<f(-3.2)<<"\n";
    cout<<"f(-2.1) = "<<f(-2.1)<<"\n";
    cout<<"f(0) = "<<f(0)<<"\n";
    cout<<"f(2.1) = "<<f(2.1)<<"\n";
    system("pause");
    return 0;

}