#include<iostream>
using namespace std;

// Function to find the integer part of the square root
int sqrt(int n, int s, int e) {
    int ans = -1;
    int mid = s + (e - s) / 2;
    while (s <= e) {
        if (mid * mid == n) {
            return mid;
        } else if (mid * mid > n) {
            e = mid - 1;
        } else {
            ans = mid;
            s = mid + 1;
        }
        mid = s + (e - s) / 2;
    }
    return ans;
}

// Function to find the square root with precision
double sqrtWithPrecision(int n, int precision) {
    int s = 0, e = n;
    int intPart = sqrt(n, s, e);

    double ans = intPart;
    double increment = 0.1;
    for (int i = 0; i < precision; i++) {
        while (ans * ans <= n) {
            ans += increment;
        }
        ans -= increment;
        increment /= 10;
    }

    return ans;
}

int main() {
    int n;
    cout << "Enter any number: ";
    cin >> n;

    int precision;
    cout << "Enter the number of decimal places for precision: ";
    cin >> precision;

    double ans = sqrtWithPrecision(n, precision);
    cout << "Square root of " << n << " is: " << ans << endl;

    return 0;
}
