class Solution
{
    vector<int> nextSmallerElement(vector<int> &arr, int n)
    {
        stack<int> s;
        s.push(n);
        vector<int> ans(n);
        for (int i = n - 1; i >= 0; i--)
        {
            int curr = arr[i];
            while (s.top() != n && arr[s.top()] >= curr)
            {
                s.pop();
            }
            ans[i] = s.top();
            s.push(i);
        }
        return ans;
    }
    vector<int> prevSmallerElement(vector<int> &arr, int n)
    {
        stack<int> s;
        s.push(-1);
        vector<int> ans(n);
        for (int i = 0; i < n; i++)
        {
            int curr = arr[i];
            while (s.top() != -1 && arr[s.top()] >= curr)
            {
                s.pop();
            }
            ans[i] = s.top();
            s.push(i);
        }
        return ans;
    }
    int largestRectangleArea(vector<int> heights)
    {
        int n = heights.size();
        vector<int> next = nextSmallerElement(heights, n);
        vector<int> prev = prevSmallerElement(heights, n);
        int maxArea = 0;
        for (int i = 0; i < n; i++)
        {
            int width = next[i] - prev[i] - 1;
            maxArea = max(maxArea, heights[i] * width);
        }
        return maxArea;
    }

public:
    int maximalRectangle(vector<vector<char>> &matrix)
    {
        if (matrix.empty())
            return 0;
        int n = matrix.size();
        int m = matrix[0].size();
        vector<int> heights(m, 0);

        // Convert first row to int heights
        for (int j = 0; j < m; j++)
        {
            heights[j] = matrix[0][j] - '0';
        }

        int maxArea = largestRectangleArea(heights);
        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                heights[j] = (matrix[i][j] == '1') ? heights[j] + 1 : 0;
            }
            maxArea = max(maxArea, largestRectangleArea(heights));
        }
        return maxArea;
    }
};