class Solution {
public:
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {

        // n = length of nums1, m = length of nums2
        int n = nums1.size(), m = nums2.size();

        // A very small number to represent "invalid / impossible" states
        // We use this because the answer can be negative
        const int NEG = -1e9;

        // dp[i][j] = maximum dot product using
        // first i elements of nums1 and first j elements of nums2
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, NEG));

        // Iterate through all prefixes of nums1
        for (int i = 1; i <= n; i++) {

            // Iterate through all prefixes of nums2
            for (int j = 1; j <= m; j++) {

                // Option 1: take nums1[i-1] and nums2[j-1] together
                // - multiply them
                // - add dp[i-1][j-1] only if it is positive
                //   (otherwise, starting fresh is better)
                int take = nums1[i - 1] * nums2[j - 1]
                           + max(0, dp[i - 1][j - 1]);

                // dp[i][j] is the maximum of:
                // 1. taking both current elements
                // 2. skipping nums1[i-1]
                // 3. skipping nums2[j-1]
                dp[i][j] = max({
                    take,          // take both
                    dp[i - 1][j],  // skip nums1[i-1]
                    dp[i][j - 1]   // skip nums2[j-1]
                });
            }
        }

        // Final answer: best dot product using all elements
        return dp[n][m];
    }
};
TC: O(n*m);
SC: O(m*m);
