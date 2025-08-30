#include<bits/stdc++.h>
#define ll long long
using namespace std;

const float tolerance = 1e-6;

double f(double x) {
    return pow(x, 5) - 3 * x + 5;
}
double f_deri(double x) {
    return 5 * pow(x, 4) - 3;
}

void newtonRaphson(double x0) {
    cout << "Iteration"<<" " << "f(x)" <<"  "<<"Error"<<endl;
    double x1, error = 100;
    int i = 0;
    while (error > tolerance) {
        double fx = f(x0);
        double fpx = f_deri(x0);
        if (fpx == 0) {
            cout << "Derivative is zero. Method fails." << endl;
        return;
        }
        x1 = x0 - fx / fpx;
        if (i != 0)
            error = fabs((x1 - x0) / x1);
        else
            error = 100;
        cout << i << " " << x0 << " " << fx << " " << error << endl;
        x0 = x1;
        i++;
    }
    cout << "Root : "<< x1 << endl;
}

int main(){
    double x0;
    cin>>x0;
    newtonRaphson(x0);

}