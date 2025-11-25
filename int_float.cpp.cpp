#include <iostream>
using namespace std;
int main()
{
    // declare int , float
    int num1 , num2;
    float num3;
    cout<<"Enter first integer: "<<endl;
    cin>>num1;
    cout<<"Enter second interger: ";
    cin>>num2;
    cout<<"Enter a floating point: "<<endl;
    cout<<"Enter Floating point : "<<endl;
    cin>>num3;
    // Arthimetic expression
    cout<<"/n Arthimetic expression"<<endl;
    cout<<"Sum of value "<< num1+num2+num3<<endl;
    cout<<"Sutraction of value "<< num1-num2-num3<<endl;
    cout<<"Mutiplication of value "<< num1*num2*num3<<endl;
    cout<<"Division of value "<< num1/num2<<endl;
    cout<<"Modulus of value " <<num1/num3<<endl;
    //float division
    cout<<"Division of  float value "<<num1/num3<<endl;
    cout<<"Modulus of  float value "<<num1/num3<<endl;
    // Expression of opertor precedence
    float result = (num1+num2)*num3-num2/2.0; 
    cout<<"\nExpression result ((num1+num2)*num3-num2/2.0) is "<<result;

    return 0;
}