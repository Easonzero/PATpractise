//
// Created by eason on 8/18/17.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int n,m;
    vector<int> nd,md;
    cin >> n;
    for(int i=0;i<n;i++){
        int k;
        cin >> k;
        nd.push_back(k);
    }
    cin >> m;
    for(int i=0;i<m;i++){
        int k;
        cin >> k;
        md.push_back(k);
    }
    sort(nd.begin(),nd.end());
    sort(md.begin(),md.end());
    int total = 0;
    unsigned long nlen = nd.size(),mlen = md.size();
    for(int i=0;i<nlen&&i<mlen;i++){
        if(md[mlen-1-i]>0&&nd[nlen-1-i]>0)
            total += nd[nlen-1-i]*md[mlen-1-i];
        else
            break;
    }
    for(int i=0;i<nlen&&i<mlen;i++){
        if(nd[i]<0&&md[i]<0)
            total += nd[i]*md[i];
        else
            break;
    }
    cout << total << endl;
    return 0;
}