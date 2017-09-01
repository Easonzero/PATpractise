//
// Created by eason on 8/31/17.
//

#include <iostream>
#include <vector>

using namespace std;

vector<int> result;
bool is = true;

void genTree(int* pre,int* post,int pres,int pree,int posts,int poste) {
    if(pres>pree) return;
    if(pres==pree){
        result.push_back(pre[pres]);
        return;
    }
    if(pree-pres==1){
        result.push_back(pre[pres]);
        result.push_back(pre[pree]);
        is = false;
        return;
    }
    int root = pre[pres];
    int rroot = post[poste-1];

    int index;
    for(int i=pres;i<=pree;i++){
        if(pre[i]==rroot) {
            index=i;
            break;
        }
    }

    genTree(pre,post,pres+1,index-1,posts,posts+index-pres-2);
    result.push_back(root);
    genTree(pre,post,index,pree,posts+index-pres-1,poste-1);
}

int main(){
    int n;
    cin >> n;
    int pre[n],post[n];
    for(int i=0;i<n;i++){
        cin >> pre[i];
    }
    for(int i=0;i<n;i++){
        cin >> post[i];
    }
    genTree(pre,post,0,n-1,0,n-1);
    string str = is?"Yes":"No";
    cout << str << endl;
    for(int i=0;i<result.size();i++){
        cout << result[i];
        if(i!=result.size()-1) cout << " ";
    }
    cout << endl;
    return 0;
}