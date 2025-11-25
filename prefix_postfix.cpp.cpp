#include<iostream>
using namespace std;
int main()
{
    int x;
    //enter x value
    cout<<"Enter value of x ";
    cin>>x;
    // prefix increment 
    cout<<"Original value of x is: "<<x<<endl;
    cout<<"After prefix value of x: "<<++x<<endl;
    //prefix decrement
    cout<<"After decrement of prefix is: "<<--x<<endl;
    // postfix increment 
    cout<<"Original value of x is: "<<x<<endl;
    cout<<"After prefix value of x: "<<x++<<endl;
    //postfix decrement
    cout<<"After decrement of prefix is: "<<x--<<endl;
    // Rational operator
    cout<<"\n Rational operator "<<endl;
    if (x>10)
    cout<<"x is greater than 10 "<<endl;
    else if(x==10)
    cout<<"x is equal than 10"<<endl;
    else
    cout <<"x is les than 10"<<endl;
    return 0;
}