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
       void backtrack(TreeNode * node, int target, vector<int> &temp, vector<vector<int>>&ans)
{
    if(node == nullptr)
    {
        return;
    }

    temp.push_back(node->val);
    if(node->val == target && node->left == nullptr && node->right == nullptr)
    {
        ans.push_back(temp);
    }

    if(node->left != nullptr)
    {
        backtrack(node->left, target - node->val, temp, ans);
    }
    if(node->right != nullptr)
    {
        backtrack(node->right, target - node->val, temp, ans);
    }

    temp.pop_back(); 
}

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        vector<int> temp;
        backtrack(root,targetSum,temp,ans);
        return ans;
    }
};