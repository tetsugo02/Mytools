#include <iostream>

using namespace std;
//define the "student" class
class student
{
protected:
    string name;
    int Num;
    int Age;

public:
    student();
    student(string name, int Num, int Age);
    void setName(string na);//change the name
    void setNum(int n);//change the ID
    void setAge(int n);//change the Age
    void show();
};

student::student()
{
    cout << "One student has been written." << endl;
}
student::student(string na, int Nu, int Ag)
{
    name = na;
    Num = Nu;
    Age = Ag;
}
void student::setName(string na)
{
    name = na;
}

void student::setNum(int n)
{
    Num = n;
}

void student::setAge(int n)
{
    Age = n;
}

void student::show()
{
    cout<<name<<" age:"<<Age<<" ID: "<<Num<<endl;
}
int main()
{
    student person[10];

}