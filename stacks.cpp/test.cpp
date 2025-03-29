// #include <iostream>
// #include <vector>
// #include <chrono>
// using namespace std;
// using namespace std::chrono;
// typedef long long int S;

// int main() {
//     S n;
//     cout << "Enter the upper limit (n): ";
//     cin >> n;

//     // Start measuring time
//     auto start = high_resolution_clock::now();

//     // Initialize a boolean vector to mark whether each number is prime or not
//     vector<bool> is_prime(n, true);
//     is_prime[0] = is_prime[1] = false;

//     // Sieve of Eratosthenes algorithm to mark primes and composites
//     for (S i = 2; i * i < n; i++) {
//         if (is_prime[i]) {
//             for (S j = i * i; j < n; j += i)
//                 is_prime[j] = false;
//         }
//     }

//     // Print prime numbers
//     cout << "Prime numbers up to " << n << " are:\n";
//     for (S i = 2; i < n; i++) {
//         if (is_prime[i])
//             cout << i << " ";
//     }
//     cout << endl;

//     // Stop measuring time
//     auto stop = high_resolution_clock::now();

//     // Calculate the runtime
//     auto duration = duration_cast<milliseconds>(stop - start);

//     // Print the runtime
//     cout << "Execution time: " << duration.count() << " milliseconds" << endl;

//     return 0;
// }

#include<iostream>
using namespace std;
int main(){
    int a= 0647;
    cout<< a << endl;
    return 0;
}