#include <iostream>
#include <ctime>
using namespace std;


int f(int , int );
int f_2(int , int );

int main()
{
    int loop_num = 30000;
    int a, b;
    cin >> a >> b;
    double start_time = clock(); // get clock before execute

    for(int i=0;i<loop_num;i++){
        b = f_2(a, b);
        for(int j=0;j<loop_num;j++){
            a = f(a, b);
        }
    }
    double end_time = clock(); // get clock after execute

    cout << a << endl;
    cout << b << endl;
    cout << end_time - start_time << endl; // get execute time

    return 0;
}


int f(int a, int b){
    a = a % 7;
    b = b % 11;
    a = a * a - 3 * b;
    return a;
}

int f_2(int a, int b){
    a = a % 13;
    b = b % 5;
    b = b * b - 13 * a;
    return b;
}
