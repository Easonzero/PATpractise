//
// Created by eason on 7/24/17.
//

#include <iostream>

using namespace std;

long long cvtDec(const string &src,const long long radix){
    long long result = 0;
    unsigned long len = src.size();
    for(int i=0;i<len;i++){
        long long bit_num = src[i]>='a'?src[i]-'a'+10:src[i]-'0';
        if(bit_num >= radix) return -1;
        result = result*radix + bit_num;
    }
    return result;
}

long long rdx(const long long dst, const string &src){
    long long radix,start=2,end=dst>2?dst+1:3;
    long long cvtResult = 0;
    while(start<=end){
        radix = (start + end)/2;
        cvtResult = cvtDec(src,radix);
        if(cvtResult==dst) return radix;
        if(cvtResult<dst&&cvtResult>-1.1) start = radix+1;
        else if(cvtResult>dst||cvtResult<0) end = radix-1;
    }

    return 0;
}

int main() {
    string num1,num2;
    int tag,radix;
    long long result;
    cin >> num1 >> num2 >> tag >> radix;
    if(tag==1){
        long long decnum = cvtDec(num1,radix);
        result = rdx(decnum,num2);
    }else if(tag==2){
        long long decnum = cvtDec(num2,radix);
        result = rdx(decnum,num1);
    }

    if(result==0) cout << "Impossible";
    else cout << result;

    return 0;
}