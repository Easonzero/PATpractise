//
// Created by eason on 9/16/17.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int A[10010];
int area[10010];
int sets[10010];
vector<int> toID;

int find(int x){
    int p = x;
    while(A[p]>=0) p = A[p];
    while(p!=x){
        int tmp = x;
        x = A[x];
        A[tmp] = p;
    }
    return p;
}

void merge(int x1,int x2){
    if(x1<0||x2<0) return;
    int root1 = find(x1);
    int root2 = find(x2);

    if(root1==root2) return;

    if(toID[root1-1]>toID[root2-1]){
        int tmp = root1;
        root1 = root2;
        root2 = tmp;
    }

    A[root1] += A[root2];
    A[root2] = root1;
    area[root1] += area[root2];
    sets[root1] += sets[root2];
}

void init(int x,int _sets,int _area){
    int root = find(x);
    area[root] += _area;
    sets[root] += _sets;
}

int pushID(int id){
    int index = 0;
    for(auto e:toID){
        index++;
        if(id==e) return index;
    }
    toID.push_back(id);
    return index+1;
}

vector<int> result;

bool cmp(int i,int j){
    return ((float)area[i]/(float)A[i]<(float)area[j]/(float)A[j])||
            ((float)area[i]/(float)A[i]==(float)area[j]/(float)A[j])&&toID[i-1]<toID[j-1];
}

int main(){
    fill(A,A+10010,-1);
    int n;
    cin >> n;
    for(int i=0;i<n;i++){
        int k,f,m,cn;
        cin >> k >> f >> m >> cn;
        int indexk = pushID(k);
        if(f!=-1) {
            merge(indexk,pushID(f));
        }
        if(m!=-1) {
            merge(indexk,pushID(m));
        }
        for(int j=0;j<cn;j++){
            int child;
            cin >> child;
            merge(indexk,pushID(child));
        }
        int area,sets;
        cin >> sets >> area;
        init(indexk,sets,area);
    }
    for(int i=1;i<=toID.size();i++){
        if(A[i]<0) result.push_back(i);
    }
    sort(result.begin(),result.end(),cmp);
    cout << result.size() << endl;
    for(auto e:result){
        printf("%04d %d %0.3f %0.3f\n",toID[e-1],-A[e],-(float)sets[e]/(float)A[e],-(float)area[e]/(float)A[e]);
    }
    return 0;
}