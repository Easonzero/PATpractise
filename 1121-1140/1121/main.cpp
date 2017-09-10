//
// Created by eason on 9/10/17.
//

#include <iostream>
#include <map>
#include <set>

using namespace std;

map<int,int> couple;
set<int> result;

int main(){
    int n,m;
    cin >> n;
    for(int i=0;i<n;i++){
        int f,m;
        cin >> f >> m;
        couple[f] = m;
        couple[m] = f;
    }

    cin >> m;
    for(int i=0;i<m;i++){
        int guest;
        cin >> guest;
        if(couple.count(guest)==0) result.insert(guest);
        else{
            if(result.count(couple[guest])==0) result.insert(guest);
            else{
                auto itr = result.find(couple[guest]);
                result.erase(itr);
            }
        }
    }

    cout << result.size() << endl;

    int k=1;
    for(auto i:result){
        printf("%05d",i);
        if(k<*result.end()) cout << " ";
        k++;
    }
    return 0;
}