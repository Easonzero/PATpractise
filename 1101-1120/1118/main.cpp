//
// Created by eason on 9/8/17.
//

#include <iostream>

using namespace std;

int data[10010];

int find(int v){
    int p=v;
    while(data[v]>0) {
        v = data[v];
    }
    while(data[p]>0) {
        int tmp = data[p];
        data[p] = v;
        p = tmp;
    }
    return v;
}

void merge(int v1,int v2){
    if(v1==v2) return;
    int v1root = find(v1);
    int v2root = find(v2);
    int v2count = data[v2root];
    data[v2root] = v1root;
    data[v1root] += v2count;
}

int main(){
    fill(data,data+10010,-1);
    int n,max=0;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        int k;
        scanf("%d",&k);
        int first=-1;
        for(int j=0;j<k;j++){
            int v;
            scanf("%d",&v);
            if(j==0) first = v;
            if(v>max) max = v;
            merge(first,v);
        }
    }
    int count = 0;
    for(int i=1;i<=max;i++){
        if(data[i]<0) {
            count++;
        }
    }
    printf("%d %d\n",count,max);
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        int v0,v1;
        scanf("%d %d",&v0,&v1);
        if(find(v0)==find(v1)) printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}