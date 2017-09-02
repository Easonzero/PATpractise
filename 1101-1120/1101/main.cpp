//
// Created by eason on 9/1/17.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> result;

int main(){
    int n,max=0;
    cin >> n;
    int src[n],dest[n];
    for(int i=0;i<n;i++){
        cin >> src[i];
        dest[i] = src[i];
    }

    sort(dest,dest+n);
    for(int i=0;i<n;i++){
        if(dest[i]==src[i]&&src[i]>max) result.push_back(src[i]);
        if(src[i]>max) max = src[i];
    }

    cout << result.size() << endl;
    for(int i=0;i<result.size();i++){
        cout << result[i];
        if(i!=result.size()-1) cout << " ";
    }
    cout << endl;
    return 0;
}