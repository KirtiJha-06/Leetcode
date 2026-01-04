class Solution {                     
public:
    int sumFourDivisors(vector<int>& nums) {   
        int totalSum = 0;             // Stores final answer

        for (int num : nums) {        // Loop through each number in the array
            int count = 0, sum = 0;   // count = number of divisors, sum = sum of divisors

            for (int i = 1; i * i <= num; ++i) {   // Check divisors from 1 to sqrt(num)
                if (num % i == 0) {                // If i divides num
                    int j = num / i;               // j is the paired divisor

                    if (i == j) {                  // If num is a perfect square
                        count++;                   // Only one divisor counted
                        sum += i;                  // Add the divisor once
                    } else {                        // If i and j are different
                        count += 2;                // Two divisors found
                        sum += i + j;              // Add both divisors
                    }
                }

                if (count > 4)                     // If more than 4 divisors
                    break;                         // Stop checking further
            }

            if (count == 4) {                      // If exactly 4 divisors found
                totalSum += sum;                   // Add their sum to totalSum
            }
        }
        return totalSum;                           // Return the final result
    }
};

TC: O(n × √m)
SC: O(1)
