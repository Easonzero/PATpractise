//
// Created by eason on 8/3/17.
//
#include <iostream>
#include <queue>

using namespace std;

int post[50],in[50];

struct Node{
    int v;
    Node* left = nullptr;
    Node* right = nullptr;
};

int getRootIndex(int is,int ie,int root){
    while(is!=ie){
        if(root==in[is]) return is;
        is++;
    }
    return -1;
}

void genTree(Node* &head,int ps,int pe,int is,int ie){
    if(ps==pe) return;
    int root = post[pe-1];
    int index = getRootIndex(is,ie,root);
    head = new Node();
    head->v = root;
    genTree(head->left,ps,ps+index-is,is,index);
    genTree(head->right,ps+index-is,pe-1,index+1,ie);
}

void levelTravel(Node* head){
    queue<Node*> q;
    q.push(head);
    while(!q.empty()){
        Node* node = q.front();
        q.pop();
        cout << node->v;
        if(node->left != nullptr) q.push(node->left);
        if(node->right != nullptr) q.push(node->right);
        if(!q.empty()) cout << " ";
    }
}

int main(){
    Node* head = nullptr;
    int n;
    cin >> n;
    for(int i=0;i<n;i++)
        cin >> post[i];
    for(int i=0;i<n;i++)
        cin >> in[i];
    genTree(head,0,n,0,n);
    levelTravel(head);
    return 0;
}