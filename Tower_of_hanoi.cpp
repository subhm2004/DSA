#include <iostream>
#include <cmath>  // for pow
using namespace std;

class Solution {
public:
    // Function to implement Tower of Hanoi
    long long Tower_of_hanoi(int n, int from, int to, int aux) {
        if (n == 1) {
            cout << "move disk " << n << " from rod " << from << " to rod " << to << endl;
            return 1;
        }

        long long count = 0;
        count += Tower_of_hanoi(n - 1, from, aux, to);
        cout << "move disk " << n << " from rod " << from << " to rod " << to << endl;
        count++;
        count += Tower_of_hanoi(n - 1, aux, to, from);

        return count;
    }
};

int main() {
    int N;
    cout << "Enter number of disks: ";
    cin >> N;

    Solution obj;
    long long totalMoves = obj.Tower_of_hanoi(N, 1, 3, 2);
    
    // Expected total moves using formula: 2^n - 1
    long long expectedMoves = pow(2, N) - 1;

    cout << "Total moves (by function): " << totalMoves << endl;
    cout << "Expected moves (2^" << N << " - 1): " << expectedMoves << endl;

    return 0;
}
