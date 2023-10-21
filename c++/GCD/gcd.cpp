#include <iostream>
using namespace std;

int main()
{
    int a,b;
    cin>>a>>b;
    int c;
    while (c!=0)
    {
        if (a>=b)
        {
            c=a%b;
            a=b;
            b=c;
        }
        else
        {
            c=b%a;
            b=a;
            a=c;
        }
        
    }
    cout<<max(a,b)<<endl;
    
    

}