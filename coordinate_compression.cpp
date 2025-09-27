#include <bits/stdc++.h>
using namespace std;

class Coordinate_Compression
{
public:
    unordered_map<int, int> compress; // original value -> compressed value
    vector<int> rev_map;              // compressed value -> original value

    // ------------------------------
    // Constructor: coordinate compression
    // ------------------------------
    Coordinate_Compression(const vector<int> &arr)
    {
        set<int> st(arr.begin(), arr.end()); // unique & sorted elements
        int id = 0;
        for (int x : st)
        {
            compress[x] = id;     // map original -> compressed
            rev_map.push_back(x); // reverse map
            id++;
        }
    }

    // ------------------------------
    // Get compressed array
    // ------------------------------
    vector<int> get_compressed(const vector<int> &arr)
    {
        vector<int> res(arr.size());
        for (int i = 0; i < arr.size(); i++)
            res[i] = compress[arr[i]]; // replace with compressed value
        return res;
    }

    // ------------------------------
    // Get original value from compressed value
    // ------------------------------
    int get_original(int val)
    {
        return rev_map[val];
    }
};

// ============================
// Example Usage
// ============================
int main()
{
    // Original array
    vector<int> arr = {100, 500, 1000, 500, 200, 1000, 300};

    // ✅ Step 1: Create coordinate compression object
    Coordinate_Compression cc(arr);

    // ✅ Step 2: Get compressed array
    vector<int> compressed = cc.get_compressed(arr);

    cout << "Original Array: ";
    for (int x : arr)
        cout << x << " ";
    cout << "\n";

    cout << "Compressed Array: ";
    for (int x : compressed)
        cout << x << " ";
    cout << "\n";

    // ✅ Step 3: Reverse mapping example
    cout << "Original of compressed[2] (" << compressed[2] << "): "
         << cc.get_original(compressed[2]) << "\n";

    // ✅ Step 4: Show all compressed -> original mapping
    cout << "Compressed -> Original mapping:\n";
    for (int i = 0; i < cc.rev_map.size(); i++)
    {
        cout << i << " -> " << cc.get_original(i) << "\n";
    }

    return 0;
}
