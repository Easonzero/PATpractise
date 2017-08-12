//
// Created by eason on 8/8/17.
//

#include <iostream>
#include <algorithm>

using namespace std;

const int START = 8*60*60,END = 21*60*60;

struct Customer{
    int arrive;
    int t;
    int serve;
    bool vip;
};

struct Table{
    int end = START;
    int n = 0;
    bool vip = false;
};

Customer* queue[10010];
Table* tables[110];

int timeTo(int h,int m,int s){
    return h*60*60+m*60+s;
}

void toTime(int t,int* h,int* m,int* s){
    *h = t/3600;
    *m = (t-*h*3600)/60;
    *s = t%60;
}

bool cmp(Customer* e1,Customer* e2){
    return e1->arrive<e2->arrive;
}

bool cmp2(Customer* e1,Customer* e2){
    return e1->serve<e2->serve;
}

void print(Customer* e){
    int h,m,s;
    toTime(e->arrive,&h,&m,&s);
    printf("%02d:%02d:%02d ",h,m,s);
    toTime(e->serve,&h,&m,&s);
    printf("%02d:%02d:%02d ",h,m,s);
    cout << (e->serve-e->arrive+30)/60 << endl;
}

void insertVip(int start,int end){
    Customer* vip = queue[end];
    for(int k=end-1;k>=start;k--){
        queue[k+1] = queue[k];
    }
    queue[start] = vip;
}

int main(){
    int n,k,m;
    cin >> n;
    for(int i=0;i<n;i++){
        queue[i] = new Customer;
        int h,m,s;
        scanf("%d:%d:%d ",&h,&m,&s);
        cin >> queue[i]->t >> queue[i]->vip;
        if(queue[i]->t>120) queue[i]->t=120;
        queue[i]->arrive = timeTo(h,m,s);
    }
    cin >> k >> m;
    for(int i=1;i<=k;i++)
        tables[i] = new Table();
    for(int i=0;i<m;i++){
        int index;
        cin >> index;
        tables[index]->vip = true;
    }
    sort(queue,queue+n,cmp);
    for(int i=0;i<n;i++){
        Customer* e = queue[i];
        if(e->arrive>=END) break;
        bool served = false;
        int tmp = -1,min = END,minIndex = -1;
        for(int j=1;j<=k;j++){
            if(tables[j]->end<min){
                min = tables[j]->end;
                minIndex = j;
            }
            if(e->vip&&e->arrive>=tables[j]->end){
                if(tables[j]->vip){
                    tables[j]->end = e->arrive+e->t*60;
                    tables[j]->n++;
                    served = true;
                    e->serve = e->arrive;
                    break;
                }else if(tmp==-1) tmp = j;
            }else if(e->arrive>=tables[j]->end){
                tables[j]->end = e->arrive+e->t*60;
                tables[j]->n++;
                served = true;
                e->serve = e->arrive;
                break;
            }
        }
        if(!served&&minIndex!=-1){
            if(e->vip&&tmp!=-1){
                tables[tmp]->end = e->arrive+e->t*60;
                tables[tmp]->n++;
                e->serve = e->arrive;
            }else{
                if(tables[minIndex]->vip&&!e->vip)
                    for(int j=i+1;j<n;j++){
                        if(queue[j]->arrive>tables[minIndex]->end)
                            break;
                        if(queue[j]->vip)
                            insertVip(i,j);
                    }
                queue[i]->serve = tables[minIndex]->end;
                tables[minIndex]->end += queue[i]->t*60;
                tables[minIndex]->n++;
            }
        }
    }
    sort(queue,queue+n,cmp2);
    for(int i=0;i<n;i++){
        if(queue[i]->serve==0) continue;
        print(queue[i]);
    }
    for(int i=1;i<=k;i++){
        cout << tables[i]->n;
        if(i!=k) cout << " ";
    }
    return 0;
}