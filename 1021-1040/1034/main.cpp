//
// Created by eason on 8/16/17.
//

#include <iostream>
#include <map>
#include <stack>

using namespace std;

map<string,map<string,int>> data;

void dps(int k){
    map<string,bool> visit;
    map<string,int> result;

    for(auto i:data){
        visit[i.first] = false;
    }

    for(auto i:visit){
        if(!i.second){
            stack<string> s;
            s.push(i.first);
            string head;
            int max=0,total=0,totalTime=0;
            while(!s.empty()){
                string name;
                name = s.top();
                s.pop();

                if(visit[name]) continue;

                int time = 0;
                visit[name] = true;
                for(auto j:data[name]){
                        s.push(j.first);
                    time += j.second;
                }
                if(time > max) {
                    max = time;
                    head = name;
                }
                total++;
                totalTime+=time;
            }
            if(totalTime/2>k&&total>2)
                result[head] = total;
        }
    }

    unsigned long size = result.size();
    cout << size << endl;

    if(size > 0)
        for(auto i:result)
            cout << i.first << " " << i.second << endl;
}

int main(){
    int n,k;
    cin >> n >> k;
    for(int i=0;i<n;i++){
        string name,key;
        int value;
        cin >> name >> key >> value;
        if(data.count(name)==0) data[name] = map<string,int>();
        if(data.count(key)==0) data[key] = map<string,int>();
        data[name][key] += value;
        data[key][name] += value;
    }

    dps(k);

    return 0;
}