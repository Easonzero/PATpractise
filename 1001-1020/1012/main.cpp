//
// Created by eason on 7/25/17.
//

#include <iostream>

using namespace std;

string toCategory = "CMEA";

struct Student{
    int id;
    int grade[4];
    Student *left = nullptr;
    Student *right = nullptr;
};

int order[4][101]={0};
Student* head = nullptr;

void addStudent(Student* &head,Student* student){
    if(head == nullptr){
        head = student;
        return;
    }

    Student* p = head;
    while(true){
        if(student->id<p->id) {
            if(p->left== nullptr){
                p->left = student;
                break;
            }
            p = p->left;
        }
        else if(student->id>p->id) {
            if(p->right== nullptr){
                p->right = student;
                break;
            }
            p = p->right;
        }
    }
}

Student* findStudent(Student* head,int id){
    if(head== nullptr) return nullptr;

    if(id<head->id) findStudent(head->left,id);
    else if(id>head->id) findStudent(head->right,id);
    else return head;
}

int main(){
    int n,m;
    cin >> n >> m;
    for(int i=0;i<n;i++){
        int id,grade[4];
        cin >> id >> grade[0] >> grade[1] >> grade[2];
        grade[3] = (grade[0]+grade[1]+grade[2])/3;
        Student* student = new Student();
        student->id = id;
        for(int j=0;j<4;j++){
            student->grade[j]=grade[j];
            for(int i=0;i<grade[j];i++){
                order[j][i]++;
            }
        }
        addStudent(head,student);
    }

    for(int i=0;i<m;i++){
        int id;
        cin >> id;
        Student* student = findStudent(head,id);
        if(student == nullptr) cout << "N/A" << endl;
        else {
            int best = 2010,category = 0;
            for(int j=0;j<4;j++){
                int rank = order[j][student->grade[j]]+1;
                if(rank<best) {
                    best = rank;
                    category = j;
                }else if(rank==best&&
                         (j==3||j<category))
                    category = j;
            }
            cout << best << " " << toCategory[category] << endl;
        }
    }
    return 0;
}