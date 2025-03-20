class Solution
{
public:
    int trap(vector<int> &height)
    {
        int n = height.size();

        int l = 0;
        int r = n - 1;

        int lMax = 0, rMax = 0;
        int ans = 0;

        while (l < r)
        {
            lMax = max(lMax, height[l]);
            rMax = max(rMax, height[r]);

            if (lMax < rMax)
            {
                ans += lMax - height[l];
                l++;
            }
            else
            {
                ans += rMax - height[r];
                r--;
            }
        }

        return ans;
        // vector<int> leftMax(n,0);
        // vector<int> rightMax(n,0);

        // leftMax[0]=height[0];
        // rightMax[n-1]=height[n-1];

        // for(int i=1;i<n;i++){
        //     leftMax[i]=max(leftMax[i-1],height[i]);
        // }

        // for(int i=n-2;i>=0;i--){
        //     rightMax[i]=max(rightMax[i+1],height[i]);
        // }

        // int trapwater=0;
        // for(int i=0;i<n;i++){
        //     trapwater=trapwater+min(leftMax[i],rightMax[i])-height[i];
        // }

        // return trapwater;
    }
};