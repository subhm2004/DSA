#include <iostream>
#include <vector>
using namespace std;

class Union_find
{
    vector<int> parent; // Parent vector to store the representative of each set
    vector<int> size;   // Size vector to store the size of each set
    vector<int> rank;   // Rank vector for optimizing the union operation

public:
    // Constructor to initialize the parent, size, and rank arrays
    Union_find(int n)
    {
        parent.resize(n);
        size.resize(n, 1); // Initial size of each set is 1
        rank.resize(n, 0); // Initial rank of each set is 0

        for (int i = 0; i < n; i++)
        {
            parent[i] = i; // Har node ka parent apne aap ko banate hain
        }
    }

    // Find function with path compression to find the representative of set containing 'x'
    int find(int x)
    {
        if (x == parent[x])                 // Agar 'x' apne hi parent ko point karta hai
            return x;                       // Toh x apne set ka representative hai
        return parent[x] = find(parent[x]); // Path compression: recursively find and update the parent
    }

    // UNION_BY_SIZE: Dono sets ko size ke according merge karte hain
    void UNION_BY_SIZE(int x, int y)
    {
        int x_parent = find(x); // x ka representative
        int y_parent = find(y); // y ka representative

        if (x_parent == y_parent) // Agar dono already same set mein hain
            return;

        // Jo set bada hai, usme chhota set attach karte hain
        if (size[x_parent] > size[y_parent])
        {
            parent[y_parent] = x_parent;
            size[x_parent] += size[y_parent]; // Size update karte hain
        }
        else if (size[x_parent] < size[y_parent])
        {
            parent[x_parent] = y_parent;
            size[y_parent] += size[x_parent]; // Size update karte hain
        }
        else
        {
            parent[x_parent] = y_parent;
            size[y_parent] += size[x_parent]; // Size update karte hain
            rank[y_parent]++;                 // Agar size same hai toh rank ko increase karte hain
        }
    }

    // UNION_BY_RANK: Dono sets ko rank ke according merge karte hain
    void UNION_BY_RANK(int x, int y)
    {
        int x_parent = find(x); // x ka representative
        int y_parent = find(y); // y ka representative

        if (x_parent == y_parent) // Agar dono already same set mein hain
            return;

        // Rank ke hisaab se merge karte hain
        if (rank[x_parent] < rank[y_parent])
        {
            parent[x_parent] = y_parent; // Chhoti rank wale ko bade rank wale mein merge karte hain
        }
        else if (rank[x_parent] > rank[y_parent])
        {
            parent[y_parent] = x_parent; // Chhoti rank wale ko bade rank wale mein merge karte hain
        }
        else
        {
            parent[x_parent] = y_parent; // Agar rank same hai toh ek ko doosre mein merge karte hain
            rank[y_parent]++;            // Rank ko increase karte hain
        }
    }

    // Count the number of connected components
    int countComponents()
    {
        int components = 0; // Initialize components count
        for (int i = 0; i < parent.size(); ++i)
        {
            if (parent[i] == i) // Agar parent khud apna representative hai, toh wo root node hai
                components++;   // Components ka count increase karte hain
        }
        return components;
    }
};

int main()
{
    // Create a Union_find object with 6 elements (0 to 5)
    Union_find Union_find(6);

    // UNION_BY_SIZE kuch sets ko merge karte hain
    Union_find.UNION_BY_SIZE(0, 1);
    Union_find.UNION_BY_SIZE(0, 2);
    Union_find.UNION_BY_RANK(3, 4);
    Union_find.UNION_BY_SIZE(1, 3);

    // Check if elements are connected
    cout << "Are 0 and 3 in the same set? " << (Union_find.find(0) == Union_find.find(3) ? "Yes" : "No") << endl;
    cout << "Are 0 and 5 in the same set? " << (Union_find.find(0) == Union_find.find(5) ? "Yes" : "No") << endl;
    cout << "Are 3 and 4 in the same set? " << (Union_find.find(3) == Union_find.find(4) ? "Yes" : "No") << endl;

    // Check number of connected components
    cout << "Number of connected components: " << Union_find.countComponents() << endl;

    return 0;
}
