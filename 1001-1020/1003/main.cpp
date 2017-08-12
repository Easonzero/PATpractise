//
// Created by eason on 7/18/17.
//

#include <iostream>
#include <algorithm>
using namespace std;

const int MAXNUM = 510;
const int MAXDIST = 10000;

int dist[MAXNUM],previous[MAXNUM],rescueNum[MAXNUM],num[MAXNUM],w[MAXNUM];
int roadLen[MAXNUM][MAXNUM];

void dijkstra(int v0,int n){
    bool visit[n];
    for(int i=0;i<n;i++){
        visit[i]=false;
        dist[i] = roadLen[v0][i];
        previous[i] = dist[i] == MAXDIST ? -1 : v0;
    }

    dist[v0] = 0;
    w[v0] = rescueNum[v0];
    num[v0] = 1;

    for(int i=1;i<n;i++){
        int u = -1,mindist = MAXDIST;
        for(int j=0;j<n;j++){
            if(dist[j]<mindist&&!visit[j]){
                u = j;
                mindist = dist[j];
            }
        }

        if(u == -1) break;
        visit[u]=true;

        for(int j=0;j<n;j++){
            if(!visit[j]&&dist[j])
                if(dist[u]+roadLen[u][j]<dist[j]&&!visit[j]){
                    dist[j] = dist[u] + roadLen[u][j];
                    previous[j]=u;
                    num[j] = num[u];
                    w[j] = w[u] + rescueNum[j];
                }else if(dist[u] + roadLen[u][j] == dist[j]&&!visit[j]) {
                    num[j] += num[u];
                    if(w[u] + rescueNum[j] > w[j])
                        w[j] = w[u] + rescueNum[j];
                }
        }
    }
}

int main() {
    int n,m,c1,c2;
    scanf("%d%d%d%d", &n, &m, &c1, &c2);
    for(int i = 0; i < n; i++)
        scanf("%d", &rescueNum[i]);
    fill(roadLen[0], roadLen[0] + MAXNUM * MAXNUM, MAXDIST);
    fill(dist, dist + MAXNUM, MAXDIST);
    int a, b, c;
    for(int i = 0; i < m; i++) {
        scanf("%d%d%d", &a, &b, &c);
        roadLen[a][b] = c;
        roadLen[b][a] = c;
    }
    dijkstra(c1,n);
    cout << num[c2] << " " << w[c2];
    return 0;
}