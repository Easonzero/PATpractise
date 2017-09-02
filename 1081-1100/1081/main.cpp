//
// Created by eason on 9/2/17.
//

#include <iostream>
#include <cstdlib>

using namespace std;

struct Number{
    long long n = 0;
    long long d = 1;
};

long long c(long long n,long long d){
    return d==0?abs(n):c(d,n%d);
}

void simple(Number* num){
    long long factor = c(num->n,num->d);
    num->n /= factor;
    num->d /= factor;
}

void add(Number* num1,Number* num2){
    simple(num2);
    num1->n = num1->n*num2->d+num2->n*num1->d;
    num1->d = num1->d*num2->d;
    simple(num1);
}

int main(){
    int n;
    cin >> n;
    Number* result = new Number();
    for(int i=0;i<n;i++){
        Number* number = new Number();
        scanf("%lld/%lld",&number->n,&number->d);
        add(result,number);
    }
    long long N = result->n/result->d;
    long long nn = result->n-N*result->d;
    if(N!=0) cout << N;
    if(N!=0&&nn!=0) cout << " ";
    if(nn!=0) cout << nn << "/" << result->d;
    if(N==0&&nn==0) cout << 0;
    return 0;
}