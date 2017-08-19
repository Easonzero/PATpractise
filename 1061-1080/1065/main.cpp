//
// Created by eason on 8/19/17.
//

#include <iostream>

using namespace std;

int main() {
    long long t,a,b,c;
    cin >> t;
    for(long long i= 1;i<=t;i++){
        cin >> a >> b >> c;
        long long sum = a+b;
        if(a>0&&b>0&&sum<0) cout << "Case #" << i << ": true" << endl;
        else if(a<0&&b<0&&a+b>=0) cout << "Case # << " << i << ": false" << endl;
        else if(sum>c) cout << "Case #" << i << ": true" << endl;
        else cout << "Case #" << i << ": false" << endl;
    }
    return 0;
}