//
// Created by eason on 8/30/17.
//

#include <iostream>

using namespace std;

int S[210][210],N;

bool tell(int* vs,int n){
    if(n!=N+1) return false;
    if(vs[0]!=vs[n-1]) return false;
    int times[210];
    fill(times,times+210,0);
    for(int i=0;i<n-1;i++){
        times[vs[i]]++;
        if(S[vs[i]][vs[i+1]]==0) return false;
    }
    for(int i=1;i<=N;i++){
        if(times[i]!=1) return false;
    }
    return true;
}

int main(){
    int m;
    cin >> N >> m;
    for(int i=0;i<m;i++){
        int v1,v2;
        cin >> v1 >> v2;
        S[v1][v2] = 1;
        S[v2][v1] = 1;
    }
    int t;
    cin >> t;
    for(int i=0;i<t;i++){
        int k;
        cin >> k;
        int vs[k];
        for(int j=0;j<k;j++){
            cin >> vs[j];
        }
        if(tell(vs,k)) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}