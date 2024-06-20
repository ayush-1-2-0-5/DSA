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
     int d(vector<int> &maxi,TreeNode*root)
     {
        if(root==nullptr)
        return 0;
        int lh=d(maxi,root->left);
        int rh=d(maxi,root->right);
        maxi[0]=max(maxi[0],lh+rh);
        return 1+max(lh,rh);
     }
    int diameterOfBinaryTree(TreeNode* root) {
      vector<int> maxi(1,-1);
       int b= d(maxi,root);
        return maxi[0];
    }
};