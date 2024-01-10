#include <iostream>
#include <iomanip>
#include "Subjects.h"
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

int main()
{   

    while(1)
    {   
        cout<<"-----------------------------------"<<endl;
        cout<< "1. Create a subject"<<endl;
        cout<< "2. Show the GPA"<<endl;
        cout<< "3. Exit"<<endl;
        cout<<"-----------------------------------"<<endl;
        int choice;
        cin>>choice;
        //新しい授業を作成する
        if(choice==1)
        {
            cout<<"-----------------------------------"<<endl;
            Subject subject1;
            string name,teacher,grade;
            cout<<"Enter the subject name: ";
            cin>>name;
            cout<<"Enter the subject teacher: ";
            cin>>teacher;
            cout<<"Enter the subject grade: ";
            cin>>grade;
            cout<<"-----------------------------------"<<endl;
            subject1.setName(name);
            subject1.setTeacher(teacher);

            //成績がエラーかどうかを確認する
            int grade_point=grade_caculate(grade);
            if(grade_point==-1)
            {
                cout<<"The grade you entered is not correct"<<endl;
                return 0;
            }
            else
            {
                subject1.setGrade(grade);
            }
            
            //データが正しいかどうかを確認する
            cout<<"The data you entered is correct? (y/n)"<<endl;
            subject1.showGrade();
            cout<<"-----------------------------------"<<endl;
            char confirm;
            cin>>confirm;
            cout<<"-----------------------------------"<<endl;

            
            
            if(confirm=='y'&&grade_point!=-1)
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
        //GPAを計算して表示する
        else if (choice==2)
        {   
            cout<<"-----------------------------------"<<endl;
            cout<<"GPA: "<<endl;
            ifstream csvFile("Grades.csv"); // ファイルを読み込みモードで開く
            int targetColumn = 2; // 3列目を取得する
            vector<string> targetData; 
            string line; // ファイルから読み込んだ1行のデータを格納する変数

            if (csvFile.fail()) 
            {
                cerr << "Error: file not opened." << endl;
                return -1;
            }
            while (getline(csvFile, line)) 
            {
                stringstream ss(line);
                string data; // 1列分のデータを格納する変数
                int column = 0; // 列番号をカウントする変数
                while (getline(ss, data, ',')) 
                {
                    if (column == targetColumn) 
                    {
                        targetData.push_back(data); // 3列目のデータを取得
                    }
                    column++;
                }
            }
            csvFile.close(); // ファイルを閉じる

            //GPAを計算する
            double sum=0.00;
            for(int i=0; i<targetData.size();i++)
            {
                sum+=stod(targetData.at(i));
            }
            cout<<fixed<<setprecision(2)<<sum/targetData.size()<<endl;//小数点以下2桁まで表示する
            cout<<"-----------------------------------"<<endl;

        }
        //プログラムを終了する
        else if(choice==3)
        {
            cout<<"-----------------------------------"<<endl;
            cout<<"Program terminated"<<endl;
            cout<<"-----------------------------------"<<endl;
            break;
        }
    }
    
}



