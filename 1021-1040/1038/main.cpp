//
// Created by eason on 8/19/17.
//

#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>
using namespace std;

vector<string> v;

long long toLongLong(string s){
    stringstream ss(s);
    long long l;
    ss >> l;
    return l;
}

bool cmp(string num1,string num2){
    return toLongLong(num1+num2) < toLongLong(num2+num1);
}

int main(){
    int n;
    cin >> n;
    for(int i=0;i<n;i++){
        string s;
        cin >> s;
        v.push_back(s);
    }
    sort(v.begin(),v.end(),cmp);
    bool first = true;
    for(auto s:v){
        if(s[0]=='0'&&first){
            long long tmp = toLongLong(s);
            if(tmp!=0){
                cout << tmp;
                first = false;
            }
        }
        else {
            cout << s;
            first = false;
        }
    }

    if(first) cout << 0;
}