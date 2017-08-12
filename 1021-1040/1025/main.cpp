//
// Created by eason on 8/8/17.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Record{
    long long id;
    int group;
    int grade;
};

vector<Record*> v;
vector<Record*> tmp;

bool cmp(Record* e1,Record* e2){
    if(e1->grade==e2->grade)
        return e1->id < e2->id;
    else
        return e1->grade > e2->grade;
}

void print(int n){
    int rank=0,groupRank[n+1]={0},tmp[n+1]={0},preGrade[n+1];
    fill(preGrade,preGrade+n+1,-1);
    for(int i=0;i<v.size();i++){
        Record* p = v[i];
        tmp[0]++;
        tmp[p->group]++;
        if(p->grade!=preGrade[0]) rank = tmp[0];
        if(p->grade!=preGrade[p->group]) groupRank[p->group] = tmp[p->group];
        printf("%013lld %d %d %d\n", p->id, rank, p->group, groupRank[p->group]);
        preGrade[0] = p->grade;
        preGrade[p->group] = p->grade;
    }
}

int main(){
    int n;
    cin >> n;
    int total = 0;
    for(int i=1;i<=n;i++){
        int m;
        cin >> m;
        tmp.clear();
        for(int j=0;j<m;j++){
            total++;
            Record* e = new Record();
            cin >> e->id >> e->grade;
            e->group = i;
            tmp.push_back(e);
        }
        sort(tmp.begin(),tmp.end(),cmp);
        v.insert(v.end(),tmp.begin(),tmp.end());
    }
    sort(v.begin(),v.end(),cmp);
    cout << total << endl;
    print(n);
    return 0;
}