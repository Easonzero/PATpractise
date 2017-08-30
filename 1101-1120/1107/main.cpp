//
// Created by eason on 8/29/17.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int s[1010],h[1010];

int finds(int x){
    while(s[x]>=0) x = s[x];
    return x;
}

void unions(int root1,int root2){
    root1 = finds(root1);
    root2 = finds(root2);
    s[root1] += s[root2];
    s[root2] = root1;
}

int main(){
    fill(s,s+1010,-1);
    fill(h,h+1010,-1);
    int n;
    cin >> n;
    for(int i=0;i<n;i++){
        int m;
        cin >> m;
        cin.get();
        for(int j=0;j<m;j++){
            int t;
            cin >> t;
            if(h[t]!=-1)
                unions(i,h[t]);
            h[t] = i;
        }
    }
    sort(s,s+n);
    int total=0;
    for(int i=0;i<n;i++){
        if(s[i]<0) total++;
        else break;
    }
    cout << total << endl;
    for(int i=0;i<total;i++){
        cout << (-s[i]);
        if(i!=total-1) cout << " ";
    }
    return 0;
}