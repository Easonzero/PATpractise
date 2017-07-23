//
// Created by eason on 7/23/17.
//

#include <iostream>
using namespace std;

int main() {
    int a,now = 0,time = 0;

    cin >> a;
    while(cin >> a){
        if(a>now)
            time += 6*(a - now);
        else if(a < now)
            time += 4*(now - a);

        now = a;
        time += 5;
    }

    cout << time;

    return 0;
}
