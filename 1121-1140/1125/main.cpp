//
// Created by eason on 9/8/17.
//

#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    int n;
    cin >> n;
    int array[n];
    for(int i=0;i<n;i++){
        cin >> array[i];
    }

    sort(array,array+n);
    int size = (array[0]+array[1])/2;
    for(int i=2;i<n;i++){
        size = (array[i]+size)/2;
    }
    cout << size;
}