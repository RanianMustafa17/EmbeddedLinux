#include<iostream>
#include"Calculator.hpp"
using namespace std;
int main()
{
int x ,y ;
cout <<"enter first operand "<<endl;
cin>>x;
cout <<"enter sec operand "<<endl;
cin>>y;

cout <<"addition "<<addFunc(x,y)<<endl;
cout <<"addition "<<subFunc(x,y)<<endl;
cout <<"addition "<<mulFunc(x,y)<<endl;
cout <<"addition "<<divFunc(x,y)<<endl;

return 0;
}
