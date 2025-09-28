// Newton Raphson Method to find sqaure root of a number
#include <bits/stdc++.h>
using namespace std;

double sqrt_newton(double n)
{
    const double eps = 1E-15; // precision
    double x = 1;             // initial guess
    for (;;)
    {
        double nx = (x + n / x) / 2; // Newton iteration
        if (abs(x - nx) < eps)
            break; // stop when change is very small
        x = nx;
    }
    return x;
}

int main()
{
    double n = 10.0;
    cout << fixed << setprecision(15); // show 15 digits after decimal
    cout << "Square root of " << n << " = " << sqrt_newton(n) << "\n";
    return 0;
}
