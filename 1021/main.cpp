//
// Created by eason on 8/4/17.
//

#include <iostream>
#include <stack>

using namespace std;

bool A[10010][10010] = {false};
int tmp[10010] = {0};

void dps(int n,int p,int e,int height){
    tmp[e] = height;
    height++;
    for(int i=1;i<=n;i++){
        if(i==p) continue;
        if(A[e][i]) dps(n,e,i,height);
    }
}

int checkCntGraph(int n){
    bool visit[n+1] = {false};
    stack<int> stack;
    int count = 0;
    for(int i=1;i<=n;i++){
        if(!visit[i]){
            count++;
            stack.push(i);
            while(!stack.empty()){
                int e = stack.top();
                visit[e] = true;
                stack.pop();
                for(int j=1;j<=n;j++){
                    if(A[e][j]&&!visit[j]) stack.push(j);
                }
            }
        }
    }
    return count;
}

int main(){
    int n;
    cin >> n;
    for(int i=0;i<n-1;i++){
        int one,two;
        cin >> one >> two;
        A[one][two] = true;
        A[two][one] = true;
    }
    int count = checkCntGraph(n);
    if(count != 1) cout << "Error: " << count << " components";
    else{
        dps(n,0,1,1);
        bool result[n] = {false};
        int max=0,maxIndex;
        for(int i=1;i<=n;i++){
            if(tmp[i]>max){
                max = tmp[i];
                maxIndex = i;
            }
        }
        for(int i=1;i<=n;i++){
            if(tmp[i]==max) result[i]=true;
        }
        dps(n,0,maxIndex,1);
        max = 0;
        for(int i=1;i<=n;i++)
            if(tmp[i]>max)
                max = tmp[i];
        for(int i=1;i<=n;i++){
            if(result[i]||tmp[i]==max) cout << i << endl;
        }
    }
    return 0;
}