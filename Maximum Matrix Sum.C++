class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {  
        // Function to return the maximum possible sum of the matrix

        long long totalSum = 0;  
        // Stores the sum of absolute values of all elements

        int minAbsVal = INT_MAX;  
        // Tracks the smallest absolute value in the matrix

        int negativeCount = 0;  
        // Counts how many negative numbers exist in the matrix

        for (auto& row : matrix) {  
            // Loop through each row of the matrix

            for (int val : row) {  
                // Loop through each element in the current row

                totalSum += abs(val);  
                // Add absolute value to maximize contribution

                if (val < 0) {  
                    // Check if the element is negative
                    negativeCount++;  
                    // Increase negative number count
                }

                minAbsVal = min(minAbsVal, abs(val));  
                // Update the smallest absolute value found so far
            }
        }

        if (negativeCount % 2 != 0) {  
            // If the number of negatives is odd

            totalSum -= 2 * minAbsVal;  
            // One value must remain negative, so subtract twice the smallest abs value
        }

        return totalSum;  
        // Return the maximum possible matrix sum
    }
};
TC: O(N*M)
SC: O(1)
