//
// Created by eason on 9/14/17.
//

#include <iostream>
#include <map>
#include <vector>

using namespace std;

int line[10010][10010];
map<int,vector<int>> cnt;
bool visit[10010];

vector<int> result,tmp;

int minCnt = 99999,minTransfer = 99999;

int getRoadNum(vector<int> a){
    int cnt = -1, preLine = 0;
    for (int i = 1; i < a.size(); i++) {
        if (line[a[i-1]][a[i]] != preLine) cnt++;
        preLine = line[a[i-1]][a[i]];
    }
    return cnt;
}

void dfs(int node, int end) {
    if(node == end){
        if(tmp.size()<minCnt){
            result = tmp;
            minTransfer = getRoadNum(tmp);
            minCnt = tmp.size();
            return;
        }else if(tmp.size()==minCnt&&getRoadNum(tmp)<minTransfer) {
            minTransfer = getRoadNum(tmp);
            result = tmp;
            return;
        }
        return;
    }
    for (int i = 0; i < cnt[node].size(); i++) {
        if (visit[cnt[node][i]] == 0) {
            visit[cnt[node][i]] = 1;
            tmp.push_back(cnt[node][i]);
            dfs(cnt[node][i], end);
            visit[cnt[node][i]] = 0;
            tmp.pop_back();
        }
    }
}

int main(){
    int n,k;
    cin >> n;
    for(int i=0;i<n;i++){
        int m,pre;
        cin >> m >> pre;
        for(int j=1;j<m;j++){
            int id;
            cin >> id;
            if(cnt.count(pre)==0) cnt[pre] = vector<int>();
            if(cnt.count(id)==0) cnt[id] = vector<int>();
            cnt[pre].push_back(id);
            cnt[id].push_back(pre);
            line[pre][id] = i+1;
            line[id][pre] = i+1;
            pre = id;
        }
    }
    cin >> k;
    for(int i=0;i<k;i++){
        minCnt = 99999;minTransfer = 99999;
        int start,end;
        cin >> start >> end;
        tmp.clear();
        tmp.push_back(start);
        visit[start] = true;
        dfs(start,end);
        visit[start] = false;
        cout << result.size()-1 << endl;
        int preLine = 0, preTransfer = start;
        for (int j = 1; j < result.size(); j++) {
            if (line[result[j-1]][result[j]] != preLine) {
                if (preLine != 0) printf("Take Line#%d from %04d to %04d.\n", preLine, preTransfer, result[j-1]);
                preLine = line[result[j-1]][result[j]];
                preTransfer = result[j-1];
            }
        }
        printf("Take Line#%d from %04d to %04d.\n", preLine, preTransfer, end);
    }
    return 0;
}