//
// Created by eason on 8/12/17.
//

#include <iostream>
#include <stack>

using namespace std;

const int MAX = 99999;

int D[550][550],C[550][550];
int dist[550],cost[550],pre[550];

void dijkstra(int n,int v0){
    bool visit[n];
    fill(visit,visit+n,false);
    dist[v0] = 0;
    for(int i=0;i<n;i++){
        int min = MAX,u = -1;
        for(int j=0;j<n;j++){
            if(!visit[j]&&dist[j]<min){
                u = j;
                min = dist[j];
            }
        }
        if(u==-1) break;
        visit[u] = true;
        for(int j=0;j<n;j++){
            if(!visit[j]&&dist[j]>dist[u]+D[u][j]){
                dist[j] = dist[u]+D[u][j];
                pre[j] = u;
                cost[j] = cost[u]+C[u][j];
            }else if(!visit[j]&&dist[j]==dist[u]+D[u][j]){
                if(cost[j]>cost[u]+C[u][j]){
                    pre[j] = u;
                    cost[j] = cost[u]+C[u][j];
                }
            }
        }
    }
}

void print(int n,int dest){
    int i = dest;
    stack<int> tmp;
    while(i!=-1){
        tmp.push(i);
        i=pre[i];
    }
    while(!tmp.empty()){
        cout << tmp.top() << " ";
        tmp.pop();
    }
    cout << dist[dest] << " " << cost[dest];
}

int main(){
    fill(dist,dist+550,MAX);
    fill(pre,pre+550,-1);
    fill(D[0],D[0]+550*550,MAX);
    fill(D[0],D[0]+550*550,MAX);

    int n,m,s,d;
    cin >> n >> m >> s >> d;

    for(int i=0;i<m;i++){
        int a,b;
        cin >> a >> b;
        cin >> D[a][b] >> C[a][b];
        D[b][a] = D[a][b];
        C[b][a] = C[a][b];
    }

    dijkstra(n,s);
    print(n,d);
    return 0;
}