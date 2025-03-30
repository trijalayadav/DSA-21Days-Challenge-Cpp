class Solution
{
public:
    void update(int index, vector<int> &bit)
    {
        while (index <= bit.size())
        {
            bit[index]++;
            index += index & -index;
        }
    }
    int getSum(int index, vector<int> &bit)
    {
        int sum = 0;
        while (index > 0)
        {
            sum += bit[index];
            index -= index & -index;
        }
        return sum;
    }
    vector<int> countSmaller(vector<int> &nums)
    {
        vector<int> result(nums.size(), 0);
        vector<int> bit(20005, 0);
        for (int i = 0; i < nums.size(); i++)
        {
            nums[i] += 10001;
        }
        for (int i = nums.size() - 1; i >= 0; i--)
        {
            int smallerCount =
                getSum(nums[i] - 1, bit);
            result[i] =
                smallerCount;
            update(nums[i], bit);
        }
        return result;
    }
};