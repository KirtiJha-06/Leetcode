
class Solution {

    // Helper function to compute all possible distances (edges)
    // between any two fences, including the borders (1 and border)
    unordered_set<int> getEdges(vector<int>& fences, int border) {

        unordered_set<int> st; 
        // Stores all unique distances between fence positions

        fences.push_back(1);      
        // Add the starting border (row 1 or column 1)

        fences.push_back(border); 
        // Add the ending border (row m or column n)

        sort(fences.begin(), fences.end());
        // Sort fence positions so distance calculation is valid

        for (int i = 0; i < fences.size(); i++) {
            // Pick first fence
            for (int j = i + 1; j < fences.size(); j++) {
                // Pick second fence after the first
                st.insert(fences[j] - fences[i]);
                // Store the distance between the two fences
            }
        }

        return st;
        // Return all possible segment lengths
    }

public:
    int maximizeSquareArea(int m, int n, vector<int>& hFences,
                           vector<int>& vFences) {

        // Get all possible vertical distances (heights)
        auto hEdges = getEdges(hFences, m);

        // Get all possible horizontal distances (widths)
        auto vEdges = getEdges(vFences, n);

        int res = 0;
        // Stores the maximum possible square side length

        for (auto e : hEdges) {
            // Check every possible height
            if (vEdges.contains(e)) {
                // If the same distance exists horizontally,
                // a square of side e is possible
                res = max(res, e);
                // Keep the largest possible side
            }
        }

        if (res == 0) {
            // No common distance found → no square possible
            res = -1;
        } else {
            // Square area = side², apply modulo
            res = 1ll * res * res % 1000000007;
        }

        return res;
        // Return maximum square area or -1
    }
};
TC: O(H² + V²)
SC: O(H² + V²)
