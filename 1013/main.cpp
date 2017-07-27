//
// Created by eason on 7/26/17.
//

#include <iostream>
#include <stack>

using namespace std;

bool A[1000][1000] = {false};

int checkCnt(int n,int diss){
    bool visit[n+1] = {false};
    int cnt = 0;
    stack<int> stack;
    visit[diss] = true;

    for(int i=1;i<=n;i++){
        if(!visit[i]){
            cnt++;
            int first = i;
            stack.push(first);
            visit[first]=true;
            while(!stack.empty()){
                int e = stack.top();
                stack.pop();
                for(int i=1;i<=n;i++){
                    if(A[e][i]&&!visit[i]) {
                        stack.push(i);
                        visit[i]=true;
                    }
                }
            }
        }
    }

    return cnt;
}

int main(){
    int n,m,k;
    cin >> n >> m >> k;
    for(int i=0;i<m;i++){
        int c1,c2;
        cin >> c1 >> c2;
        A[c1][c2] = true;
        A[c2][c1] = true;
    }
    for(int i=0;i<k;i++){
        int e;
        cin >> e;
        cout << checkCnt(n,e)-1 << endl;
    }
    return 0;
}