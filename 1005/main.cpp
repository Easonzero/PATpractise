//
// Created by eason on 7/21/17.
//

#include <iostream>
#include <stack>

using namespace std;

string tostr[10] = {"zero","one","two","three","four","five","six","seven","eight","nine"};

int main() {
    string s;
    cin >> s;

    int sum = 0;
    for(int i=0;i<s.length();i++){
        sum+=s.at(i)-'0';
    }
    stack<string> stack1;
    stack1.push(tostr[sum%10]);
    sum /= 10;
    while(sum>0){
        stack1.push(tostr[sum%10]);
        sum /= 10;
    }
    while(!stack1.empty()){
        cout << stack1.top();
        stack1.pop();
        if(!stack1.empty()) cout << " ";
    }
    return 0;
}
