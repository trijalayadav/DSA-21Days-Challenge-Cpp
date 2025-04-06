class Solution
{
public:
    int solveOptimal(int n, vector<int> &a)
    {
        if (n == 0)
        {
            return 0;
        }
        vector<int> ans;
        ans.push_back(a[0]);

        for (int i = 1; i < n; i++)
        {
            if (a[i] > ans.back())
            {
                ans.push_back(a[i]);
            }
            else
            {
                int index =
                    lower_bound(ans.begin(), ans.end(), a[i]) - ans.begin();
                ans[index] = a[i];
            }
        }
        return ans.size();
    }
    int maxEnvelopes(vector<vector<int>> &envelopes)
    {
        if (envelopes.empty())
            return 0;

        // Step 1: Sort by width (ascending) and height (descending for same
        // width)
        sort(envelopes.begin(), envelopes.end(),
             [](vector<int> &a, vector<int> &b)
             {
                 if (a[0] == b[0])
                     return a[1] > b[1]; // Descending height for same width
                 return a[0] < b[0];     // Ascending width
             });

        // Step 2: Extract heights and apply LIS
        vector<int> heights;
        for (auto &envelope : envelopes)
        {
            heights.push_back(envelope[1]);
        }

        return solveOptimal(heights.size(), heights);
    }
};