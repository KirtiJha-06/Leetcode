
class Solution {
public:
    // Modulo value as required by the problem
    long long MOD = 1e9 + 7;

    // Stores the maximum product found
    long long ans = 0;

    // DFS function to compute subtree sums
    long long dfs(TreeNode* node) {
        // Base case: empty node contributes 0
        if (!node) return 0;

        // Recursively compute sum of left and right subtrees
        // Add them to current node's value
        node->val += dfs(node->left) + dfs(node->right);

        // Return the total sum of this subtree
        return node->val;
    }

    int maxProduct(TreeNode* root) {
        // First DFS calculates the total sum of the entire tree
        // After this, each node->val contains the sum of its subtree
        long long total = dfs(root);

        // Use BFS (queue) to traverse all nodes
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();

            if (!node) continue;

            /*
              If we cut the edge above this node:
              - One subtree has sum = node->val
              - The other subtree has sum = total - node->val
              Compute the product of these two parts
            */
            long long cur = (total - node->val) * node->val;

            // Update maximum product found so far
            ans = max(ans, cur);

            // Push children into queue for BFS traversal
            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
        }

        // Return the maximum product modulo 1e9 + 7
        return ans % MOD;
    }
};
TC: O(n)
SC: O(n)
