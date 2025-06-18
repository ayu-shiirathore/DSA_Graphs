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
    TreeNode* searchBST(TreeNode* root, int val) {
        // Base case: if root is null or the value is found
        if (root == nullptr || root->val == val) {
            return root;
        }
        
        // If the value to search is smaller than the current node's value,
        // recurse on the left subtree.
        if (val < root->val) {
            return searchBST(root->left, val);
        }
        
        // If the value to search is greater than the current node's value,
        // recurse on the right subtree.
        return searchBST(root->right, val);
    }
};