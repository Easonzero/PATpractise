//
// Created by eason on 8/12/17.
//

#include <iostream>

using namespace std;

void printSpace(unsigned long n){
    for(int i=0;i<n;i++){
        cout << " ";
    }
}

void printMid(string src,unsigned long s,unsigned long n){
    for(int i=0;i<n;i++){
        cout << src[s+i];
    }
}

int main(){
    string src;
    cin >> src;
    unsigned long len = src.length();
    unsigned long lr = (len+2)/3;
    unsigned long mid = len - lr*2;
    for(int i=0;i<lr;i++){
        cout << src[i];
        i!=lr-1?printSpace(mid):printMid(src,lr,mid);
        cout << src[len-i-1] << endl;
    }
    return 0;
}