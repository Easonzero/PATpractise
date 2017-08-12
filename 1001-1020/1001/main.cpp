//
// Created by eason on 7/17/17.
//

#include <iostream>
using namespace std;

int main() {
    int a,b;
    cin >> a >> b;
    string s = to_string(a + b);
    int len = s.length();
    for(int i=0;i<len;i++){
        if (i != 0 && s[i-1] != '-' && (len-i)%3==0)
            cout << ",";
        cout << s[i];
    }
    return 0;
}