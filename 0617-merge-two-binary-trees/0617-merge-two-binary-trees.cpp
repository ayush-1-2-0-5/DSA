/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr, right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* merge(TreeNode* a, TreeNode* b) {
        if (a == nullptr && b == nullptr) return nullptr;
        if (a == nullptr) return b;
        if (b == nullptr) return a;
        
        TreeNode* res = new TreeNode(a->val + b->val);
        res->left = merge(a->left, b->left);
        res->right = merge(a->right, b->right);
        return res;
    }

    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        return merge(root1, root2);
    }
};
