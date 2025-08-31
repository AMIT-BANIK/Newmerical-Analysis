#include<bits/stdc++.h>
using namespace std;

int Polynomial(float x,float x0,float x1,float x2,float y0,float y1,float y2,float trueValue){
    float f01=((y1-y0)/(x1-x0));
    float f02=((y2-y1)/(x2-x1));
    float f012=((f01-f02)/(x2-x0));
    float f2x=y0+(f01*(x-x0))+(f012*(x-x0)*(x-x1));

    float Et=((trueValue-f2x)/trueValue)*100;
    cout<<"True percent relative error :"<<Et<<endl;
    return f2x;
}

int main(){
   float x,x0,x1,x2,y0,y1,y2,trueValue;
   cin>>x>>x0>>x1>>y0>>y1>>trueValue;
   cout<<Polynomial(x,x0,x1,x2,y0,y1,y2,trueValue)<<endl;
}