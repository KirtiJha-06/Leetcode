
class Solution {                    
public:
    int minimumDifference(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());   
        // Sort the array so elements are in increasing order.
        // This helps us compare groups of k elements efficiently.

        int mindiff = INT_MAX;        
        // Initialize the minimum difference with the largest possible value.

        for (int i = 0; i <= nums.size() - k; ++i) {
            // Loop through the array.
            // nums.size() - k ensures we only check valid subarrays of size k.

            int diff = nums[i + k - 1] - nums[i];
            // Calculate the difference between the maximum and minimum
            // elements in the current window of size k.

            mindiff = min(mindiff, diff);
            // Update the minimum difference if the current one is smaller.
        }

        return mindiff;               
        // Return the smallest difference found.
    }
};
TC: O(nlogn)
SC: O(1)
