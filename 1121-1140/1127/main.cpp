//
// Created by eason on 9/9/17.
//

#include <iostream>
#include <deque>

using namespace std;

struct Node{
    int value;
    int deepth;
    Node* lchild = nullptr;
    Node* rchild = nullptr;
};

int getIndex(int *tree,int v){
    int i=0;
    while(true){
        if(tree[i]==v){
            break;
        }
        i++;
    }
    return i;
}

void toTree(int *in,int *post,int ins,int ine,int pos,int poe,Node*& head,int deepth){
    if(ins>=ine||pos>=poe) return;
    int root = post[poe-1];
    int index = getIndex(in,root);

    head = new Node;
    head->value = root;
    head->deepth = deepth;

    toTree(in,post,ins,index,pos,pos+index-ins,head->lchild,deepth+1);
    toTree(in,post,index+1,ine,pos+index-ins,poe-1,head->rchild,deepth+1);
}

int main(){
    int n;
    cin >> n;
    int post[n],in[n];
    for(int i=0;i<n;i++){
        cin >> in[i];
    }
    for(int i=0;i<n;i++){
        cin >> post[i];
    }
    Node * head = nullptr;
    toTree(in,post,0,n,0,n,head,0);
    deque<Node*> q;
    q.push_back(head);
    while(!q.empty()){
        int flag = q.front()->deepth%2;
        deque<Node*> tmpq;
        while(!q.empty()){
            Node* node = nullptr;
            if(flag==1){
                node = q.front();
                q.pop_front();
                if(node->lchild!=nullptr) tmpq.push_back(node->lchild);
                if(node->rchild!=nullptr) tmpq.push_back(node->rchild);
            }else if(flag==0){
                node = q.back();
                q.pop_back();
                if(node->rchild!=nullptr) tmpq.push_front(node->rchild);
                if(node->lchild!=nullptr) tmpq.push_front(node->lchild);
            }
            cout << node->value;
            if(!q.empty()||!tmpq.empty()) cout << " ";
        }
        q.swap(tmpq);
    }
    return 0;
}