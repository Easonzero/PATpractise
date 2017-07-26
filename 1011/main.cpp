//
// Created by eason on 7/25/17.
//
#include <iostream>

using namespace std;

string toResult = "WTL";

int main(){
    float max[3][2] = {0.0};
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            float odd;
            cin >> odd;
            if(max[i][1]<odd) {
                max[i][0] = j;
                max[i][1] = odd;
            }
        }
    }

    float profitOdd = 0.65;
    for(int i=0;i<3;i++){
        profitOdd *= max[i][1];
        cout << toResult[max[i][0]] << " ";
    }
    printf("%.2f",(profitOdd-1.0)*2);
    return 0;
}