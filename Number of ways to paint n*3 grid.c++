
class Solution {
public:
    int numOfWays(int n) {

        const int MOD = 1000000007; // Modulo to prevent integer overflow

        long long x = 6, y = 6;     
        // x = number of ways where a row has 3 different colors (ABC)
        // y = number of ways where a row has 2 same + 1 different colors (ABA)
        // For the first row:
        // ABC → 3 * 2 * 1 = 6
        // ABA → 3 * 2 = 6

        for (int i = 2; i <= n; i++) {
            // Compute number of ABC patterns for current row
            // From previous ABC → 3 choices
            // From previous ABA → 2 choices
            long long new_x = (3 * x + 2 * y) % MOD;

            // Compute number of ABA patterns for current row
            // From previous ABC → 2 choices
            // From previous ABA → 2 choices
            long long new_y = (2 * x + 2 * y) % MOD;

            // Update for next iteration
            x = new_x;
            y = new_y;
        }

        // Total ways = ABC patterns + ABA patterns in the last row
        return (x + y) % MOD;
    }
};

TC: O(n)
SC: O(1)
