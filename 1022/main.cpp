//
// Created by eason on 8/5/17.
//

#include <iostream>
#include <sstream>
#include <map>
#include <set>

using namespace std;

map<string,set<int>> indexes[5];

int main(){
    int n,m;
    cin >> n;
    for(int i=0;i<n;i++){
        int id;
        cin >> id;
        getchar();
        for(int j=0;j<5;j++){
            string key;
            getline(cin,key);
            if(j!=2){
                indexes[j][key].insert(id);
            }else{
                stringstream ss(key);
                string sub_key;
                while(getline(ss,sub_key,' '))
                    indexes[j][sub_key].insert(id);
            }
        }
    }
    cin >> m;
    for(int i=0;i<m;i++){
        int index;
        string key;
        scanf("%d: ",&index);
        getline(cin,key);
        cout << index << ": " << key << endl;
        if(indexes[index-1].find(key)==indexes[index-1].end()) cout << "Not Found" << endl;
        else
            for(auto id:indexes[index-1][key])
                printf("%07d\n", id);
    }
    return 0;
}