//
// Created by eason on 8/2/17.
//
#include <iostream>
#include <time.h>
using namespace std;

int data[1000];

void genRandV2(int max,int n) {
    srand(time(0));
    data[0]=0;
    for(int i = 1; i <= n;i++){
        data[i] = rand() % max;
        data[i] -= max/2;
    }
}

void test1(int *need,int *back,int n){
    for(int i = n - 1; i >= 0; i--) {
        if(data[i] > 0) {
            *back += data[i];
        } else {
            if(*back > (0 - data[i])) {
                *back += data[i];
            } else {
                *need += ((0 - data[i]) - *back);
                *back = 0;
            }
        }
    }
}

void test2(int *need,int *back,int n){
    int total = 0;
    for(int i = n - 1; i >= 0; i--) {
        total += data[i];
    }
    if(total>0){
        *back = total;
        *need = 0;
    }else{
        *back = 0;
        *need = -total;
    }
}

int main(){
    int cmax,n;
    cin >> cmax >> n;
    genRandV2(cmax,n);
    int need1=0,back1=0,need2=0,back2=0;
    test1(&need1,&back1,n);
    test2(&need2,&back2,n);
    if(need1!=need2||back1!=back2){
        for(int i=0;i<n;i++)
            cout << data[i] << " ";
        cout << endl;
        cout << "y:need->" << need1 << " back->" << back1 << endl;
        cout << "n:need->" << need2 << " back->" << back2 << endl;
    }else cout << "right" << endl;
    return 0;
}