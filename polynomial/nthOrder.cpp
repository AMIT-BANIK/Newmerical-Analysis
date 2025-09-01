#include <bits/stdc++.h>
using namespace std;

void dividedDiffTable(float x[], float y[], int n) {
    float table[20][20]; 

    for (int i = 0; i < n; i++) {
        table[i][0] = y[i];
    }

   
    for (int j = 1; j < n; j++) {
        for (int i = 0; i < n - j; i++) {
            table[i][j] = (table[i + 1][j - 1] - table[i][j - 1]) / (x[i + j] - x[i]);
        }
    }

    for (int i = 0; i < n; i++) {
        y[i] = table[0][i];
    }

   
    cout << "\nDivided Difference Table:\n";
    for (int i = 0; i < n; i++) {
        cout << setw(10) << x[i];
        for (int j = 0; j < n - i; j++) {
            cout << setw(12) << fixed << setprecision(4) << table[i][j];
        }
        cout << endl;
    }
}

float applyFormula(float value, float x[], float coef[], int n) {
    float sum = coef[n - 1];
    for (int i = n - 2; i >= 0; i--) {
        sum = sum * (value - x[i]) + coef[i];
    }
    return sum;
}

void printPolynomial(float x[], float coef[], int n) {
    cout << "\nNewton Interpolation Polynomial P(x) = \n";
    cout << fixed << setprecision(4);

    cout << coef[0];
    for (int i = 1; i < n; i++) {
        if (coef[i] >= 0) cout << " + ";
        else cout << " - ";
        cout << fabs(coef[i]);
        for (int j = 0; j < i; j++) {
            cout << "(x - " << x[j] << ")";
        }
    }
    cout << "\n";
}

int main() {
    int n;
    float x[20], y[20], value;
    cin >> n; 
    for (int i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
    }
    dividedDiffTable(x, y, n);

    printPolynomial(x, y, n);

    cin >> value;

    cout << "\nValue at " << value << " is "
         << applyFormula(value, x, y, n) << endl;

    return 0;
}
