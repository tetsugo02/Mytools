
#ifndef SUBJECT_H
#define SUBJECT_H
#include <string>
#include <iostream>
using namespace std;

//creat class subject to sore imoformation
class Subject{
    public:
        Subject();
        Subject(string name,string teacher ,int grade);
        void setName(string name_set);
        void setTeacher(string teacher_set);
        void setGrade(int grade_set);
    protected:
        string name;
        string teacher;
        int grade;
};

Subject::Subject()
{
    cout<<"Subject created"<<endl;
}
Subject::Subject(string name,string teacher ,int grade)
{
    this->name=name;
    this->teacher=teacher;
    this->grade=grade;
}
//授業の名前、先生、成績を設定する
void Subject::setName(string name_set)
{
    name=name_set;
}
void Subject::setTeacher(string teacher_set)
{
    teacher=teacher_set;
}
void Subject::setGrade(int grade_set)
{
    grade=grade_set;
}


#endif // SUBJECT_H