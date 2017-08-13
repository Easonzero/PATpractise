//
// Created by eason on 8/12/17.
//

#include <iostream>

using namespace std;

int mnext[100000];
char mdata[100000];

int getLen(int head){
    int t = head,len = 0;
    while(t!=-1){
        len++;
        t = mnext[t];
    }
    return len;
}

int getAddress(int head,int dt){
    int t = head;
    while(dt!=0){
        t = mnext[t];
        dt--;
    }
    return t;
}

int chkSharing(int head1,int head2){
    int sharing=-1,p1=head1,p2=head2;
    bool flag = false;
    while(p1!=p2){
        flag = false;
        p1 = mnext[p1];
        p2 = mnext[p2];
        if(p1==p2&&!flag){
            sharing = p1;
            flag = true;
        }
    }

    if(!flag) sharing=-1;
    return sharing;
}

int main(){
    int head1,head2,n;

    cin >> head1 >> head2 >> n;

    for(int i=0;i<n;i++){
        int address,nextAddress;
        char data;
        cin >> address >> data >> nextAddress;
        mnext[address] = nextAddress;
        mnext[address] = nextAddress;
        mdata[address] = data;
    }

    int len1 = getLen(head1),len2 = getLen(head2);
    int sharing;
    if(len1>len2){
        int address = getAddress(head1,len1-len2);
        sharing = chkSharing(address,head2);
    }else{
        int address = getAddress(head2,len2-len1);
        sharing = chkSharing(head1,address);
    }

    cout << sharing;

    return 0;
}