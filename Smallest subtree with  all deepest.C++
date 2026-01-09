class Solution {
public:

    // DFS returns:
    // 1) TreeNode* → root of the subtree containing all deepest nodes
    // 2) int        → maximum depth from this node downward
    pair<TreeNode*, int> dfs(TreeNode* root) {

        // Base case: empty node
        // No subtree, depth = 0
        if (!root) {
            return {nullptr, 0};
        }

        // Recursively solve for left subtree
        auto left = dfs(root->left);

        // Recursively solve for right subtree
        auto right = dfs(root->right);

        // If left subtree is deeper than right
        // → all deepest nodes lie in the left subtree
        if (left.second > right.second) {
            // Keep left subtree root
            // Increase depth by 1 (current node)
            return {left.first, left.second + 1};

        // If right subtree is deeper than left
        // → all deepest nodes lie in the right subtree
        } else if (left.second < right.second) {
            // Keep right subtree root
            // Increase depth by 1
            return {right.first, right.second + 1};

        // If both depths are equal
        // → deepest nodes exist in BOTH subtrees
        // → current node becomes the LCA (answer)
        } else {
            return {root, left.second + 1};
        }
    }

    // Main function required by the problem
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {

        // We only need the subtree root, not the depth
        return dfs(root).first;
    }
};

TC: O(N)
SC: O(H)
