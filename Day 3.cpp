class Solution
{
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        int m = nums1.size(), n = nums2.size();
        if (m > n)
        {
            return findMedianSortedArrays(nums2, nums1);
        }
        int low = 0, high = m;
        while (low <= high)
        {
            int part1 = (low + high) / 2;
            int part2 = (m + n + 1) / 2 - part1;

            int maxLeft1 = (part1 == 0) ? INT_MIN : nums1[part1 - 1];
            int minRight1 = (part1 == m) ? INT_MAX : nums1[part1];

            int maxLeft2 = (part2 == 0) ? INT_MIN : nums2[part2 - 1];
            int minRight2 = (part2 == n) ? INT_MAX : nums2[part2];

            if (maxLeft1 <= minRight2 && maxLeft2 <= minRight1)
            {
                if ((m + n) % 2 == 0)
                {
                    return (max(maxLeft1, maxLeft2) +
                            min(minRight1, minRight2)) /
                           2.0;
                }
                else
                {
                    return max(maxLeft1, maxLeft2);
                }
            }
            else if (maxLeft1 > minRight2)
            {
                high = part1 - 1;
            }
            else
            {
                low = part1 + 1;
            }
        }
        return 0.0;
    }
};