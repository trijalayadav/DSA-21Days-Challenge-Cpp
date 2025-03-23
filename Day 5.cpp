class Solution
{
public:
    string minWindow(string s, string t)
    {
        if (s.length() < t.length())
            return "";

        vector<int> freqT(128, 0), freqS(128, 0);
        for (char ch : t)
            freqT[ch]++;

        int i = 0, j = 0, matchCount = 0;
        int minLen = INT_MAX, startIndex = -1;

        while (i < s.length())
        {
            // Expand window
            char ch = s[i];
            freqS[ch]++;
            if (freqS[ch] <= freqT[ch])
                matchCount++;

            // Shrink window
            while (matchCount == t.length())
            {
                if (i - j + 1 < minLen)
                {
                    minLen = i - j + 1;
                    startIndex = j;
                }

                // Remove character at `j`
                char chj = s[j];
                freqS[chj]--;
                if (freqS[chj] < freqT[chj])
                    matchCount--;

                j++; // Move left pointer
            }
            i++; // Move right pointer
        }

        return (startIndex == -1) ? "" : s.substr(startIndex, minLen);
    }
};
