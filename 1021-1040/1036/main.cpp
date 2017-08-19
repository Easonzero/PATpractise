//
// Created by eason on 8/18/17.
//

#include <iostream>

using namespace std;

struct Student{
    string name;
    char gender;
    string id;
    int grade;
};

int main(){
    int n;
    cin >> n;
    Student* male = nullptr,*female = nullptr;
    for(int i=0;i<n;i++){
        Student* student = new Student;
        cin >> student->name >> student->gender >> student->id >> student->grade;
        if(student->gender=='F'){
            if(female==nullptr||female->grade<student->grade){
                female = student;
                continue;
            }
        }else if(student->gender=='M'){
            if(male==nullptr||male->grade>student->grade){
                male = student;
                continue;
            }
        }
    }
    if(female==nullptr) cout << "Absent" << endl;
    else cout << female->name << " " << female->id << endl;
    if(male==nullptr) cout << "Absent" << endl;
    else cout << male->name << " " << male->id << endl;
    if(female==nullptr||male==nullptr) cout << "NA" << endl;
    else cout << female->grade-male->grade << endl;
    return 0;
}