/*
Assignment 12
Name: 陳柏燊
Student Number: 110502529
Course 2021-CE1003-A
*/
#include <iostream>
#include <ctime>
using namespace std;


void f(int* a, int* b);
void f_2(int* a, int* b);

int main()
{
    int loop_num = 30000;
    int a, b;
    cin >> a >> b;
    double start_time = clock(); // get clock before execute

    for(int i=0;i<loop_num;i++){
        f_2(&a, &b);
        for(int j=0;j<loop_num;j++){
            f(&a, &b);
        }
    }
    double end_time = clock(); // get clock after execute

    cout << a << endl;
    cout << b << endl;
    cout << end_time - start_time << endl; // get execute time

    return 0;
}


void f(int* a, int* b){
    //a = a % 7;
    //b = b % 11;
    //a = a * a - 3 * b;
    *a = (*a%7)*(*a%7) - 3*(*b%11);
    return ;
}

void f_2(int* a, int* b){
    //a = a % 13;
    //b = b % 5;
    //b = b * b - 13 * a;
    *b = (*b%5)*(*b%5) - 13*(*a%13);
    return ;
}
