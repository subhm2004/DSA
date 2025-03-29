// given k number of cooks with their rank r
// given n number of pratas to be prepared
// find the minimum time in which cooks can prepare n number of pratas
#include <bits/stdc++.h>
using namespace std;

bool possible(vector<int> cooksRanks, int P, int mid)
{
    int currP = 0;
    for (int i = 0; i < cooksRanks.size(); i++)
    {
        int R = cooksRanks[i];
        int j = 1;
        int timetaken = 0;
        while (true)
        {
            if (timetaken + j * R <= mid)
            {
                currP++;
                timetaken += j * R;
                j++;
            }
            else
            {
                break;
            }
        }
        if (currP >= P)
        {
            return true;
        }
    }
    return false;
}
int minTime(vector<int> cooksRank, int P)
{
    int start = 0;
    int highestRank = *max_element(cooksRank.begin(), cooksRank.end());
    int end = highestRank * (P * (P + 1) / 2);
    int ans = -1;
    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        if (possible(cooksRank, P, mid))
        {
            ans = mid;
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
    }
    return ans;
}
int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int P, C;
        cin >> P >> C;
        vector<int> cookRank;
        while (C--)
        {
            int R;
            cin >> R;
            cookRank.push_back(R);
        }
        cout << endl;
        cout << minTime(cookRank, P) << endl
             << endl;
    }
    return 0;
}