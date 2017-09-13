//
// Created by eason on 9/13/17.
//

#include <iostream>

using namespace std;

int statistics[100],tmp[100];

int main(){
    int k;
    cin >> k;
    string str,ori;
    cin >> str;
    int pre = -1;
    for(int i=0;i<str.length();i++){
        char c = str[i];
        int index;
        if(c=='_') index = 99;
        else index = c>='a'?c-'a'+10:c-'0';
        if(pre==index&&tmp[pre]<k){
            tmp[index]++;
        }else if(pre!=-1){
            if(tmp[pre]==k&&statistics[pre]!=-1){
                statistics[pre] = 1;
            }else{
                statistics[pre] = -1;
            }
            tmp[pre]=0;
            tmp[index]=1;
        }else{
            tmp[index]=1;
        }
        pre = index;

        if(i==str.length()-1){
            if(tmp[index]==k&&statistics[index]!=-1){
                statistics[index] = 1;
            }else{
                statistics[index] = -1;
            }
        }
    }
    fill(tmp,tmp+100,0);
    for(int i=0;i<str.length();i++){
        char c = str[i];
        ori+=c;
        int index;
        if(c=='_') index = 99;
        else index = c>='a'?c-'a'+10:c-'0';
        if(statistics[index]==1){
            i+=k-1;
            if(tmp[index]==0) {
                cout << c;
                tmp[index]=1;
            }
        }
    }
    cout << endl;
    cout << ori << endl;
    return 0;
}