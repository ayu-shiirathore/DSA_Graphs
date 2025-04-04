/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        int maxDepth = -1;  // To keep track of the maximum depth encountered
        return findLCA(root, 0, maxDepth).first;  // Start DFS from root at depth 0
    }
private:
    // Helper function that returns a pair: (LCA node, depth)
    pair<TreeNode*, int> findLCA(TreeNode* node, int depth, int& maxDepth) {
        if (!node) return {nullptr, depth};  // Base case: null node

        // Recurse on left and right subtrees
        auto left = findLCA(node->left, depth + 1, maxDepth);
        auto right = findLCA(node->right, depth + 1, maxDepth);

        // If both left and right have the same depth, current node is the LCA
        if (left.second == right.second) {
            return {node, left.second};
        }

        // If one subtree is deeper, return the deeper one
        return (left.second > right.second) ? left : right;
    }
};