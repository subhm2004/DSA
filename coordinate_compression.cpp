#include <bits/stdc++.h>
using namespace std;

// ============================================================================
// 🎯 COORDINATE COMPRESSION CLASS
// ============================================================================
// Purpose: Large values ko small indices (0, 1, 2...) mein convert karna
// Example: [1000000, 5, 999999] → [2, 0, 1]
// Benefits: Memory save, faster operations with BIT/Segment Tree
// ============================================================================

class Coordinate_Compression
{
public:
    // -------- Data Members --------
    
    // compress: Original value se compressed ID tak mapping
    // Example: {1000000 → 2, 5 → 0, 999999 → 1}
    unordered_map<int, int> compress;
    
    // rev_map: Compressed ID se original value tak mapping
    // Example: [5, 999999, 1000000]
    //    Index: 0    1       2
    vector<int> rev_map;
    
    
    // -------- Constructor --------
    // Input: Original array of integers
    // Process: Unique values nikalo, sort karo, aur IDs assign karo
    
    Coordinate_Compression(const vector<int> &arr)
    {
        // Step 1: Set use karo to get UNIQUE + SORTED values
        // Set automatically duplicates remove kar deta hai aur sort kar deta hai
        // Example: arr = [100, 50, 100, 50, 1]
        //          st  = {1, 50, 100}  (unique + sorted)
        set<int> st(arr.begin(), arr.end());
        
        // Step 2: Har unique value ko ek compressed ID assign karo (0-based)
        int id = 0;  // Compressed ID counter (starts from 0)
        
        for (int x : st)  // Set mein values already sorted order mein hain
        {
            // Forward mapping: Original value → Compressed ID
            // Example: compress[1] = 0, compress[50] = 1, compress[100] = 2
            compress[x] = id;
            
            // Reverse mapping: Compressed ID → Original value
            // rev_map[0] = 1, rev_map[1] = 50, rev_map[2] = 100
            rev_map.push_back(x);
            
            id++;  // Next ID ke liye increment
        }
        
        // Final state after construction:
        // compress = {1:0, 50:1, 100:2}
        // rev_map  = [1, 50, 100]
    }
    
    
    // -------- Function 1: Get Compressed Array --------
    // Input: Original array (can have duplicates)
    // Output: Compressed array (har value ko uski compressed ID se replace karo)
    // Example: [100, 50, 100] → [2, 1, 2]
    
    vector<int> get_compressed(const vector<int> &arr)
    {
        // Result array banaao (same size as input)
        vector<int> res(arr.size());
        
        // Har element ko compress karo
        for (int i = 0; i < (int)arr.size(); i++)
        {
            // arr[i] = original value
            // compress[arr[i]] = compressed ID
            // Example: arr[i] = 100 → compress[100] = 2
            res[i] = compress[arr[i]];
        }
        
        return res;  // Compressed array return karo
    }
    
    
    // -------- Function 2: Get Original Value --------
    // Input: Compressed ID
    // Output: Original value
    // Example: get_original(2) → 100
    
    int get_original(int val)
    {
        // val = compressed ID (0, 1, 2, ...)
        // rev_map[val] = original value
        // Example: rev_map[2] = 100
        return rev_map[val];
    }
};


// ============================================================================
// 🚀 MAIN FUNCTION - TESTING & DEMONSTRATION
// ============================================================================

int main()
{
    // ========== Test Case Setup ==========
    // Original array with large values and duplicates
    vector<int> arr = {1000, 50, 1000, 200, 50, 1};
    
    cout << "Original Array: ";
    for (int x : arr) cout << x << " ";
    cout << "\n\n";
    
    
    // ========== Step 1: Create Compression Object ==========
    // Constructor automatically:
    // 1. Extracts unique values: {1, 50, 200, 1000}
    // 2. Sorts them (already sorted in set)
    // 3. Assigns IDs: 1→0, 50→1, 200→2, 1000→3
    
    Coordinate_Compression cc(arr);
    
    
    // ========== Step 2: Print Forward Mapping ==========
    // Shows: Original Value → Compressed ID
    
    cout << "📊 Compression Mapping (original -> compressed):\n";
    for (auto [val, id] : cc.compress)
        cout << "   " << val << " → " << id << "\n";
    // Output example:
    //    1 → 0
    //    50 → 1
    //    200 → 2
    //    1000 → 3
    
    
    // ========== Step 3: Print Reverse Mapping ==========
    // Shows: Compressed ID → Original Value
    
    cout << "\n📊 Reverse Mapping (compressed -> original):\n";
    for (int i = 0; i < cc.rev_map.size(); i++)
        cout << "   " << i << " → " << cc.rev_map[i] << "\n";
    // Output example:
    //    0 → 1
    //    1 → 50
    //    2 → 200
    //    3 → 1000
    
    
    // ========== Step 4: Compress the Array ==========
    // Converts: [1000, 50, 1000, 200, 50, 1]
    //       To: [3, 1, 3, 2, 1, 0]
    
    vector<int> compressed = cc.get_compressed(arr);
    
    cout << "\n✅ Compressed Array: ";
    for (int x : compressed) cout << x << " ";
    cout << "\n";
    // Output: 3 1 3 2 1 0
    
    
    // ========== Step 5: Verify - Convert Compressed Back to Original ==========
    // Proves that compression is reversible (no data loss)
    
    cout << "\n🔄 Converting Compressed Back to Original:\n";
    for (int i = 0; i < compressed.size(); i++)
    {
        int comp_val = compressed[i];           // Compressed ID
        int orig_val = cc.get_original(comp_val); // Original value
        
        cout << "   Position " << i << ": "
             << comp_val << " → " << orig_val << "\n";
    }
    // Output example:
    //    Position 0: 3 → 1000
    //    Position 1: 1 → 50
    //    Position 2: 3 → 1000
    //    Position 3: 2 → 200
    //    Position 4: 1 → 50
    //    Position 5: 0 → 1
    
    
    // ========== Step 6: Show Practical Benefit ==========
    // Without compression: BIT size = max(arr) + 1 = 1001 😱
    // With compression: BIT size = unique_count = 4 ✅
    
    cout << "\n🎯 Using with Fenwick Tree:\n";
    
    int K = cc.rev_map.size();  // Count of unique values = 4
    cout << "BIT size needed: " << K << " (instead of 1001!)\n";
    
    // -------- Example Usage with BIT --------
    // Now you can create a small BIT and use compressed IDs:
    
    // Fenwick_Tree bit(K);  // BIT of size 4 (not 1001!)
    
    // for (int comp_id : compressed) {
    //     bit.update(comp_id + 1, 1);  // Insert into BIT (1-indexed)
    // }
    
    // Query example:
    // int count = bit.sum_query(2);  // Count elements with compressed ID <= 1
    //                                // Which are original values: 1, 50
    
    return 0;
}
```

---

## 🎨 **Visual Flow Chart:**
```
Input Array: [1000, 50, 1000, 200, 50, 1]
                    ↓
         ┌──────────────────────┐
         │  Constructor Called  │
         └──────────────────────┘
                    ↓
         ┌──────────────────────┐
         │ Extract Unique Values│
         │    (using set)       │
         └──────────────────────┘
                    ↓
              {1, 50, 200, 1000}  ← Automatically sorted
                    ↓
         ┌──────────────────────┐
         │   Assign IDs (0-N)   │
         └──────────────────────┘
                    ↓
    ┌────────────────────────────────┐
    │ compress = {1:0, 50:1,         │
    │             200:2, 1000:3}     │
    │                                │
    │ rev_map = [1, 50, 200, 1000]  │
    └────────────────────────────────┘
                    ↓
         ┌──────────────────────┐
         │  get_compressed()    │
         │      called          │
         └──────────────────────┘
                    ↓
    For each element in original array:
    1000 → compress[1000] → 3
    50   → compress[50]   → 1
    1000 → compress[1000] → 3
    200  → compress[200]  → 2
    50   → compress[50]   → 1
    1    → compress[1]    → 0
                    ↓
    Compressed Array: [3, 1, 3, 2, 1, 0]
                    ↓
         ┌──────────────────────┐
         │  Use with BIT/       │
         │  Segment Tree        │
         │  (Size = 4 only!)    │
         └──────────────────────┘
```

---

## 💡 **Memory Comparison:**
```
WITHOUT Compression:
━━━━━━━━━━━━━━━━━━━━
Array: [1, 50, 200, 1000]
BIT Size needed: 1001
Memory: 1001 * 8 bytes = ~8 KB

WITH Compression:
━━━━━━━━━━━━━━━━━━━━
Compressed: [0, 1, 2, 3]
BIT Size needed: 4
Memory: 4 * 8 bytes = 32 bytes

Savings: 8000 bytes! 🎉
```
