#include <bits/stdc++.h> // for max profit
using namespace std;

// Typedef for better readability
typedef tuple<char, int, int> Job; // {id, deadline, profit}

// Comparator to sort jobs by profit in descending order
bool compareByProfit(Job a, Job b)
{
    return get<2>(a) > get<2>(b); // Compare based on profit
}

// Function to schedule jobs to maximize profit
void printJobScheduling(vector<Job> jobs)
{
    int n = jobs.size();

    // Sort jobs by profit
    sort(jobs.begin(), jobs.end(), compareByProfit);

    // Find the maximum deadline among the jobs
    int maxDeadline = 0;
    for (int i = 0; i < n; i++)
    {
        maxDeadline = max(maxDeadline, get<1>(jobs[i]));
    }

    // Create a slot array to keep track of free time slots
    vector<int> slots(maxDeadline + 1, -1); // -1 indicates the slot is free

    // To store the job sequence
    vector<char> jobSequence;
    int totalProfit = 0;

    // Iterate over each job
    for (int i = 0; i < n; i++)
    {
        // Get job details
        char id = get<0>(jobs[i]);
        int deadline = get<1>(jobs[i]);
        int profit = get<2>(jobs[i]);

        // Find a free slot for this job (starting from its deadline)
        for (int j = deadline; j > 0; j--)
        {
            if (slots[j] == -1)
            {
                // Assign this job to the free slot
                slots[j] = i;
                jobSequence.push_back(id);
                totalProfit += profit;
                break;
            }
        }
    }

    // Print the job sequence and total profit
    cout << "Job sequence: ";
    for (char job : jobSequence)
    {
        cout << job << " ";
    }
    cout << "\nTotal Profit: " << totalProfit << endl;
}

// Driver code
int main()
{
    // Jobs represented as {id, deadline, profit}
    vector<Job> jobs = {
        {'a', 2, 100},
        {'b', 1, 19},
        {'c', 2, 27},
        {'d', 1, 25},
        {'e', 3, 15}};

    cout << "Following is the maximum profit sequence of jobs:\n";
    printJobScheduling(jobs);

    return 0;
}
