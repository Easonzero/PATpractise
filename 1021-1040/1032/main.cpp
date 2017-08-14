//
// Created by eason on 8/12/17.
//

#include <iostream>

using namespace std;

int mnext[100000];
bool visit[100000];

void travel(int head){
    int p = head;
    while(p!=-1){
        visit[p]=true;
        p = mnext[p];
    }
}

int chkSharing(int head){
    int p=head;

    while(p!=-1){
        if(visit[p]) return p;
        p = mnext[p];
    }

    return -1;
}

int main(){
    int head1,head2,n;

    cin >> head1 >> head2 >> n;

    for(int i=0;i<n;i++){
        int address,nextAddress;
        char data;
        cin >> address >> data >> nextAddress;
        mnext[address] = nextAddress;
    }

    travel(head1);
    int sharing = chkSharing(head2);
    if(sharing!=-1) printf("%05d",sharing);
    else cout << -1;
    return 0;
}