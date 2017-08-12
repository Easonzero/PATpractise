//
// Created by eason on 7/22/17.
//
#include <cstdio>

int maxSubSeq(int *nk,int n,int* start,int* end){
    int sum = 0,max = -1,begin=0;
    *start = 0,*end = 0;
    for(int i = 0; i < n; i++) {
        sum += nk[i];
        if(sum > max) {
            max = sum;
            *start = begin;
            *end = i;
        }else if(sum < 0) {
            sum = 0;
            begin = i + 1;
        }
    }
    return max;
}

int main() {
    int n;
    scanf("%d", &n);
    int nk[n],start,end;
    bool flag = false;
    for(int i=0;i<n;i++){
        scanf("%d",nk+i);
        if(nk[i]>=0) flag=true;
    }

    int max = maxSubSeq(nk,n,&start,&end);
    if(!flag)
        printf("0 %d %d", nk[0], nk[n - 1]);
    else
        printf("%d %d %d", max, nk[start], nk[end]);
    return 0;
}
