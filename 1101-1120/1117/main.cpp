//
// Created by eason on 9/12/17.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> v;

bool cmp(int a, int b) {
    return a > b;
}

int main(){
    int n;
    cin >> n;
    for(int i=0;i<n;i++){
        int k;
        cin >> k;
        v.push_back(k);
    }
    sort(v.begin(),v.end(),cmp);
    int result = 0;
    for(int i=0;i<n&&v[i]>i+1;i++){
        result=i+1;
    }
    cout << result;
    return 0;
}