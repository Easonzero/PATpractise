//
// Created by eason on 9/13/17.
//

#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

float numbers[110];

bool check(string num){
    int i = 0,fb = 0;
    bool flag = false;
    for(auto c:num){
        if(c=='-'&&i==0) continue;
        if(c=='.'&&!flag){
            flag = true;
            continue;
        }
        if(c-'0'<0||c-'0'>9) return false;
        if(flag) fb++;
        if(fb>2) return false;
        i++;
    }
    return true;
}

float toFloat(string num){
    stringstream ss(num);
    float r;
    ss >> r;
    return r;
}

vector<string> error;
vector<float> success;

int main(){
    int n;
    cin >> n;
    for(int i=0;i<n;i++){
        string str;
        cin >> str;
        if(check(str)){
            float f = toFloat(str);
            if(f>1000||f<-1000) error.push_back(str);
            else success.push_back(toFloat(str));
        }
        else
            error.push_back(str);
    }

    for(auto str : error){
        cout << "ERROR: " << str <<  " is not a legal number" << endl;
    }

    if(success.size()==0){
        cout << "The average of 0 numbers is Undefined";
    }else{
        float average = 0;
        for(auto f : success){
            average += f;
        }

        average /= success.size();

        if(success.size()==1) printf("The average of %d number is %.2f",success.size(),average);
        else printf("The average of %d numbers is %.2f",success.size(),average);
    }

    return 0;
}