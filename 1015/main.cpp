//
// Created by eason on 7/28/17.
//

#include <iostream>
using namespace std;

int reverse(int n,int radix){
    int result=0;
    for(int i=0;n!=0;i++){
        result = result*radix+n%radix;
        n /= radix;
    }
    return result;
}

bool prime(int n){
    if(n <= 1) return false;
    for(unsigned i=2;i<n/2+1;++i){
        if ( 0 == n % i )
            return false;
    }
    return true;
}

int main(){
    int number,radix;
    while(true){
        cin >> number;
        if(number<0) break;
        cin >> radix;
        if(!prime(number)) {
            cout << "No" << endl;
            continue;
        }
        int r = reverse(number,radix);
        if(prime(r)) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
    return 0;
}