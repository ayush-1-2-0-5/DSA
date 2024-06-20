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
   bool isSym(TreeNode*root1,TreeNode*root2)
    {
        if(root1==nullptr && root2==nullptr)
        return true;
         if(root1==nullptr || root2==nullptr)
         return false;
         if(root1->val!=root2->val)
         return false;

         bool check=isSym(root1->left,root2->left) && isSym(root1->right,root2->right);

         return check;
    }
    bool isSameTree(TreeNode* p, TreeNode* q) {
        return isSym(p,q);
    }
};