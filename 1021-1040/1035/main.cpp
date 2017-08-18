//
// Created by eason on 8/17/17.
//

#include <iostream>
#include <vector>

using namespace std;

struct User{
    string uid;
    string pwd;
};

vector<User*> v;

int main(){
    int n;
    cin >> n;
    for(int i=0;i<n;i++){
        User* user = new User;
        cin >> user->uid >> user->pwd;
        bool flag = false;
        for(int i=0;i<user->pwd.size();i++){
            char c = user->pwd[i];
            switch(c){
                case '1':
                    flag = true;
                    user->pwd[i]='@';
                    break;
                case 'l':
                    flag = true;
                    user->pwd[i]='L';
                    break;
                case '0':
                    flag = true;
                    user->pwd[i]='%';
                    break;
                case 'O':
                    flag = true;
                    user->pwd[i]='o';
                    break;
            }
        }
        if(flag) v.push_back(user);
    }
    if(v.size()==0&&n==1) printf("There is 1 account and no account is modified");
    else if(v.size()==0) printf("There are %d accounts and no account is modified",n);
    else{
        cout << v.size() << endl;
        for(auto i:v){
            cout << i->uid << " " << i->pwd << endl;
        }
    }
    return 0;
}