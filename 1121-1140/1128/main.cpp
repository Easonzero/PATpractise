//
// Created by eason on 9/5/17.
//

#include <iostream>
#include <cstdlib>

using namespace std;

int main(){
    int n;
    cin >> n;
    for(int i=0;i<n;i++){
        int k;
        cin >> k;
        int v[k];
        bool flag = true;
        for(int j=0;j<k;j++){
            cin >> v[j];
            for(int t=0;t<j;t++){
                if(v[t]==v[j]||abs(v[j]-v[t])==j-t){
                    flag = false;
                    break;
                }
            }
        }
        if(flag) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}