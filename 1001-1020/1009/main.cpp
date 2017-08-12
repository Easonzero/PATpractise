//
// Created by eason on 7/23/17.
//

#include <iostream>
using namespace std;

struct Item{
    int exp;
    float co;
    Item* next = nullptr;
};

void addItem(Item*& head,int exp,float co){
    if(head == nullptr){
        head = new Item();
        head->exp = exp;
        head->co = co;
        return;
    }else if(head->exp<exp){
        Item *temp = head;
        head = new Item();
        head->exp = exp;
        head->co = co;
        head->next = temp;
        return;
    }

    Item *p = head,*pre = nullptr;

    while(p!=nullptr){
        if(p->exp==exp){
            p->co += co;
            return;
        }else if(p->exp<exp){
            pre->next = new Item();
            pre->next->exp = exp;
            pre->next->co = co;
            pre->next->next = p;
            return;
        }

        pre = p;
        p = p->next;
    }

    pre->next = new Item();
    pre->next->exp = exp;
    pre->next->co = co;
}

void printItems(Item* head){
    Item *p = head;

    while(p!=nullptr){
        if(p->co!=0)
            printf(" %d %.1f", p->exp, p->co);
        p = p->next;
    }
}

int getLength(Item* head){
    int count=0;
    Item *p = head;
    while(p!=nullptr){
        if(p->co!=0) count++;
        p = p->next;
    }

    return count;
}

int main() {
    int m,n,exp;
    float co;
    Item *head = nullptr,*result = nullptr;

    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        scanf("%d%f", &exp, &co);
        addItem(head,exp,co);
    }
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d%f", &exp, &co);

        Item *p = head;

        while(p!=nullptr){
            addItem(result,exp+p->exp,co*p->co);
            p = p->next;
        }
    }

    cout << getLength(result);
    printItems(result);
    return 0;
}