class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {

        // Loop through the array, but stop before the last element
        // because we are checking ahead (i+1, i+2, i+3)
        for(int i = 0; i < nums.size() - 1; i++) {
            // If current element is equal to the next element,
            // then this must be the repeated element
            if(nums[i] == nums[i + 1]) {
                return nums[i];
            }
            // Check element 2 positions ahead (to avoid out-of-bound access)
            // If nums[i] equals nums[i+2], return it
            if(i + 2 < nums.size() && nums[i] == nums[i + 2]) {
                return nums[i];
            }
            // Check element 3 positions ahead (to cover more possible patterns)
            // If nums[i] equals nums[i+3], return it
            if(i + 3 < nums.size() && nums[i] == nums[i + 3]) {
                return nums[i];
            }
        }

        // If no repeated element is found, return -1
        return -1;
    }
};

TC:  O(n)
SC:  O(1)
