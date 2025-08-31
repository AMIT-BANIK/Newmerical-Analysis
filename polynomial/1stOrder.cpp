#include<bits/stdc++.h>
using namespace std;

int Polynomial(float x,float x0,float x1,float y0,float y1){
    float f01=((y1-y0)/(x1-x0));
    float f1x=y0+(f01*(x-x0));
    return f1x;
}

int main(){
   float x,x0,x1,y0,y1;
   cin>>x>>x0>>x1>>y0>>y1;
   cout<<Polynomial(x,x0,x1,y0,y1)<<endl;
}