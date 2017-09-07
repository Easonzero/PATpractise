//
// Created by eason on 9/7/17.
//

#include <iostream>
#include <set>

using namespace std;

struct Data{
    int key = -1;
    int value = 1;
    bool operator < (const Data& data) const{
        return (value != data.value) ? value > data.value : key < data.key;
    }
};

set<Data> s;

int main(){
    int n,m;
    cin >> n >> m;
    int book[n+1];
    fill(book,book+n+1,1);
    for(int i=0;i<n;i++){
        Data data;
        cin >> data.key;
        data.value = book[data.key];

        if(i!=0){
            int num=0;
            cout << data.key << ":";
            for(auto c:s){
                if(num>=m) break;
                num++;
                cout << " " << c.key;
            }
            cout << endl;
        }

        auto itr = s.find(data);
        if(itr!=s.end()){
            data.value++;
            book[data.key]++;
            s.erase(itr);
        }
        s.insert(data);
    }
    return 0;
}