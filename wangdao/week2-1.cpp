#include<iostream>
using namespace std;

int main() {

    int x;

	cin >> x;
/*
    if(a%4==0)
    {
        if(a%400==0)
        cout<<"������"<<endl;
        else
        {
             if(a%100==0)
                cout<<"��������"<<endl;
            else
                cout<<"������"<<endl;
        }
       
    }
    else
    {
        cout<<"��������"<<endl;    
    }
*/
if(x % 4 == 0 && x % 100 != 0 || x % 400 == 0)
    cout<<"yes"<<endl;
else
    cout<<"no"<<endl;
	return 0;
}




/*
if(year % 4 == 0 && year % 100 != 0 || year % 400 == 0)
    cout<<"������"<<endl;
else
    cout<<"��������"<<endl;
*/

