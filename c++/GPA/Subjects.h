
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

int grade_caculate(string grade)
{
    //成績を計算する
    if(grade=="S"||"s")
    {
        return 5;
    }
    else if(grade=="A"||"a")
    {
        return 4;
    }
    else if(grade=="B"||"b")
    {
        return 3;
    }
    else if(grade=="C"||"c")
    {
        return 2;
    }
    else if(grade=="D"||"d")
    {
        return 1;
    }
    else
    {
        return -1;
    }
}


#endif // SUBJECT_H