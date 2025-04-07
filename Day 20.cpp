class Solution
{
public:
    int maxCoins(vector<int> &nums)
    {
        int n = nums.size();

        nums.insert(nums.begin(), 1);
        nums.push_back(1);

        vector<vector<int>> dp(n + 2, vector<int>(n + 2, 0));

        for (int length = 1; length <= n; length++)
        {
            for (int left = 1; left <= n - length + 1; left++)
            {
                int right = left + length - 1;
                for (int k = left; k <= right; k++)
                {
                    dp[left][right] =
                        max(dp[left][right],
                            dp[left][k - 1] +
                                nums[left - 1] * nums[k] * nums[right + 1] +
                                dp[k + 1][right]);
                }
            }
        }

        return dp[1][n];
    }
};