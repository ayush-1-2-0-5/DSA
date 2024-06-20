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
    void traverse(TreeNode* root, int currentMin, int currentMax, int &maxDiff) {
        if (root == nullptr) return;
        currentMin = min(currentMin, root->val);
        currentMax = max(currentMax, root->val);
        maxDiff = max(maxDiff, currentMax - currentMin);
        traverse(root->left, currentMin, currentMax, maxDiff);
        traverse(root->right, currentMin, currentMax, maxDiff);
    }

    int maxAncestorDiff(TreeNode* root) {
        int maxDiff = 0;
        if (root == nullptr) return maxDiff;
        traverse(root, root->val, root->val, maxDiff);
        return maxDiff;
    }
};
