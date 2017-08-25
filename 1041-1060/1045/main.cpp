//
// Created by eason on 8/22/17.
//

#include <iostream>

using namespace std;

int fcolor[210],a[10010];

int main(){
    int k,n,m,l=0,max=0;
    cin >> k;
    cin >> n;
    for(int i=0;i<n;i++){
        int color;
        cin >> color;
        fcolor[color] = i+1;
    }
    cin >> m;
    for(int i=0;i<m;i++){
        int color;
        cin >> color;
        if(fcolor[color]>=1){
            a[l++]=fcolor[color];
        }
    }
    int dp[10010];
    for(int i=0;i<l;i++){
        dp[i]=1;
        for(int j=0;j<i;j++){
            if(a[i]>=a[j]&&dp[i]<dp[j]+1){
                dp[i] = dp[j]+1;
            }
        }
        if(dp[i]>max) max = dp[i];
    }
    cout << max;
    return 0;
}