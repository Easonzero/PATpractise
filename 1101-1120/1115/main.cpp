//
// Created by eason on 9/16/17.
//

#include <iostream>
#include <queue>

using namespace std;

struct Node{
    int v;
    int h = 0;
    Node* l = nullptr;
    Node* r = nullptr;
};

int maxHeight = 0;

void insertNode(Node* &head,Node* node){
    if(head==nullptr){
        head = node;
        if(node->h>maxHeight) maxHeight = node->h;
        return;
    }
    node->h++;
    if(node->v<=head->v) insertNode(head->l,node);
    else insertNode(head->r,node);
}

int main(){
    Node* head = nullptr;
    int n;
    cin >> n;
    for(int i=0;i<n;i++){
        Node* node = new Node();
        cin >> node->v;
        insertNode(head,node);
    }
    queue<Node*> q;
    q.push(head);
    int n1=0,n2=0;
    while(!q.empty()){
        Node* node = q.front();
        q.pop();
        if(node->h==maxHeight-1){
            n2++;
        }else if(node->h==maxHeight){
            n1++;
        }
        if(node->l!=nullptr) q.push(node->l);
        if(node->r!=nullptr) q.push(node->r);
    }
    printf("%d + %d = %d",n1,n2,n1+n2);
    return 0;
}