//
// Created by eason on 8/25/17.
//

#include <iostream>
#include <queue>

using namespace std;

struct Node{
    int num;
    Node* left = nullptr;
    Node* right = nullptr;
};

Node* rll(Node* root){
    Node* right = root->right;
    root->right = right->left;
    right->left = root;
    return right;
}

Node* rrr(Node* root){
    Node* left = root->left;
    root->left = left->right;
    left->right = root;
    return left;
}

Node* rlr(Node* root){
    root->left = rll(root->left);
    return rrr(root);
}

Node* rrl(Node* root){
    root->right = rrr(root->right);
    return rll(root);
}

int getHeight(Node* node){
    if(node == nullptr) return 0;

    int l = getHeight(node->left);
    int r = getHeight(node->right);

    return l>r?l+1:r+1;
}

Node* insertNode(Node* root,Node* node){
    if(root == nullptr) return node;

    if(node->num<root->num){
        root->left = insertNode(root->left,node);
        int l = getHeight(root->left);
        int r = getHeight(root->right);
        if(l-r>=2){
            if(node->num<root->left->num){
                root = rrr(root);
            }else{
                root = rlr(root);
            }
        }
    }else{
        root->right = insertNode(root->right,node);
        int l = getHeight(root->left);
        int r = getHeight(root->right);
        if(r-l>=2){
            if(node->num>root->right->num){
                root = rll(root);
            }else{
                root = rrl(root);
            }
        }
    }

    return root;
}

void levelorder(Node* root){
    if(root == nullptr) return;

    queue<Node*> q;
    q.push(root);

    bool after = false,complete = true;
    while(!q.empty()){
        Node* node = q.front();
        q.pop();
        if(node->left != nullptr){
            if(after){
                complete = false;
            }
            q.push(node->left);
        }else{
            after = true;
        }

        if(node->right != nullptr){
            if(after){
                complete = false;
            }
            q.push(node->right);
        }else{
            after = true;
        }

        cout << node->num;
        if(!q.empty()){
            cout << " ";
        }
    }
    cout << endl;
    if(complete) cout << "YES";
    else cout << "NO";
}

int main(){
    int n;
    Node* head = nullptr;
    cin >> n;
    for(int i=0;i<n;i++){
        Node* node = new Node();
        cin >> node->num;
        head = insertNode(head,node);
    }
    levelorder(head);
    return 0;
}