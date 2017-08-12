//
// Created by eason on 8/10/17.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

struct Record{
    int id;
    char name[10];
    int grade;
};

vector<Record*> list;

int main(){
    int n,k;
    cin >> n >> k;
    for(int i=0;i<n;i++){
        Record* record = new Record();
        cin >> record->id >> record->name >> record->grade;
        list.push_back(record);
    }
    sort(list.begin(),list.end(),[k](Record* a,Record* b){
        if(k==2&&strcmp(a->name, b->name)!=0)
            return strcmp(a->name, b->name) < 0;
        else if(k==3&&a->grade!=b->grade)
            return a->grade < b->grade;
        else if(k==1)
            return a->id < b->id;
    });
    for(auto record:list){
        printf("%06d %s %d\n", record->id, record->name, record->grade);
    }
    return 0;
}