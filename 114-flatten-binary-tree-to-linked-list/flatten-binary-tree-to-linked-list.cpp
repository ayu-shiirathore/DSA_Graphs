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
private:
    void helper(TreeNode*node,TreeNode*&prev){
        if(node==NULL) return;

        helper(node->right,prev);
        helper(node->left,prev);
        node->right=prev;
        node->left=NULL;
        prev=node;
       
    }
public:
    void flatten(TreeNode* root) {
        TreeNode*prev=NULL;
        helper(root,prev);
    }
};