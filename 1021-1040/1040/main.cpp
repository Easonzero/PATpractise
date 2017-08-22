//
// Created by eason on 8/20/17.
//

#include <iostream>

using namespace std;

int dp[1010][1010];
string str;

void dpfunc(int i,int j){
    if(str[i]==str[j]){
        if(dp[i+1][j-1]==-1){
            dpfunc(i+1,j-1);
        }
        dp[i][j] = dp[i+1][j-1];
    }else{
        dp[i][j] = 0;
    }
}

int main(){
    fill(dp[0],dp[0]+1010*1010,-1);
    getline(cin,str);
    int l = str.size();
    int len = 1;
    for(int i=0;i<l-1;i++){
        dp[i][i] = 1;
        dp[i][i+1] = str[i]==str[i+1]?1:0;
        if(dp[i][i+1]==1) len=2;
    }

    if(len!=2) {
        cout << len;
        return 0;
    }

    bool flag = false;
    for(int i=3;i<=l;i++){
        for(int j=0;j<l+1-i;j++){
            dpfunc(j,j+i-1);
            if(dp[j][j+i-1]==1){
                flag = true;
                len = i;
            }
        }
        if(!flag) break;
    }
    cout << len;
    return 0;
}