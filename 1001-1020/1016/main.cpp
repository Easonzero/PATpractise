//
// Created by eason on 7/29/17.
//

#include <iostream>
#include <map>

using namespace std;

struct Record{
    int day;int hour;int min;
    bool state;
    Record* next = nullptr;
};

map<string,Record*> storage;
int cost[24],totalcost=0;

bool compareRecord(Record* e1,Record* e2){
    return e1->day<e2->day||
            (e1->day==e2->day&&
                    (e1->hour<e2->hour||
                            (e1->hour==e2->hour&&e1->min<e2->min)));
}

void insertRecord(Record*& head,Record* e){
    if(head == nullptr){
        head = e;
        return;
    }
    Record *p = head,*prep = nullptr;
    while(true){
        if(compareRecord(e,p)){
            if(prep == nullptr){
                e->next = p;
                head = e;
            }
            else{
                e->next = p;
                prep->next = e;
            }
            break;
        }
        if(p->next == nullptr){
            p->next = e;
            e->next = nullptr;
            break;
        }

        prep = p;
        p = p->next;
    }
}

double callProfitFromZero(Record* e,int* total) {
    double tmp = cost[e->hour] * e->min + totalcost * e->day * 60;
    for(int i=0;i<e->hour;i++)
        tmp += cost[i] * 60;
    *total = e->day*24*60 + e->hour*60 + e->min;
    return tmp / 100.0;
}

int main(){
    for(int i=0;i<24;i++){
        cin >> cost[i];
        totalcost += cost[i];
    }
    int n,mon;
    cin >> n;
    for(int i=0;i<n;i++){
        string name,state;
        int day;int hour;int min;
        cin >> name;
        scanf("%d:%d:%d:%d", &mon, &day, &hour, &min);
        cin >> state;
        if(storage.count(name)==0) storage[name]=nullptr;
        Record* e = new Record();
        e->state = state=="on-line";
        e->hour = hour;
        e->day = day;
        e->min = min;
        insertRecord(storage[name],e);
    }
    for(auto pair : storage){
        bool has = false;
        Record *p=pair.second,*pn=p->next;
        double sum=0;
        while(pn!=nullptr){
            if(!pn->state&&p->state){
                if(!has) {
                    printf("%s %02d\n",pair.first.c_str(),mon);
                    has = true;
                }
                double profit1,profit2;
                int total1,total2;
                profit1 = callProfitFromZero(p,&total1);
                profit2 = callProfitFromZero(pn,&total2);
                printf("%02d:%02d:%02d ",p->day,p->hour,p->min);
                printf("%02d:%02d:%02d %d $%.2f\n",pn->day,pn->hour,pn->min,total2-total1,profit2-profit1);
                sum += profit2-profit1;
            }
            p = p->next;
            pn = pn->next;
        }
        if(has) printf("Total amount: $%.2f\n",sum);
    }
    return 0;
}