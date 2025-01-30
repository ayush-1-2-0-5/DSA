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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root==nullptr)
        return ans;
        queue<TreeNode*> q;
        q.push(root);
        int level=0;


        while(!q.empty())
        {
           int sz=q.size();
           vector<int> temp;

           for(int i=0;i<sz;++i)
           {
            auto nd=q.front();
            q.pop();
            temp.push_back(nd->val);

            if(nd->left)
            q.push(nd->left);
            if(nd->right)
            q.push(nd->right);
           }

           ans.push_back(temp);
            
        }
        return ans;
    }
};