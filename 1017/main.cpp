//
// Created by eason on 7/31/17.
//

#include <iostream>
#include <algorithm>

using namespace std;

struct Customer{
    int t;
    int p;
};

const int START = 8*60*60,END = 17*60*60;

bool cmp(Customer* c1,Customer* c2){
    return c1->t - c2->t < 0;
}

int main(){
    int n,k;
    float wait=0;
    cin >> n >> k;
    Customer* queue[n];
    int windows[k];
    for(int i=0;i<n;i++){
        int h,m,s;
        queue[i] = new Customer();
        scanf("%d:%d:%d %d",&h,&m,&s,&queue[i]->p);
        queue[i]->t = h*60*60 + m*60 + s;
        if(queue[i]->p>60) queue[i]->p=3600;
        else queue[i]->p*=60;
    }
    sort(queue,queue+n,cmp);
    for(int i=0;i<k;i++){
        int d = START-queue[i]->t;
        if(d>0) {
            wait += d;
            windows[i]=queue[i]->p+START;
        }else windows[i]=queue[i]->t+queue[i]->p;
    }
    int i=k;
    while(i<n){
        if(queue[i]->t>END) break;
        int min = 99999,id=0;
        for(int j=0;j<k;j++){
            if(windows[j]<min) {
                min = windows[j];
                id = j;
            }
        }
        int d = windows[id]-queue[i]->t;
        if(d<0) windows[id] = queue[i]->t+queue[i]->p;
        else{
            wait+=d;
            windows[id] += queue[i]->p;
        }
        i++;
    }
    printf("%.1f",wait/(60*i));
    return 0;
}