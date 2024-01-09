#include <iostream>
#include "Subjects.h"
#include <fstream>
using namespace std;

int main()
{   
    cout<< "1. Create a subject"<<endl;
    cout<< "2. Show the GPA"<<endl;

    int choice;
    cin>>choice;
    //新しい授業を作成する
    if(choice==1)
    {
        Subject subject1;
        string name,teacher,grade;
        cout<<"Enter the subject name: ";
        cin>>name;
        cout<<"Enter the subject teacher: ";
        cin>>teacher;
        cout<<"Enter the subject grade: ";
        cin>>grade;
        subject1.setName(name);
        subject1.setTeacher(teacher);

        //成績がエラーかどうかを確認する
        if(grade_caculate(grade)==-1)
        {
            cout<<"The grade you entered is not correct"<<endl;
            return 0;
        }
        else
        {
            subject1.setGrade(grade);
        }
        subject1.setGrade(grade);

        //データが正しいかどうかを確認する
        cout<<"The data you entered is correct? (y/n)"<<endl;
        subject1.showGrade();
        char confirm;
        cin>>confirm;

        
        
        if(confirm=='y')
        {   
            ofstream csvFile("Grades.csv", ios::app); // ファイルを追記モードで開く
            cout<<"Data saved"<<endl;
            csvFile << name << "," << teacher << "," <<grade_caculate(grade)-1<< std::endl; // ファイルに書き込む
            csvFile.close(); // ファイルを閉じる
        }
        else
        {
            cout<<"Data not saved"<<endl;
        }
        
    }
}



