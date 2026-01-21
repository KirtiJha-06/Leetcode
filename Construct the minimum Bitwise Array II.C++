class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {

        // Iterate through each element of the array by reference
        for (int &x : nums) {

            // Default answer is -1 (used if no valid bit is found)
            int res = -1;

            // Start checking from the least significant bit (2^0)
            int d = 1;

            // While the current bit in x is set (equals 1)
            while ((x & d) != 0) {

                // If this bit is 1, subtract its value from x
                // Store this as the current best result
                res = x - d;

                // Move to the next higher bit (2^1, 2^2, ...)
                d <<= 1;
            }

            // Replace x with the computed result
            // If x had no trailing 1 bits, res remains -1
            x = res;
        }

        // Return the modified array
        return nums;
    }
};
TC: O(nlogn)
SC: O(1)
