//
// Created by eason on 9/10/17.
//

#include <iostream>
#include <stack>

using namespace std;

bool A[550][550];

int main(){
    fill(A[0],A[0]+550*550,false);
    int n,m;
    cin >> n >> m;
    for(int i=0;i<m;i++){
        int v1,v2;
        cin >> v1 >> v2;
        A[v1][v2] = true;
        A[v2][v1] = true;
    }

    stack<int> tmp;
    bool visit[n+1];
    fill(visit+1,visit+n,false);
    tmp.push(1);
    while(!tmp.empty()){
        int u = tmp.top();
        visit[u] = true;
        tmp.pop();
        for(int j=1;j<=n;j++){
            if(!visit[j]&&A[u][j]){
                tmp.push(j);
            }
        }
    }
    bool isCnt = true,isEulerian = true,semi = false;
    int odd=0;
    for(int i=1;i<=n;i++){
        if(!visit[i]) {
            isCnt = false;
        }
        int degree = 0;
        for(int j=1;j<=n;j++){
            if(A[i][j]) degree++;
        }
        cout << degree;
        if(i==n) cout << endl;
        else cout << " ";
        if(degree%2==1){
            odd++;
        }
        if(odd==2) semi = true;
        else if(odd>2){
            semi = false;
            isEulerian = false;
        } else semi = false;
    }
    if(isCnt&&isEulerian){
        if(semi) cout << "Semi-Eulerian";
        else cout << "Eulerian";
    }else{
        cout << "Non-Eulerian";
    }

    return 0;
}