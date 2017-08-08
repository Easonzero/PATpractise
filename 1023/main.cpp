//
// Created by eason on 8/7/17.
//

#include <iostream>

using namespace std;

int origin[10] = {0};
int result[10] = {0};

bool check(){
    for(int i=0;i<10;i++){
        if(origin[i] != result[i]) return false;
    }
    return true;
}

void count(int* array,string n){
    for(int i=0;i<n.length();i++)
        array[n[i]-'0']++;
}

string muti2(string n){
    int tmp = 0;
    for(int i=n.length()-1;i>=0;i--){
        tmp = (n[i]-'0')*2 + tmp/10;
        n[i] = tmp%10 + '0';
        if(tmp>9&&i==0){
            string head = string(1,tmp/10+'0');
            return head + n;
        }
    }
    return n;
}

int main(){
    string n;
    cin >> n;
    count(origin,n);
    string n2 = muti2(n);
    count(result,n2);
    if(check()) cout << "Yes" << endl;
    else cout << "No" << endl;
    cout << n2;
    return 0;
}