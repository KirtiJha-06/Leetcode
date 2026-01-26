class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& A) {
        // Sort the array so that minimum absolute differences
        // will always occur between adjacent elements
        sort(A.begin(), A.end());

        // Initialize the minimum difference to the largest possible int
        int minDiff = INT_MAX;

        // Result vector to store pairs with minimum absolute difference
        vector<vector<int>> res;

        // Start from index 1 to compare each element with its previous one
        for (int i = 1; i < A.size(); i++) {
            // Compute the difference between adjacent elements
            int diff = A[i] - A[i - 1];

            // If a smaller difference is found
            if (diff < minDiff) {
                // Update the minimum difference
                minDiff = diff;

                // Clear previous results since we found a better minimum
                res = {};

                // Store the new pair
                res.push_back({A[i - 1], A[i]});
            }
            // If the difference matches the current minimum
            else if (diff == minDiff) {
                // Add this pair to the result
                res.push_back({A[i - 1], A[i]});
            }
        }

        // Return all pairs with the minimum absolute difference
        return res;
    }
TC:O(n log n)
SC: O(n)
};
