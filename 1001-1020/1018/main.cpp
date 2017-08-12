//
// Created by eason on 8/1/17.
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>

using namespace std;

const int MAX = 99999;
int minNeed = MAX, minBack = MAX;
int D[1000][1000],C[1000];
int dist[1000];
vector<int> pre[1000];
int cmax;

vector<int> path, temppath;
void dfs(int v) {
    if(v == 0) {
        temppath.push_back(v);
        int need = 0, back = 0;
        for(int i = temppath.size() - 1; i >= 0; i--) {
            int id = temppath[i];
            if(C[id] > 0) {
                back += C[id];
            } else {
                if(back > (0 - C[id])) {
                    back += C[id];
                } else {
                    need += ((0 - C[id]) - back);
                    back = 0;
                }
            }
        }
        if(need < minNeed) {
            minNeed = need;
            minBack = back;
            path = temppath;
        } else if(need == minNeed && back < minBack) {
            minBack = back;
            path = temppath;
        }
        temppath.pop_back();
        return ;
    }
    temppath.push_back(v);
    for(int i = 0; i < pre[v].size(); i++)
        dfs(pre[v][i]);
    temppath.pop_back();
}

void dijkstra(int v0,int n){
    bool visit[n] = {false};

    dist[v0] = 0;

    for(int i=1;i<n;i++){
        int v,min=MAX;
        for(int j=0;j<n;j++){
            if(!visit[j]&&dist[j]<min){
                v = j;
                min = dist[j];
            }
        }
        visit[v] = true;
        for(int j=0;j<n;j++){
            if(!visit[j]&&dist[j]>dist[v]+D[v][j]){
                dist[j] = dist[v]+D[v][j];
                pre[j].clear();
                pre[j].push_back(v);
            }else if(!visit[j]&&dist[j]==dist[v]+D[v][j]){
                pre[j].push_back(v);
            }
        }
    }
}

int main(){
    fill(D[0], D[0] + 1000 * 1000, MAX);
    fill(dist,dist + 1000, MAX);
    int n,sp,m;
    cin >> cmax >> n >> sp >> m;
    for(int i=1;i<n+1;i++){
        cin >> C[i];
        C[i]-=cmax/2;
    }
    for(int i=1;i<=m;i++){
        int s,e,t;
        cin >> s >> e >> t;
        D[s][e] = t;
        D[e][s] = t;
    }
    dijkstra(0,n+1);
    dfs(sp);
    printf("%d 0", minNeed);
    for(int i = path.size() - 2; i >= 0; i--)
        printf("->%d", path[i]);
    printf(" %d", minBack);
    return 0;
}