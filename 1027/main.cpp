//
// Created by eason on 8/10/17.
//

#include <iostream>

using namespace std;

char to13Number(int n){
    if(n>9) return n-10+'A';
    return n+'0';
}

string to13Radix(int n){
    char s[10],r[10];
    unsigned long i=0;
    bool first = true;
    while(n!=0||first){
        first = false;
        s[i]=to13Number(n%13);
        n/=13;
        i++;
    }

    if(i==1) {
        r[0]='0';
        r[1]=s[0];
        i++;
    }else
        for(int j=0;j<i;j++)
            r[j]=s[i-j-1];
    return string(r,i);
}

string toColor(int r,int g,int b){
    return to13Radix(r).append(to13Radix(g)).append(to13Radix(b));
}

int main(){
    int r,g,b;
    cin >> r >> g >> b;
    cout << "#" << toColor(r,g,b);
    return 0;
}