//
// Created by eason on 8/13/17.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX = 99999;

struct Station{
    float distance;
    float price;
};

bool cmp(Station* s1,Station* s2){
    return s1->distance < s2->distance;
}

vector<Station*> v;

int main(){
    int c,d,n;
    float avg;
    cin >> c >> d >> avg >> n;

    for(int i=0;i<n;i++){
        auto station = new Station();
        cin >> station->price >> station->distance;
        v.push_back(station);
    }

    sort(v.begin(),v.end(),cmp);

    if(v[0]->distance!=0){
        printf("The maximum travel distance = 0.00");
        return 0;
    }

    float reach=0,preprice=0,total=0,min = MAX,ctmp=c,cmin=MAX;
    for(auto station:v){
        float dt = station->distance-reach;
        if(station->price<=preprice||station->distance==0) {
            if (dt <= ctmp * avg) {
                total += dt*preprice/avg;
            }else{
                total += ctmp*preprice+(dt-ctmp*avg)*min/avg;
            }
            reach = station->distance;
            preprice = station->price;
            min = MAX;
            ctmp = c;
        }else if(dt > ctmp*avg&&min!=MAX){
            total += ctmp*preprice;
            reach += ctmp*avg;
            if(min < station->price){
                preprice = min;
                ctmp = cmin;
                min = station->price;
                cmin = c-ctmp+(station->distance-reach)/avg;
            }else{
                total += (dt-ctmp*avg)*min/avg;
                reach = station->distance;
                preprice = station->price;
                min = MAX;
                ctmp = c;
            }
        }else if(dt > ctmp*avg&&min==MAX){
            printf("The maximum travel distance = %.2f",reach+ctmp*avg);
        }else{
            if(station->price < min) {
                min = station->price;
                cmin = (station->distance-reach)/avg;
            }
        }
    }
    float dt = d-reach;
    if(dt>ctmp*avg&&min==MAX){
        printf("The maximum travel distance = %.2f",reach+ctmp*avg);
    }else{
        if(dt<=ctmp*avg){
            total += dt*preprice/avg;
        }else{
            total += ctmp*preprice + (dt-ctmp*avg)*min;
        }
        printf("%.2f",total);
    }
    return 0;
}