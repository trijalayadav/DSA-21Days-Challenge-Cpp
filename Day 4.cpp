class Solution
{
public:
    int subarraySum(vector<int> &nums, int k)
    {
        int count = 0;
        int sum = 0;
        unordered_map<int, int> m;
        m[0] = 1;
        for (auto num : nums)
        {
            sum += num;
            int val = sum - k;
            if (m.find(val) != m.end())
            {
                count += m[val];
            }
            m[sum]++;
        }

        return count;

        // int count=0;
        // for(int i=0;i<nums.size();i++){
        //     int sum=0;
        //     for(int j=i;j<nums.size();j++){
        //         sum+=nums[j];
        //         if(sum==k){
        //             count++;
        //         }
        //     }
        // }
        // return count;
    }
};