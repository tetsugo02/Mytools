
#ifndef SUBJECT_H
#define SUBJECT_H
#include <iostream>
using namespace std;

//creat class subject to sore imoformation
class Subject{
    public:
        Subject();
        Subject(string name,string teacher ,string grade);
        void setName(string name_set);
        void setTeacher(string teacher_set);
        void setGrade(string grade_set);
        void showGrade();
    protected:
        string name;
        string teacher;
        string grade;
};

Subject::Subject()
{
    cout<<"Subject created"<<endl;
}
Subject::Subject(string name,string teacher ,string grade)
{
    this->name=name;
    this->teacher=teacher;
    this->grade=grade;
}
//授業の名前、先生、成績、成績を設定する
void Subject::setName(string name_set)
{
    name=name_set;
}
void Subject::setTeacher(string teacher_set)
{
    teacher=teacher_set;
}
void Subject::setGrade(string grade_set)
{
    grade=grade_set;
}
void Subject::showGrade()
{
    cout<<"Subject name: "<<name<<endl;
    cout<<"Subject teacher: "<<teacher<<endl;
    cout<<"Subject grade: "<<grade<<endl;
}

#endif // SUBJECT_H