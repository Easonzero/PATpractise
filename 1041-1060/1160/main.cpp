//
// Created by eason on 9/11/17.
//

#include <iostream>

using namespace std;

struct Num{
    string h3b;
    int x;
};

Num toNum(string num,int b){
    int flag = 1,bit=0,in=0;
    int flag2 = 1,first=0,isZero=true;
    Num number;
    for(auto c:num){
        if(c=='.'){
            flag = 0;
            continue;
        }
        if(flag2==1&&c=='0'){
            first++;
        }else if(flag2==1&&c!='0'){
            flag2=0;
        }
        if(flag==1) in++;
        if(flag2==0){
            if(bit<b){
                number.h3b += c;
                if(c-'0'>0) isZero=false;
            }
            bit++;
        }
    }

    for(int i=number.h3b.size();i<b;i++) {
        number.h3b += '0';
    }

    if(isZero){
        number.x = 0;
    }else{
        if(first==0){
            number.x = in;
        }else{
            number.x = in-first;
        }
    }
    return number;
}

int main(){
    int ss;
    string num1,num2;
    cin >> ss;
    cin >> num1 >> num2;
    Num number1 = toNum(num1,ss);
    Num number2 = toNum(num2,ss);
    if(number1.h3b==number2.h3b&&number1.x==number2.x) {
        cout << "YES" << " " << "0.";
        cout << number1.h3b << "*10^" << number1.x << endl;
    }
    else {
        cout << "NO" << " " << "0.";
        cout << number1.h3b << "*10^" << number1.x << " " << "0.";
        cout << number2.h3b << "*10^" << number2.x << endl;
    }
    return 0;
}