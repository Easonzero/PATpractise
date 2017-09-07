//
// Created by eason on 9/5/17.
//

#include <iostream>
#include <vector>

using namespace std;

vector<string> v;

void reverse(char* s,int n){
    for(int i=0;i<n/2;i++){
        char tmp = s[i];
        s[i] = s[n-i-1];
        s[n-i-1] = tmp;
    }
}

int main(){
    int n;
    cin >> n;
    cin.get();
    unsigned long min = 99999;
    for(int i=0;i<n;i++){
        string str;
        getline(cin,str);
        if(str.size()<min) min = str.size();
        v.push_back(str);
    }
    char result[min];
    int len=0;
    bool eq = true;
    for(int i=0;i<min;i++){
        result[i] = v[0][v[0].size()-1-i];
        bool flag = true;
        for(auto str : v){
            if(str[str.size()-1-i]!=result[i]) {flag = false;break;}
        }
        if(!flag){
            eq = false;
            result[i] = '\0';
            len = i;
            break;
        }
    }
    if(eq){
        len = min;
        result[len] = '\0';
    }
    reverse(result,len);
    if(len==0) cout << "nai" << endl;
    else cout << result << endl;
    return 0;
}