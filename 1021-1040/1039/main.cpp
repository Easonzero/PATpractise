//
// Created by eason on 8/20/17.
//

#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

map<string,vector<int>> data;

int main(){
    int n,k;
    cin >> n >> k;
    for(int i=0;i<k;i++){
        int id,m;
        cin >> id >> m;
        for(int j=0;j<m;j++){
            string name;
            cin >> name;
            if(data.count(name)==0) data[name] = vector<int>();
            data[name].push_back(id);
        }
    }
    for(int i=0;i<n;i++){
        string name;
        cin >> name;

        if(data.count(name)==0){
            cout << name << " " << 0 << endl;
            continue;
        }

        cout << name << " " << data[name].size();
        sort(data[name].begin(),data[name].end());
        for(int i=0;i<data[name].size();i++){
            cout << " " << data[name][i];
        }
        cout << endl;
    }
    return 0;
}