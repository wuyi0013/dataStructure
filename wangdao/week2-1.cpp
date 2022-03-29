#include<iostream>
using namespace std;

int main() {

    int x;

	cin >> x;
/*
    if(a%4==0)
    {
        if(a%400==0)
        cout<<"是闰年"<<endl;
        else
        {
             if(a%100==0)
                cout<<"不是闰年"<<endl;
            else
                cout<<"是闰年"<<endl;
        }
       
    }
    else
    {
        cout<<"不是闰年"<<endl;    
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
    cout<<"是闰年"<<endl;
else
    cout<<"不是闰年"<<endl;
*/

