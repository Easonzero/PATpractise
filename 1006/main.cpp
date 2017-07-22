//
// Created by eason on 7/21/17.
//

#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

struct Record{
    string id;
    int in[3];
    int out[3];
};

int compareTime(int* time1,int* time2,int bit){
    if(time1[bit]<time2[bit]) return -1;
    if(time1[bit]>time2[bit]) return 1;
    if(time1[bit]==time2[bit]&&bit==2) return 0;
    return compareTime(time1,time2,bit+1);
}

Record* getIn(vector<Record*> v){
    Record* in = v.at(0);
    for(auto record:v){
        int result = compareTime(in->in,record->in,0);
        if(result>0) in = record;
    }
    return in;
}

Record* getOut(vector<Record*> v){
    Record* out = v.at(0);
    for(auto record:v){
        int result = compareTime(out->out,record->out,0);
        if(result<0) out = record;
    }
    return out;
}


int main() {
    int n;
    vector<Record*> v;

    cin >> n;
    for(int i=0;i<n;i++){
        string id;
        int in[3],out[3];
        cin >> id;
        scanf("%d:%d:%d %d:%d:%d",in,in+1,in+2,out,out+1,out+2);
        Record *record = new Record();
        record->id = id;
        memcpy(record->in,in,sizeof(in));
        memcpy(record->out,out,sizeof(out));
        v.push_back(record);
    }

    cout << getIn(v)->id << " " << getOut(v)->id;

    return 0;
}
