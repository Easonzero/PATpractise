//
// Created by eason on 8/7/17.
//

#include <iostream>

using namespace std;

bool check(string n){
    unsigned long len = n.length();
    for(int i=0;i<len;i++){
        if(n[i]!=n[len-i-1]) return false;
    }
    return true;
}

string rAdd(string n){
    string reverse = n;
    int tmp = 0;
    unsigned long len = n.length();
    for(int i=0;i<len;i++){
        tmp = n[len-i-1]+reverse[i]+tmp/10-'0'*2;
        n[len-i-1] = tmp%10 + '0';
        if(tmp>9&&i==len-1){
            string head = string(1,tmp/10+'0');
            return head + n;
        }
    }

    return n;
}

int main(){
    string n;
    int k;
    cin >> n >> k;
    for(int i=0;i<=k;i++){
        if(check(n)||i==k){
            cout << n << endl;
            cout << i << endl;
            break;
        }
        n = rAdd(n);
    }
    return 0;
}