#include <bits/stdc++.h>
using namespace std;

// Function to compute Lagrange interpolation at a given value
double lagrangeInterpolation(double x[], double y[], int n, double value) {
    double result = 0.0;

    for (int i = 0; i < n; i++) {
        double term = y[i]; // start with y[i]
        for (int j = 0; j < n; j++) {
            if (j != i) {
                term *= (value - x[j]) / (x[i] - x[j]);
            }
        }
        result += term;
    }

    return result;
}

// Function to print the Lagrange polynomial in symbolic form (optional)
void printLagrangePolynomial(double x[], double y[], int n) {
    cout << "\nLagrange Interpolation Polynomial P(x) = \n";
    cout << fixed << setprecision(4);
    for (int i = 0; i < n; i++) {
        if (i > 0) cout << " + ";
        cout << y[i] << " * ";
        cout << "(";
        for (int j = 0; j < n; j++) {
            if (j != i) {
                if (j > 0) cout << " * ";
                cout << "(x - " << x[j] << ")";
                cout << " / " << (x[i] - x[j]);
            }
        }
        cout << ")";
    }
    cout << "\n";
}

int main() {
    int n;
    cout << "Enter number of data points: ";
    cin >> n;

    double x[20], y[20];

    cout << "Enter the data points (x y):\n";
    for (int i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
    }

    // Print symbolic polynomial
    printLagrangePolynomial(x, y, n);

    double value;
    cout << "\nEnter value to interpolate: ";
    cin >> value;

    double result = lagrangeInterpolation(x, y, n, value);
    cout << "\nInterpolated value at " << value << " is " << fixed << setprecision(4) << result << endl;

    return 0;
}
