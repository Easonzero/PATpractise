//
// Created by eason on 9/3/17.
//
#include <iostream>
#include <map>
#include <stack>

using namespace std;

const int MAX = 99999;

map<string,int> mapId;

int A[210][210],dh[210],pre[210],cost[210],happ[210],num[210];

void dijk(int n){
    bool visit[n];

    fill(visit,visit+n,false);
    fill(pre,pre+n,-1);
    fill(cost,cost+n,MAX);
    fill(happ,happ+n,0);
    fill(num,num+n,0);

    cost[0] = 0;

    for(int i=0;i<n;i++){
        int u=0,min=MAX;
        for(int i=0;i<n;i++){
            if(!visit[i]&&min>cost[i]){
                min = cost[i];
                u = i;
            }
        }
        visit[u] = true;
        for(int i=0;i<n;i++){
            if(!visit[i]&&A[u][i]<MAX){
                if(cost[i]>cost[u]+A[u][i]){
                    cost[i] = cost[u]+A[u][i];
                    pre[i] = u;
                    happ[i] = happ[u]+dh[i];
                    num[i] = 1;
                }else if(cost[i]==cost[u]+A[u][i]){
                    num[i]++;
                    if(happ[i]<happ[u]+dh[i]){
                        pre[i] = u;
                        happ[i] = happ[u]+dh[i];
                    }
                }
            }
        }
    }
}

string getCity(int i){
    for(auto m:mapId){
        if(m.second==i) return m.first;
    }
}

void print(int v){
    stack<string> s;
    int p=v;
    while(p>=0){
        s.push(getCity(p));
        p = pre[p];
    }
    cout << num[v] << " " << cost[v] << " " << happ[v] << " " << happ[v]/2 << endl;
    while(!s.empty()){
        cout << s.top();
        s.pop();
        if(s.size()!=0) cout << "->";
    }
}

int main(){
    fill(A[0],A[0]+210*210,MAX);
    int n,m;
    cin >> n >> m;
    string start;
    cin >> start;
    mapId[start]=0;
    for(int i=1;i<=n-1;i++){
        string city;
        int h;
        cin >> city >> h;
        mapId[city] = i;
        dh[i] = h;
    }
    for(int i=0;i<m;i++){
        string city1,city2;
        int c,i1,i2;
        cin >> city1 >> city2 >> c;
        i1 = mapId[city1];
        i2 = mapId[city2];
        A[i1][i2] = c;
        A[i2][i1] = c;
    }
    dijk(n);
    print(mapId["ROM"]);
    return 0;
}