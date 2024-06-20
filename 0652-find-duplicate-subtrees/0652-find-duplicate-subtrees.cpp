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
    string traverse(vector<TreeNode*>& ans, unordered_map<string, int>& subtreeMap, TreeNode* root) {
        if (root == nullptr) {
            return "N";
        }
        string s = to_string(root->val) + "," + traverse(ans, subtreeMap, root->left) + "," + traverse(ans, subtreeMap, root->right);
        if (subtreeMap[s] == 1) {
            ans.push_back(root);
        }
        subtreeMap[s]++;
        return s;
    }

    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        vector<TreeNode*> ans;
        unordered_map<string, int> subtreeMap;
        traverse(ans, subtreeMap, root);
        return ans;
    }
};
