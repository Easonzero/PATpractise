//
// Created by eason on 8/3/17.
//

#include <iostream>
#include <vector>

using namespace std;
vector<int> array;

void decTo(int src,int radix){
    while(src!=0){
        array.push_back(src%radix);
        src /= radix;
    }
}

string checkPalindromic(){
    unsigned long len = array.size();
    for(int i=0;i<len/2;i++){
        if(array[i]!=array[len-i-1])
            return "No";
    }
    return "Yes";
}

int main(){
    int n,b;
    cin >> n >> b;
    decTo(n,b);
    cout << checkPalindromic() << endl;

    if(array.size()==0) cout << 0;
    else
        for(int i=array.size()-1;i>=0;i--){
            cout << array[i];
            if(i!=0) cout << " ";
        }
    return 0;
}